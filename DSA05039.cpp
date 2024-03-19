#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <stack>
#include <cmath>
#include <climits>
#include <iomanip>
#include <cstdlib>
#include <numeric>
#include <unordered_set>
using namespace std;

#define ll long long
// MAX (long long) 1000000000000000000
//#define M 100 + 5
#define N 1003
#define ld long double
#define sz size()
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define zero(n) setw(n) << setfill('0')
#define stp(n) fixed << setprecision(n)
#define pii pair<int, int> 

int dp[105][8105];

int find(int a, int b) {
	if (a > 100 || b > 8100 || a > b || a < 0 || b < 0) return -1;
	if (a == 0 && b == 0) return 0;
	if (dp[a][b] != -1) return dp[a][b];

	int res = 105;

	for (int i = 1; i <= 9; i++) {
		int tmp = find(a - i, b - i * i);
		if (tmp != -1) {
			res = min(res, tmp + 1);
		}
	}

	return dp[a][b] = res;
}

int main() {
	faster();
	int t;
	cin >> t;


	while (t--) {
		memset(dp, -1, sizeof dp);
		dp[0][0] = 0;
		int a, b;
		cin >> a >> b;

		int mn = find(a, b);
		if (mn == -1 || mn > 100) {
			cout << -1;
		}
		else {
			while (a > 0 && b > 0) {
				for (int i = 1; i <= 9; i++) {
					if (a - i >= 0 && b - i * i >= 0 && dp[a - i][b - i * i] + 1 == dp[a][b]) {
						cout << i;
						a -= i;
						b -= i * i;
						break;
					}
				}
			}
		}
		cout << endl;
	}

	return 0;
}