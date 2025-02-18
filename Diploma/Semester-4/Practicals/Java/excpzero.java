class excpzero {
    public static void main(String[] args) {
        try{
            System.out.println("Dividing 3/0: "+(3/0));
        }
        catch(ArithmeticException e){
            System.out.println("Exception: "+e.getMessage());
        }
    }    
}
