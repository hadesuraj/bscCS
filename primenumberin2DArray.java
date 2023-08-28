import java.util.*;
public class prime2D{
    static boolean isPrime(int n){
    if(n <= 1)
        return false;
    if(n <= 3)
        return true;
    if(n % 2 == 0 || n % 3 == 0)
        return false;
    
    for(int i = 5; i * i <= n; i += 6){
        if(n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n1 = sc.nextInt();
        int n2 = sc.nextInt();
        int arr[][] = new int[n1][n2];
        System.out.println("Enter the elements of 2D array: ");
        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++)
            {
                arr[i][j]=sc.nextInt();
            }
        }
        System.out.println("The Elements are: ");
        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++)
            {
                System.out.print(arr[i][j]+" ");
            }
        }
        System.out.println();
        System.out.println("The prime numbers in the 2D array are: ");
        for(int row = 0;row<arr.length;row++){
            for(int col = 0;col<arr[row].length;col++){
                if(isPrime(arr[row][col])){
                    System.out.println(arr[row][col]+" at position "+ row+","+col+" ");
                }
            }
        }
    }
}

/*
Output:
2 
2
Enter the elements of 2D array: 2 4 5 8
The Elements are: 
2 4 5 8 
The prime numbers in the 2D array are: 
2 at position 0,0 
5 at position 1,0 
*/
