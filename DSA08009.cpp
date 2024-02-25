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
		int s, t;
		cin >> s >> t;

		queue<int> q;
		q.push(s);

		int f[10001] = { 0 };

		while (!q.empty()) {
			int tmp = q.front();
			q.pop();

			if (tmp == t) {
				cout << f[tmp] << endl;
				break;
			}

			if (tmp * 2 < t * 2 && !f[tmp * 2]) {
				f[tmp * 2] = f[tmp] + 1;
				q.push(tmp * 2);
			}

			if (tmp - 1 >= 0 && !f[tmp - 1]) {
				f[tmp - 1] = f[tmp] + 1;
				q.push(tmp - 1);
			}
		}
	}

	return 0;
}