#include <iostream>
#include <vector>
using namespace std;

int K, N;
vector<long long> lens;
long long answer;

void bound(long long start, long long end) {
	if (start > end) {
		return;
	}
	long long mid = (start + end) / 2;
	if (mid == 0) return;

	long long minAns = 0;
	for (int i = 0; i < lens.size(); i++) {
		minAns += lens[i] / mid;
	}
	if (minAns >= N) {
		if (answer < mid) {
			answer = mid;
		}
		bound(mid + 1, end);
	}
	else {
		bound(start, mid-1);
	}
	

}

int main() {
	cin >> K >> N;
	long long bigLens = 0;
	lens.clear();
	answer = 0;
	for (int i = 0; i < K; i++) {
		long long a;
		cin >> a;
		if (bigLens < a) {
			bigLens = a;
		}
		lens.push_back(a);
	}
	bound(1, bigLens);
	cout << answer << '\n';
}