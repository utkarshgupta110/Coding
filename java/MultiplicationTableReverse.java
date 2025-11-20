import java.util.Scanner;
public class MultiplicationTableReverse {
    public static void main(String[] args) {
        Scanner sc =new Scanner(System.in);
        System.out.print("enter a no. for multiplication: ");
        int num =sc.nextInt();
        System.out.print("enter how many times a no. to be multiplicated: ");
        int n =sc.nextInt();
        for(int i=n;i>0;i--){
            if(i==n-num){
                System.out.println("I can't multiply for "+i+" Sorry!");
                continue; // control is not transfer to ||System.out.println(num+" X "+i+" = "+num*i);|| if the condition is met.
            }
            System.out.println(num+" X "+i+" = "+num*i);   
        }
    }
}
