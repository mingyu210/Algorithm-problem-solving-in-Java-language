#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

long long N;
int M;
int K;
int repre;
vector<long long> arr;
vector<long long> bucket;

void update(long long index, long long value) {
	long long diff = value - arr[index];
	arr[index] = value;
	bucket[index / repre] += diff;
}

long long query(long long start, long long end) {
	long long ret = 0;
	while (start % repre != 0 && start <= end) {
		ret += arr[start];
		start++;
	}
	while ((end+1) % repre != 0 && start <= end) {
		ret += arr[end];
		end--;
	}

	while (start <= end) {
		ret += bucket[start / repre];
		start += repre;
	}
	return ret;
}

int main() {
	cin >> N >> M >> K;
	repre = sqrt(N);
	bucket.resize(N / repre + 2, 0);
	for (int i = 0; i < N; i++) {
		long long a;
		cin >> a;
		arr.push_back(a);
		bucket[i / repre] += a; 
	}
	int number = M + K;
	while (number--) {
		long long a;
		cin >> a;
		if (a == 1) {
			long long b;
			long long c;
			cin >> b >> c;
			update(b-1, c);
		}
		else if (a == 2) {
			long long b;
			long long c;
			cin >> b >> c;
			cout << query(b-1, c-1) << '\n';
		}
	}
}