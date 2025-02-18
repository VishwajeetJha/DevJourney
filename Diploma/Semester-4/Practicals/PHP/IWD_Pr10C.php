<?php
echo "Image Uploaded Successfully!";
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "iwdpr10";
$conn = new mysqli($servername, $username, $password, $dbname);
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $image_name = $_FILES['image']['name'];
    $image_size = $_FILES['image']['size'];
    $image_type = $_FILES['image']['type'];
    $image_tmp = $_FILES['image']['tmp_name'];
    
    $sql = "INSERT INTO imagedetails (ImageName, Imagesize, Imagetype, Imagepath)
            VALUES ('$image_name', '$image_size', '$image_type', '$image_tmp')";
    if ($conn->query($sql) === TRUE) {
        echo "<br>New record created successfully";
    } else {
        echo "Error: " . $sql . "<br>" . $conn->error;
    }
}
$conn->close();
?>