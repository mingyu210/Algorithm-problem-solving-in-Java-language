#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N;
vector<pair<int, int>> arr[100001];
int dist[100001];
bool visited[100001];
int endPoint;
int answer;

void dfs(int start, int value) {
	visited[start] = true;
	dist[start] = value;

	if (answer < value) {
		answer = value;
		endPoint = start;
	}

	for (auto K : arr[start]) {
		int end = K.first;
		int cost = K.second;
		if (!visited[end]) {
			dfs(end, cost + value);
		}
	}


}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		int index = 0;
		while (1) {
			int x;
			cin >> x;
			if (x == -1) break;
			int y;
			cin >> y;
			arr[a].push_back({ x,y });
			arr[x].push_back({ a,y });
		}
	}
	dfs(1, 0);
	memset(dist, 0, sizeof(dist));
	memset(visited, false, sizeof(visited));
	dfs(endPoint, 0);
	cout << answer;
}