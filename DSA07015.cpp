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
#include <climits>
#include <iomanip>
#include <cstdlib>
#include <numeric>
#include <unordered_set>
using namespace std;

#define ll long long
// MAX (long long) 1000000000000000000
//#define M 100 + 5
#define N 600000

#define MOD (ll) 998244353
#define ld long double
#define sz size()
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define zero(n) setw(n) << setfill('0')
#define stp(n) fixed << setprecision(n)
#define endl "\n"

int degree(char x) {
	if (x == '*' || x == '/') return 2;
	if (x == '+' || x == '-') return 1;
	return 0;
}

ll calc(ll a, ll b, char x) {
	if (x == '+') return a + b;
	else if (x == '-') return a - b;
	else if (x == '*') return a * b;
	else if (x == '/') return a / b;
	return 0;
}

void store(vector<ll>& res, char x) {
	ll b = res.back();
	res.pop_back();
	ll a = res.back();
	res.pop_back();
	ll c = calc(a, b, x);
	res.push_back(c);
}


int main() {
	int t;
	cin >> t;

	while (t--) {
		string s;
		cin >> s;

		s = "(" + s + ")";

		stack<char> st;

		vector<ll> res;
		string tmp = "";

		for (int i = 0; i < s.length(); i++) {
			if (isdigit(s[i])) {
				tmp += s[i];
				if (!isdigit(s[i + 1])) res.push_back(stoi(tmp)), tmp = "";
			}
			else
				if (s[i] == '(') st.push(s[i]);
				else if (s[i] == ')') {
					while (!st.empty() && st.top() != '(') {
						store(res, st.top());
						st.pop();
					}
					st.pop();
				}
				else {
					while (!st.empty() && degree(st.top()) >= degree(s[i])) {
						store(res, st.top());
						st.pop();
					}
					st.push(s[i]);
				}
		}

		while (!st.empty()) {
			store(res, st.top());
			st.pop();
		}

		cout << res.front() << endl;
	}
	return 0;
}