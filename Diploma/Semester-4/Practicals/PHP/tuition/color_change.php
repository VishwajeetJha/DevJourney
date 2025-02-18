<?php
    $ch = $_POST["col"];

    switch($ch){
        case 'red':
            echo '<body style="background-color:red">';
            break;

        case 'blue':
            echo '<body style="background-color:blue">';
            break;

        case 'green':
            echo '<body style="background-color:green">';
            break;

        default:
            echo '<body style="background-color:linen">';
            break;

    }
    
?>