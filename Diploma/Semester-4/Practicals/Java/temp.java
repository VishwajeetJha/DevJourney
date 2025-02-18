import java.io.*;

// class temp{
//     public static void main(String[] args) {
//         try(
//             FileInputStream inp = new FileInputStream(new File("file.txt"));
//             FileOutputStream out = new FileOutputStream(new File("file.txt"),true);
//             ){
//                 //Reading Part
//                 int fileSize;
//                 byte[] buffer = new byte[1024];

//                 while((fileSize = inp.read(buffer)) != -1){
//                     String line = new String(buffer,0,fileSize);
//                     System.out.println(line);
//                 }

//                 //Writing Part
//                 String msg = "Data for file.txt\n";
//                 byte[] msgByte = msg.getBytes();
//                 out.write(msgByte);

//         }
//         catch(Exception e){
//             System.out.println(e);
//         }
//     }
// }

// class ThreadEx extends Thread{
//     public ThreadEx(String nStr){
//         super(nStr);
//     }

//     public void run(){
//         for(int i = 1;i <= 200; i++){
//             if(i%2 == 0){
//                 System.out.println(this.getName()+": Even Number "+i);
//                 try{
//                     Thread.sleep(1000);
//                 }
//                 catch(InterruptedException e){
//                     System.err.println(e);
//                 }
//             }
//             if(i%2 != 0){
//                 System.out.println(this.getName()+": Odd Number "+i);
//                 try{
//                     Thread.sleep(2000);
//                 }
//                 catch(InterruptedException e){
//                     System.err.println(e);
//                 }
//             }
//         }
//     }
// }

// class hTh extends Thread{
//     public hTh(String nStr){
//         super(nStr);
//     }

//     public void run(){
//         while(true){
//             System.out.println(this.getName()+": Hello");
//             try {
//                 Thread.sleep(2000);
//             } catch (Exception e) {
//                 System.err.println(e);
//             }
//         }
//     }
// }
// class wTh extends Thread{
//     public wTh(String nStr){
//         super(nStr);
//     }

//     public void run(){
//         while(true){
//             System.out.println(this.getName()+": World");
//             try {
//                 Thread.sleep(4000);
//             } catch (Exception e) {
//                 System.err.println(e);
//             }
//         }
//     }
// }

// public class temp{
//     public static void main(String[] args) {
//         hTh Hello = new hTh("helloThread");
//         wTh World = new wTh("worldThread");

//         Hello.start();
//         World.start();
//     }
// }

public class temp{
    public static void main(String[] args) {
        try (FileReader rd = new FileReader("file.txt")) {
            int c;
            while((c = rd.read()) != -1){
                System.out.print((char)c);
            }
            
        } catch (Exception e) {
            System.err.println(e);
        }
    }
}