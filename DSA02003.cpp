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
int arr[N][N];
int dx[2] = { 1, 0 };
int dy[2] = { 0 , 1 };
string road = "";
set<string> res;

bool isSafe(int x, int y) {
	if (x >= 0 && y >= 0 && x < n && y < n && arr[x][y] == 1) return true;
	return false;
}

void dfs(int x, int y) {
	if (x == n - 1 && y == n - 1) {
		res.insert(road);
		return;
	}

	for (int i = 0; i < 2; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (isSafe(nx, ny)) {
			arr[nx][ny] = 0;
			if (i == 0) road += "D";
			else road += "R";
			dfs(nx, ny);

			road.pop_back();
			arr[nx][ny] = 1;
		}
	}
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		cin >> n;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
			}
		}

		if (arr[0][0] == 0) cout << -1 << endl;
		else {
			dfs(0, 0);
			if (res.size()) {
				for (auto x : res) {
					cout << x << " ";
				}
				cout << endl;
			}
			else cout << -1 << endl;
		}



		res.clear();

	}

	return 0;
}