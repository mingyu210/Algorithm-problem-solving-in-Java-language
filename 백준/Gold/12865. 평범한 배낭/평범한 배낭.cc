#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
vector<pair<int, int>> bag; 
vector<int> dp;

int main() {
    cin >> n >> k;
    bag.resize(n);
    dp.resize(k + 1, 0); 

    for (int i = 0; i < n; i++) {
        int w, v;
        cin >> w >> v;
        bag[i] = { w, v };
    }

    for (int i = 0; i < n; i++) {
        int weight = bag[i].first;
        int value = bag[i].second;
        for (int j = k; j >= weight; j--) {
            dp[j] = max(dp[j], dp[j - weight] + value);
        }
    }

    cout << dp[k];
    return 0;
}
