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
#define N 600000

#define MOD (ll) 998244353
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
		string s;
		cin >> s;

		stack<char> st;


		for (int i = 0; i < s.length(); i++) {
			if (s[i] == ']') {
				string res = "";
				while (!st.empty() && st.top() != '[') {
					res = st.top() + res;
					st.pop();
				}

				st.pop();

				string num = "";

				while (!st.empty() && isdigit(st.top())) {
					num = st.top() + num;
					st.pop();
				}

				if (num == "") num = "1";
				string x = res;

				for (int j = 0; j < stoi(num) - 1; j++) {
					res = res + x;
				}

				for (int j = 0; j < res.length(); j++) {
					st.push(res[j]);
				}
			}
			else {
				st.push(s[i]);
			}
		}

		string ans = "";

		while (!st.empty()) {
			ans = st.top() + ans;
			st.pop();
		}

		cout << ans << endl;

	}

	return 0;
}