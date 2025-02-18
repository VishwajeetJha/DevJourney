class ThreadEx extends Thread{
	ThreadEx(String s){
    	super(s);
	}

	public void run(){
		for (int i = 1; i <= 200; i++){
		    if (Thread.currentThread().getName() == "Thread 1"){
		        if (i % 2 != 0){
			        System.out.println(Thread.currentThread().getName()+" Printing Odd Number: " +i);
		        } 
		    }
		    if(Thread.currentThread().getName() == "Thread 2"){
			    if(i%2==0){
			        System.out.println(Thread.currentThread().getName()+" Printing Even Number: "+i);
		        }
		    }	
	    }
    }
}
class aoop_p26{
	public static void main(String []args){
		ThreadEx a1 = new ThreadEx("Thread 1");
		ThreadEx a2 = new ThreadEx("Thread 2");
        a1.start();
        a2.start();
	}
}

/*OUTPUT:-
Thread 1 Printing Odd Number: 1
Thread 1 Printing Odd Number: 3
Thread 1 Printing Odd Number: 5
.
.
.
Thread 1 Printing Odd Number: 45
Thread 2 Printing Even Number: 2
.
.
Thread 1 Printing Odd Number: 199
Thread 2 Printing Even Number: 162
.
.
Thread 2 Printing Even Number: 200

 */