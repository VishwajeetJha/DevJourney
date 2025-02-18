<?php
$name = $_POST['name'] ?? '';
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Rules</title>
    <link rel="stylesheet" href="styles.css">
</head>
<body>
    <div class="container">
        <h1>Welcome <?php echo $name; ?>, Ready for Quiz</h1>
        <h2>Rules:</h2>
        <ul>
            <li>Answer all questions to give your best.</li>
            <li>Do not use any external resources or assistance.</li>
            <li>Incomplete answers will not be counted.</li>
            <li>Scores will be displayed at the end of the quiz.</li>
        </ul>
        <form action="quiz.php" method="post">
            <input type="hidden" name="name" value="<?php echo htmlspecialchars($name); ?>">
            <input type="submit" value="Start Quiz">
        </form>
    </div>
</body>
</html>
