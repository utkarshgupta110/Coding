import java.util.Scanner;
public class SumOfEvenNumbers {
    public static void main(String[] args) {
        Scanner sc =new Scanner(System.in);
        System.out.print("enter amount of even nos. to be added: ");
        int n =sc.nextInt();
        int sum =0;
        int i =1;
        while(i<=n){
            sum+= 2*i;
            i++;
        }
        System.out.println("sum of first "+n+" even nos. is: "+sum);
    }  
}
