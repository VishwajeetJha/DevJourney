<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Login</title>
    <link rel="stylesheet" href="styles.css">
</head>
<body>
    <div class="container">
        <h1>Login</h1>
        <form action="rules.php" method="post">
            <label for="name">Enter your name:</label>
            <input type="text" id="name" name="name" required>
            <label for="id">Enter your Enrollment Number:</label>
            <input type="number" id="erno" name="erno" required>
            <input type="submit" value="Start Quiz">
        </form>
    </div>
</body>
</html>