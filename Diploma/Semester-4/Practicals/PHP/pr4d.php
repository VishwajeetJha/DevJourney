<?php
    $nm = $_POST["n"];
    echo "Table of $nm";
    for($i=1;$i<=10;$i++){
        echo "<br>$nm x $i = ". ($nm * $i);
    }
?>