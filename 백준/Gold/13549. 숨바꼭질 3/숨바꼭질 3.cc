#include <iostream>
#include <deque>
using namespace std;

int N, M;
int dist[100001];

void bfs(int start, int end) {
    deque<int> dq;
    for (int i = 0; i <= 100000; i++) dist[i] = 1e9;

    dist[start] = 0;
    dq.push_front(start);

    while (!dq.empty()) {
        int cur = dq.front();
        dq.pop_front();

        if (cur == end) break;


        if (cur * 2 <= 100000 && dist[cur * 2] > dist[cur]) {
            dist[cur * 2] = dist[cur];
            dq.push_front(cur * 2);
        }


        if (cur + 1 <= 100000 && dist[cur + 1] > dist[cur] + 1) {
            dist[cur + 1] = dist[cur] + 1;
            dq.push_back(cur + 1);
        }


        if (cur - 1 >= 0 && dist[cur - 1] > dist[cur] + 1) {
            dist[cur - 1] = dist[cur] + 1;
            dq.push_back(cur - 1);
        }
    }

    cout << dist[end];
}

int main() {
    cin >> N >> M;
    bfs(N, M);
    return 0;
}
