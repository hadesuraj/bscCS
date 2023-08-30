public class index{
	public static void main(String [] args){
		int arr[]=new int[5];
		try{
			System.out.println(arr[6]);
		}
		catch(Exception e)
		{
			System.out.println("Index out of bound");
		}
	}
}
