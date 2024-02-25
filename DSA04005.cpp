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
//#define N 50000

#define MOD (ll) 123456789
#define ld long double
#define sz size()
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define zero(n) setw(n) << setfill('0')
#define stp(n) fixed << setprecision(n)

int main() {
	ll f[100];

	f[1] = 1;
	f[2] = 1;

	for (int i = 3; i <= 92; i++) {
		f[i] = f[i - 1] + f[i - 2];
	}

	int t;
	cin >> t;

	while (t--) {
		ll n, k;
		cin >> n >> k;
		
		while (n > 2) {
			if (k <= f[n - 2]) n -= 2;
			else {
				k -= f[n - 2];
				n--;
			}
		}

		string s[4];
		s[1] = "A";
		s[2] = "B";

		cout << s[n][k - 1] << endl;
	}

	return 0;
}