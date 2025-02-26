import java.util.*;

public class Main {

   static public int N;
   static public int M;
   static public int K;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        String str1 = Integer.toString(N);
        M = sc.nextInt();
        String str2 = Integer.toString(M);
        String str3 = str1 + str2;
        K = sc.nextInt();
        System.out.println(N + M - K);
        System.out.println(Integer.parseInt(str3) - K);

        sc.close();

    }
}
