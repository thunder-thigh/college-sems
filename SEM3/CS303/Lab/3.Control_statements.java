import java.util.Scanner;

public class ControlStatements{
		public static void main(String[] args){
				Scanner sc = new Scanner(System.in);

				//if-else
				System.out.println("Enter a number: ");
				int number = sc.nextInt();
				if (number>0) System.out.println("Number is +ve");
				else if (number<0) System.out.println("Number is -ve");
				else System.out.println("Number is 0");


				//switch-case
				System.out.println("Enter a grade (A/B/C)");
				char grade = sc.next().charAt(0);
				switch(grade){
						case 'A':
								System.out.println("Excellent grade");
								break;
						case 'B':
								System.out.println("Good grade");
								break;
						case 'C':
								System.out.println("Satisfactory grade");
								break;
						default:
								System.out.println("Invalide grade");
								break;
				}

				//for loop
				for (int i=0; i<5; i++){
						System.out.println("Printing loop "+i+" iteration");
				}
				System.out.println();

				//do while loop
				int i=0;
				do{
						System.out.println("Printing loop "+i+" iteration");
						i++;
				}while(i<5);
				System.out.println();

				//break and continue
				for (i=0; i<30; i++){
						if (i%2!=0) continue;
						System.out.println(i);
						if (i==24) break;
				}
				sc.close();
		}
}

