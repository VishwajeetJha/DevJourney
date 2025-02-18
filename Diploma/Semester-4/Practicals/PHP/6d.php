<html>
<body bgcolor="linen">
    <?php
        date_default_timezone_set('Asia/Kolkata');

        $currentDateTime = date('Y-m-d H:i:s');

        echo "Current Date and Time (Y-m-d H:i:s): " . $currentDateTime . "<br>";

        echo "Date only (Y-m-d): " . date('Y-m-d') . "<br>";
        echo "Time only (H:i:s): " . date('H:i:s') . "<br>";
        echo "Current day, date and time (Custom Format): " . date('l, F j, Y g:i A') . "<br>";

    ?>
</body>
</html>