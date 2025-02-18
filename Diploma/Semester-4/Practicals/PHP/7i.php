<?php
    interface A{
        function ex();
    }

    class B implements A{
        public function ex(){
            echo "Implemented function ex() from interface A\n";
        }
    }

    $obj = new B();
    $obj->ex();
?>