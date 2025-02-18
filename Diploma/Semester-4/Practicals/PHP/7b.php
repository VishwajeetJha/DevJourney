<?php
    class pr{
        public $a;

        public function fn(){
            echo "Object Function fn() called..\n";
            echo "Value of a is: ".$this->a;
        }
    }

    $obj = new pr();
    $obj->a = 24;
    $obj->fn();

?>