import java.util.Arrays;
import java.util.Scanner;
import java.util.Vector;


public class Main {

    static int n,m;
    static int[] arr;
    static int[] brr;


    public static int binarySearch(int num){
        int left = 0;
        int right = n-1;
        while(left <= right){
            int mid = (left + right)/2;
            if(num == arr[mid]){
                return 1;
            }
            if(num < arr[mid]){
                right = mid-1;
            }
            else if(num > arr[mid]){
                left = mid+1;
            }
        }
        return 0;
    }


    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        arr = new int[n];

        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }
        m = scanner.nextInt();
        brr = new int[m];
        for (int i = 0; i < m; i++) {
            brr[i] = scanner.nextInt();
        }
        Arrays.sort(arr);
        Vector<Integer> v = new Vector<>();
        for(int i=0;i<m;i++){
            v.add(binarySearch(brr[i]));
        }

        for(Integer i : v){
            System.out.print(i + " ");
        }

    }
}
