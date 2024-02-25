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
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <numeric>
#include <unordered_set>
using namespace std;

#define ll long long
#define MAX (long long) 1000000000000000000
//#define M 100 + 5
#define N 5000000 + 11
#define MOD (ll) 998244353
#define ld long double
#define sz size()
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define zero(n) setw(n) << setfill('0')
#define stp(n) fixed << setprecision(n)

int n, m;
int arr[501][501];
int fx[] = { 0, -1, -1, -1, 0, 1, 1 , 1 };
int fy[] = { 1, 1, 0, -1, -1, -1, 0, 1 };

bool isValid(int i, int j) {
	if (i >= 0 && j >= 0 && i < n && j < m && arr[i][j] == 1) return true;
	return false;
}

void dfs(int x, int y) {
	arr[x][y] = 0;

	for (int i = 0; i < 8; i++) {
		int nextX = x + fx[i];
		int nextY = y + fy[i];
		if (isValid(nextX, nextY)) {
			dfs(nextX, nextY);
		}
	}
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		cin >> n >> m;


		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> arr[i][j];
			}
		}

		int cnt = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] == 1) {
					dfs(i, j);
					cnt++;
				}
			}
		}

		cout << cnt << endl;

	}

	return 0;
}