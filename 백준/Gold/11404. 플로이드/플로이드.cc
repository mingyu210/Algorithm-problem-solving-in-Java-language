#include <iostream>
#include <algorithm>
#include <climits>


using namespace std;

int n, m;
int graph[101][101];
int answer[101][101];

void floyd() {
	for (int j = 1; j <= n; j++) {
		for (int i = 1; i <= n; i++) {
			if (answer[i][j] != 0 && answer[i][j] != INT_MAX) {
				for (int u = 1; u <= n; u++) {
					if (i != u && answer[j][u]!= INT_MAX) {
						answer[i][u] = min(answer[i][j] + answer[j][u], answer[i][u]);
					}
					
				}
			}
		}
	}
}



int main() {
	cin >> n >> m;

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (i == j) {
				answer[i][j] = 0;
			}
			else {
				answer[i][j] = INT_MAX;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (graph[a][b] != 0) {
			graph[a][b] = min(graph[a][b], c);
			answer[a][b] = graph[a][b];
		}
		else {
			graph[a][b] = c;
			answer[a][b] = c;
		}
	}

	floyd();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (answer[i][j] == INT_MAX) {
				cout << 0 << " ";
			}
			else {
				cout << answer[i][j] << " ";
			}
		}
		cout << endl;
	}
	
}