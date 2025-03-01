/**
 * MICRO PROJECT
 * Topic: Student Attendance Management System
 * Definition: This System will be used as a replacement to traditional systems that maintain attendance with something more digital and
 *              straightforward. Traditional hard  copy attendance records are prone to errors and lead to mistakes such a problematic attendance
 *              counts.
 * Semester: 4
 *
 * Initial Features:-
 * 1. Student Registration
 * 2. Attendance Recording
 * 3. Attendance Viewing
 *
 * Initial Requisites:-
 * 1. Swing
 * 2. JDBC
 * 3. File Management, not Database since it'll be harder to implement
 * 
 * To-Do:-
 * 1. Date format change to DD-MM-YYYY
 * 2. 
 *
 * 
 * Work Started at 12:34 PM IST on 09-03-2024
 *
 * PLEASE NOTE ALL DATES AND TIMES ARE IN: DD-MM-YY HH-MM AM in IST.
 *
 */


 import javax.swing.*;
 import java.awt.*;
 import java.awt.event.ActionEvent;
 import java.awt.event.ActionListener;
 import java.io.*;
 import java.time.LocalDate;
 import java.time.ZoneId;
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
     private JButton addStudentButton, markAttendanceButton, viewAttendanceButton, studentDetailsButton, subjectAttendanceButton;
     private JSpinner dateSpinner;
     private JComboBox<String> subjectComboBox;
     private HashMap<String, Person> persons;
     private ArrayList<AttendanceRecord> attendanceRecords;
 
     private final String CSV_FILE_NAME = "attendance_data.csv";
 
     public MCP() {
         frame = new JFrame("MCP - Attendance Management System");
         frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
         frame.setSize(800, 600);
         frame.setLocationRelativeTo(null);
 
         panel = new JPanel();
         panel.setLayout(new BoxLayout(panel, BoxLayout.Y_AXIS));
 
         JPanel inputPanel = new JPanel();
         inputPanel.setLayout(new GridLayout(4, 2, 4, 4));
         inputPanel.setBackground(Color.YELLOW);
 
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
         buttonPanel.setBackground(Color.YELLOW);
         buttonPanel.setLayout(new GridLayout(4, 2, 4, 4));
 
         addStudentButton = new JButton("Add Student");
         addStudentButton.setPreferredSize(new Dimension(150, addStudentButton.getPreferredSize().height));
         addStudentButton.setForeground(Color.WHITE);
         addStudentButton.setBackground(Color.BLACK);
 
         markAttendanceButton = new JButton("Mark Attendance");
         markAttendanceButton.setForeground(Color.WHITE);
         markAttendanceButton.setBackground(Color.BLACK);
 
         viewAttendanceButton = new JButton("View Attendance");
         viewAttendanceButton.setForeground(Color.WHITE);
         viewAttendanceButton.setBackground(Color.BLACK);
 
         studentDetailsButton = new JButton("Show Student Details");
         studentDetailsButton.setForeground(Color.WHITE);
         studentDetailsButton.setBackground(Color.BLACK);
 
         subjectAttendanceButton = new JButton("Show Subject Attendance");
         subjectAttendanceButton.setForeground(Color.WHITE);
         subjectAttendanceButton.setBackground(Color.BLACK);
 
         buttonPanel.add(addStudentButton);
         buttonPanel.add(markAttendanceButton);
         buttonPanel.add(viewAttendanceButton);
         buttonPanel.add(studentDetailsButton);
         buttonPanel.add(subjectAttendanceButton);
 
         JPanel datePanel = new JPanel();
         JLabel dateLabel = new JLabel("Select Date:");
         dateSpinner = new JSpinner(new SpinnerDateModel());
         dateSpinner.setForeground(Color.WHITE);
         dateSpinner.setBackground(Color.BLACK);
         JSpinner.DateEditor dateEditor = new JSpinner.DateEditor(dateSpinner, "yyyy-MM-dd");
         dateSpinner.setEditor(dateEditor);
         datePanel.add(dateLabel);
         datePanel.add(dateSpinner);
 
         JPanel displayPanel = new JPanel();
         displayPanel.setBackground(Color.YELLOW);
         displayArea = new JTextArea(40, 60);
         displayArea.setEditable(false);
         JScrollPane scrollPane = new JScrollPane(displayArea);
         displayPanel.add(scrollPane);
 
         panel.add(inputPanel, BorderLayout.NORTH);
         panel.add(buttonPanel);
         panel.add(displayPanel);
         panel.add(datePanel, BorderLayout.SOUTH);
 
         frame.getContentPane().add(panel);
         frame.setVisible(true);
 
         persons = new HashMap<>();
         attendanceRecords = new ArrayList<>();
 
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
                 LocalDate selectedDate = ((SpinnerDateModel) dateSpinner.getModel()).getDate().toInstant().atZone(ZoneId.systemDefault()).toLocalDate();
                 String subject = (String) subjectComboBox.getSelectedItem();
                 markAttendance(selectedDate, subject);
             }
         });
 
         viewAttendanceButton.addActionListener(new ActionListener() {
             public void actionPerformed(ActionEvent e) {
                 LocalDate selectedDate = ((SpinnerDateModel) dateSpinner.getModel()).getDate().toInstant().atZone(ZoneId.systemDefault()).toLocalDate();
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
         try (BufferedReader reader = new BufferedReader(new FileReader(CSV_FILE_NAME))) {
             String line;
             while ((line = reader.readLine()) != null) {
                 if (line.trim().isEmpty()) {
                     continue;
                 }
                 String[] parts = line.split(",");
                 if (parts.length == 6) {
                     LocalDate date = LocalDate.parse(parts[0], DateTimeFormatter.ofPattern("yyyy-MM-dd"));
                     String day = parts[1];
                     String name = parts[2];
                     String id = parts[3];
                     String subject = parts[4];
                     boolean present = Boolean.parseBoolean(parts[5]);
                     AttendanceRecord record = new AttendanceRecord(date, day, name, id, subject, present);
                     attendanceRecords.add(record);
                 } else {
                     System.err.println("Invalid Data Format: " + line);
                 }
             }
         } catch (IOException e) {
             e.printStackTrace();
         }
     }
 
     private void loadStudentsFromCSV() {
         try (BufferedReader reader = new BufferedReader(new FileReader("students.csv"))) {
             String line;
             while ((line = reader.readLine()) != null) {
                 if (line.trim().isEmpty()) {
                     continue;
                 }
                 String[] parts = line.split(",");
                 String id = parts[0];
                 String name = parts[1];
                 persons.put(id, new Student(name, id));
             }
         } catch (IOException e) {
             e.printStackTrace();
         }
     }
 
     private void saveToCSV() {
         try (BufferedWriter writer = new BufferedWriter(new FileWriter(CSV_FILE_NAME, true))) {
             for (AttendanceRecord record : attendanceRecords) {
                 File file = new File(CSV_FILE_NAME);
                 if (!file.exists()) {
                     file.createNewFile();
                 }
                 String line = String.format("%s,%s,%s,%s,%s,%b%n",
                         record.getDate().format(DateTimeFormatter.ofPattern("yyyy-MM-dd")),
                         record.getDay(), record.getName(), record.getId(),
                         record.getSubject(), record.isPresent());
                 writer.write(line);
             }
         } catch (IOException e) {
             e.printStackTrace();
         }
     }
 
     private void saveStudentsToCSV() {
         try (BufferedWriter writer = new BufferedWriter(new FileWriter("students.csv"))) {
             File file = new File(CSV_FILE_NAME);
             if (!file.exists()) {
                 file.createNewFile();
             }
             for (Person person : persons.values()) {
                 String line = person.getId() + "," + person.getName() + "\n";
                 writer.write(line);
             }
         } catch (IOException e) {
             e.printStackTrace();
         }
     }
 
     private void markAttendance(LocalDate date, String subject) {
         JPanel checkboxPanel = new JPanel();
         checkboxPanel.setLayout(new BoxLayout(checkboxPanel, BoxLayout.Y_AXIS));
 
         HashMap<String, JCheckBox> checkboxes = new HashMap<>();
         for (String id : persons.keySet()) {
             JCheckBox checkbox = new JCheckBox(persons.get(id).getName());
             checkboxes.put(id, checkbox);
             checkboxPanel.add(checkbox);
         }
 
         int result = JOptionPane.showConfirmDialog(frame, new JScrollPane(checkboxPanel), "Mark Attendance", JOptionPane.OK_CANCEL_OPTION);
         if (result == JOptionPane.OK_OPTION) {
             for (String id : checkboxes.keySet()) {
                 markAttendanceForStudent(date, id, subject, checkboxes.get(id).isSelected());
             }
             saveToCSV();
             JOptionPane.showMessageDialog(frame, "Attendance marked for the selected date and subject.");
         }
     }
 
     private void markAttendanceForStudent(LocalDate date, String id, String subject, boolean isPresent) {
         for (AttendanceRecord record : attendanceRecords) {
             if (record.getId().equals(id) && record.getDate().equals(date) && record.getSubject().equals(subject)) {
                 record.setPresent(isPresent);
                 return;
             }
         }
         String day = date.getDayOfWeek().name();
         Person student = persons.get(id);
         if (student != null) {
             AttendanceRecord newRecord = new AttendanceRecord(date, day, student.getName(), id, subject, isPresent);
             attendanceRecords.add(newRecord);
         }
     }
 
     private void displayAttendance(LocalDate date) {
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