<?php
    $da = (($_POST["sal"]/100) * 50);
    $hra = (($_POST["sal"]/100) * 10);
    $medical = (($_POST["sal"]/100) * 4);
    $grossSalary = $_POST["sal"] + $da + $hra + $medical;
    $insurance = (($grossSalary/100) * 7);
    $pf = (($grossSalary/100) * 5);
    $deduction = $insurance + $pf;
    $netSalary = $grossSalary - $deduction;
    echo "<br>"."Salary: ".$_POST["sal"]."<br>";
    echo "<br>"."Net Salary: ".$netSalary."<br>";
    echo "<br>"."Gross Salary: ".$grossSalary."<br>";
    echo "<br>"."Dearness Allowance: ".$da."<br>";
    echo "<br>"."House Rent Allowance: ".$hra."<br>";
    echo "<br>"."Medical: ".$medical."<br>";
    echo "<br>"."Insurance: ".$insurance."<br>";
    echo "<br>"."Deduction: ".$deduction."<br>";
    echo "<br>"."Provident Fund: ".$pf."<br>";
?>