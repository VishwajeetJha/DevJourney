<?php
    if($_POST["n"]<0){
        echo "Can't print Fibonacci series in negative range!";
    }
    else{
        $a = 0;
        $b = 1;
        $c = 0;
        echo "$a ";
        for($i=0;$i<($_POST["n"]-1);$i+=1){
            $a = $b;
            $b = $c;
            $c = $a + $b;
            echo " $c";
       }
    }

?>