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

//#define MOD (ll) 1000000007
#define ld long double
#define sz size()
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define zero(n) setw(n) << setfill('0')
#define stp(n) fixed << setprecision(n)

int n;
int col[N] = { 0 };
int cheo_chinh[N] = { 0 };
int cheo_phu[N] = { 0 };
int cnt = 0;

void Try(int i) {
	for (int j = 1; j <= n; j++) {
		if (!col[j] && !cheo_chinh[i - j + n] && !cheo_phu[i + j - 1]) {
			col[j] = 1;
			cheo_chinh[i - j + n] = 1;
			cheo_phu[i + j - 1] = 1;

			if (i == n) cnt++;
			else Try(i + 1);

			col[j] = 0;
			cheo_chinh[i - j + n] = 0;
			cheo_phu[i + j - 1] = 0;
		}
	}
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		cin >> n;
		cnt = 0;
		Try(1);
		cout << cnt << endl;
	}

	return 0;
}