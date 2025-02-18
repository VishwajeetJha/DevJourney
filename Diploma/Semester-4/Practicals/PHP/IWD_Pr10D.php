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
    $password = $_POST['password'];
    $login_query = "SELECT * FROM EmpDetails WHERE EmpID = '$employee_id' AND EPassword = '$password'";
    $login_result = $conn->query($login_query);
    if ($login_result->num_rows == 1) {
        $employee_query = "SELECT * FROM empdetails WHERE EmpID = '$employee_id'";
        $employee_result = $conn->query($employee_query);
        if ($employee_result->num_rows == 1) {
            $employee_data = $employee_result->fetch_assoc();
            echo "<h2>Welcome " . $employee_data['FirstName'] . " " . $employee_data['LastName'] . "</h2>";
            echo "<p>Employee ID: " . $employee_data['EmpID'] . "</p>";
            echo "<p>Phone Number: " . $employee_data['PhoneNumber'] . "</p>";
            echo "<p>Email: " . $employee_data['MailID'] . "</p>";
            echo "<p>Gender: " . $employee_data['Gender'] . "</p>";
            echo "<p>Age: " . $employee_data['Age'] . "</p>";
            echo "<p>Salary: " . $employee_data['Salary'] . " $ </p>";
            echo "<p>Date of Birth: " . $employee_data['DateOfBirth'] . " </p>";
        } else {
            echo "Error: Employee details not found";
        }
    } else {
        echo "Error: Invalid Employee ID or password";
    }
}
$conn->close();
?>