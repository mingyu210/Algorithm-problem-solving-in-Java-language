import java.util.*;

public class Main {

    public static int T;
    public static int H;
    public static int W;
    public static int N;


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        T = sc.nextInt();
        for(int i=0; i<T; i++) {
            H = sc.nextInt();
            W = sc.nextInt();
            N = sc.nextInt();
            int answer = 0;
            for(int j=1; j<=W; j++) {
                for(int k=1; k<=H; k++) {
                    answer++;
                    if(answer == N){
                        String str1 = Integer.toString(k);
                        String str2 = Integer.toString(j);
                        if(str2.length() == 1) {
                            str2 = "0" + str2;
                        }
                        System.out.println(str1 + str2);
                        break;
                    }
                }
            }

        }


    }
}
