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
		int n;
		string s;

		cin >> n >> s;

		int ix = s.length() - 1;
		while (ix > 0 && s[ix] <= s[ix - 1]) ix--;
		ix--;

		if (ix < 0) {
			cout << n << " " << "BIGGEST" << endl;
		}
		else {
			int p = 0;
			char c_min = '9';
			for (int i = ix + 1; i < s.length(); i++) {
				if (s[i] > s[ix] && s[i] <= c_min) {
					c_min = min(c_min, s[i]);
					p = i;
				}
			}
			swap(s[ix], s[p]);
			string a = s.substr(0, ix + 1);
			string b = s.substr(ix + 1);
			reverse(b.begin(), b.end());

			cout << n << " " << a + b << endl;
		}
	}

	return 0;
}