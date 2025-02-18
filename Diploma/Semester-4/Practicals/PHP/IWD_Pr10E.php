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
    $employee_id = $_POST['employee_id'];
    $sql = "DELETE FROM empdetails WHERE EmpID = $employee_id";

    if ($conn->query($sql) === TRUE) {
        echo "Employee Deleted successfully";
    } else {
        echo "Error: " . $sql . "<br>" . $conn->error;
    }
}
$conn->close();
?>