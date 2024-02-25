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
#define N 200

#define MOD (ll) 1000000007
#define ld long double
#define sz size()
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define zero(n) setw(n) << setfill('0')
#define stp(n) fixed << setprecision(n)

int n;
string operation = "+-*/";
vector<string> v;

class Node {
public:
	Node* left;
	Node* right;
	string c;

	Node(string c) {
		this->c = c;
		this->left = nullptr;
		this->right = nullptr;
	}
};

Node* createNode(string c) {
	Node* node = new Node(c);
	return node;
}

Node* buildTree(Node* r, int i) {
	if (i < n) {
		r = createNode(v[i]);
		r->left = buildTree(r->left, i * 2 + 1);
		r->right = buildTree(r->right, i * 2 + 2);
	}

	return r;
}

void inOrder(Node* s) {
	if (s != nullptr) {
		inOrder(s->left);
		cout << s->c;
		inOrder(s->right);
	}
}

int calc(Node* s) {
	if (operation.find(s->c[0]) == string::npos) {
		return stoi(s->c);
	}
	else {
		if (s->c[0] == '+') return calc(s->left) + calc(s->right);
		else
			if (s->c[0] == '-') return calc(s->left) - calc(s->right);
			else
				if (s->c[0] == '*') return calc(s->left) * calc(s->right);
				else
					if (s->c[0] == '/') return calc(s->left) / calc(s->right);
	}
}

int main() {
	int t;
	cin >> t;


	while (t--) {
		cin >> n;

		v.resize(n);

		for (auto& i : v) cin >> i;

		Node* root = nullptr;
		root = buildTree(root, 0);

		cout << calc(root);
		cout << endl;
	}

	return 0;
}