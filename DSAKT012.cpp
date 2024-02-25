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

int money[100];

bool check = false;
int res;
int n, s;

void Try(int sum_money, int lim, int cnt) {
	if (check) return;
	if (sum_money < 0) return;
	if (sum_money == 0) {
		check = 1;
		res = cnt;
		return;
	}
	for (int j = lim; j >= 0; j--) {
		Try(sum_money - money[j], j - 1, cnt + 1);
	}
}

int main() {
	int t;
	//cin >> t;
	t = 1;

	while (t--) {
		cin >> n >> s;

		for (int i = 0; i < n; i++) cin >> money[i];
		sort(money, money + n);

		check = false;
		Try(s, n - 1, 0);

		if (check)
			cout << res << endl;
		else cout << -1 << endl;
	}

	return 0;
}