import java.util.Scanner;
import java.util.StringTokenizer;


public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine();
        scanner.close();
        StringTokenizer tokenizer = new StringTokenizer(input);
        int answer = tokenizer.countTokens();
        System.out.println(answer);




    }
}
