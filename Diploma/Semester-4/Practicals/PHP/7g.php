<?php
    class pr{
        public function fun(){
            echo "Original Function..\n";
        }
    }
    class ch extends pr{
        public function fun(){
            echo "Overridden Function\n";
        }
    }

    $obj = new ch();
    $obj->fun();
?>