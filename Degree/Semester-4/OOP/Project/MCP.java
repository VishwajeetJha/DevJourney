import javafx.application.Application;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Alert;
import javafx.scene.control.Button;
import javafx.scene.control.ButtonBar;
import javafx.scene.control.ButtonType;
import javafx.scene.control.CheckBox;
import javafx.scene.control.ComboBox;
import javafx.scene.control.DatePicker;
import javafx.scene.control.Dialog;
import javafx.scene.control.Label;
import javafx.scene.control.ScrollPane;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;
import javafx.scene.control.TextInputDialog;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.Priority;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;
import java.util.Optional;
import java.util.TreeMap;

public class MCP extends Application {
    private static final DateTimeFormatter STORAGE_DATE_FORMAT = DateTimeFormatter.ISO_LOCAL_DATE;
    private static final DateTimeFormatter DISPLAY_DATE_FORMAT = DateTimeFormatter.ofPattern("dd-MM-yyyy");
    private static final List<String> SUBJECTS = Arrays.asList("Mathematics", "Physics", "Chemistry");

    private static final Path ATTENDANCE_FILE = Path.of("attendance_data.csv");
    private static final Path STUDENTS_FILE = Path.of("students.csv");

    private final Map<String, Student> students = new TreeMap<>();
    private final List<AttendanceRecord> attendanceRecords = new ArrayList<>();

    private TextField nameField;
    private TextField idField;
    private DatePicker datePicker;
    private ComboBox<String> subjectComboBox;
    private TextArea outputArea;

    @Override
    public void start(Stage stage) {
        initializeData();

        BorderPane root = new BorderPane();
        root.setPadding(new Insets(16));

        root.setTop(buildInputPane());
        root.setCenter(buildOutputPane());
        root.setBottom(buildActionPane());

        Scene scene = new Scene(root, 960, 640);
        stage.setTitle("MCP - Attendance Management System (JavaFX)");
        stage.setScene(scene);
        stage.show();

        outputArea.setText("Loaded " + students.size() + " students and " + attendanceRecords.size() + " attendance records.");
    }

    private VBox buildInputPane() {
        Label title = new Label("Student Attendance Management");
        title.setStyle("-fx-font-size: 20px; -fx-font-weight: bold;");

        nameField = new TextField();
        idField = new TextField();
        datePicker = new DatePicker(LocalDate.now());
        subjectComboBox = new ComboBox<>();
        subjectComboBox.getItems().addAll(SUBJECTS);
        subjectComboBox.getSelectionModel().selectFirst();

        GridPane form = new GridPane();
        form.setHgap(10);
        form.setVgap(10);

        form.add(new Label("Name:"), 0, 0);
        form.add(nameField, 1, 0);
        form.add(new Label("ID:"), 2, 0);
        form.add(idField, 3, 0);
        form.add(new Label("Date:"), 0, 1);
        form.add(datePicker, 1, 1);
        form.add(new Label("Subject:"), 2, 1);
        form.add(subjectComboBox, 3, 1);

        VBox topPane = new VBox(10, title, form);
        return topPane;
    }

    private ScrollPane buildOutputPane() {
        outputArea = new TextArea();
        outputArea.setEditable(false);
        outputArea.setWrapText(true);

        ScrollPane scrollPane = new ScrollPane(outputArea);
        scrollPane.setFitToWidth(true);
        scrollPane.setFitToHeight(true);
        VBox.setVgrow(scrollPane, Priority.ALWAYS);
        return scrollPane;
    }

    private HBox buildActionPane() {
        Button addStudentButton = new Button("Add Student");
        Button markAttendanceButton = new Button("Mark Attendance");
        Button viewAttendanceButton = new Button("View Attendance");
        Button studentDetailsButton = new Button("Show Student Details");
        Button subjectAttendanceButton = new Button("Show Subject Attendance");

        addStudentButton.setOnAction(e -> addStudent());
        markAttendanceButton.setOnAction(e -> markAttendance());
        viewAttendanceButton.setOnAction(e -> displayAttendanceForDate());
        studentDetailsButton.setOnAction(e -> promptAndDisplayStudentDetails());
        subjectAttendanceButton.setOnAction(e -> displaySubjectAttendance());

        HBox actionPane = new HBox(10,
                addStudentButton,
                markAttendanceButton,
                viewAttendanceButton,
                studentDetailsButton,
                subjectAttendanceButton
        );
        actionPane.setAlignment(Pos.CENTER_LEFT);
        actionPane.setPadding(new Insets(16, 0, 0, 0));
        return actionPane;
    }

