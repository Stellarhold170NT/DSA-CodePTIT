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
	int n, w;
	cin >> n >> w;

	int arr[101];
	int brr[101];

	for (int i = 1; i <= n; i++) cin >> brr[i];
	for (int i = 1; i <= n; i++) cin >> arr[i];

	int f[101][101];
	memset(f, 0, sizeof f);

	//for (int i = 0; i <= w; i++) f[0][i] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= w; j++) {
			if (j >= arr[i]) f[i][j] = max(f[i - 1][j], f[i - 1][j - arr[i]] + brr[i]);
			else f[i][j] = f[i - 1][j];
		}
	}


	cout << f[n][w] << endl;

	int x[100] = { 0 };

	int tmp = f[n][w];
	int i = n, j = w;

	while (i >= 0 && j >= 0) {
		while (tmp == f[i - 1][j]) {
			i--;
		}
		x[i] = 1;
		tmp = tmp - brr[i];
		j -= arr[i];
		i--;
	}

	for (int i = 1; i <= n; i++) cout << x[i] << " ";


	return 0;
}