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

#define int long long
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

main() {
	int t;
	cin >> t;

	while (t--) {
		int k;
		string s;
		cin >> k >> s;

		int cnt[1000] = { 0 };

		for (auto x : s) cnt[x]++;

		priority_queue<int> p;

		for (char c = 'A'; c <= 'Z'; c++)
			if (cnt[c]) p.push(cnt[c]);

		while (k--) {
			int x = p.top();
			p.pop();
			x--;
			if (x)
				p.push(x);
		}

		int res = 0;

		while (!p.empty()) {
			res += p.top() * p.top();
			p.pop();
		}

		cout << res << endl;
	}

	return 0;
}