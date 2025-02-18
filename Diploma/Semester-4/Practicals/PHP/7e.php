<?php
    interface I1{
        function fun1();
    }
    interface I2{
        function fun2();
    }
    class child_class implements I1,I2{
        public function fun1(){
            echo "Function from interface 1\n";
        }
        public function fun2(){
            echo "Function from interface 2\n";
        }
    }

    $obj = new child_class();
    $obj->fun1();
    $obj->fun2();
?>
