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
//#define N 50000

#define MOD (ll) 123456789
#define ld long double
#define sz size()
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define zero(n) setw(n) << setfill('0')
#define stp(n) fixed << setprecision(n)

ll lt(ll a, ll b) {
	if (b == 0) return 1;
	if (b == 1) return a;

	ll tmp = lt(a, b / 2);
	if (b % 2 == 0) return (tmp * tmp);
	else return (tmp * tmp * a);
}

char find(ll n, ll k) {
	// the largest number = n after n copy
	ll position_of_largest_num = lt(2, n - 1);

	if (k == position_of_largest_num) return n + 'A' - 1;
	else if (k < position_of_largest_num) return find(n - 1, k);
	return find(n - 1, k - position_of_largest_num);

}
int main() {
	int t;
	cin >> t;

	while (t--) {
		ll n, k;
		cin >> n >> k;

		cout << find(n, k) << endl;
	}

	return 0;
}