//Practical 4: add two 3x3 matrices
package Java.pr4; //line important for code to work in VS Code
import java.util.Scanner;

public class App {
    public static void main(String[] args) {
        Scanner inp = new Scanner(System.in);
        int[][] A = new int [3][3];
        int[][] B = new int [3][3];
        int[][] C = new int [3][3];

        System.out.println("Enter  elements of first matrix (A):");
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                System.out.print("A "+i+" "+j+":");
                A[i][j] = inp.nextInt();
            }   
        }
        System.out.println("\nEnter elements of second matrix (B):");
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                System.out.print("B "+i+" "+j+":");
                B[i][j] = inp.nextInt();
            }   
        }

        inp.close(); //closing the Scanner object 'inp'

        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                C[i][j] = A[i][j] + B[i][j];
            }   
        }

        System.err.println("Sum of matrices:- ");
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                System.out.print(C[i][j]+" ");
            } 
            System.out.println();  
        }

    }
    
}
