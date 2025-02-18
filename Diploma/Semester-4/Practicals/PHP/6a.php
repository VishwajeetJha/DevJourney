<html>
    <body bgcolor="linen">
    <?php
        function deno($amt) {
            $temp = $amt;
            $denominations = [100, 50, 20, 10, 5, 2, 1];
            $counts = array_fill(0, count($denominations), 0); //makes an array jisme denominations wale array_values keys ban jayenge and give them value 0
        
            foreach ($denominations as $i => $denomination) {
                while ($amt >= $denomination) {
                    $amt -= $denomination;
                    $counts[$i]++;
                }
            }
        
            echo "Note Denominations Required for {$temp}rs:<br>";
            foreach ($denominations as $i => $denomination) {
                echo "{$denomination}s: {$counts[$i]}<br>"; //curly braces in double quotes FTW!
            }
        }
    
        deno($_POST["val"]);
    ?>
    </body>
</html>
