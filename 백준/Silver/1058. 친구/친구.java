import java.util.Scanner;

public class Main {
    static int[][] arr = new int[51][51];
    static boolean[][] visited = new boolean[51][51];

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        for(int i = 0; i < N; i++) {
            String str = scanner.next();
            for(int j = 0; j < N; j++) {
                if(str.charAt(j) == 'Y') {
                    arr[i][j] = 1;
                }
            }
        }
        int minAnswer = 0;
        int answer = 0;
        for(int i = 0; i < N; i++) {
            minAnswer = 0;
            for(int j = 0; j < N; j++) {
               if(arr[i][j] == 1 && i !=j) {
                   visited[i][j] = true;
                   minAnswer++;
               }
               else if(i != j){
                   for(int k = 0; k < N; k++) {
                       if(arr[i][k] == 1 && arr[k][j] == 1 && !visited[i][j])  {
                           minAnswer++;
                           visited[i][j] = true;
                       }
                   }
               }
            }
            if(minAnswer > answer) {
                answer = minAnswer;
            }
        }
        System.out.println(answer);

    }
}
