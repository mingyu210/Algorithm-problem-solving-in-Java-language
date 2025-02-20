import java.util.*;

public class Main {

    static public int[][] graph;
    static boolean[] visited;

    static public void dfs(int a){
        System.out.print(a + " ");
        visited[a] = true;
        for(int v = 1; v < graph.length; v++){
            if(graph[a][v] != 0 && !visited[v]){
                dfs(v);
            }
        }
    }

    static public void bfs(int a){
        boolean[] visited2 = new boolean[graph.length];
        visited2[a] = true;
        Queue<Integer> q = new LinkedList<>();
        q.add(a);
        while(!q.isEmpty()){
            int v = q.poll();
            System.out.print(v + " ");
            for(int w = 1; w < graph.length; w++){
                if(graph[v][w] != 0 && !visited2[w]){
                    visited2[w] = true;
                    q.add(w);
                }
            }
        }
    }

    public static void main(String[] args)  {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int v = sc.nextInt();
        graph = new int[n+1][n+1];

        for(int i = 0; i < m; i++){
            int a = sc.nextInt();
            int b = sc.nextInt();
            graph[a][b] = 1;
            graph[b][a] = 1;
        }

        visited = new boolean[n+1];

        dfs(v);
        System.out.println();
        bfs(v);

        sc.close();
    }
}
