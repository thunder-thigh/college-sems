import java.util.Scanner;

public class PositiveNegativeCheck {
		public static void main(String[] args){							
				Scanner inputScanner = new Scanner(System.in);
				System.out.println("Enter a num");
				int num = inputScanner.nextInt();
				if (num>0) System.out.println("Positive num");
				else if (num<0) System.out.println("Negative number");
				else System.out.println("You entered Zero!");
				inputScanner.close();
		}
}
