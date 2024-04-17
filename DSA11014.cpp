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
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define F(i, a, b) for(int i = a; i < b; ++i)
#define FD(i, a, b) for(int i = a; i > b; --i)
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(), (x).end()
#define endl '\n'

int d = 0;
bool check = true;

string res1 = "";
string res2 = "";

long long sum = 0;

class Node {
public:
	int x;
	Node* left;
	Node* right;

	Node(int x) {
		this->x = x;
		left = nullptr;
		right = nullptr;
	}
};

unordered_map<int, Node*> mp;


void connect(Node* r, int u, int v, char c) {

	if (c == 'L') {

		mp[u]->left = new Node(v);

		mp[v] = mp[u]->left;

	}

	else {

		mp[u]->right = new Node(v);

		mp[v] = mp[u]->right;

	}

}

bool isLeaf(Node* r) {
	if (r->left == nullptr && r->right == nullptr) return true;
	return false;
}

void inOrder(Node* r) {
	if (r != nullptr) {
		if (r->right && isLeaf(r->right)) sum += r->right->x;
		if (r->left && !isLeaf(r->left))
			inOrder(r->left);
		if (r->right && !isLeaf(r->right))
			inOrder(r->right);
	}
}

int calc(Node* root) {
	int sum = 0;
	if (root == NULL)
		return sum;
	if (root->right != NULL && isLeaf(root->right)) {
		sum += root->right->x;
	}
	if (root->right != NULL && !isLeaf(root->right)) {
		sum += calc(root->right);
	}
	if (root->left != NULL && !isLeaf(root->left)) {
		sum += calc(root->left);
	}
	return sum;
}

int main() {
	faster();
	int t;
	cin >> t;

	while (t--) {
		mp.clear();
		int n;
		cin >> n;

		Node* root = nullptr;

		while (n--) {
			int u, v;
			char c;

			cin >> u >> v >> c;

			if (root == nullptr) {

				root = new Node(u);

				mp[u] = root;

				connect(root, u, v, c);



			}

			else

				connect(root, u, v, c);
		}

		/*sum = 0;
		inOrder(root);
		cout << sum << endl;*/

		cout << calc(root) << '\n';

	}
	return 0;
}