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
#include <unordered_map>
#include <unordered_set>
using namespace std;

#define ll long long
// MAX (long long) 1000000000000000000
//#define M 100 + 5

#define MOD (ll) 998244353
#define ld long double
#define sz size()
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define zero(n) setw(n) << setfill('0')
#define stp(n) fixed << setprecision(n)

const int N = 100000;
int root[N];

int findRoot(int n) {
	if (root[n] != n) root[n] = findRoot(root[n]);
	return root[n];
}
int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= N; i++) {
		root[i] = i;
	}

	for (int i = 1; i <= n; i++) {
		int a, b, t;
		cin >> a >> b >> t;

		int rootA = findRoot(a);
		int rootB = findRoot(b);

		if (t == 1) {
			if (rootA != rootB) root[rootA] = rootB;
		}
		else {
			if (rootA == rootB) {
				cout << "1" << endl;
			}
			else cout << "0" << endl;
		}
	}
}