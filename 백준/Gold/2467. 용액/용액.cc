#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N;
long long answer;
pair<long long, long long> ans;
vector<long long> arr;

bool zeroFind(long long x, long long y) {
	long long xValue = abs(x);
	long long yValue = abs(y);
	if (xValue >= yValue) {  // y가 0에 더 가까움
		return true;
	}
	else { // x가 0에 더 가까움
		return false;
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		long long a;
		cin >> a;
		arr.push_back(a);
	}
	int i = 0;
	int j = N - 1;
	answer = arr[i] + arr[j];
	ans = { arr[i],arr[j]};
	long long minAns = answer;
	while (i < j) {
		minAns = arr[i] + arr[j];
		if (minAns == 0) {
			ans = { arr[i],arr[j] };
			break;
		}
		if (zeroFind(answer, minAns)) { //y가 0에 더 가까울때
			answer = minAns;
			ans = { arr[i],arr[j]};
			if (answer > 0) {
				j--;
			}
			else {
				i++;
			}
		}
		else { //answer이 0에 더 가까움
			if (minAns > 0) {
				j--;
			}
			else {
				i++;
			}
		}
	}

	cout << ans.first << " " << ans.second << '\n';
}