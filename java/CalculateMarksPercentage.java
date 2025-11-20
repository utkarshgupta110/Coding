import java.util.Scanner;
public class CalculateMarksPercentage{
public static void main(String[] args) {
    Scanner sc= new Scanner(System.in);
    System.out.println("enter subject1 marks out of 100: ");
    float a= sc.nextFloat();
    System.out.println("enter subject2 marks out of 100: ");
    float b= sc.nextFloat();
    System.out.println("enter subject3 marks out of 100: ");
    float c= sc.nextFloat();
    System.out.println("enter subject4 marks out of 100: ");
    float d= sc.nextFloat();
    System.out.println("enter subject5 marks out of 100: ");
    float e= sc.nextFloat();
    float TotalMarks= 500;
    float sum= a+b+c+d+e;
    System.out.println("your total marks is: "+sum);
    float percentage= (sum/TotalMarks)*100;
    System.out.println("overall percentage is: "+percentage+"%");
}
}