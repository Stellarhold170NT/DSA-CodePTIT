#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <numeric>
#include <unordered_set>
using namespace std;

#define ll long long
// MAX (long long) 1000000000000000000
//#define M 100 + 5
#define N 200

#define MOD (ll) 1000000007
#define ld long double
#define sz size()
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define zero(n) setw(n) << setfill('0')
#define stp(n) fixed << setprecision(n)

int n, k;
int arr[100];
int dd[100] = { 0 };
bool check;

void Try(int cnt, int sum, int x) {
	if (check) return;
	if (cnt == k) {
		check = true;
		return;
	}
	if (x > sum) return;
	if (x == sum) {
		Try(cnt + 1, sum, 0);
	}

	for (int i = 0; i < n; i++) {
		Try(cnt, sum, x + arr[i]);
	}
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		cin >> n >> k;

		memset(dd, 0, sizeof dd);
		check = false;
		int sum = 0;

		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			sum += arr[i];
		}

		if (sum % k == 0) {
			sum /= k;
			Try(0, sum, 0);
			if (check) cout << 1 << endl;
			else cout << 0 << endl;
		}
		else cout << 0 << endl;
	}

	return 0;
}