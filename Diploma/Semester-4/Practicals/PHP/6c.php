<?php
    $r1 = $_POST["r1"];
    $r2 = $_POST["r2"];
    $dec = $_POST["dec"];
    $angle = $_POST["angle"];

    //A
    echo "Random Integer between $r1 and $r2: ".rand($r1,$r2)."<br>";

    //B
    echo "Binary of $dec: ".decbin($dec)."<br>";
    echo "Octal of $dec: ".decoct($dec)."<br>";
    echo "Hexadecimal of $dec: ".dechex($dec)."<br>";

    //C
    echo "Sin of angle $angle: ".sin(($angle*(pi()/180)))."<br>";
    echo "Cos of angle $angle: ".cos(($angle*(pi()/180)))."<br>";
    echo "Tan of angle $angle: ".tan(($angle*(pi()/180)))."<br>";

?>