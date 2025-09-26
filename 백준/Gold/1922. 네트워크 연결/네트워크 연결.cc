#include <iostream>
#include <vector>
#include <queue>


using namespace std;

int N, M;
vector<pair<int, int>> adj[1001];

void prim() {
	bool visited[1001] = { false };
	int count = 0;
	int total = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	pq.push({ 0,1 });
	while (!pq.empty() && count < N) {
		auto k = pq.top();
		int cost = k.first;
		int u = k.second;

		pq.pop();

		
		if (visited[u]) continue;
		visited[u] = true;
		total += cost;
		count++;

		for (auto o : adj[u]) {
			if (!visited[o.second]) {
				pq.push({ o.first,o.second });
			}
		}
	}
	cout << total;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ c,b });
		adj[b].push_back({ c,a });
	}
	prim();
}