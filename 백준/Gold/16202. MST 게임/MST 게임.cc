#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int N, M, K;
int arr[1001][1001];
int answer;

void prim() {
	tuple<int, int, int> del = { 1e9,1,1 };
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	vector<bool> visited(N + 1, false);
	pq.push({ 0,1 }); //비용, 시작점

	while (!pq.empty()) {
		int cost = pq.top().first;
		int end = pq.top().second;
		pq.pop();
		if (visited[end]) {
			continue;
		}
		visited[end] = true;
		answer += cost;
		for (int i = 1; i <= N; i++) {
			if (arr[end][i] != 0 && !visited[i]) {
				pq.push({ arr[end][i],i });
				if (get<0>(del) > arr[end][i]) {
					del = { arr[end][i],end,i };
				}
			}
		}
		
	}
	int x, y, z;
	tie(x, y, z) = del;
	arr[y][z] = 0;
	arr[z][y] = 0;
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			answer = 0;
		}
	}

}

int main() {
	cin >> N >> M >> K;
	for (int i = 1; i <= M; i++) {
		int a, b;
		cin >> a >> b;
		arr[a][b] = i;
		arr[b][a] = i;
	}

	for (int i = 0; i < K; i++) {
		prim();
		if (answer == 0) {
			for (int j = i; j < K; j++) {
				cout << 0 << " ";
			}
			break;
		}
		cout << answer << " ";
		answer = 0;
	}

}