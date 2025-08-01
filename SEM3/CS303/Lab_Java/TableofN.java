import java.util.Scanner;

public class TableofN{
		public static void main(String[] args){
				Scanner inputScanner = new Scanner(System.in);
				System.out.print("Enter a number: ");
				int num = inputScanner.nextInt();
				inputScanner.close();
				for (int i = 1; i <= num; i++){
						System.out.println(num+" x "+i+" = "+i*num);
				}
		}
}
