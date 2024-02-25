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
	int t;
	cin >> t;



	while (t--) {
		int n;
		cin >> n;

		queue<string> q;

		q.push("6");
		q.push("8");

		vector<string> res;

		res.push_back("6");
		res.push_back("8");

		while (q.front().size() < n) {
			queue<string> tmp;

			while (!q.empty()) {
				res.push_back(q.front() + "6");
				res.push_back(q.front() + "8");
				tmp.push(q.front() + "6");
				tmp.push(q.front() + "8");
				q.pop();
			}

			q = tmp;
		}

		cout << res.size() << endl;
		for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
		cout << endl;
	}

	return 0;
}