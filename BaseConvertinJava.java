import java.util.Scanner;

public class NumberBaseConvert{

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        // Get input base
        System.out.print("Enter input base (between 2 and 10): ");
        int inputBase = sc.nextInt();
        if (inputBase < 2 || inputBase > 10) {
            System.out.println("Invalid input base.");
            return;
        }
        // Get output base
        System.out.print("Enter output base (between 2 and 10): ");
        int outputBase = sc.nextInt();
        if (outputBase < 2 || outputBase > 10) {
            System.out.println("Invalid output base.");
            return;
        }
        // Get integer value in input base
        System.out.print("Enter an integer value in base " + inputBase + ": ");
        String inputValue = sc.next();
        try {
            // Convert input value to decimal (base 10)
            int decimalValue = Integer.parseInt(inputValue, inputBase);
            // Convert decimal value to output base
            String outputValue = Integer.toString(decimalValue, outputBase);
            // Display the result
            System.out.println("Result in base " + outputBase + ": " + outputValue);
        } catch (NumberFormatException e) {
            System.out.println("Invalid input value.");
        }
        finally {
            System.out.println("Program Exit");
        }
    }
}
/*
Output:
Enter input base (between 2 and 10): 8
Enter output base (between 2 and 10): 2
Enter an integer value in base 8: 71
Result in base 2: 111001
Program Exit
*/
