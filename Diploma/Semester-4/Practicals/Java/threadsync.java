class Counter {
    private int count = 0;

    // Synchronized method to ensure only one thread can access it at a time
    public synchronized void increment() {
        count++;
    }

    public int getCount() {
        return count;
    }
}

public class threadsync {
    public static void main(String[] args) {
        Counter counter = new Counter();

        // Create two threads that increment the counter using anonymous inner classes
        Thread t1 = new Thread(new Runnable() {
            public void run() {
                for (int i = 0; i < 1000; i++) {
                    counter.increment();
                }
            }
        });

        Thread t2 = new Thread(new Runnable() {
            public void run() {
                for (int i = 0; i < 1000; i++) {
                    counter.increment();
                }
            }
        });

        // Start both threads
        t1.start();
        t2.start();

        // Wait for both threads to finish
        try {
            t1.join();
            t2.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        // Print the final count
        System.out.println("Final count: " + counter.getCount());
    }
}
