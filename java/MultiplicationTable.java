import java.util.Scanner;
public class MultiplicationTable {
    public static void main(String[] args) {
        Scanner sc =new Scanner(System.in);
        System.out.print("enter a no. for multiplication: ");
        int num =sc.nextInt();
        System.out.print("enter how many times a no. to be multiplicated: ");
        int n =sc.nextInt();
        int i =1;
        /*while(i<=n){
            System.out.println(num+" X "+i+" = "+num*i);    
            i++; 
        }
    }
}*/
// sum of resultant multiplication table
        int sum =0;
        while(i<=n){
            System.out.println(num+" X "+i+" = "+num*i); 
            sum = sum + num*i;
            System.out.println("The sum is: "+sum);
            i++;
        }
        System.out.println("The overall sum is: "+sum);
    }
}
