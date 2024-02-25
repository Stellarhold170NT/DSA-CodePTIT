#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <climits>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <stack>
using namespace std;

#define MAX 1000000000 + 5
//#define M 100 + 5
#define N 101
#define MOD (long long)1000000007
#define ll long long
//#define int long long
#define ld long double
#define sz size()
#define F(i, a, b) for (int i = a; i < b; i++)
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define zero(n) setw(n) << setfill('0')
#define stp(n) fixed << setprecision(n)

int main() {
    int t;
    cin >> t;

    cin.ignore();

    while (t--) {
        string s;
        getline(cin, s);

        string s1;
        getline(cin, s1);

        s = s + " + " + s1;

        int i = 0;
        bool flag = true;
        string heso = "";
        string mu = "";
        map<int, int> mp;
        while (i < s.length()) {
            if (isdigit(s[i])) {
                if (flag) {
                    while (isdigit(s[i]) && i < s.length()) heso = heso + s[i++];
                    flag = false;
                }
                else {
                    while (isdigit(s[i]) && i < s.length()) mu = mu + s[i++];
                    mp[stoi(mu)] += stoi(heso);
                    mu = "";
                    heso = "";
                    flag = true;
                }
            }
            else i++;
        }

        string result = "";

        for (auto x : mp) {
            result = " + " + to_string(x.second) + "*x^" + to_string(x.first) + result;
        }

        result.erase(0, 3);
        cout << result << endl;
    }

    return 0;
}