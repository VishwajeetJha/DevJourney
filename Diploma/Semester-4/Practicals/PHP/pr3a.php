<?php
    echo "Calculator"."<br><br>";
    echo 'Value of Num1: '.$_POST["n1"]."<br><br>";
    echo 'Value of Num2: '.$_POST["n2"]."<br><br>";
    echo 'Addition :'.$_POST["n1"]." + ".$_POST["n2"]." = ".$_POST["n1"] + $_POST["n2"]."<br><br>";
    echo 'Subtraction :'.$_POST["n1"]." - ".$_POST["n2"]." = ".$_POST["n1"] - $_POST["n2"]."<br><br>";
    echo 'Multiplication :'.$_POST["n1"]." * ".$_POST["n2"]." = ".$_POST["n1"] * $_POST["n2"]."<br><br>";
    if ($_POST["n2"]==0){
        echo 'Cannot Divide with 0';
    }
    else{
        echo 'Division :'.$_POST["n1"]." / ".$_POST["n2"]." = ".$_POST["n1"] / $_POST["n2"]."<br><br>";
    }
?>