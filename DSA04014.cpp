#include <iostream>
using namespace std;

#define int long long
#define SIZE 10000000

int n;
int arr[SIZE];
int tree[SIZE * 4];

int getSum(int index, int left, int right, int a, int b) {
	if (left > b || right < a) return 0;
	if (left >= a && right <= b) return tree[index];

	int mid = (left + right) / 2;

	return getSum(index * 2, left, mid, a, b) + getSum(index * 2 + 1, mid + 1, right, a, b);
}

void update(int index, int left, int right, int a, int b, int val) {
	if (left > b || right < a) return;
	if (left == right) {
		tree[index] += val;
		return;
	}

	int mid = (left + right) / 2;

	update(index * 2, left, mid, a, b, val);
	update(index * 2 + 1, mid + 1, right, a, b, val);

	tree[index] = tree[index * 2] + tree[index * 2 + 1];
}

main() {
	int t;
	cin >> t;

	while (t--) {
		int res = 0;
		int maxArr = 0;

		cin >> n;
		memset(tree, 0, sizeof tree);

		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			maxArr = max(maxArr, arr[i]);
		}

		for (int i = n; i >= 1; i--) {
			int t = getSum(1, 1, maxArr, 1, arr[i] - 1);
			res = res + t;
			//cout << i << " - ";
			update(1, 1, maxArr, arr[i], arr[i], 1);
		}

		cout << res << endl;
	}

	return 0;
}
