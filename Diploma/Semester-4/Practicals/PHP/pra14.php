<?php
function isPrime($num) {
    if($num == 1)
        return false;

    for ($i = 2; $i <= sqrt($num); $i++) {
        if ($num % $i == 0) {
            return false;
        }
    }
    return true;
}

$sum = 0;
for ($i = 2; $i <= 50; $i++) {
    if (isPrime($i)) {
        $sum += $i;
    }
}

echo "The total of all prime numbers from 1 to 50 is: " . $sum;
echo "\nSo Anjali will get $sum rupees";
?>
