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
	int n, k;
	cin >> n >> k;

	int f[101][101];

	for (int i = 1; i <= k; i++) for (int j = 1; j <= n; j++) f[i][j] = 0;

	int arr[101];
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		f[1][i] = 1;
	}

	int res = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 2; j <= k; j++) {
			for (int p = 1; p < i; p++) {
				if (arr[i] > arr[p])
					f[j][i] += f[j - 1][p];
			}
		}
		res += f[k][i];
	}

	/*for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) cout << f[j][i] << " ";
		cout << endl;
	}*/

	cout << res << endl;


	return 0;
}