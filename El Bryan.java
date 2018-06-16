/*
*	User: Isanchez_Aguilar
*	Problem: omegaUp El Bryan
*/
import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		BigInteger n = in.nextBigInteger();
		BigInteger factorial = new BigInteger("1");

		while (!n.equals(BigInteger.ZERO)) {
			factorial = factorial.multiply(n);
			n = n.subtract(BigInteger.ONE);
		}

		System.out.println(factorial);
	}
}