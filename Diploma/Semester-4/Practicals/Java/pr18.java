class Car {
    public int topSpeed;
    public String name;

    Car(int sp, String name){
        this.topSpeed = sp;
        this.name = name;
    }

    @Override
    public String toString(){
        String a = String.format("%s has a top speed of %d km/h",this.name,this.topSpeed);;
        return a;
    }

    public static void main(String[] args) {
		Car Agera = new Car(458, "Koenigsegg Agera RS");
		Car Tuatara = new Car(455, "SSC Tuatara");
        Car Venom = new Car(435, "Hennessey Venom GT");
        Car Nevera = new Car(415, "Rimac Nevera");
        Car TT = new Car(411, "SSC Ultimate Aero TT");

		System.out.println(Agera);
		System.out.println(Tuatara);
		System.out.println(Nevera);
		System.out.println(TT);
        System.out.println(Venom);
    }
}