    private void initializeData() {
        loadStudentsFromCsv();
        loadAttendanceFromCsv();
        deduplicateAttendance();
    }

    private void addStudent() {
        String name = normalize(nameField.getText());
        String id = normalize(idField.getText());

        if (name.isBlank() || id.isBlank()) {
            showError("Validation Error", "Name and ID are required.");
            return;
        }

        if (!id.matches("[A-Za-z0-9_-]+")) {
            showError("Validation Error", "ID must contain only letters, numbers, underscore, or hyphen.");
            return;
        }

        if (students.containsKey(id)) {
            showError("Duplicate ID", "A student with this ID already exists.");
            return;
        }

        students.put(id, new Student(name, id));
        saveStudentsToCsv();

        nameField.clear();
        idField.clear();
        showInfo("Success", "Student added successfully.");
    }

    private void markAttendance() {
        if (students.isEmpty()) {
            showError("No Students", "Add students before marking attendance.");
            return;
        }

        LocalDate selectedDate = datePicker.getValue();
        String subject = subjectComboBox.getValue();
        if (selectedDate == null || subject == null || subject.isBlank()) {
            showError("Validation Error", "Please select a valid date and subject.");
            return;
        }

        Dialog<ButtonType> dialog = new Dialog<>();
        dialog.setTitle("Mark Attendance");
        dialog.setHeaderText("Date: " + selectedDate.format(DISPLAY_DATE_FORMAT) + " | Subject: " + subject);

        ButtonType saveButtonType = new ButtonType("Save", ButtonBar.ButtonData.OK_DONE);
        dialog.getDialogPane().getButtonTypes().addAll(saveButtonType, ButtonType.CANCEL);

        VBox listContainer = new VBox(8);
        listContainer.setPadding(new Insets(10));
        Map<String, CheckBox> checkBoxes = new HashMap<>();

        students.values().stream()
                .sorted(Comparator.comparing(Student::getName, String.CASE_INSENSITIVE_ORDER))
                .forEach(student -> {
                    CheckBox checkBox = new CheckBox(student.getName() + " (" + student.getId() + ")");
                    AttendanceRecord existing = findAttendance(selectedDate, student.getId(), subject);
                    checkBox.setSelected(existing != null && existing.isPresent());
                    checkBoxes.put(student.getId(), checkBox);
                    listContainer.getChildren().add(checkBox);
                });

        ScrollPane scrollPane = new ScrollPane(listContainer);
        scrollPane.setFitToWidth(true);
        scrollPane.setPrefViewportHeight(320);
        dialog.getDialogPane().setContent(scrollPane);

        Optional<ButtonType> result = dialog.showAndWait();
        if (result.isPresent() && result.get().getButtonData() == ButtonBar.ButtonData.OK_DONE) {
            for (Map.Entry<String, CheckBox> entry : checkBoxes.entrySet()) {
                String studentId = entry.getKey();
                boolean isPresent = entry.getValue().isSelected();
                upsertAttendance(selectedDate, studentId, subject, isPresent);
            }
            deduplicateAttendance();
            saveAttendanceToCsv();
            showInfo("Saved", "Attendance updated successfully.");
        }
    }

    private void upsertAttendance(LocalDate date, String studentId, String subject, boolean isPresent) {
        AttendanceRecord existing = findAttendance(date, studentId, subject);
        if (existing != null) {
            existing.setPresent(isPresent);
            return;
        }

        Student student = students.get(studentId);
        if (student == null) {
            return;
        }

        attendanceRecords.add(new AttendanceRecord(
                date,
                date.getDayOfWeek().name(),
                student.getName(),
                studentId,
                subject,
                isPresent
        ));
    }

