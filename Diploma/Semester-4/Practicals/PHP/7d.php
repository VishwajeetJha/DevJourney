<?php
    class pr{
        public function parent_fn(){
            echo "Parent class function..\n";
        }
    }
    class prt extends pr{
        public function fun(){
            echo "Child class function..\n";
        }
    }

    $obj = new prt();
    $obj->parent_fn();
    $obj->fun();
?>