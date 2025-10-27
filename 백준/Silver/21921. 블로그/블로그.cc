#include <iostream>
#include <vector>
using namespace std;

int N, x;
vector<int> arr;
int answer;
int ansNum;

int main() {
	cin >> N >> x;
	answer = 0;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		arr.push_back(a);
	}
	for (int i = 0; i < x; i++) {
		answer += arr[i];
	}
	int minAns = answer;
	ansNum = 1;
	for (int i = 1; i <= N - x; i++) {
		minAns = minAns - arr[i - 1] + arr[i + x-1];
		if (answer == minAns) {
			ansNum++;
		}
		else if (answer < minAns) {
			answer = minAns;
			ansNum = 1;
		}
	}

	if (answer == 0) {
		cout << "SAD" << '\n';
	}
	else {
		cout << answer << '\n' << ansNum << '\n';
	}
}