<?php
class Person{
public $Vname;
public $age;

function show(){
    echo($this->Vname." is ".$this->age." years old.");
}
}

class Car{
    public $make;
    public $model;
    
    function showCar(){
        echo($this->make." Made the Car ".$this->model);
    }
}

class Rectangle{
    public $len;
    public $wid;
    
    function CalArea(){
        $area = $this->len * $this->wid;
        echo("Area of Rectangle with Length of 10 and Width of 5 is: ".$area);
    }
}


$p = new Person();
$p->Vname = "John";
$p->age = 30;
$p->show();

$c = new Car();
$c->make = "Toyota";
$c->model = "Camry";
echo "<br>";
$c->showCar();

$a = new Rectangle();
$a->len = 10;
$a->wid = 5;
echo "<br>";
$a->CalArea();

?>