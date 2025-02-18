<html>
    <body bgcolor="linen">
        <?php
    $str = $_POST["str"];

    echo "Your string: $str<br><br>";

    //A
    if(strtolower($str) == $str){
        echo "String is lowercase<br>";
    }
    else{
        echo "String is not lowercase<br>";
    }

    //B
    echo "String: $str in reverse: ".strrev($str)."<br>";

    //C
    echo "String: $str without whitespaces: ".str_replace(' ','',$str)."<br>";
    
    //D
    echo "<br>New string: ".str_replace("v","V",$str);
?>
    </body>
</html>