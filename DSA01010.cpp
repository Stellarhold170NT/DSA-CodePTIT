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

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, k;
		cin >> n >> k;

		int arr[100];
		int next_arr[100];
		for (int i = 1; i <= k; i++) {
			cin >> arr[i];
			next_arr[i] = arr[i];
		}

		int ix = k;
		while (ix > 0 && arr[ix] == n - k + ix) ix--;
		if (ix == 0) {
			cout << k << endl;
		}
		else {
			next_arr[ix]++;
			for (int i = ix + 1; i <= k; i++) {
				next_arr[i] = next_arr[i - 1] + 1;
			}

			int cnt = 0;
			for (int i = 1; i <= k; i++) {
				for (int j = 1; j <= k; j++) {
					if (arr[i] == next_arr[j]) {
						cnt++;
					}
				}
			}

			cout << k - cnt << endl;
		}
	}

	return 0;
}