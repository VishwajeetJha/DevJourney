<?php
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "iwdpr10";
$conn = new mysqli($servername, $username, $password, $dbname);
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $empId = $_POST['empid'];
    $first_name = $_POST['first_name'];
    $last_name = $_POST['last_name'];
    $phone_number = $_POST['phone_number'];
    $email = $_POST['email'];
    $gender = $_POST['gender'];
    $age = $_POST['age'];
    $epass = $_POST['pass'];
    $salary = $_POST['salary'];
    $DOB = $_POST['DOB'];
    $sql = "INSERT INTO EmpDetails (EmpID, FirstName, LastName, PhoneNumber, MailID, Gender, Age, EPassword, Salary, DateOfBirth)
            VALUES ('$empId', '$first_name', '$last_name', '$phone_number', '$email', '$gender', '$age', '$epass','$salary', '$DOB')";

    if ($conn->query($sql) === TRUE) {
        echo "New record created successfully";
    } else {
        echo "Error: " . $sql . "<br>" . $conn->error;
    }
}
$conn->close();
?>