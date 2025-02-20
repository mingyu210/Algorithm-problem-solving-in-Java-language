import java.util.*;

public class Main {

    static public int n;
    static Integer[][] grid;
    static int blueAnswer = 0;
    static int whiteAnswer = 0;

    static public void direction(int a, int b,int n){
        boolean flag = true;
        int color = grid[a][b];
        for(int i=a;i< a+n;i++){
            for(int j=b;j< b +n;j++){
                if(grid[i][j]!=color){
                    flag = false;
                }
            }
        }
        if(flag && grid[a][b] == 1){
            blueAnswer += 1;
            return;
        }
        else if(flag && grid[a][b] == 0){
            whiteAnswer += 1;
            return;
        }
        else{
            direction(a, b, n/2);              // 왼쪽 위
            direction(a, b + n/2, n/2);     // 오른쪽 위
            direction(a+ n/2, b, n/2);     // 왼쪽 아래
            direction(a + n/2, b + n/2, n/2);
        }




    }

    public static void main(String[] args)  {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        grid = new Integer[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                grid[i][j] = sc.nextInt();
            }
        }
        direction(0,0,n);
        System.out.println(whiteAnswer);
        System.out.println(blueAnswer);


    }
}
