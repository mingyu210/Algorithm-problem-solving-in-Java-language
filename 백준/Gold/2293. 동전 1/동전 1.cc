#include <iostream>
#include <vector>
using namespace std;

int N, K;
vector<int> coin;
int dp[10001];

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        coin.push_back(a);
    }

    dp[0] = 1;

    for (int i = 0; i < N; i++) {
        for (int j = coin[i]; j <= K; j++) {
            dp[j] += dp[j - coin[i]];
        }
    }

    cout << dp[K];
}