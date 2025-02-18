<?php
    $st1 = true;
    $st2 = false;

    $sc1 = $st1 && $st2?"True":"False";
    $sc2 = $st1 || $st2?"True":"False";
    $sc3 = $st1 && !$st2?"True":"False";

    echo "Scenario 1: ".$sc1."\n"."Scenario 2: ".$sc2."\n"."Scenario 3: ".$sc3."\n";
?>