    private AttendanceRecord findAttendance(LocalDate date, String studentId, String subject) {
        for (AttendanceRecord record : attendanceRecords) {
            if (record.getDate().equals(date)
                    && record.getId().equals(studentId)
                    && record.getSubject().equalsIgnoreCase(subject)) {
                return record;
            }
        }
        return null;
    }

    private void displayAttendanceForDate() {
        LocalDate selectedDate = datePicker.getValue();
        if (selectedDate == null) {
            showError("Validation Error", "Please select a date.");
            return;
        }

        StringBuilder builder = new StringBuilder();
        builder.append("Attendance for ").append(selectedDate.format(DISPLAY_DATE_FORMAT)).append(":\n\n");

        boolean found = false;
        for (AttendanceRecord record : attendanceRecords) {
            if (record.getDate().equals(selectedDate)) {
                found = true;
                builder.append("Name: ").append(record.getName())
                        .append(" | ID: ").append(record.getId())
                        .append(" | Subject: ").append(record.getSubject())
                        .append(" | Status: ").append(record.isPresent() ? "Present" : "Absent")
                        .append("\n");
            }
        }

        if (!found) {
            builder.append("No attendance found for this date.");
        }

        outputArea.setText(builder.toString());
    }

    private void promptAndDisplayStudentDetails() {
        TextInputDialog dialog = new TextInputDialog();
        dialog.setTitle("Student Details");
        dialog.setHeaderText("Find Student by ID");
        dialog.setContentText("Enter Student ID:");

        Optional<String> result = dialog.showAndWait();
        result.ifPresent(id -> {
            String normalizedId = normalize(id);
            if (!students.containsKey(normalizedId)) {
                showError("Not Found", "Student not found for ID: " + normalizedId);
                return;
            }
            displayStudentDetails(normalizedId);
        });
    }

    private void displayStudentDetails(String studentId) {
        Student student = students.get(studentId);
        if (student == null) {
            showError("Not Found", "Student not found for ID: " + studentId);
            return;
        }

        StringBuilder builder = new StringBuilder();
        builder.append("Student Details\n")
                .append("ID: ").append(student.getId()).append("\n")
                .append("Name: ").append(student.getName()).append("\n\n")
                .append("Attendance History:\n");

        boolean found = false;
        for (AttendanceRecord record : attendanceRecords) {
            if (record.getId().equals(studentId)) {
                found = true;
                builder.append(record.getDate().format(DISPLAY_DATE_FORMAT))
                        .append(" | ")
                        .append(record.getSubject())
                        .append(" | ")
                        .append(record.isPresent() ? "Present" : "Absent")
                        .append("\n");
            }
        }

        if (!found) {
            builder.append("No attendance records available for this student.");
        }

        outputArea.setText(builder.toString());
    }

    private void displaySubjectAttendance() {
        String subject = subjectComboBox.getValue();
        if (subject == null || subject.isBlank()) {
            showError("Validation Error", "Please select a subject.");
            return;
        }

        StringBuilder builder = new StringBuilder();
        builder.append("Attendance for Subject: ").append(subject).append("\n\n");

        boolean found = false;
        for (AttendanceRecord record : attendanceRecords) {
            if (record.getSubject().equalsIgnoreCase(subject)) {
                found = true;
                builder.append(record.getDate().format(DISPLAY_DATE_FORMAT))
                        .append(" | ")
                        .append(record.getName())
                        .append(" (").append(record.getId()).append(")")
                        .append(" | ")
                        .append(record.isPresent() ? "Present" : "Absent")
                        .append("\n");
            }
        }

        if (!found) {
            builder.append("No attendance records found for this subject.");
        }

        outputArea.setText(builder.toString());
    }

    private void loadStudentsFromCsv() {
        if (!Files.exists(STUDENTS_FILE)) {
            return;
        }

        try (BufferedReader reader = Files.newBufferedReader(STUDENTS_FILE)) {
            String line;
            while ((line = reader.readLine()) != null) {
                if (line.isBlank()) {
                    continue;
                }
                String[] parts = line.split(",", 2);
                if (parts.length < 2) {
                    continue;
                }
                String id = normalize(parts[0]);
                String name = normalize(parts[1]);
                if (!id.isBlank() && !name.isBlank()) {
                    students.put(id, new Student(name, id));
                }
            }
        } catch (IOException exception) {
            showError("Load Error", "Unable to read students file: " + exception.getMessage());
        }
    }

