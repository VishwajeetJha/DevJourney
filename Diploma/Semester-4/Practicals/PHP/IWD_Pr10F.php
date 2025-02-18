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
    $empID = $_POST['empID'];
    $newPassword = $_POST['newPassword'];
    $updatePassword = "UPDATE empdetails SET EPassword = '$newPassword' WHERE EmpID = '$empID'";
    if ($conn->query($updatePassword) === TRUE) {
        echo "Password updated successfully.";
    } else {
        echo "Error updating password: " . $conn->error;
    }
}
$conn->close();
?>