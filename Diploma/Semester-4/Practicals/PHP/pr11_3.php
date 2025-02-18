<?php
// Associative array
$associativeArray = array(
    "name" => "vishwajeet",
    "age" => 30,
    "city" => "Ahemedabad"
);

// Convert associative array to JSON string
$jsonString = json_encode($associativeArray);

echo "JSON String:";
echo $jsonString ;

// Convert JSON string back to associative array
$decodedArray = json_decode($jsonString, true);

echo "\nDecoded Associative Array:";
print_r($decodedArray);
?>
