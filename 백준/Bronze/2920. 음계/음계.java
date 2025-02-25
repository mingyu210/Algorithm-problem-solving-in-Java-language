import java.util.*;

public class Main {
    static public int[] arr = new int[8];

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        boolean flag = true;
        for(int i = 0; i < 8; i++) {
            arr[i] = sc.nextInt();

        }

        if(arr[0] == 1){
            for(int i = 1; i < 8; i++) {
                if(arr[i] != arr[i-1] + 1){
                    System.out.println("mixed");
                    return;
                }
            }
            System.out.println("ascending");
        }
        else if(arr[0] == 8){
            for(int i = 1; i < 8; i++) {
                if(arr[i] != arr[i-1] - 1){
                    System.out.println("mixed");
                    return;
                }
            }
            System.out.println("descending");
        }
        else{
            System.out.println("mixed");
        }
        sc.close();



    }
}
