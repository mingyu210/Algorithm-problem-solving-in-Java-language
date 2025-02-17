import java.util.*;

public class Main {

    static char[][] grid;
    static int answer = 10000;

    static public int white(int a, int b){
        char[][] board = new char[8][8];
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                if((j+i)%2 == 0){
                    board[i][j] = 'W';
                }
                else{
                    board[i][j] = 'B';
                }
            }
        }
        int diff = 0;
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                if(grid[i+a][j+b] != board[i][j]){
                    diff++;
                }
            }
        }
        return diff;
    }

    static public int black(int a, int b){
        char[][] board = new char[8][8];
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                if((j+i)%2 == 0){
                    board[i][j] = 'B';
                }
                else{
                    board[i][j] = 'W';
                }
            }
        }
        int diff = 0;
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                if(grid[i+a][j+b] != board[i][j]){
                    diff++;
                }
            }
        }
        return diff;
    }



    public static void main(String[] args)  {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        sc.nextLine();

        grid = new char[n][m];
        for(int i = 0; i < n; i++){
            String line = sc.nextLine();
            for(int j = 0; j < m; j++){
                grid[i][j] = line.charAt(j);
            }

        }
        for(int i = 0; i < n-7; i++){
            for(int j = 0; j < m-7; j++){
                int whiteAnswer = white(i, j);
                int blackAnswer = black(i, j);
                if(whiteAnswer > blackAnswer){
                    if(answer > blackAnswer){
                        answer = blackAnswer;
                    }
                }
                else{
                    if(answer > whiteAnswer){
                        answer = whiteAnswer;
                    }
                }
            }
        }
        System.out.println(answer);
        sc.close();

    }
}
