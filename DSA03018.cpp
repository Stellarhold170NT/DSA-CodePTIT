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

		int lim = n / 7;
		bool flag = false;


		for (int i = lim; i >= 0; i--) {
			if ((n - 7 * i) % 4 == 0) {
				string b(i, '7');
				string a((n - 7 * i) / 4, '4');
				cout << a + b << endl;
				flag = true;
				break;
			}
		}

		if (!flag) cout << -1 << endl;
	}
}