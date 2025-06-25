#include <iostream>
#include <algorithm>
using namespace std;

int N;
int dp[1001][3];
int answer;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			int a;
			cin >> a;
			dp[i][j] = a;
		}
	}

	for (int i = 1; i < N; i++) {
		dp[i][0] += min(dp[i - 1][1], dp[i - 1][2]);
		dp[i][1] += min(dp[i - 1][0], dp[i - 1][2]);
		dp[i][2] += min(dp[i - 1][0], dp[i - 1][1]);
	}
	
	answer = min({dp[N - 1][0], dp[N - 1][1], dp[N - 1][2]});

	cout << answer;
	
	return 0;
	
}