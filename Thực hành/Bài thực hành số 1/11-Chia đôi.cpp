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

#define int long long
// MAX (long long) 1000000000000000000
//#define M 100 + 5
#define N 200

#define MOD (int) 1000000007
#define ld long double
#define sz size()
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define zero(n) setw(n) << setfill('0')
#define stp(n) fixed << setprecision(n)

int n;
int nt[1001] = { 0 };
int res[1001] = { 0 };

void PTI(int x, int value) {
	for (int i = 2; i * i <= x; i++) {
		while (x % i == 0) {
			nt[i] += value;
			x /= i;
		}
	}

	if (x > 1) nt[x] += value;
}

main() {
	int t;
	cin >> t;

	while (t--) {
		cin >> n;

		memset(nt, 0, sizeof nt);
		memset(res, 0, sizeof res);

		for (int i = n + 1; i <= 2 * n; i++) PTI(i, 1);
		for (int i = 2; i <= n + 1; i++) PTI(i, -1);

		res[0] = 1;
		int len = 1;

		for (int i = 2; i <= 2 * n; i++) {
			while (nt[i]--) {
				len += 5;
				for (int j = 0; j < len; j++) res[j] *= i;
				for (int j = 1; j < len; j++) {
					res[j] = res[j - 1] / 10 + res[j];
					res[j - 1] %= 10;
				}
				while (res[len - 1] == 0) len--;
			}
		}

		for (int i = len - 1; i >= 0; i--) cout << res[i];
		cout << endl;
	}

	return 0;
}