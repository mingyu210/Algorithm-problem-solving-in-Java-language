#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 100001;
const int LOG = 18; // 0..17 사용 -> 2^17 = 131072 >= 100000

int N;
int M;
vector<int> tree[MAX];
int depth[MAX];
int parent[LOG][MAX];

void solveDepth() {
    // visited 초기화
    static bool visited[MAX];
    memset(visited, 0, sizeof(visited));

    queue<pair<int,int>> q;
    q.push({1, 0});
    visited[1] = true;
    depth[1] = 0; // 루트 깊이 명시적으로 초기화

    while (!q.empty()) {
        int num = q.front().first;
        int dep = q.front().second;
        q.pop();
        for (auto K : tree[num]) {
            if (!visited[K]) {
                depth[K] = dep + 1;
                parent[0][K] = num;
                visited[K] = true;
                q.push({K, dep + 1});
            }
        }
    }
}

void solveParent() {
    // i는 1..LOG-1 까지
    for (int i = 1; i < LOG; i++) {
        for (int j = 1; j <= N; j++) {
            int mid = parent[i - 1][j];
            if (mid == 0) parent[i][j] = 0;
            else parent[i][j] = parent[i - 1][mid];
        }
    }
}

int lca(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);
    int diff = depth[a] - depth[b];

    // depth 맞추기: diff의 비트에 따라 점프
    for (int k = 0; k < LOG; k++) {
        if (diff & (1 << k)) {
            a = parent[k][a];
        }
    }

    if (a == b) return a;

    for (int k = LOG - 1; k >= 0; k--) {
        if (parent[k][a] != parent[k][b]) {
            a = parent[k][a];
            b = parent[k][b];
        }
    }
    return parent[0][a];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 1; i < N; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    // parent 배열 0으로 초기화 (전역이면 이미 0으로 되지만 명시적으로 해도 안전)
    memset(parent, 0, sizeof(parent));

    solveDepth();
    solveParent();

    cin >> M;
    while (M--) {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << '\n';
    }
    return 0;
}
