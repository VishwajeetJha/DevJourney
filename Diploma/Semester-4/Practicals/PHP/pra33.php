<?php
    interface Charging{
        function type();
    }

    interface Audio{
        function type();
    }

    class Samsung implements Charging, Audio{
        public function type(){
            echo "\nType of interfaces implemented:\n";
            echo "1. Charging\n";
            echo "2. Audio\n";
        }
    }

    class Apple implements Charging{
        public function type(){
            echo "\nType of interfaces implemented:\n";
            echo "1. Charging\n";
        }
    }

    $S21 = new Samsung();
    $SE11 = new Apple();

    $S21->type();
    $SE11->type();
?>
