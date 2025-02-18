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
    $employee_id = $_POST['EmpID'];
    $password = $_POST['Password'];
    $login_query = "SELECT * FROM EmpDetails WHERE EmpID = '$employee_id' AND EPassword = '$password'";
    $login_result = $conn->query($login_query);
    if ($login_result->num_rows == 1) {
        $employee_query = "SELECT * FROM empdetails WHERE EmpID = '$employee_id'";
        $employee_result = $conn->query($employee_query);
        $employee_data = $employee_result->fetch_assoc();
        echo "<h1>Login Successful<h1>";
        echo "<h2>Welcome " . $employee_data['FirstName'] . " " . $employee_data['LastName'] . "</h2>";
    } else {
        echo "Error: Invalid Employee ID or password";
    }
}
$conn->close();
?>