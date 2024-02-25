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

string xoa_ngoac(string s) {
	s = "(" + s + ")";

	stack<string> st;


	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ')') {
			string tmp1 = "";

			while (!st.empty() && st.top() != "(") {
				tmp1 = st.top() + tmp1;
				st.pop();
			}

			st.pop();

			if (!st.empty() && st.top() == "-") {
				for (auto& x : tmp1) {
					if (x == '+') x = '-';
					else if (x == '-') x = '+';
				}
			}

			st.push(tmp1);
		}
		else
			st.push(string(1, s[i]));
	}

	return st.top();
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		string s;
		cin >> s;

		s = xoa_ngoac(s);

		string s1;
		cin >> s1;

		s1 = xoa_ngoac(s1);

		if (s == s1) cout << "YES\n";
		else cout << "NO\n";

	}

	return 0;
}