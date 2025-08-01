import java.util.Scanner;

public class CheckAdultOrNot{
		public static void main(String[] args){
				Scanner inputScanner = new Scanner(System.in);
				System.out.print("Enter your age: ");
				int age = inputScanner.nextInt();
				if (age>=18) System.out.println("Adult");
				else System.out.println("Underage");

				inputScanner.close();
		}
}
