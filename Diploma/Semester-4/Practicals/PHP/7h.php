<?php
    class pr{
        public function __call($name, $args){
            if($name == 'sum'){
                $i = count($args);
                switch($i){
                    case 1:
                        echo "Only one argument was passed: ".$args[0]."\n";
                        break;

                    default:
                        $sum = 0;
                        while($i!=0){
                            $sum += $args[$i-1];
                            $i--;
                        }
                        echo "Sum is: ".$sum."\n";
                        break;
                }
            }
        }
    }

    $obj = new pr();
    $obj->sum(3);
    $obj->sum(3,3);
    $obj->sum(3,3,4);
?>