class SimProc extends Thread{
    SimProc(String ThreadName){ 
        super(ThreadName);
	}
	public void run(){
		while(true){
            if (Thread.currentThread().getName() == "t1"){


                System.out.println(Thread.currentThread().getName()+" Printing Thread 1");
		    	
				
				try{
		    		Thread.sleep(1000);
		    	} catch (Exception e){
		    		System.out.println(e);
		        }
	        } 
		    else {
		    	System.out.println(Thread.currentThread().getName()+" Printing Thread 2");
		    	try{
		    		Thread.sleep(1000);
		    	} catch (Exception e){
		    		System.out.println(e);
		    	}
	        }
        }
    }
}
class aoop_p25{
	public static void main(String []args){
		SimProc a1 = new SimProc("t1");
		SimProc a2 = new SimProc("t2");
        a1.start();
        a2.start();
	}
}

/* 
OUTPUT
t1 Printing Thread 1
t2 Printing Thread 2
t1 Printing Thread 1
t2 Printing Thread 2
.
.
.
t1 Printing Thread 1
t2 Printing Thread 2
CANCELED USING CTRL+C

*/