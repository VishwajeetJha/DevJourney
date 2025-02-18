<?php
$name = $_POST['name'] ?? '';
$questions = json_decode($_POST['questions'], true) ?? [];
$score = 0;
$total_questions = 10; // Subtract 1 for the name fieldz

foreach ($_POST as $key => $value) {
    if ($key != 'name' && $key != 'questions') {
        $question_index = substr($key, strlen('answer_'));
        $question = $questions[$question_index];
        if ($value == $question['answer']) {
            $score++;
        }
    }
}


?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Quiz Score</title>
    <link rel="stylesheet" href="styles.css">
</head>
<body>
    <div class="container">
        <h1>Quiz Score</h1>
        <p>Thank you, <?php echo htmlspecialchars($name); ?>, for taking the quiz!</p>
        <p>Your score: <?php echo "$score / $total_questions"; ?></p>
        <p>Want to take the quiz again? <a href="quiz.php">Click here</a></p>
    </div>
</body>
</html>
