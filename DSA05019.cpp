#include <iostream>
#include <stack>
#include <cmath>
#include <cstring>
using namespace std;
// y tuong, tai 1 vi tri tim ra diem gan nhat, gia tri lon nhat nho hon no

int a, b;
const int SIZE = 1000;
int arr[SIZE];
int res;

void calc(int n) {
	stack<int> L;
	stack<int> R;

	int left[SIZE];
	int right[SIZE];

	L.push(0);
	for (int i = 0; i < n; i++) {
		while (L.size() && arr[L.top()] >= arr[i]) {
			L.pop();
		}
		if (L.empty()) {
			left[i] = 0;
		}
		else {
			left[i] = L.top() + 1;
		}
		L.push(i);
	}

	R.push(n - 1);
	for (int i = n - 1; i >= 0; i--) {
		while (R.size() && arr[R.top()] >= arr[i]) {
			R.pop();
		}
		if (R.empty()) {
			right[i] = n - 1;
		}
		else {
			right[i] = R.top() - 1;
		}
		R.push(i);
	}

	for (int i = 0; i < n; i++) {
		res = max(res, min((right[i] - left[i] + 1), arr[i]));
	}
}
int main() {
	int t;
	cin >> t;

	while (t--) {
		cin >> a >> b;
		res = 0;
		memset(arr, 0, sizeof arr);

		int ans = 0;
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < b; j++) {
				int x;
				cin >> x;
				if (x == 0) arr[j] = 0;
				else
					arr[j] = arr[j] + x;
			}

			calc(b);
		}
		cout << res << endl;
	}

	return 0;
}