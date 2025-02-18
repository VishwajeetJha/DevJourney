<?php
    class pr{
        private $a;

        public function setAttribute($value){
            $this->a = $value;
        }
        public function getAttribute(){
            return $this->a;
        }
        
    }

    $obj = new pr();
    $obj->setAttribute(5);
    echo "Accessing private attribute..\n";
    echo "Value of a is: ".$obj->getAttribute();

?>