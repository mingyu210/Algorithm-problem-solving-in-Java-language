#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int N, D;
int dp[10001];
vector<tuple<int, int, int>> arr;

int main() {
	cin >> N >> D;
	for (int i = 0; i <= D; i++) {
		dp[i] = i;
	}
	for (int i = 0; i < N; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		arr.push_back({ a, b, c });
	}
	sort(arr.begin(), arr.end());

	int unit = 0;

	for (int i = 0; i <= D; i++) {
		if (i > 0) {
			dp[i] = min(dp[i], dp[i - 1] + 1);
		}
		while (unit < arr.size()) {
			int start, end, value;
			tie(start, end, value) = arr[unit];

			if (start != i) break;

			if (end <= D && (end - start) > value) {
				dp[end] = min(dp[end], dp[start] + value);
			}
			unit++;
		}
	}
	

	cout << dp[D];
}