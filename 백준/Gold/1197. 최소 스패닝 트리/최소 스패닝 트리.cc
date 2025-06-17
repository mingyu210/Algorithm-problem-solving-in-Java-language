#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>


using namespace std;

vector<vector<pair<int, int>>> graph;
int v, e;
bool visited[10001];
int answer;
int number = 1;



void prim() {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	for (auto fringe : graph[1]) {
		pq.push(fringe);
	}
	visited[1] = true;
	while (!pq.empty()) {
		auto tree = pq.top();
		pq.pop();

		if (!visited[tree.second]) {
			visited[tree.second] = true;
			answer += tree.first;
			number++;
			if (number == v) {
				return;
			}
			for (auto fringe : graph[tree.second]) {
				pq.push(fringe);
			}
		}
	}
}


int main() {
	cin >> v >> e;
	graph.resize(v + 1);
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ c, b });
		graph[b].push_back({ c, a });
	}
	prim();
	cout << answer;
}