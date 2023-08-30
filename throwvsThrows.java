//throw vs throws keyword
import java.util.*;
class negativeRadiusException extends Exception{
	//@override
	public String toString(){
		return "Radius cannot be negative";
	}
	
	//@override
	public String getMessage(){
		return "Radius cannot be negative";
	}
}

public class throwvthrows
{
	public static double area(int r) throws negativeRadiusException{
		if(r<0){
			throw new negativeRadiusException();
		}
		double res = Math.PI * r * r;
		return res;
	}	
	
	public static int divide(int a,int b) throws ArithmeticException{
		//made by suraj
		int res=a/b;
		return res;
	}
	
	public static void main(String args[])
	{
		 Scanner sc = new Scanner(System.in);
		 int r, a, b;
		 System.out.println("Enter the radius, a and b:");
		 r=sc.nextInt();
		 a=sc.nextInt();
		 b=sc.nextInt();
		
		//user prithiraj
		try{
			int c=divide(a,b);
			System.out.println("Result: "+c);
		}
		catch (Exception e){
			System.out.println("EXCEPTION");
		}
		
		try{
			double ar = area(r);
			System.out.println("Result: "+ar);
		}
		catch(Exception e){
			System.out.println("EXCEPTION 2");
		}
	}	
}
