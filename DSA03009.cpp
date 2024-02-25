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
#include <bitset>
#include <unordered_set>
using namespace std;

#define ll long long
// MAX (long long) 1000000000000000000
//#define M 100 + 5
#define N 200

#define MOD (ll) 1000000007
#define ld long double
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

		vector<pair<int, int>> v(n);

		int id;
		for (int i = 0; i < n; i++) {
			cin >> id >> v[i].first >> v[i].second;
		}

		sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b) {
			return a.second > b.second;
			});

		bitset<1005> bs;
		int cnt = 0, sum = 0;

		for (auto x : v) {
			while (bs[x.first] && x.first) x.first--;

			if (!bs[x.first] && x.first) {
				cnt++;
				sum += x.second;
				bs[x.first] = 1;
			}
		}

		cout << cnt << " " << sum << endl;
	}

	return 0;
}