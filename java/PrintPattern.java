import java.util.Scanner;
public class PrintPattern {
    public static void main(String[] args) {
        Scanner sc =new Scanner(System.in);
        System.out.print("enter no. of rows for pattern: ");
        int n=sc.nextInt();
        System.out.print("enter symbol for pattern: ");
        String symbol=sc.next();
        //using for loop
        /*for(int i=n;i>0;i--){
            for(int j=0;j<i;j++){
                System.out.print(symbol+"\t");
            }
            System.out.println("\n");
       }
    }
}*/
         //using while loop
         int i=n;
         while(i>0){
            int j=0;
            while(j<i){
                System.out.print(symbol+"\t");
                j++;
            }
            System.out.println("\n");
            i--;
      }          
   }
}


