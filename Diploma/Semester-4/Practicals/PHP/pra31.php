<?php

abstract class MarutiCar{
    public $modelname,$type,$gearshift;
    public $mileage;

    public function __construct($mn,$t,$gs,$ml){
        $this->modelname = $mn;
        $this->type = $t;
        $this->gearshift = $gs;
        $this->mileage = $ml;
    }

    abstract function setdata($a,$b);

    public function showdata(){
        echo "\nCar: $this->modelname\n";
        echo "Type: $this->type\n";
        echo "Gearshift: $this->gearshift\n";
        echo "Mileage: $this->mileage KMpl\n";
    }
}

class MarutiDzire extends MarutiCar{
    public $hasPowerSteering, $hasPowerWindow;

    public function __construct($mn, $t, $gs, $ml){
        parent::__construct($mn,$t,$gs,$ml);
    }

    public function setdata($a,$b){
        $this->hasPowerSteering = $a;
        $this->hasPowerWindow = $b;
    }

    public function showdata(){
        parent::showdata();
        echo "Supports Power Steering?: $this->hasPowerSteering\n";
        echo "Supports power Windows?: $this->hasPowerWindow\n";
    }
}

class MarutiBrezza extends MarutiCar{
    public $topSpeed;
    public $fuelType;

    public function __construct($mn, $t, $gs, $ml){
        parent::__construct($mn, $t, $gs, $ml);
    }
    public function setdata($a, $b){
        $this->topSpeed = $a;
        $this->fuelType = $b;
    }

    public function showdata(){
        parent::showdata();
        echo "Top Speed: $this->topSpeed KMph\n";
        echo "Fuel Type: $this->fuelType\n";
    }
}

$brezza = new MarutiBrezza("Maruti Brezza","SUV", "Manual", 15);
$dzire = new MarutiDzire("Maruti Dzire","Hatchback","Manual",18);

$dzire->setdata(true,true);
$brezza->setdata(188,"Diesel");

$brezza->showdata();
$dzire->showdata();

// $b1 = new MarutiBrezza("Maruti Brezza","SUV", "Manual", 15);
// $b2 = new MarutiBrezza("Maruti Brezza","SUV", "Manual", 15);
// $b3 = new MarutiBrezza("Maruti Brezza","SUV", "Manual", 15);
// $d1 = new MarutiDzire("Maruti Dzire","Hatchback","Manual",18);
// $d2 = new MarutiDzire("Maruti Dzire","Hatchback","Manual",18);
// $d3 = new MarutiDzire("Maruti Dzire","Hatchback","Manual",18);
// $d4 = new MarutiDzire("Maruti Dzire","Hatchback","Manual",18);
// $d5 = new MarutiDzire("Maruti Dzire","Hatchback","Manual",18);

// unset($d3,$d5);
// unset($b3);

// MarutiCar::carsStats();

?>