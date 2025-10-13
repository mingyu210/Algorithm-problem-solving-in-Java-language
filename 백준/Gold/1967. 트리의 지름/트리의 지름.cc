#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N;
vector<pair<int, int>> tree[10001];
int dist[10001];
bool visited[10001];
int maxDist;
int farNode;

void dfs(int start, int value) {
	visited[start] = true;
	dist[start] = value;;
	if (value > maxDist) {
		maxDist = value;
		farNode = start;
	}

	for (auto K : tree[start]) {
		int next = K.first;
		int cost = K.second;
		if (!visited[next]) {
			dfs(next, value + cost);
		}
	}
	
}

int main() {
	cin >> N;
	for (int i = 1; i < N; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		tree[a].push_back({ b, c });
		tree[b].push_back({ a, c });
	}
	maxDist = 0;
	farNode = 1;
	dfs(1,0);
	maxDist = 0;
	memset(visited, false, sizeof(visited));
	memset(dist, 0, sizeof(dist));
	dfs(farNode, 0);
	cout << maxDist;
}
