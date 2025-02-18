<?php
// Animal and Cat classes
class Animal {
    public function makeSound() {
        return "This animal makes a sound";
    }
}

class Cat extends Animal {
    public function makeSound() {
        return "Meow";
    }
}

$cat = new Cat();
echo $cat->makeSound()."\n"; // Outputs: Meow

// Shape, Rectangle, and Triangle classes
class Shape {
    public function calcArea() {
        return 0;
    }
}

class Rectangle extends Shape {
    private $width;
    private $height;

    public function __construct($width, $height) {
        $this->width = $width;
        $this->height = $height;
    }

    public function calcArea() {
        return $this->width * $this->height;
    }
}

class Triangle extends Shape {
    private $base;
    private $height;

    public function __construct($base, $height) {
        $this->base = $base;
        $this->height = $height;
    }

    public function calcArea() {
        return 0.5 * $this->base * $this->height;
    }
}

$rectangle = new Rectangle(5, 7);
echo $rectangle->calcArea()."\n"; // Outputs: 35

$triangle = new Triangle(6, 8);
echo $triangle->calcArea()."\n"; // Outputs: 24

// Employee and Manager classes
class Employee {
    protected $name;
    protected $salary;

    public function __construct($name, $salary) {
        $this->name = $name;
        $this->salary = $salary;
    }

    public function calculateSalary() {
        return $this->salary;
    }
}

class Manager extends Employee {
    private $bonus;

    public function __construct($name, $salary, $bonus) {
        parent::__construct($name, $salary);
        $this->bonus = $bonus;
    }

    public function calculateSalary() {
        return parent::calculateSalary() + $this->bonus;
    }
}

$manager = new Manager("John Doe", 50000, 5000);
echo $manager->calculateSalary()."\n"; // Outputs: 55000
?>