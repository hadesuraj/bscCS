class Thread1 implements Runnable{
	public void run(){
		for(int i=0;i<5;i++)
			System.out.println("Thread 1 running");
			try{Thread.sleep(5);}
			catch(Exception e){}
	}
}

class Thread2 implements Runnable{
	public void run(){
		for(int i=0;i<5;i++)
			System.out.println("Thread 2 running");
			try{Thread.sleep(5);}
			catch(Exception e){}
	}
}

public class demoThread{
	public static void main(String args[]){
		Runnable ob1 = new Thread1();
		Runnable ob2 = new Thread2();
		
		
		Thread t1 = new Thread(ob1);
		Thread t2 = new Thread(ob2);
		
		t1.start();
		try{Thread.sleep(1);}
		catch(Exception e){}
		t2.start();
	}
}
