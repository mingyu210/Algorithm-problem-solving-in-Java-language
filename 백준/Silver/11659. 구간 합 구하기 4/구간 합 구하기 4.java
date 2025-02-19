import java.util.*;

public class Main {
    static int[] arr;
    static int addNum = 0;
    static int addsum = 0;
    static public Integer add(int a, int b) {
        int answer = 0;
        for(int i=a-1; i<b; i++){
            answer += arr[i];
        }
        return answer;
    }
    static public Integer sub(int a, int b) {
        int answer = 0;
        for(int i=0; i<a-1; i++){
            addNum -= arr[i];
        }
        for(int i=b; i<arr.length; i++){
            addNum-=arr[i];
        }
        return addNum;
    }



    public static void main(String[] args)  {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();
        sc.nextLine();

        arr = new int[N];
        for(int i = 0; i < N; i++){
            arr[i] = sc.nextInt();
            addsum += arr[i];
        }
        sc.nextLine();
        for(int i = 0; i < M; i++){
            addNum = addsum;
            int a = sc.nextInt();
            int b = sc.nextInt();
            if((b-a) < (N/2)){
                System.out.println(add(a,b));
            }
            else{
                System.out.println(sub(a,b));
            }

        }

    }
}
