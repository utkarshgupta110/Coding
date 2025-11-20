import java.util.Scanner;
public class Factorial {
    public static void main(String[] args) {
        Scanner sc =new Scanner(System.in);
        System.out.print("enter a no. for calculating its factorial: ");
        long num =sc.nextLong();
        long fact=1;
        for(int i=0;i<num;i++){ //for(int i=1;i<=num;i++)
            fact*=num-i; //fact*=i;
        }
    System.out.println("The factorial of "+num+" is: "+fact);
}
}
