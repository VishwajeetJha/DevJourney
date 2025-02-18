<?php
    function fact($a){
        $b = 1;
        if($a == 0){
            return 0;
        }
        else{
            for($i=1;$i<$a+1;$i++){
                $b *= $i;
            }
            return $b;
        }
    }
    
    $ch = $_POST["ch"];
    $var_a = $_POST["var_a"];
    
    if($ch == 'PosNegZero'){
        if($var_a > 0){
            echo $var_a." is a positive number";
        }
        else if($var_a < 0){
            echo $var_a." is a negative number";
        }
        else{
            echo $var_a." is a zero";
        }
    }
    else if($ch == 'Factorial'){
        echo "Factorial of $var_a is: ".fact($var_a);
    }
    else if($ch == 'Reverse'){
        $temp = $var_a;
        $rev = 0;       
        while($temp > 0){
            $rem = $temp % 10;
            $rev = ($rev*10) + $rem;
            $temp = (int)($temp/10);
        }
        echo "Reverse is: $rev";
    }

    
?>