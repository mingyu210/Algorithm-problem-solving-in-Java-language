import java.util.*;

public class Main {
    static public int[] arr = new int[9];

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int num = 0;
        int answer = 0;
        for(int i = 0; i < 9; i++) {
            arr[i] = sc.nextInt();
            if(arr[i] > answer) {
                answer = arr[i];
                num = i;
            }
        }
        System.out.println(answer);
        System.out.println(num+1);


    }
}
