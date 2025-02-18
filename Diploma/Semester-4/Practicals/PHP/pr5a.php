<?php
    $length_of_string = 0;
    $words_in_string = 0;
    $inserted_string = $_POST["str"];
    echo "Inserted String: " . $inserted_string . "<br>";
    while (isset($inserted_string[$length_of_string])) {
        if ($inserted_string[$length_of_string] == ' ') {
            $words_in_string++;
        }
        $length_of_string++;
    }
    echo "<br>Length of String: " . $length_of_string . "<br>";
    echo "Words in String: " . $words_in_string;
?>