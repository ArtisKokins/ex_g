import java.util.Arrays;
import java.util.Scanner;

public class AlphabeticOrder {

	public static void main(String[] args) {
		String a;
		int i;
		Scanner dati = new Scanner(System.in);
		System.out.println("Ievadi vārdu");
		a = dati.nextLine();
		char[] w = a.toCharArray();
		for (i = 0; i < a.length(); i++) {
			Arrays.sort(w);
			System.out.print(w[i]);
		}
		dati.close();

	}

}
