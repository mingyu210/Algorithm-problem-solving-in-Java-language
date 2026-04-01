#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int N;
int arr[30][30];
pair<int, int> spot;
bool stop;
int ztime;
int sizes;
int eating;

int bfs() {
	int dx[4] = { -1,0,0,1 };
	int dy[4] = { 0,-1,1,0 };
	bool visited[30][30] = { false };
	visited[spot.first][spot.second] = true;
	queue<tuple<int,int, int>> q;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	q.push({spot.first,spot.second,0});
	int minTime = 0;

	while (!q.empty()) {
		int x, y, times;
		tie(x, y, times) = q.front();
		q.pop();

		if (arr[x][y] < sizes && arr[x][y] > 0) {
			if (minTime == 0) {
				minTime = times;
				pq.push({ x,y });
			}
			else if (minTime == times) {
				pq.push({ x,y });
			}
		}

		for (int i = 0; i < 4; i++) {
			int newX = dx[i] + x;
			int newY = dy[i] + y;

			if (newX >= 0 && newX < N && newY >= 0 && newY < N && arr[newX][newY] <= sizes && !visited[newX][newY]) {
				q.push({ newX,newY,times + 1 });
				visited[newX][newY] = true;
			}
		}
	}
	if (minTime == 0) {
		return 0;
	}
	else {
		int x = pq.top().first;
		int y = pq.top().second;
		eating++;
		spot = { x,y };
		arr[x][y] = 0;
		return minTime;
	}
	

}


int main() {
	cin >> N;
	sizes = 2;
	eating = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int a;
			cin >> a;
			if (a == 9) {
				spot = { i,j };
				arr[i][j] = 0;
			}
			else {
				arr[i][j] = a;
			}
			
		}
	}
	while (!stop) {
		int usingTime;
		usingTime = bfs();
		if (usingTime == 0) {
			stop = true;
		}
		else {
			ztime += usingTime;
			if (eating == sizes) {
				sizes++;
				eating = 0;
			}
		}
	}

	cout << ztime << '\n';
}

