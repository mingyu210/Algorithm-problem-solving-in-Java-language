import java.util.*;

public class Main {

    static public int H;
    static public int M;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        H = sc.nextInt();
        M = sc.nextInt();

        if(M - 45 > 0){
            System.out.println(H + " " + (M - 45));
        }
        else if(M - 45 < 0){
            if(H == 0){
                System.out.println(23 + " " + (M - 45 + 60));
            }
            else{
                System.out.println((H-1) + " " + (M-45 + 60));
            }
        }
        else{
            System.out.println(H + " " + 0);
        }


    }
}
