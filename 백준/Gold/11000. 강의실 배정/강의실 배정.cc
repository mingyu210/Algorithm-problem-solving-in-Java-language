#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<long long> start;
vector<long long> ending;
int answer;


int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		long long a, b;
		cin >> a >> b;
		start.push_back(a);
		ending.push_back(b);
	}
	sort(start.begin(), start.end());
	sort(ending.begin(), ending.end());

	int room = 0;
	int max_room = 0;
	int i = 0; int j = 0;

	while (i < N && j < N) {
		if (start[i] < ending[j]) {
			//i는 시작점, j는 끝나는 시간
			i++;
			room++;
			max_room = max(max_room, room);
		}
		else {
			room--;
			j++;
		}
	}

	cout << max_room << '\n';

}