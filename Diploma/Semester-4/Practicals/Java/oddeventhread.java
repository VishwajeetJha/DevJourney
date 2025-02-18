class oTh extends Thread{
    public void run(){
        try{
            for(int i = 1; i <= 30; i++){
                if(i%2 != 0){
                    System.out.println("Odd Number: "+i);
                    Thread.sleep(1000);
                }
            }
        }
        catch(InterruptedException e){
            System.out.println(e);
        }
    }
}

class eTh extends Thread{
    public void run(){
        try{
            for(int i = 1; i <= 30; i++){
                if(i%2 == 0){
                    System.out.println("Even Number: "+i);
                    Thread.sleep(2000);
                }
            }
        }
        catch(InterruptedException e){
            System.out.println(e);
        }
    }
}

class oddeventhread {
    public static void main(String[] args) {
        oTh oddNumbers = new oTh();
        eTh evenNumbers = new eTh();

        oddNumbers.start();
        evenNumbers.start();
    }
}
