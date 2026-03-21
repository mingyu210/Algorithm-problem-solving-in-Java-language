#include <iostream>
#include <vector>
using namespace std;

int N;
vector<pair<int, int>> answer;

void hanoi(int n, int from, int via, int to) {
	if (n == 1) {
		answer.push_back({ from,to });
		return;
	}
	hanoi(n - 1, from, to, via);
	answer.push_back({ from,to });
	hanoi(n - 1, via, from, to);
}

int main() {
	cin >> N;

	hanoi(N, 1, 2, 3);
	cout << answer.size() << "\n";
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i].first << " " << answer[i].second << '\n';
	}

}