import java.util.*;

public class Main {


    public static void main(String[] args)  {
        int N;
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        sc.nextLine();
        String[] arr = new String[N];

        for(int i = 0; i < N; i++){
            arr[i] = sc.nextLine();
        }
        Character[] arr2 = new Character[arr[0].length()];
        for(int i=0;i<arr[0].length();i++){
            for(int j=0; j<N; j++){
                if(arr[j].charAt(i) != arr[0].charAt(i)){
                    arr2[i] = '?';
                    break;
                }
                arr2[i] = arr[0].charAt(i);
            }
        }

        for(int i=0; i<arr[0].length(); i++){
            System.out.print(arr2[i]);
        }

    }
}
