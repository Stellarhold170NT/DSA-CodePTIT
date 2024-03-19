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
#define N 1003

#define MOD (ll) 1000000007
#define ld long double
#define sz size()
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define zero(n) setw(n) << setfill('0')
#define stp(n) fixed << setprecision(n)

int k, m, n;
string dic[101];
char a[4][4];
bool check = false;
bool visited[4][4];
int dx[] = { -1, -1, 0, 1, 1, 1, 0 };
int dy[] = { 0, 1, 1, 1, 0, -1 , -1, -1 };

bool isSafe(int x, int y) {
	if (x >= 0 && x < m && y >= 0 && y < n) return true;
	return false;
}

void dfs(int x, int y, int idx, int wi) {
	if (check) return;
	visited[x][y] = true;
	if (idx == dic[wi].size() - 1) {
		check = true;
		return;
	}
	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (isSafe(nx, ny) && !visited[nx][ny] && idx + 1 <= dic[wi].size() - 1) {
			if (dic[wi][idx + 1] == a[nx][ny]) {
				dfs(nx, ny, idx + 1, wi);
			}

		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	int t;
	cin >> t;

	while (t--) {
		cin >> k >> m >> n;

		for (int i = 0; i < k; i++) {
			cin >> dic[i];
		}

		sort(dic, dic + k);

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cin >> a[i][j];
			}
		}

		for (int i = 0; i < k; i++) {
			for (int j = 0; j < m; j++) {
				for (int p = 0; p < n; p++) {
					if (a[j][p] == dic[i][0]) {
						memset(visited, false, sizeof visited);
						check = false;
						dfs(j, p, 0, i);
						if (check) cout << dic[i] << " ";
					}
				}
			}
		}
		cout << endl;
	}

	return 0;
}