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
#include <climits>
#include <cstdlib>
#include <numeric>
#include <unordered_set>
using namespace std;

#define ll long long
// MAX (long long) 1000000000000000000
//#define M 100 + 5
#define N 1003

#define MOD (ll) 1000000007
#define ld long double
#define sz size()
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define zero(n) setw(n) << setfill('0')
#define stp(n) fixed << setprecision(n)

ll nt[] = { 0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 };
ll ans;
int n;

void Try(int i, ll a = 1, ll b = 1) {
	if (b > n) return;
	if (b == n) {
		ans = min(ans, a);
	}

	int j = 1;

	while (a * nt[i] <= ans) {
		a = a * nt[i];
		Try(i + 1, a, b * (j + 1));
		j++;
	}
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		cin >> n;

		ans = 1e18;
		Try(1);
		cout << ans << endl;
	}

	return 0;
}