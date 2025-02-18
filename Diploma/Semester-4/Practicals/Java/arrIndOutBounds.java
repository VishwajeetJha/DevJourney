class arrIndOutBounds {
    public static void main(String[] args) {
        int a[] = {0,1,2};
        try{
            System.out.println("Printing a[1]: "+a[1]);
            System.out.println("Printing a[42]: "+a[42]);
        }
        catch(ArrayIndexOutOfBoundsException e){
            System.out.println("Exception: "+e.getMessage());
        }
    }
}


