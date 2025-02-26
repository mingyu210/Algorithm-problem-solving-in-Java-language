import java.util.*;

public class Main {

   static public int N;
   static public String M;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        sc.nextLine();
        M = sc.nextLine();
        int answer = 0;
        for (int i = 0; i < N; i++) {
           answer += (M.charAt(i) - '0');
        }
        System.out.println(answer);
        sc.close();

    }
}
