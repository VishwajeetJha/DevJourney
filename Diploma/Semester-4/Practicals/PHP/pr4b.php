<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>PR4D</title>
</head>
<body>
    <table border="2">
        <th>Marks</th>
        <th>Grade</th>
        <th>Subject</th>
        <tr>
            <td><?php echo $_POST["aoop"];?>
            <td>
                <?php
                    if($_POST["aoop"]>=85 and $_POST["aoop"]<=100){
                        echo "AA";
                    }
                    else if($_POST["aoop"]>=75 and $_POST["aoop"]<=84){
                        echo "AB";
                    }
                    else if($_POST["aoop"]>=65 and $_POST["aoop"]<=74){
                        echo "BB";
                    }
                    else if($_POST["aoop"]>=55 and $_POST["aoop"]<=64){
                        echo "BC";
                    }
                    else if($_POST["aoop"]>=45 and $_POST["aoop"]<=54){
                        echo "CC";
                    }
                    else if($_POST["aoop"]>=40 and $_POST["aoop"]<=44){
                        echo "CD";
                    }
                    else if($_POST["aoop"]>=35 and $_POST["aoop"]<=39){
                        echo "DD";
                    }
                    else{
                        echo "FF";
                    }
                ?>
            </td>
            <td>
                AOOP 
            </td>
        </tr>
        <tr>
            <td><?php echo $_POST["ise"];?></td>
            <td>
                <?php
                    if($_POST["ise"]>=85 and $_POST["ise"]<=100){
                        echo "AA";
                    }
                    else if($_POST["ise"]>=75 and $_POST["ise"]<=84){
                        echo "AB";
                    }
                    else if($_POST["ise"]>=65 and $_POST["ise"]<=74){
                        echo "BB";
                    }
                    else if($_POST["ise"]>=55 and $_POST["ise"]<=64){
                        echo "BC";
                    }
                    else if($_POST["ise"]>=45 and $_POST["ise"]<=54){
                        echo "CC";
                    }
                    else if($_POST["ise"]>=40 and $_POST["ise"]<=44){
                        echo "CD";
                    }
                    else if($_POST["ise"]>=35 and $_POST["ise"]<=39){
                        echo "DD";
                    }
                    else{
                        echo "FF";
                    }
                ?>
            </td>
            <td>
                ISE
            </td>
        </tr>
        <tr>
            <td><?php echo $_POST["cn"];?></td>
            <td>
                <?php
                    if($_POST["cn"]>=85 and $_POST["cn"]<=100){
                        echo "AA";
                    }
                    else if($_POST["cn"]>=75 and $_POST["cn"]<=84){
                        echo "AB";
                    }
                    else if($_POST["cn"]>=65 and $_POST["cn"]<=74){
                        echo "BB";
                    }
                    else if($_POST["cn"]>=55 and $_POST["cn"]<=64){
                        echo "BC";
                    }
                    else if($_POST["cn"]>=45 and $_POST["cn"]<=54){
                        echo "CC";
                    }
                    else if($_POST["cn"]>=40 and $_POST["cn"]<=44){
                        echo "CD";
                    }
                    else if($_POST["cn"]>=35 and $_POST["cn"]<=39){
                        echo "DD";
                    }
                    else{
                        echo "FF";
                    }
                ?>
            </td>
            <td>
                CN
            </td>
        </tr>
        <tr>
            <td><?php echo $_POST["iwd"];?></td>
            <td>
                <?php
                    if($_POST["iwd"]>=85 and $_POST["iwd"]<=100){
                        echo "AA";
                    }
                    else if($_POST["iwd"]>=75 and $_POST["iwd"]<=84){
                        echo "AB";
                    }
                    else if($_POST["iwd"]>=65 and $_POST["iwd"]<=74){
                        echo "BB";
                    }
                    else if($_POST["iwd"]>=55 and $_POST["iwd"]<=64){
                        echo "BC";
                    }
                    else if($_POST["iwd"]>=45 and $_POST["iwd"]<=54){
                        echo "CC";
                    }
                    else if($_POST["iwd"]>=40 and $_POST["iwd"]<=44){
                        echo "CD";
                    }
                    else if($_POST["iwd"]>=35 and $_POST["iwd"]<=39){
                        echo "DD";
                    }
                    else{
                        echo "FF";
                    }
                ?>
            </td>
            <td>
                IWD
            </td>
        </tr>
    </table>
    <?php 
        if($_POST["aoop"] <= 34 or $_POST["iwd"] <= 34 or $_POST["ise"] <= 34 or $_POST["cn"] <= 34){
            echo "Sorry you <b>Failed</b> This Exam!";
        }
        else{
            echo "Congratulations you <b>Passed</b> this Exam!";
        }
    ?>
</body>
</html>