import java.util.Scanner;

public class SumOfNaturalNums{
		public static void main(String[] args){
				Scanner inputScanner = new Scanner(System.in);
				System.out.print("Enter a num:");
				int limit = inputScanner.nextInt();
				inputScanner.close();
				int total = 0;
				for (int i=0; i <= limit; i++){
						total = total + i;
				}
				System.out.println("Sum of natural numbers till "+limit+" is "+total);
		}
}
