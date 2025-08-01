import java.util.Scanner;

public class InputArray{
		public static void main(String[] args){
				Scanner inputScanner = new Scanner(System.in);
				System.out.println("Start entering numbers");
				int[] array = new int[10];
				for (int i=0; i<10; i++){
						array[i] = inputScanner.nextInt();
				}
				inputScanner.close();
				System.out.println("\n\nArray you entered is:");

				for (int i=0; i<10; i++){
						System.out.println(array[i]);
				}
		}
}
