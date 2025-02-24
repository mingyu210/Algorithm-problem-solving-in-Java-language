import java.util.*;

public class Main {
    static public int[][] grid;
    static public int[][] new_grid;
    static public int N;
    static public int M;
    static public int R;
    static public int x1;
    static public int y1;
    static public int x2;
    static public int y2;

    public static void diffusion(){
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(grid[i][j] >= 5){
                    if(i-1 >=0 && grid[i-1][j] !=-1){
                        new_grid[i-1][j] += grid[i][j]/5;
                        new_grid[i][j] -= grid[i][j]/5;
                    }
                    if(i+1 < N && grid[i+1][j] !=-1){
                        new_grid[i+1][j] += grid[i][j]/5;
                        new_grid[i][j] -= grid[i][j]/5;
                    }
                    if(j-1 >=0 && grid[i][j-1] !=-1){
                        new_grid[i][j-1] += grid[i][j]/5;
                        new_grid[i][j] -= grid[i][j]/5;
                    }
                    if(j+1 < M && grid[i][j+1] !=-1){
                        new_grid[i][j+1] += grid[i][j]/5;
                        new_grid[i][j] -= grid[i][j]/5;
                    }
                }
            }
        }

    }
    public static void wind() {
        // 위쪽 공기청정기 (반시계 방향)
        for (int i = x1 - 1; i > 0; i--) {
            new_grid[i][0] = new_grid[i - 1][0];
        }
        for (int i = 0; i < M - 1; i++) {
            new_grid[0][i] = new_grid[0][i + 1];
        }
        for (int i = 0; i < x1; i++) {
            new_grid[i][M - 1] = new_grid[i + 1][M - 1];
        }
        for (int i = M - 1; i > 1; i--) {
            new_grid[x1][i] = new_grid[x1][i - 1];
        }
        new_grid[x1][1] = 0;

        // 아래쪽 공기청정기 (시계 방향)
        for (int i = x2 + 1; i < N - 1; i++) {
            new_grid[i][0] = new_grid[i + 1][0];
        }
        for (int i = 0; i < M - 1; i++) {
            new_grid[N - 1][i] = new_grid[N - 1][i + 1];
        }
        for (int i = N - 1; i > x2; i--) {
            new_grid[i][M - 1] = new_grid[i - 1][M - 1];
        }
        for (int i = M - 1; i > 1; i--) {
            new_grid[x2][i] = new_grid[x2][i - 1];
        }
        new_grid[x2][1] = 0;

        // 공기청정기 위치는 항상 -1 유지
        new_grid[x1][0] = -1;
        new_grid[x2][0] = -1;

        // wind()가 끝난 후 grid에 new_grid 반영
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                grid[i][j] = new_grid[i][j];
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        R = sc.nextInt();
        grid = new int[N][M];
        new_grid = new int[N][M];
        int num = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                int l = sc.nextInt();
                if(num == 0 && l == -1){
                    x1 = i;
                    y1 = j;
                    num++;
                }
                else if(num == 1 && l == -1){
                    x2 = i;
                    y2 = j;
                }
                grid[i][j] = l;
                new_grid[i][j] = l;
            }
        }
        for(int i = 0; i < R; i++) {
            diffusion();
            wind();
        }
        int answer = 0;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(grid[i][j] != -1) {
                    answer += grid[i][j];
                }
            }
        }
        System.out.println(answer);

    }
}
