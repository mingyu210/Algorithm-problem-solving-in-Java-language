import java.util.*;

public class Main {
    static public int N, M;
    static public ArrayList<Integer> arr = new ArrayList<>();
    static public ArrayList<Integer> answer = new ArrayList<>();
    static public boolean[] visited;

    static public void backTracking(int k) {
        if (k == M) {
            for (Integer i : answer) {
                System.out.print(i + " ");
            }
            System.out.println();
            return;
        }

        Integer lastUsed = null;
        for (int i = 0; i < arr.size(); i++) {
            if (!visited[i] && !Objects.equals(lastUsed, arr.get(i))) {  // 중복 방지
                visited[i] = true;
                answer.add(arr.get(i));
                lastUsed = arr.get(i);
                backTracking(k + 1);
                answer.remove(answer.size() - 1);
                visited[i] = false;
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        visited = new boolean[N];

        for (int i = 0; i < N; i++) {
            arr.add(sc.nextInt());
        }

        Collections.sort(arr);  // 정렬 필수
        backTracking(0);
    }
}
