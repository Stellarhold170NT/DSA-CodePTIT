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



int main() {
	int n, m;
	cin >> n >> m;

	int edge[101][101];

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) edge[i][j] = 10000000;
		edge[i][i] = 0;
	}

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edge[a][b] = c;
		edge[b][a] = c;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				edge[i][j] = min(edge[i][j], edge[i][k] + edge[k][j]);
			}
		}
	}

	int q;
	cin >> q;

	while (q--) {
		int a, b;
		cin >> a >> b;
		cout << edge[a][b] << endl;
	}

	return 0;
}