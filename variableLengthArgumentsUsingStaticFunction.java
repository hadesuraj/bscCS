import java.util.*;
public class variableLengthArgumentsUsingStaticFunction{
    public static void fun(int...a){
        System.out.println("Number of variable arguments: "+a.length);
        for(int i: a){
            System.out.print(i+" ");
        }
        System.out.println();
    }
    public static void main(String args[]){
            fun(1,2,3,4);
            fun();
            fun(100);
    }
}
