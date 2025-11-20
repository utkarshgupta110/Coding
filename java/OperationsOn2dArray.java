import java.util.Scanner;
public class OperationsOn2dArray {
    public static void main(String[] args) {
        Scanner sc =new Scanner(System.in);

        // Program to find the sum of the elements of a 2D array
        System.out.print("enter the no. of rows: ");
        int rows = sc.nextInt();
        System.out.print("enter the no. of columns: ");
        int columns = sc.nextInt();
        int[][] arr = new int[rows][columns];
        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                System.out.print("Enter the element at index arr["+i+"]["+j+"]"+" : ");
                arr[i][j] = sc.nextInt();
            }
        }
        int sum = 0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                sum = sum + arr[i][j];
            }
        }
        System.out.println("The sum of the elements of the array is: "+sum);
        
        // Program to search for an element in a 2D array
        // Approach: 1
        System.out.print("enter the element to be searched: ");
        int search = sc.nextInt();
        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                if(arr[i][j] == search){
                    System.out.println("Element found at index arr["+i+"]["+j+"]");
                    return;
                }
            }
        }
        System.out.println("Element not found");
        // Approach: 2
        System.out.print("enter the element to be searched: ");
        search = sc.nextInt();
        boolean found = false;
        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                if(arr[i][j] == search){
                    found = true;
                    break;
                }
            }
            if(found){
                break;
            }
        }
        if(found){
            System.out.println("Element found");
        }else{
            System.out.println("Element not found");
        }
        
        // Program to find the maximum element in a 2D array
        int max = arr[0][0];
        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                if(arr[i][j] > max){
                    max = arr[i][j];
                }
            }
        }
        System.out.println("The maximum element in the array is: "+max);
        
        // Program to find the minimum element in a 2D array
        int min = arr[0][0];
        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                if(arr[i][j] < min){
                    min = arr[i][j];
                }
            }
        }
        System.out.println("The minimum element in the array is: "+min);

        // Program to find the sum of the elements of the main diagonal of a 2D array
        sum = 0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                if(i == j){
                    sum = sum + arr[i][j];
                }
            }
        }
        System.out.println("The sum of the elements of the main diagonal of the array is: "+sum);

        // Program to find the sum of the elements of the other diagonal of a 2D array
        sum = 0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                if(i+j == rows-1){
                    sum = sum + arr[i][j];
                }
            }
        }
        System.out.println("The sum of the elements of the other diagonal of the array is: "+sum);

        // Program to find the sum of the elements of the upper triangle of a 2D array
        sum = 0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                if(i<=j){
                    sum = sum + arr[i][j];
                }
            }
        }
        System.out.println("The sum of the elements of the upper triangle of the array is: "+sum);

        // Program to find the sum of the elements of the lower triangle of a 2D array
        sum = 0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                if(i>=j){
                    sum = sum + arr[i][j];
                }
            }
        }
        System.out.println("The sum of the elements of the lower triangle of the array is: "+sum);

        // Program to find the sum of the elements of the left diagonal of a 2D array
        sum = 0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                if(i == j){
                    sum = sum + arr[i][j];
                }
            }
        }
        System.out.println("The sum of the elements of the left diagonal of the array is: "+sum);

        // Program to find the sum of the elements of the right diagonal of a 2D array
        sum = 0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                if(i+j == rows-1){
                    sum = sum + arr[i][j];
                }
            }
        }
        System.out.println("The sum of the elements of the right diagonal of the array is: "+sum);

        // Program to find the sum of the elements of the boundary of a 2D array
        sum = 0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                if(i == 0 || j == 0 || i == rows-1 || j == columns-1){
                    sum = sum + arr[i][j];
                }
            }
        }
        System.out.println("The sum of the elements of the boundary of the array is: "+sum);

        // Program to find the average of the elements of a 2D array
        sum = 0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                sum = sum + arr[i][j];
            }
        }
        double average = (double)sum/(rows*columns);
        System.out.println("The average of the elements of the array is: "+average);

        // Program to find the sum of two 2D arrays
        System.out.print("enter the no. of rows of the second array: ");
        int rows2 = sc.nextInt();
        System.out.print("enter the no. of columns of the second array: ");
        int columns2 = sc.nextInt();
        if(rows != rows2 || columns != columns2){
            System.out.println("The sum of the arrays is not possible");
        }else{
            int[][] arr2 = new int[rows2][columns2];
            for(int i=0;i<rows2;i++){
                for(int j=0;j<columns2;j++){
                    System.out.print("Enter the element at index arr2["+i+"]["+j+"]"+" : ");
                    arr2[i][j] = sc.nextInt();
                }
            }
            int[][] sumArr = new int[rows][columns];
            for(int i=0;i<rows;i++){
                for(int j=0;j<columns;j++){
                    sumArr[i][j] = arr[i][j] + arr2[i][j];
                }
            }
            System.out.println("The sum of the arrays is: ");
            for(int i=0;i<rows;i++){
                for(int j=0;j<columns;j++){
                    System.out.print(sumArr[i][j]+" ");
                }
                System.out.println();
            }
        }
        // Program to find the whether the 2D array is sorted or not
        boolean sorted = true;
        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                if(i == 0 && j == 0){
                    continue;
                }
                if(arr[i][j] < arr[i-1][j-1]){
                    sorted = false;
                    break;
                }
            }
            if(!sorted){
                break;
            }
        }
        if(sorted){
            System.out.println("The array is sorted");
        }else{
            System.out.println("The array is not sorted");
        }

        
    }
}

