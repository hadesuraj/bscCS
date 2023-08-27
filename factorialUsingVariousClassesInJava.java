import java.io.*;
import java.util.*;

public class factorialUsingVariousClasses {
    public static int factorial(int n) {
        if (n == 0 || n == 1)
            return 1;
        else
            return n * factorial(n - 1);
    }

    public static void main(String args[]) throws IOException {
        Scanner sc = new Scanner(System.in);
        int num1 = sc.nextInt();

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int num2 = Integer.parseInt(br.readLine());

        DataInputStream dis = new DataInputStream(System.in);
        int num3 = Integer.parseInt(dis.readLine());

        int fact1 = factorial(num1);
        int fact2 = factorial(num2);
        int fact3 = factorial(num3);

        System.out.println("Factorial of " + num1 + " is: " + fact1);
        System.out.println("Factorial of " + num2 + " is: " + fact2);
        System.out.println("Factorial of " + num3 + " is: " + fact3);
    }
}
