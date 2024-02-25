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


priority_queue<ll, vector<ll>, greater<ll>> p;
vector<ll> ugly;
unordered_map<ll, bool> mp;

void add(ll x) {
	if (!mp[x]) {
		p.push(x);
		mp[x] = 1;
	}
}

int main() {
	int t;
	cin >> t;

	p.push(1);
	ugly.push_back(1);

	while (ugly.size() < 1e4) {
		ll x = p.top();
		p.pop();
		ugly.push_back(x);

		add(x * 2);
		add(x * 3);
		add(x * 5);
	}

	while (t--) {
		int n;
		cin >> n;

		cout << ugly[n] << endl;
	}

	return 0;
}