    private void loadAttendanceFromCsv() {
        if (!Files.exists(ATTENDANCE_FILE)) {
            return;
        }

        try (BufferedReader reader = Files.newBufferedReader(ATTENDANCE_FILE)) {
            String line;
            while ((line = reader.readLine()) != null) {
                if (line.isBlank()) {
                    continue;
                }

                String[] parts = line.split(",", -1);
                if (parts.length != 6) {
                    continue;
                }

                LocalDate date = LocalDate.parse(parts[0], STORAGE_DATE_FORMAT);
                attendanceRecords.add(new AttendanceRecord(
                        date,
                        parts[1],
                        parts[2],
                        parts[3],
                        parts[4],
                        Boolean.parseBoolean(parts[5])
                ));
            }
        } catch (IOException exception) {
            showError("Load Error", "Unable to read attendance file: " + exception.getMessage());
        }
    }

    private void saveStudentsToCsv() {
        try (BufferedWriter writer = Files.newBufferedWriter(STUDENTS_FILE)) {
            for (Student student : students.values()) {
                writer.write(student.getId() + "," + student.getName());
                writer.newLine();
            }
        } catch (IOException exception) {
            showError("Save Error", "Unable to save students: " + exception.getMessage());
        }
    }

    private void saveAttendanceToCsv() {
        attendanceRecords.sort(Comparator
                .comparing(AttendanceRecord::getDate)
                .thenComparing(AttendanceRecord::getSubject, String.CASE_INSENSITIVE_ORDER)
                .thenComparing(AttendanceRecord::getName, String.CASE_INSENSITIVE_ORDER));

        try (BufferedWriter writer = Files.newBufferedWriter(ATTENDANCE_FILE)) {
            for (AttendanceRecord record : attendanceRecords) {
                writer.write(String.join(",",
                        record.getDate().format(STORAGE_DATE_FORMAT),
                        record.getDay(),
                        record.getName(),
                        record.getId(),
                        record.getSubject(),
                        String.valueOf(record.isPresent())
                ));
                writer.newLine();
            }
        } catch (IOException exception) {
            showError("Save Error", "Unable to save attendance: " + exception.getMessage());
        }
    }

    private void deduplicateAttendance() {
        Map<String, AttendanceRecord> latestByKey = new LinkedHashMap<>();
        for (AttendanceRecord record : attendanceRecords) {
            latestByKey.put(record.compositeKey(), record);
        }
        attendanceRecords.clear();
        attendanceRecords.addAll(latestByKey.values());
    }

    private void showInfo(String title, String message) {
        Alert alert = new Alert(Alert.AlertType.INFORMATION);
        alert.setTitle(title);
        alert.setHeaderText(null);
        alert.setContentText(message);
        alert.showAndWait();
    }

    private void showError(String title, String message) {
        Alert alert = new Alert(Alert.AlertType.ERROR);
        alert.setTitle(title);
        alert.setHeaderText(null);
        alert.setContentText(message);
        alert.showAndWait();
    }

    private String normalize(String value) {
        return value == null ? "" : value.trim();
    }

    public static void main(String[] args) {
        launch(args);
    }
}

class Student {
    private final String name;
    private final String id;

    Student(String name, String id) {
        this.name = name;
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public String getId() {
        return id;
    }
}

class AttendanceRecord {
    private final LocalDate date;
    private final String day;
    private final String name;
    private final String id;
    private final String subject;
    private boolean present;

    AttendanceRecord(LocalDate date, String day, String name, String id, String subject, boolean present) {
        this.date = date;
        this.day = day;
        this.name = name;
        this.id = id;
        this.subject = subject;
        this.present = present;
    }

    public LocalDate getDate() {
        return date;
    }

    public String getDay() {
        return day;
    }

    public String getName() {
        return name;
    }

    public String getId() {
        return id;
    }

    public String getSubject() {
        return subject;
    }

    public boolean isPresent() {
        return present;
    }

    public void setPresent(boolean present) {
        this.present = present;
    }

    public String compositeKey() {
        return date + "|" + id + "|" + subject.toLowerCase();
    }
}