import java.util.Scanner;

public class PercentageCalculator {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter your full marks: ");
        float fullMarks = sc.nextInt();
        System.out.print("Enter total number of subjects: ");
        float totalSubjects = sc.nextInt();
        float totalMarks = 0f;
        for(int i=1; i<=totalSubjects; i++){
            System.out.print("Enter marks in Subject "+i+": ");
            float marks = sc.nextInt();
            totalMarks = totalMarks+marks;
        }
        float totalFullMarks = fullMarks*totalSubjects;
        float percentage = (totalMarks/totalFullMarks)*100;
        System.out.println("Your total percentage is : "+percentage+"%");
        sc.close();

    }
}