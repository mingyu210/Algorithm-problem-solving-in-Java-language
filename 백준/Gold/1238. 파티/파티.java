import java.util.*;

public class Main {

    static public int N,M;
    static public int S,E;
    static public int[][] graph;
    static public int[][] graph2;
    static public int[] dist;
    static public int[] dist2;
    static public boolean[] visited;
    static public boolean[] visited2;

    public static void dijkstra(int a){
        dist = new int[1001];
        visited = new boolean[1001];
        Arrays.fill(dist,Integer.MAX_VALUE);
        dist[a] = 0;

        for(int i=1; i<=N; i++){
            int min_index = -1;
            for(int j=1; j<=N; j++){
                if(visited[j]){
                    continue;
                }
                if(min_index == -1 || dist[j] < dist[min_index]){
                    min_index = j;
                }
            }
            if (min_index == -1) break;
            visited[min_index] = true;
            for(int j=1; j<=N; j++){
                if(graph[min_index][j] == -1){
                    continue;
                }
                dist[j] = Math.min(dist[j], dist[min_index] + graph[min_index][j]);
            }
        }
    }
    public static void dijkstra2(int a){
        dist2 = new int[1001];
        visited2 = new boolean[1001];
        Arrays.fill(dist2,Integer.MAX_VALUE);
        dist2[a] = 0;

        for(int i=1; i<=N; i++){
            int min_index = -1;
            for(int j=1; j<=N; j++){
                if(visited2[j]){
                    continue;
                }
                if(min_index == -1 || dist2[j] < dist2[min_index]){
                    min_index = j;
                }
            }
            if (min_index == -1) break;
            visited2[min_index] = true;
            for(int j=1; j<=N; j++){
                if(graph2[min_index][j] == -1){
                    continue;
                }
                dist2[j] = Math.min(dist2[j], dist2[min_index] + graph2[min_index][j]);
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        graph = new int[1001][1001];
        graph2 = new int[1001][1001];
        for (int i = 0; i < 1001; i++) {
            Arrays.fill(graph[i], -1);
            Arrays.fill(graph2[i], -1);
        }


        N = sc.nextInt();
        M = sc.nextInt();
        S= sc.nextInt();
        for(int i=0; i<M; i++){
            int x,y,z;
            x = sc.nextInt();
            y = sc.nextInt();
            z = sc.nextInt();
            if(graph[y][x] == -1 || graph[y][x] > z){
                graph[y][x] = z;
            }
            if(graph2[x][y] == -1 || graph2[x][y] > z){
                graph2[x][y] = z;
            }


        }


        dijkstra(S);
        dijkstra2(S);
        int minAnswer = 0;
        for(int i=1; i<=N; i++){
            int ku = dist[i] + dist2[i];
            minAnswer = Math.max(minAnswer, ku);
        }
        System.out.println(minAnswer);

    }
}
