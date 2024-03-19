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
#include <iomanip>
#include <cstdlib>
#include <numeric>
#include <unordered_set>
using namespace std;

#define int long long
// MAX (long long) 1000000000000000000
//#define M 100 + 5
#define N 1003

#define MOD (int) 1000000007
#define ld long double
#define sz size()
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define zero(n) setw(n) << setfill('0')
#define stp(n) fixed << setprecision(n)

main() {
	vector<int> last(10, 1);
	int dp[101] = { 0 };
	dp[1] = 10;

	/*
		Xay dung cac so co i chu so bang cach xay dung cac so co (i - 1) chu so
		+ So cac so ket thuc bang digit += so cac so co (i - 1) chu so ket thuc bang x <= digit
	*/

	for (int i = 2; i <= 100; i++) {
		for (int digit = 9; digit >= 1; digit--) {
			int sum = 0;
			for (int x = 1; x <= digit; x++) {
				sum += last[x];
			}
			(dp[i] += sum) %= MOD;
			last[digit] = sum;
		}
		(dp[i] += dp[i - 1]) %= MOD;
	}

	int t;
	cin >> t;


	while (t--) {
		int n;
		cin >> n;
		cout << dp[n] << endl;
	}

	return 0;
}