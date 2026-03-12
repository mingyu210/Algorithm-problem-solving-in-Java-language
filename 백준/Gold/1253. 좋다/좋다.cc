#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<long long> arr;
int answer;



int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		long long a;
		cin >> a;
		arr.push_back(a);
	}
	sort(arr.begin(), arr.end());
	answer = 0;
	
	for (int i = 0; i < N; i++) {
		int left = 0;
		int right = N - 1;
		while (left < right) {
			if (left == i) {
				left++;
				continue;
			}
			if (right == i) {
				right--;
				continue;
			}
			long long sum = arr[left] + arr[right];
			if (sum == arr[i]) {
				answer++;
				break;
			}
			else if (sum > arr[i]) { //값을 줄여야된다.
				right--;
			}
			else { // 값을 늘려야한다/
				left++;
			}
			

		}
	}
	cout << answer << '\n';
}