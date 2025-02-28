import java.util.*;

public class Main {

    static public int N, M;
    static public int S, E;
    static public int[][] graph;
    static public long[] dist;
    static public boolean[] visited;
    static final int INF = Integer.MAX_VALUE; 

    public static void dijkstra(int a) {
        dist = new long[N + 1]; 
        visited = new boolean[N + 1];
        Arrays.fill(dist, INF);
        dist[a] = 0;

        for (int i = 1; i <= N; i++) {
            int min_index = -1;
            for (int j = 1; j <= N; j++) {
                if (!visited[j] && (min_index == -1 || dist[j] < dist[min_index])) {
                    min_index = j;
                }
            }
            if (min_index == -1) break;
            visited[min_index] = true;

            for (int j = 1; j <= N; j++) {
                if (graph[min_index][j] != INF) { 
                    dist[j] = Math.min(dist[j], dist[min_index] + graph[min_index][j]);
                }
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();

        graph = new int[N + 1][N + 1]; 
        for (int i = 0; i <= N; i++) {
            Arrays.fill(graph[i], INF); 
        }

        for (int i = 0; i < M; i++) {
            int x = sc.nextInt();
            int y = sc.nextInt();
            int z = sc.nextInt();
            if (graph[x][y] > z) { 
                graph[x][y] = z;
            }
        }

        S = sc.nextInt();
        E = sc.nextInt();

        dijkstra(S);
        System.out.println(dist[E]);
    }
}

