#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int N;
int arr[20][20];
int answer = 0;

void bfs() {
    queue<tuple<int, int, int>> q;
    // (방향, x, y)
    // 0: 가로, 1: 세로, 2: 대각선

    q.push({ 0, 1, 2 });

    while (!q.empty()) {
        int gear, x, y;
        tie(gear, x, y) = q.front();
        q.pop();

        if (x == N && y == N) {
            answer++;
            continue;
        }

        // 1. 가로
        if (gear == 0) {
            // → 오른쪽
            if (y + 1 <= N && arr[x][y + 1] == 0) {
                q.push({ 0, x, y + 1 });
            }

            // ↘ 대각선
            if (x + 1 <= N && y + 1 <= N &&
                arr[x][y + 1] == 0 &&
                arr[x + 1][y] == 0 &&
                arr[x + 1][y + 1] == 0) {
                q.push({ 2, x + 1, y + 1 });
            }
        }

        // 2. 세로
        else if (gear == 1) {
            // ↓ 아래
            if (x + 1 <= N && arr[x + 1][y] == 0) {
                q.push({ 1, x + 1, y });
            }

            // ↘ 대각선
            if (x + 1 <= N && y + 1 <= N &&
                arr[x][y + 1] == 0 &&
                arr[x + 1][y] == 0 &&
                arr[x + 1][y + 1] == 0) {
                q.push({ 2, x + 1, y + 1 });
            }
        }

        // 3. 대각선
        else {
            // → 오른쪽
            if (y + 1 <= N && arr[x][y + 1] == 0) {
                q.push({ 0, x, y + 1 });
            }

            // ↓ 아래
            if (x + 1 <= N && arr[x + 1][y] == 0) {
                q.push({ 1, x + 1, y });
            }

            // ↘ 대각선
            if (x + 1 <= N && y + 1 <= N &&
                arr[x][y + 1] == 0 &&
                arr[x + 1][y] == 0 &&
                arr[x + 1][y + 1] == 0) {
                q.push({ 2, x + 1, y + 1 });
            }
        }
    }
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> arr[i][j];
        }
    }

    bfs();
    cout << answer;
}