import java.util.*;

public class Main {
    static public int answer = 0;
    static public int N;
    static public int M;
    static boolean[] visited;
    static boolean[] visited2;
    static Vector<Integer> arr = new Vector<>();
    static Vector<Vector<Integer>> brr = new Vector<>();

    static public boolean flea(int a, int b){
        return brr.get(b).contains(a);
    }

    static public void bfs(){
        Queue<Integer> q = new LinkedList<>();
        visited = new boolean[M];
        visited2 = new boolean[N+1];
        answer = 0;

        for(int i = 0; i < arr.size(); i++){
            q.add(arr.get(i));
            visited2[arr.get(i)] = true;
        }
        while(!q.isEmpty()){
            int x = q.poll();
            for(int i = 0; i < M; i++){
                if(!visited[i] && flea(x,i)){
                    answer++;
                    visited[i] = true;
                    for(int j = 0; j < brr.get(i).size(); j++){
                        int y = brr.get(i).get(j);
                        if(!visited2[y]){
                            q.add(y);
                            visited2[y] = true;
                        }
                    }
                }
            }
        }

    }



    public static void main(String[] args)  {
      Scanner sc = new Scanner(System.in);
      N = sc.nextInt();
      M = sc.nextInt();
      int k = sc.nextInt();
      if(k == 0){
          System.out.println(M);

      }
      else{
          for(int i = 0; i < k; i++){
              int u = sc.nextInt();
              arr.add(u);
          }
          for(int i = 0; i < M; i++){
              brr.add(new Vector<>());
              int l = sc.nextInt();
              for(int j = 0; j < l; j++){
                  int z = sc.nextInt();
                  brr.get(i).add(z);
              }
          }
          bfs();

          System.out.println(M - answer);


      }
      sc.close();
      
    }
}
