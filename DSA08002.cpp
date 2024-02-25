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

	queue<int> q;
	int n;

	while (t--) {
		string s;
		cin >> s;

		if (s == "PUSH") {
			cin >> n;
			q.push(n);
		}
		else if (s == "PRINTFRONT") {
			if (!q.empty())
				cout << q.front() << endl;
			else cout << "NONE" << endl;
		}
		else if (s == "POP") {
			if (!q.empty()) {
				q.pop();
			}
		}
	}

	return 0;
}