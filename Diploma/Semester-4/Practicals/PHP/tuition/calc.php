<html>
    <body bgcolor="linen">
    <?php
        $ch = $_POST["op"];
        $var_a = $_POST["var_a"];
        $var_b = $_POST["var_b"];

        switch($ch){
            case 'add':
                echo "Addition of $var_a and $var_b = ".($var_a+$var_b);
                break;

            case 'sub':
                echo "Difference of $var_a and $var_b = ".($var_a-$var_b);
                break;
                
            case 'mul':
                echo "Multiplication of $var_a and $var_b = ".($var_a*$var_b);
                break;
                
            case 'div':
                echo "Division of $var_a and $var_b = ".($var_a/$var_b);
                break;

            default:
                echo "Unknown option!";
                break;
        }
    ?>
    </body>
</html>