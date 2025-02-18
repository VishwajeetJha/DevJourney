<?php
    $conn = mysqli_connect("localhost", "root", "");
    
    if(mysqli_connect_error()){
        die("Connection failed: ".mysqli_connect_error()); //or exit()
    }

        //1.
    // $query = "CREATE DATABASE prep";

        //2.
    //$query = "USE prep";
                //OR
    // $result = mysqli_select_db($conn, "prep");

        //3. 
    // $query = "DROP DATABASE prep";

        //4.
    // mysqli_select_db($conn, "prep");
    // $query = "CREATE TABLE table1(id INT(12), name varchar(30), created_on TIMESTAMP DEFAULT CURRENT_TIMESTAMP)";

        //5.
    // mysqli_select_db($conn, "prep");
    // $query = "INSERT INTO table1(id, name) values(5, 'name1')";

        //6.
    mysqli_select_db($conn, "prep");
    $query = "SELECT * FROM table1";

    $result = mysqli_query($conn, $query);

    if(!$result){
        die("Query failed: ".mysqli_error($conn));
    }

    while($data = mysqli_fetch_assoc($result)){
        foreach($data as $k => $v){
            echo "$k: $v\n";
        }
        echo "\n";
    }

    if($result){
        echo "Query ran successfully..\n";
    }
?>