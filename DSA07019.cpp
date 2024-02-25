#include <iostream>
#include <stack>
#include <cmath>
using namespace std;
// y tuong, tai 1 vi tri tim ra diem gan nhat, gia tri lon nhat nho hon no

int main() {
	const int SIZE = 100000;
	int t;
	cin >> t;

	int arr[SIZE];
	while (t--) {
		int n;
		cin >> n;

		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

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

		long long res = 0;
		for (int i = 0; i < n; i++) {
			res = max(res, (long long)(right[i] - left[i] + 1) * arr[i]);
		}

		cout << res << endl;

	}
}