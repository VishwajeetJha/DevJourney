<?php
    if($_POST["name"] == ''){
        echo "You've left the name field blank, please input<br>";
    }
    else if($_POST["mob"] == ''){
        echo "You've left the number field blank, please input<br>";
    }
    else if($_POST["email"] == ''){
        echo "You've left the email field blank, please input<br>";
    }
    else if($_POST["gender"] == ''){
        echo "You've left the gender field blank, please input<br>";
    }
    else{
        $name = $_POST["name"];
        $mob = $_POST["mobileno"];
        $email = $_POST["emailid"];
        $gender = $_POST["gender"];

        if(!preg_match("/^[a-zA-Z]*$/", $name)){
            echo "Name not entered in proper format<br>";
        }
        else if(!preg_match("/^[0-9]*$/", $mob)){
            echo "Number not entered in proper format<br>";
        }else if(!preg_match("^[_a-z0-9-]+(\.[a-z0-9]*$/)+@+[a-z^0-1]",$email)){

            echo "Name not entered in proper format<br>";
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
        echo "Email ID: $email<br>";
        echo "Gender: $gender<br>";
        echo "Did user agree to Terms and Conditions?: $userAgreeToTaC";
    }
?>