import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.*;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.HashMap;

class AttendanceRecord {
    private LocalDate date;
    private String day;
    private String name;
    private String id;
    private String subject;
    private boolean present;

    public AttendanceRecord(LocalDate date, String day, String name, String id, String subject, boolean present) {
        this.date = date;
        this.day = day;
        this.name = name;
        this.id = id;
        this.subject = subject;
        this.present = present;
    }

    // Getters
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

    // Setters
    public void setDate(LocalDate date) {
        this.date = date;
    }

    public void setDay(String day) {
        this.day = day;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setId(String id) {
        this.id = id;
    }

    public void setSubject(String subject) {
        this.subject = subject;
    }

    public void setPresent(boolean present) {
        this.present = present;
    }
}

class MCP {
    private JFrame frame;
    private JPanel panel;
    private JTextField nameField, idField;
    private JTextArea displayArea;
    private JButton addStudentButton, markAttendanceButton, viewAttendanceButton, markAbsentButton, studentDetailsButton, subjectAttendanceButton;
    private JSpinner dateSpinner;
    private JComboBox<String> subjectComboBox; // Added JComboBox for subject selection
    private HashMap<String, Person> persons;
    private ArrayList<AttendanceRecord> attendanceRecords;
    private HashMap<String, Integer> subjectTimetable;

    private final String CSV_FILE_NAME = "attendance_data.csv";

