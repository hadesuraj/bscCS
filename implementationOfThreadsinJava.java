class A {
    public void run() {
        System.out.println("Thread 1");
    }
}

class B {
    public void run() {
        System.out.println("Thread 2");
    }
}

class myThread extends A implements Runnable {
    public void run() {
        for (int i = 0; i < 5; i++) {
            System.out.println("Hi");
            try {
                Thread.sleep(10);
            } catch (Exception e) {
            }
        }
    }
}

class MyThread extends B implements Runnable {
    public void run() {
        for (int i = 0; i < 5; i++) {
            System.out.println("Hello");
            try {
                Thread.sleep(10);
            } catch (Exception e) {
            }
        }
    }
}

public class HelloWorld {
    public static void main(String[] args) {
        myThread myThreadRunnable = new myThread();
        MyThread myThreadRunnable2 = new MyThread();

        Thread t1 = new Thread(myThreadRunnable);
        Thread t2 = new Thread(myThreadRunnable2);

        t1.start();
        try {
            Thread.sleep(5);
        } catch (Exception e) {
        }
        t2.start();
    }
}
