#include <iostream>
#include <vector>
using namespace std;

char arr[101][101];
char arr2[101][101];
int N;
bool visited[101][101];
bool visited2[101][101];
int ans1;
int ans2;

void dfsing(int x, int y) {
	visited[x][y] = true;

	int dx[4] = { 0,0,1,-1 };
	int dy[4] = { 1,-1,0,0 };

	for (int i = 0; i < 4; i++) {
		int nowX = x + dx[i];
		int nowY = y + dy[i];
		if (nowX >= 0 && nowX < N && nowY >= 0 && nowY < N && visited[nowX][nowY] == false && arr[nowX][nowY] == arr[x][y]) {
			visited[nowX][nowY] = true;
			dfsing(nowX, nowY);
		}
	}
}

void dfs() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j] == false) {
				dfsing(i,j);
				ans1++;
			}
		}
	}


}

void dfsing2(int x, int y) {
	visited2[x][y] = true;

	int dx[4] = { 0,0,1,-1 };
	int dy[4] = { 1,-1,0,0 };

	for (int i = 0; i < 4; i++) {
		int nowX = x + dx[i];
		int nowY = y + dy[i];
		if (nowX >= 0 && nowX < N && nowY >= 0 && nowY < N && visited2[nowX][nowY] == false && arr2[nowX][nowY] == arr2[x][y]) {
			visited2[nowX][nowY] = true;
			dfsing2(nowX, nowY);
		}
	}
}

void dfs2() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited2[i][j] == false) {
				dfsing2(i, j);
				ans2++;
			}
		}
	}


}



int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		string a;
		cin >> a;
		for (int j = 0; j < a.size(); j++) {
			if (a[j] == 'R') {
				arr2[i][j] = 'G';
			}
			else {
				arr2[i][j] = a[j];
			}
			arr[i][j] = a[j];
		}
	}
	dfs();
	dfs2();
	cout << ans1 << " " << ans2;
}