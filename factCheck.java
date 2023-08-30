import java.util.*;
import java.util.Scanner;
class IndexOutOfBoundsException extends Exception{
	public IndexOutOfBoundsException(){
		System.out.println("Exception Occured "+this+" input exceeded range");
	}
}
public class factCheck
{
	public static int factorial(int n){
		if(n==0 || n==1) return n;
		else
			return n * factorial(n-1);
	}
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		int n;
		try{
			n = sc.nextInt();
			if(n<0 || n>9)
				throw new IndexOutOfBoundsException();
			else
			System.out.println("Factorial of "+n+" is: "+factorial(n));
		}
		catch(Exception e){
			System.out.println("WRONG INPUT");
		}
		finally{
			sc.close();
		}
	}
}
