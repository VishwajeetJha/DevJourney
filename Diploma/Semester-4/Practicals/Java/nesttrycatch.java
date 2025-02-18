class nesttrycatch {
    public static void main(String[] args) {
        try{
            try{
                int a = Integer.parseInt("ERR");
            }
            catch(NumberFormatException e){
                System.out.println(e.getMessage());
            }
            try{
                System.out.println(3/0);
            }
            catch(ArithmeticException e){
                System.out.println(e.getMessage());
            }
        }
        catch(Exception e){
            System.out.println(e.getMessage());
        }
    }   
}
