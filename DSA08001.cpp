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

//#define MOD (ll) 1000000007
#define ld long double
#define sz size()
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
		queue<int> que;
		int last = 0;

		while (n--) {
			int q;
			cin >> q;

			//cout << "kq = ";
			if (q == 1) cout << que.size();
			else if (q == 2) {
				if (que.empty()) cout << "YES";
				else cout << "NO";
			}
			else if (q == 3) {
				int num;
				cin >> num;
				que.push(num);
				last = num;
			}
			else if (q == 4) {
				if (!que.empty()) que.pop();
			}
			else if (q == 5) {
				if (!que.empty()) {
					cout << que.front();
				}
				else cout << -1;
			}
			else if (q == 6) {
				if (!que.empty()) {
					cout << last;
				}
				else cout << -1;
			}
			cout << endl;
		}
	}

	return 0;
}