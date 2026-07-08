package PR10;

import java.io.RandomAccessFile;

public class RandomAccessDemo {
    public static void main(String[] args) throws Exception {
        try{
            RandomAccessFile file = new RandomAccessFile("test.txt", "rw");
    
            file.writeUTF("Hello");
            file.seek(0); // move pointer to start
            System.out.println(file.readUTF());

            file.close();
        }
        catch(Exception e){
            System.out.println("Error: " + e.getMessage());
        }
    }
}