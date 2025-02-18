<?php
    $arr = array(4,1,5,7,2,8,9);
    $i = 0;

    echo "Unsorted: ";
    for ($i = 0; $i < 7; $i++){
        echo "$arr[$i] ";
    }

    for($i=0;$i<7;$i++){
        for($j=$i+1;$j<7;$j++){
            if($arr[$i] > $arr[$j]){
                $temp = $arr[$i];
                $arr[$i] = $arr[$j];
                $arr[$j] = $temp;
            }
        }
    }

    echo "<br>Sorted:";
    for ($i = 0; $i <7; $i++){
        echo "$arr[$i] ";
    }
?>