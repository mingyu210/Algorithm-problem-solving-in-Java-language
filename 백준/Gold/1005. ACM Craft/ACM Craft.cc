#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int T, N, K, W;
int values[1001];
int indegree[1001];
long long dp[1001];
vector<int> graph[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    while (T--) {
        for (int i = 1; i <= 1000; i++) {
            graph[i].clear();
            indegree[i] = 0;
            dp[i] = 0;
            values[i] = 0;
        }

        cin >> N >> K;

        for (int i = 1; i <= N; i++) {
            cin >> values[i];
        }

        for (int i = 0; i < K; i++) {
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b); //a를 해야 b를 할 수 있다
            indegree[b]++;
        }

        cin >> W;

        queue<int> q;

        for (int i = 1; i <= N; i++) {
            if (indegree[i] == 0) {
                q.push(i);
                dp[i] = values[i];
            }
        }

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            for (int next : graph[cur]) {
                dp[next] = max(dp[next], dp[cur] + values[next]);
                indegree[next]--;

                if (indegree[next] == 0) {
                    q.push(next);
                }
            }
        }

        cout << dp[W] << '\n';
    }
}