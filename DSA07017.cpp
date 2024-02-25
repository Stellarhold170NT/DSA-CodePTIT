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
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> v(n);

		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}

		stack<int> g;
		stack<int> l;

		vector<int> greater(n, -1);
		vector<int> lower(n, -1);

		for (int i = 0; i < n; i++) {
			while (!g.empty() && v[g.top()] < v[i]) {
				greater[g.top()] = i;
				g.pop();
			}
			while (!l.empty() && v[l.top()] > v[i]) {
				lower[l.top()] = i;
				l.pop();
			}

			l.push(i);
			g.push(i);
		}

		for (int i = 0; i < n; i++) {
			if (greater[i] != -1) {
				if (lower[greater[i]] != -1) {
					cout << v[lower[greater[i]]] << " ";
				}
				else cout << -1 << " ";
			}
			else cout << -1 << " ";
		}

		cout << endl;
	}

	return 0;
}