import java.util.Scanner;


public class Main {
    static boolean [][] arr = new boolean[101][101];
    static boolean [] visited = new boolean[101];
    static int answer = 0;

    static void dfs(int s) {
        visited[s] = true;
        for(int i=1; i<=100; i++){
            if(arr[s][i] && !visited[i]){
                dfs(i);
                answer++;
            }
        }
    }



    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        for(int i=0; i<m; i++){
            int x,y;
            x = scanner.nextInt();
            y = scanner.nextInt();
            arr[x][y] = true;
            arr[y][x] = true;
        }

        dfs(1);
        System.out.println(answer);

    }
}
