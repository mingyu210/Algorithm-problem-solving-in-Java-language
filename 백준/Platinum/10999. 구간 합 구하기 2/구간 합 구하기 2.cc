#include <iostream>
#include <vector>
using namespace std;

int N, M, K;


struct segNode {
	long long sum;

	segNode() {
		sum = 0;
	}
	segNode operator+(const segNode& b) const {
		segNode ret;
		ret.sum = sum + b.sum;
		return ret;
	}
};

struct segTree {
	segNode arr[1000000 * 4];
	long long lazy[1000000 * 4];

	void update_value(int start, int end, int x, long long value) {
		arr[x].sum += value * (end - start + 1);
		lazy[x] += value;
	}

	void heritage(int start, int end, int x) {
		if (start == end) return;
		int mid = (start + end) / 2;
		update_value(start, mid, 2 * x,lazy[x]);
		update_value(mid + 1, end, 2 * x + 1, lazy[x]);
		lazy[x] = 0;
	}

	void update(int start, int end, int x, int left, int right, long long value) {
		heritage(start, end, x);
		if (start >= left && end <= right) {
			update_value(start, end, x, value);
		}
		else if (left <= end && start <= right) {
			int mid = (start + end) / 2;
			update(start, mid, 2 * x, left, right, value);
			update(mid + 1, end, 2 * x + 1, left, right, value);
			arr[x] = arr[2 * x] + arr[2 * x + 1];
		}
	}

	long long query(int start, int end, int x, int left, int right) {
		heritage(start, end, x);

		if (end < left || start > right) return 0;

		if (left <= start && end <= right) return arr[x].sum;

		int mid = (start + end) / 2;
		long long a = query(start, mid, 2 * x, left, right);
		long long b = query(mid + 1, end, 2 * x + 1, left, right);
		return a + b;
	}

	void build(int start, int end, int x, const vector<long long>& init) {
		if (start == end) {
			arr[x].sum = init[start];
			return;
		}
		int mid = (start + end) / 2;
		build(start, mid, 2 * x, init);
		build(mid + 1, end, 2 * x + 1, init);
		arr[x] = arr[2 * x] + arr[2 * x + 1];
	}

};

segTree segt;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> K;
	vector<long long> init(N);
	for (int i = 0; i < N; i++) {
		cin >> init[i];
	}
	segt.build(0, N - 1, 1, init);

	for (int i = 0; i < M + K; i++) {
		int a;
		cin >> a;
		if (a == 1){
			int b, c;
			long long d;
			cin >> b >> c >> d;
			segt.update(0, N - 1, 1, b - 1, c - 1, d);
		}
		else if (a == 2) {
			int b, c;
			cin >> b >> c;
			cout << segt.query(0, N - 1, 1, b - 1, c - 1) << '\n';
		}
	}

}