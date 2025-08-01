import java.util.Scanner;

public class LinearSearchArray{
		public static void main(String[] args){
				int[] array = {123,131,415,15,1,5,16,115,1,1515};
				Scanner inputScanner = new Scanner(System.in);
				System.out.print("Enter number to search for: ");
				int num = inputScanner.nextInt();
				inputScanner.close();

				for (int i=0; i<10; i++){
						if (array[i]==num) System.out.println("Found at "+i+" position");
				}
		}
}
