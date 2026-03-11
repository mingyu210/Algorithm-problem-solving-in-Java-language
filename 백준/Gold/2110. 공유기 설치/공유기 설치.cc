#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, C;
vector<int> arr;
int answer;


int main() {
	cin >> N >> C;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		arr.push_back(x);
	}
	sort(arr.begin(), arr.end());
	
	int left = 1; //가장 짧은 거리
	int right = arr[N - 1] - arr[0]; //가장 먼 거리
	
	while (left <= right) {
		int mid = (left + right) / 2;

		int count = 1; //공유기
		int now = 0;  //지금 현재 어떤 집에 있는지

		for (int i = 1; i < N; i++) {
			if (mid <= arr[i] - arr[now]) {
				now = i;
				count++;
			}
		}

		if (count >= C) {
			left = mid + 1;
			answer = mid;
		}
		else {
			right = mid - 1;
		}

	}

	cout << answer;

}