<?php
require_once('tcpdf/tcpdf.php');

$pdf = new TCPDF(PDF_PAGE_ORIENTATION, PDF_UNIT, PDF_PAGE_FORMAT, true, 'UTF-8', false);

$pdf->SetCreator(PDF_CREATOR);
$pdf->SetAuthor('Alberto');
$pdf->SetTitle('Employee Salary Slip');
$pdf->SetSubject('Salary Slip');
$pdf->SetKeywords('Salary, Slip, Employee, Pay');

$pdf->setHeaderFont(Array(PDF_FONT_NAME_MAIN, '', PDF_FONT_SIZE_MAIN));
$pdf->setFooterFont(Array(PDF_FONT_NAME_DATA, '', PDF_FONT_SIZE_DATA));

$pdf->SetMargins(PDF_MARGIN_LEFT, PDF_MARGIN_TOP, PDF_MARGIN_RIGHT);
$pdf->SetHeaderMargin(PDF_MARGIN_HEADER);
$pdf->SetFooterMargin(PDF_MARGIN_FOOTER);

$pdf->SetAutoPageBreak(TRUE, PDF_MARGIN_BOTTOM);

$pdf->setImageScale(PDF_IMAGE_SCALE_RATIO);

$l = array();
$l['a_meta_charset'] = 'UTF-8';
$l['a_meta_dir'] = 'ltr';
$l['a_meta_language'] = 'en';
$l['w_page'] = 'page';

$pdf->setLanguageArray($l);

$pdf->AddPage();
$pdf->SetFont('helvetica', '', 12);

$employeeName = 'some name';
$employeeID = 'EMP289';
$basicSalary = 15000;
$allowance = 6000;
$totalSalary = $basicSalary + $allowance;

$html = '
<h1>Employee Salary Slip</h1>
<table border="1">
<tr><td><strong>Name:</strong></td><td>'.$employeeName.'</td></tr>
<tr><td><strong>Employee ID:</strong></td><td>'.$employeeID.'</td></tr>
<tr><td><strong>Basic Salary:</strong></td><td>$'.$basicSalary.'</td></tr>
<tr><td><strong>Allowance:</strong></td><td>$'.$allowance.'</td></tr>
<tr><td><strong>Total Salary:</strong></td><td>$'.$totalSalary.'</td></tr>
</table>';

$pdf->writeHTML($html, true, false, true, false, '');

$pdf->Output('salary_slip.pdf', 'I');

?>
