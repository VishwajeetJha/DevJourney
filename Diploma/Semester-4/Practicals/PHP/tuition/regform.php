<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Registration Form</title>
</head>
<body>
    <h1>Registration Form</h1>
    <form action="<?php $_PHP_SELF ?>" method="post">
        <label>Name: </label>
        <input type="text" name="name"> <br><br>
        <!-- <label>E-Mail: </label>
        <input type="email" name="emailid"> <br><br> -->
        <label>Mobile No.: </label>
        <input type="text" name="mobileno"> <br><br>
        <!-- <label>Gender: </label>
        <input type="radio" name="gender" value="male" >Male &nbsp;&nbsp;
        <input type="radio" name="gender" value="female" >Female &nbsp;&nbsp;
        <input type="radio" name="gender" value="other" >Other <br><br> -->
        <label>Agree to the Terms & Conditions: </label>
        <input type="checkbox" name="tac" value="true" ><br><br>
        <input type="submit">
    </form>
    
    <?php
    if($_POST["name"] == ''){
        echo "You've left the name field blank, please input<br>";
    }
    else if($_POST["mobileno"] == ''){
        echo "You've left the number field blank, please input<br>";
    }
    // else if($_POST["email"] == ''){
    //     echo "You've left the email field blank, please input<br>";
    // }
    // else if($_POST["gender"] == ''){
    //     echo "You've left the gender field blank, please input<br>";
    // }
    else{
        $name = $_POST["name"];
        $mob = $_POST["mobileno"];
        // $email = $_POST["emailid"];
        // $gender = $_POST["gender"];

        if(!preg_match("/^[a-zA-Z]*$/", $_POST["name"]))
        {
            echo "Name not entered in proper format<br>";
        }
        if(!preg_match("/^[0-9]*$/", $_POST["mob"]) || (strlen($_POST['mob']))<10){
            echo "Number not entered in proper format<r>";
        }
            if($_POST["tac"]== 'true'){
                $userAgreeToTaC = 'Yes';
            }
            else{
                $userAgreeToTaC = 'No';
            }
    
            echo "Information:-<br><br>";
            echo "User Name: $name<br>";
            echo "Mobile Number: $mob<br>";
            // echo "Email ID: $email<br>";
            // echo "Gender: $gender<br>";
            echo "Did user agree to Terms and Conditions?: $userAgreeToTaC";
        }
    
?>

</body>
</html>