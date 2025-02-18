<?php
$questions = array(
    array(
        "question" => "What does PHP stand for?",
        "options" => array(
            "Personal Hypertext Processor",
            "Hypertext Markup Language",
            "Hypertext Preprocessor",
            "Programming Hyperlinks and Pages"
        ),
        "answer" => "Hypertext Preprocessor"
    ),
    array(
        "question" => "Which of the following is NOT a valid PHP variable name?",
        "options" => array(
            "variable_name",
            "_variable_name",
            "1variable_name",
            "variableName"
        ),
        "answer" => "1variable_name"
    ),
    array(
        "question" => "What function is used to output text in PHP?",
        "options" => array(
            "echo",
            "print",
            "printf",
            "display"
        ),
        "answer" => "echo"
    ),
    array(
        "question" => "Which PHP function is used to find the length of a string?",
        "options" => array(
            "str_length()",
            "length()",
            "strlen()",
            "strcount()"
        ),
        "answer" => "strlen()"
    ),
    array(
        "question" => "In PHP, how do you start a session?",
        "options" => array(
            "start_session()",
            "session_start()",
            "begin_session()",
            "session()"
        ),
        "answer" => "session_start()"
    ),
    array(
        "question" => "What is the result of the following code: echo 10%3;",
        "options" => array(
            "3",
            "1",
            "0",
            "10"
        ),
        "answer" => "1"
    ),
    array(
        "question" => "Which of the following is a valid way to comment out multiple lines in PHP?",
        "options" => array(
            "/* Comment */",
            "// Comment",
            "# Comment",
            "' Comment"
        ),
        "answer" => "/* Comment */"
    ),
    array(
        "question" => "What does the PHP function array_push() do?",
        "options" => array(
            "Adds one or more elements to the end of an array",
            "Removes the last element from an array",
            "Sorts an array",
            "Returns the length of an array"
        ),
        "answer" => "Adds one or more elements to the end of an array"
    ),
    array(
        "question" => "Which PHP function is used to change the case of a string to uppercase?",
        "options" => array(
            "ucase()",
            "to_upper()",
            "strtoupper()",
            "upper_case()"
        ),
        "answer" => "strtoupper()"
    ),
    array(
        "question" => "What is the result of the following code: echo 'Hello' . ' World';",
        "options" => array(
            "Hello World",
            "Hello.World",
            "Hello,World",
            "Hello World!"
        ),
        "answer" => "Hello World"
    )
);
$name = isset($_POST['name']) ? $_POST['name'] : '';
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Quiz</title>
    <link rel="stylesheet" href="styles.css">
</head>
<body>
    <div class="container">
        <h1>Welcome to the Quiz</h1>
        <form action="score.php" method="post">
            <?php foreach ($questions as $index => $question) : ?>
                <h3><?php echo ($index + 1) . ". " . $question['question']; ?></h3>
                <?php foreach ($question['options'] as $option) : ?>
                    <label><input type='radio' name='answer_<?php echo $index; ?>' value='<?php echo $option; ?>'> <?php echo $option; ?></label>
                <?php endforeach; ?>
            <?php endforeach; ?>
            <input type="hidden" name="name" value="<?php echo htmlspecialchars($name); ?>">
            <input type="hidden" name="questions" value="<?php echo htmlspecialchars(json_encode($questions)); ?>">
            <input type="submit" value="Submit">
        </form>
    </div>
</body>
</html>
