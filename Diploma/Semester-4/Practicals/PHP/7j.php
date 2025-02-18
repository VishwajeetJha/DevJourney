<?php
    abstract class A{
        public $a;
        function ab(){
            echo "This function must be overriden!";
        }
    }

    class B extends A{
        // public function ab(){
        //     $a = "World";
        //     echo "Hello, $a\n";
        // }
    }

    $obj = new B();
    $obj->ab();
?>