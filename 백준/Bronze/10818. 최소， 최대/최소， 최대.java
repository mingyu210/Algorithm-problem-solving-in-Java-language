import java.util.*;

public class Main {

   static public int bigAnswer;
   static public int smallAnswer;
   static public int N;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        for (int i = 0; i < N; i++) {
            int k = sc.nextInt();
            if(i==0){
                bigAnswer = k;
                smallAnswer = k;
            }
            else{
                if(bigAnswer < k){
                    bigAnswer = k;
                }
                if(smallAnswer > k){
                    smallAnswer = k;
                }
            }
        }

        System.out.println(smallAnswer + " " + bigAnswer);
        
        sc.close();


    }
}
