<?php
    class pr{
        public function funP(){
            echo "Parent class function..\n";
        }
    }
    class ch extends pr{
        public function funCh(){
            echo "Child class 1 function..\n";
        }
    }
    class grand_ch extends ch{
        public function fun(){
            echo "Grand Child class function..\n";
        }
    }


    $obj = new grand_ch();
    $obj->funP();
    $obj->funCh();
    $obj->fun();
?>