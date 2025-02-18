<?php

    class pr{
        function __construct(){
            echo "This is the default constructor..\n";
        }
        
        function __destruct(){
            echo "This is the destructor..\n";
        }       
    }

    $obj = new pr();

?>