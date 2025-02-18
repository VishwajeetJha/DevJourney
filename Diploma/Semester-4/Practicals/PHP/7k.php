<?php
    class A{
        private $a;

        function __construct($val){
            $this->a = $val;
        }

        public function pd(){
            echo $this->a."\n";
        }
    }

    $obj = new A("Secret code: 22!");
    
    $copy = clone $obj;
    $copy->pd();
    
?>