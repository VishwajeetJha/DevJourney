import java.io.*;

class copy1to2 {
    public static void main(String[] args) {
        FileReader f1 = null;
        FileWriter f2 = null;
        try{
            f1 = new FileReader("co41.txt");
            f2 = new FileWriter("co42.txt");

            int toWrite;

            while((toWrite = f1.read()) != -1){
                f2.write(toWrite);
            }
        }
        catch(IOException e){
            System.out.println(e);
        }

        //closing f1 and f2
        finally{
            try{
                if(f1 != null){
                    f1.close();
                }
                if(f2 != null){
                    f2.close();
                }
            }
            catch(IOException e){
                System.out.println(e);
            }
        }
    }
}