    public MCP() {
        frame = new JFrame("MCP - Attendance Management System");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(1200, 600);
        frame.setLocationRelativeTo(null);

        panel = new JPanel();
        panel.setLayout(new BorderLayout());

        JPanel inputPanel = new JPanel();
        inputPanel.setLayout(new GridLayout(3, 2));

        JLabel nameLabel = new JLabel("Name:");
        nameField = new JTextField();
        JLabel idLabel = new JLabel("ID:");
        idField = new JTextField();
        JLabel subjectLabel = new JLabel("Subject:");
        subjectComboBox = new JComboBox<>();

        // Populate subjectComboBox with sample subjects
        subjectComboBox.addItem("Mathematics");
        subjectComboBox.addItem("Physics");
        subjectComboBox.addItem("Chemistry");

        inputPanel.add(nameLabel);
        inputPanel.add(nameField);
        inputPanel.add(idLabel);
        inputPanel.add(idField);
        inputPanel.add(subjectLabel);
        inputPanel.add(subjectComboBox);

        JPanel buttonPanel = new JPanel();
        addStudentButton = new JButton("Add Student");
        markAttendanceButton = new JButton("Mark Attendance");
        markAbsentButton = new JButton("Mark Absent");
        viewAttendanceButton = new JButton("View Attendance");
        studentDetailsButton = new JButton("Show Student Details");
        subjectAttendanceButton = new JButton("Show Subject Attendance");
        buttonPanel.add(addStudentButton);
        buttonPanel.add(markAttendanceButton);
        buttonPanel.add(markAbsentButton);
        buttonPanel.add(viewAttendanceButton);
        buttonPanel.add(studentDetailsButton);
        buttonPanel.add(subjectAttendanceButton);

        JPanel datePanel = new JPanel();
        JLabel dateLabel = new JLabel("Select Date:");
        dateSpinner = new JSpinner(new SpinnerDateModel());
        JSpinner.DateEditor dateEditor = new JSpinner.DateEditor(dateSpinner, "yyyy-MM-dd");
        dateSpinner.setEditor(dateEditor);
        datePanel.add(dateLabel);
        datePanel.add(dateSpinner);

        panel.add(inputPanel, BorderLayout.NORTH);
        panel.add(buttonPanel, BorderLayout.CENTER);
        panel.add(datePanel, BorderLayout.SOUTH);

        displayArea = new JTextArea(10, 30);
        displayArea.setEditable(false);
        JScrollPane scrollPane = new JScrollPane(displayArea);
        panel.add(scrollPane, BorderLayout.EAST);

        frame.getContentPane().add(panel);
        frame.setVisible(true);

        persons = new HashMap<>();
        attendanceRecords = new ArrayList<>();
        subjectTimetable = new HashMap<>();

        // Initialize subject timetable
        initializeSubjectTimetable();

        loadFromCSV();

        loadStudentsFromCSV();

        addStudentButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                String name = nameField.getText();
                String id = idField.getText();
                if (!name.isEmpty() && !id.isEmpty()) {
                    if (!persons.containsKey(id)) {
                        Student student = new Student(name, id);
                        persons.put(id, student);
                        nameField.setText("");
                        idField.setText("");
                        saveStudentsToCSV();
                        JOptionPane.showMessageDialog(frame, "Student added successfully!");
                    } else {
                        JOptionPane.showMessageDialog(frame, "Student with this ID already exists!");
                    }
                } else {
                    JOptionPane.showMessageDialog(frame, "Please enter valid name and ID!");
                }
            }
        });

        markAttendanceButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                LocalDate selectedDate = ((SpinnerDateModel) dateSpinner.getModel()).getDate().toInstant().atZone(java.time.ZoneId.systemDefault()).toLocalDate();
                String id = JOptionPane.showInputDialog(frame, "Enter student ID:");
                if (persons.containsKey(id)) {
                    markAttendance(selectedDate, id);
                    saveToCSV();
                    JOptionPane.showMessageDialog(frame, "Attendance marked for student with ID: " + id);
                } else {
                    JOptionPane.showMessageDialog(frame, "Student not found!");
                }
            }
        });

        markAbsentButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                LocalDate selectedDate = ((SpinnerDateModel) dateSpinner.getModel()).getDate().toInstant().atZone(java.time.ZoneId.systemDefault()).toLocalDate();
                String id = JOptionPane.showInputDialog(frame, "Enter student ID:");
                if (persons.containsKey(id)) {
                    markAbsent(selectedDate, id);
                    saveToCSV();
                    JOptionPane.showMessageDialog(frame, "Marked student as absent with ID: " + id);
                } else {
                    JOptionPane.showMessageDialog(frame, "Student not found!");
                }
            }
        });

        viewAttendanceButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                LocalDate selectedDate = ((SpinnerDateModel) dateSpinner.getModel()).getDate().toInstant().atZone(java.time.ZoneId.systemDefault()).toLocalDate();
                displayAttendance(selectedDate);
            }
        });

        studentDetailsButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                String id = JOptionPane.showInputDialog(frame, "Enter student ID:");
                if (persons.containsKey(id)) {
                    displayStudentDetails(id);
                } else {
                    JOptionPane.showMessageDialog(frame, "Student not found!");
                }
            }
        });

        subjectAttendanceButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                String subject = (String) subjectComboBox.getSelectedItem();
                displaySubjectAttendance(subject);
            }
        });
    }

    private void loadFromCSV() {
        // Read data from CSV file and populate attendanceRecords
        try (BufferedReader reader = new BufferedReader(new FileReader(CSV_FILE_NAME))) {
            String line;
            while ((line = reader.readLine()) != null) {
                String[] parts = line.split(",");
                // Parse each part and create AttendanceRecord object
                LocalDate date = LocalDate.parse(parts[0], DateTimeFormatter.ofPattern("yyyy-MM-dd"));
                String day = parts[1];
                String name = parts[2];
                String id = parts[3];
                String subject = parts[4];
                boolean present = Boolean.parseBoolean(parts[5]);
                AttendanceRecord record = new AttendanceRecord(date, day, name, id, subject, present);
                // Add record to attendanceRecords
                attendanceRecords.add(record);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private void loadStudentsFromCSV() {
        try (BufferedReader reader = new BufferedReader(new FileReader("students.csv"))) {
            String line;
            while ((line = reader.readLine()) != null) {
                String[] parts = line.split(",");
                String id = parts[0];
                String name = parts[1];
                // Create a new Student object and add it to the persons HashMap
                persons.put(id, new Student(name, id));
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    

    private void saveToCSV() {
        // Write data to CSV file
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(CSV_FILE_NAME))) {
            for (AttendanceRecord record : attendanceRecords) {
                // Format record fields into a CSV line
                String line = String.format("%s,%s,%s,%s,%s,%b%n",
                                             record.getDate().format(DateTimeFormatter.ofPattern("yyyy-MM-dd")),
                                             record.getDay(), record.getName(), record.getId(),
                                             record.getSubject(), record.isPresent());
                // Write line to CSV file
                writer.write(line);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private void saveStudentsToCSV() {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter("students.csv"))) {
            for (Person person : persons.values()) {
                String line = person.getId() + "," + person.getName() + "\n";
                writer.write(line);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private void initializeSubjectTimetable() {
        // Subject timetable initialization
        subjectTimetable.put("Monday", 0);
        subjectTimetable.put("Tuesday", 1);
        subjectTimetable.put("Wednesday", 2);
        subjectTimetable.put("Thursday", 3);
        subjectTimetable.put("Friday", 4);
    }

    private void markAttendance(LocalDate date, String id) {
        // Find the student by ID and mark attendance for the given date
        for (AttendanceRecord record : attendanceRecords) {
            if (record.getId().equals(id) && record.getDate().equals(date)) {
                record.setPresent(true);
                return;
            }
        }
        // If the record doesn't exist, create a new one and mark attendance
        String day = date.getDayOfWeek().name();
        Person student = persons.get(id);
        if (student != null) {
            AttendanceRecord newRecord = new AttendanceRecord(date, day, student.getName(), id, "", true);
            attendanceRecords.add(newRecord);
        }
    }

    private void markAbsent(LocalDate date, String id) {
        // Find the student by ID and mark absent for the given date
        for (AttendanceRecord record : attendanceRecords) {
            if (record.getId().equals(id) && record.getDate().equals(date)) {
                record.setPresent(false);
                return;
            }
        }
        // If the record doesn't exist, create a new one and mark absent
        String day = date.getDayOfWeek().name();
        Person student = persons.get(id);
        if (student != null) {
            AttendanceRecord newRecord = new AttendanceRecord(date, day, student.getName(), id, "", false);
            attendanceRecords.add(newRecord);
        }
    }

    private void displayAttendance(LocalDate date) {
        // Display attendance for the given date
        StringBuilder sb = new StringBuilder();
        sb.append("Attendance for ").append(date.format(DateTimeFormatter.ofPattern("yyyy-MM-dd"))).append(":\n");
        boolean found = false;
        for (AttendanceRecord record : attendanceRecords) {
            if (record.getDate().equals(date)) {
                found = true;
                sb.append("Name: ").append(record.getName()).append(", ");
                sb.append("Subject: ").append(record.getSubject()).append(", ");
                sb.append("Status: ").append(record.isPresent() ? "Present" : "Absent").append("\n");
            }
        }
        if (!found) {
            sb.append("No attendance recorded for ").append(date.format(DateTimeFormatter.ofPattern("yyyy-MM-dd")));
        }
        displayArea.setText(sb.toString());
    }

    private void displayStudentDetails(String id) {
        // Display details for the given student ID
        StringBuilder sb = new StringBuilder();
        Person student = persons.get(id);
        sb.append("Student Details for ID: ").append(id).append("\n");
        sb.append("Name: ").append(student.getName()).append("\n");
        sb.append("Subject-wise Attendance:\n");
        for (AttendanceRecord record : attendanceRecords) {
            if (record.getId().equals(id)) {
                sb.append("Date: ").append(record.getDate().format(DateTimeFormatter.ofPattern("yyyy-MM-dd"))).append(", ");
                sb.append("Subject: ").append(record.getSubject()).append(", ");
                sb.append("Status: ").append(record.isPresent() ? "Present" : "Absent").append("\n");
            }
        }
        displayArea.setText(sb.toString());
    }

    private void displaySubjectAttendance(String subject) {
        // Display attendance for the given subject
        StringBuilder sb = new StringBuilder();
        sb.append("Attendance Details for Subject: ").append(subject).append("\n");
        boolean found = false;
        for (AttendanceRecord record : attendanceRecords) {
            if (record.getSubject().equals(subject)) {
                found = true;
                sb.append("Date: ").append(record.getDate().format(DateTimeFormatter.ofPattern("yyyy-MM-dd"))).append(", ");
                sb.append("Name: ").append(record.getName()).append(", ");
                sb.append("Status: ").append(record.isPresent() ? "Present" : "Absent").append("\n");
            }
        }
        if (!found) {
            sb.append("No attendance recorded for ").append(subject);
        }
        displayArea.setText(sb.toString());
    }
    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            public void run() {
                new MCP();
            }
        });
    }
}

class Person implements Serializable {
    protected String name;
    protected String id;

    public Person(String name, String id) {
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

class Student extends Person {
    public Student(String name, String id) {
        super(name, id);
    }
}
