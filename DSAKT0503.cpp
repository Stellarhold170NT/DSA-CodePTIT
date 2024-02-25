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
		string a, b;
		cin >> a >> b;

		a = " " + a;
		b = " " + b;

		const int LIM = 1000;
		int f[LIM][LIM];

		memset(f, 0, sizeof f);

		for (int i = 1; i < a.length(); i++) {
			for (int j = 1; j < b.length(); j++) {
				if (a[i] == b[j]) f[i][j] = f[i - 1][j - 1] + 1;
				else f[i][j] = max(f[i - 1][j], f[i][j - 1]);
			}
		}


		cout << f[a.length() - 1][b.length() - 1] << endl;
	}

	return 0;
}