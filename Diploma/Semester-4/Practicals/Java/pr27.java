import java.io.*;

class pr27 {
    public static void main(String[] args) {
        FileInputStream inp = null;
        FileOutputStream out = null;
        
        try{
            byte[] buffer = new byte[1024];
            int readBytes;

            inp = new FileInputStream(new File("co41.txt"));
            out = new FileOutputStream(new File("co42.txt"));


            // agar koi string add karni hai to use this -v
            // String msg = "THIS IS HIDDEN AND SECRET CONTENT OF CO41!!\nSecret Code: 22";
            // byte[] msgByte = msg.getBytes();
            // out.write(msgByte);
            
            System.out.println("Data in File 1:-");

            while((readBytes = inp.read(buffer)) != -1){
                String line = new String(buffer, 0, readBytes);
                System.out.println(line);
            }

            inp.close();
            inp = new FileInputStream(new File("co41.txt"));

            System.out.println("\nCopying data in file 1 to file 2...");

            while((readBytes = inp.read(buffer)) != -1){
                out.write(buffer, 0, readBytes);
            }

            inp.close();
            inp = new FileInputStream(new File("co42.txt"));

            System.out.println("\nData in File 2:-");

            while((readBytes = inp.read(buffer)) != -1){
                String line = new String(buffer, 0, readBytes);
                System.out.println(line);
            }
        }
        catch(IOException e){
            System.out.println(e);
        }
        finally{
            try{
                if(inp != null) inp.close();
                if(out != null) out.close();
            }
            catch(IOException e){
                System.out.println(e);
            }
        }
    }
}

/*
OUTPUT:-

Data in File 1:-
THIS IS HIDDEN AND SECRET CONTENT OF CO41!!
Secret Code: 22

Copying data in file 1 to file 2...

Data in File 2:-
THIS IS HIDDEN AND SECRET CONTENT OF CO41!!
Secret Code: 22
 */
