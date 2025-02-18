class GMThread extends Thread{
    public void run(){
        try{
            while(true){
                System.out.println("Good Morning");
                Thread.sleep(1000);
            }
        }
        catch(InterruptedException e){
            System.out.println(e);
        }
    }
}

class GEThread extends Thread{
    public void run(){
        try{
            while(true){
                System.out.println("Good Evenin' !");
                Thread.sleep(2000);
            }
        }
        catch(InterruptedException e){
            System.out.println(e);
        }
    }
}

class morneven {
    public static void main(String[] args) {
        GMThread GM = new GMThread();
        GEThread GE = new GEThread();

        GM.start();
        GE.start();
    }
}
