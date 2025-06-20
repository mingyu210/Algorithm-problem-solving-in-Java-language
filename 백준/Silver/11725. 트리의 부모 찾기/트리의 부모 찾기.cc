#include <iostream>
#include <vector>

using namespace std;
#define MAX 100001

int N;
vector<int> v[MAX];
bool visited[MAX];
int answer[MAX];

void dfs(int root) {
	visited[root] = true;
	for (int i = 0; i < v[root].size(); i++) {
		int next = v[root][i];
		if (!visited[next]) {
			answer[next] = root;
			dfs(next);
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	dfs(1);
	for (int i = 2; i <= N; i++) {
		cout << answer[i] << '\n';
	}
}