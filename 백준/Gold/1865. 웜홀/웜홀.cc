#include <iostream>
#include <vector>
#include <cstring>
#include <tuple>
using namespace std;

int T;
int N, M, W; //지점수,도로수,웜홀수
vector<tuple<int, int, int>> edges; //시작점, 도착점, 시간
int dist[501];
bool line;
const int INF = 1e9;

void bellman_ford() {
	fill(dist, dist + N + 1, 0);

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < (int)edges.size(); j++) {
			int from, to, cost;
			tie(from, to, cost) = edges[j];

			if (dist[to] > dist[from] + cost) {
				dist[to] = dist[from] + cost;

				if (i == N) {
					cout << "YES" << '\n';
					return;
				}
			}
		}
	}
	cout << "NO" << '\n';
}



int main() {
	cin >> T;
	while (T--) {
		cin >> N >> M >> W;
		line = false;
		fill(dist, dist + 501, INF);
		edges.clear();
		for (int i = 0; i < M; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			edges.push_back({ a,b,c });
			edges.push_back({ b,a,c });
		}
		for (int i = 0; i < W; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			edges.push_back({ a,b,-c });
		}

		bellman_ford();

	}
}