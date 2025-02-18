final class maths{
    public static int Add(int a, int b){
        return a+b;
    }

    public static int Multiply(int a, int b){
        return a*b;
    }

    public static final double Divide(int a, int b){
        return a/b;
    }
}

class maths_extended extends maths{
    public static double Divide
                    (int a, int b)
        {
        double c = a/b;

        return c;
    }
}

class aoop_p212 {
    public static void main(String[] args) {
        System.out.println("Sum of 20 + 30 = "+maths.Add(20, 30));
        System.out.println("Product of 22 x 13 = "+maths.Multiply(22, 13));
        System.out.println("Quotient of 22 / 7 = "+maths.Divide(22, 7));
        
    }
}
