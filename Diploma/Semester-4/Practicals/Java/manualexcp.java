class manualexcp {
    public static void throwsExcp() throws Exception{
        throw new Exception("Manually thrown exception");
    }

    public static void main(String[] args) {
        try{
            throwsExcp();
        }
        catch(Exception e){
            System.out.println(e);
        }
    }
}
