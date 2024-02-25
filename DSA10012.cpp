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
#define N 600000

#define MOD (ll) 998244353
#define ld long double
#define sz size()
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define zero(n) setw(n) << setfill('0')
#define stp(n) fixed << setprecision(n)

const int INF = 10000000;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int v, e;
		cin >> v >> e;

		int edge[501][501];

		for (int i = 1; i <= v; i++) {
			for (int j = 1; j <= v; j++) {
				edge[i][j] = INF;
			}
		}

		for (int i = 0; i < e; i++) {
			int a, b;
			cin >> a >> b;
			edge[a][b] = 1;
		}

		for (int k = 1; k <= v; k++) {
			for (int i = 1; i <= v; i++) {
				for (int j = 1; j <= v; j++) {
					edge[i][j] = min(edge[i][j], edge[i][k] + edge[k][j]);
				}
			}
		}

		double res = 0.0;
		int cnt = 0;

		for (int i = 1; i <= v; i++) {
			for (int j = 1; j <= v; j++) {
				if (edge[i][j] != INF && i != j) {
					res = res + edge[i][j];
					cnt++;
				}
			}
		}

		cout << stp(2) << res / (cnt * 1.0) << endl;
	}

	return 0;
}