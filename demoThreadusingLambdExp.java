//Running two threads concurrently

public class demoThread{
	public static void main(String args[]){
		Thread t1 = new Thread(()->
		{
			for(int i=0;i<5;i++){
				System.out.println("Thread 1 running");
				try{Thread.sleep(5);}
				catch(Exception e){}
			}
		});
		Thread t2 = new Thread(()->
		{
			for(int i=0;i<5;i++){
				System.out.println("Thread 2 running");
				try{Thread.sleep(5);}
				catch(Exception e){}
			}
		});
		
		t1.start();
		try{Thread.sleep(2);}
		catch(Exception e){}
		t2.start();
	}
}
/*
Thread 1 running
Thread 2 running
Thread 1 running
Thread 2 running
Thread 1 running
Thread 2 running
Thread 1 running
Thread 2 running
Thread 1 running
Thread 2 running
*/
