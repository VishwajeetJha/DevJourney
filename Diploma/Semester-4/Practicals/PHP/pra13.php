<?php
    $om = 20;
    $jagdish = 23;
    $jai = 21;

    if($om > $jai){
        if($om > $jagdish){
            echo "$om is the oldest and will pay!\n";
        }
        else{
            echo "$jagdish is the oldest and will pay!\n";
        }
    }
    else{
        if($jai > $jagdish){
            echo "$jai is the oldest and will pay!\n";
        }
        else{
            echo "$jagdish is the oldest and will pay!\n";
        }
    }
?>