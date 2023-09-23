#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;


int main() {
	int n, x;
	cin >> n >> x;
	vector<int> a(n-1);
	for (int &y: a) cin >> y;
	for (int y = 0; y <= 100; y++) {

		vector<int> b = a;

		b.push_back(y);
		sort(begin(b), end(b));
		int z = accumulate(begin(b), end(b), 0) - b[0] - b[n-1];
		if (z >= x) {
			cout << y << '\n';
			return 0;
		}
        
	}
	cout << -1 << '\n';
}
