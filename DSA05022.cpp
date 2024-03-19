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
		int n;
		int x, y, z;
		cin >> n >> x >> y >> z;

		int f[101] = { 0 };

		f[1] = x;
		for (int i = 2; i <= n; i++) {
			f[i] = f[i - 1] + x;
			if (i % 2 == 1) {
				f[i] = min(f[i], f[i / 2] + y + z);
			}
			else f[i] = min(f[i], f[i / 2] + z);
		}

		cout << f[n] << endl;
	}

	return 0;
}