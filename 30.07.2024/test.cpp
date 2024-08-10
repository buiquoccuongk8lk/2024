#include <bits/stdc++.h>
using namespace std;

void cl () {
	cerr << "Time used: " << 1.0 * clock() / CLOCKS_PER_SEC << "s ";
}

const int N = (int)2e5, MAX = (int)1e6;

int n, test;
struct info {
	long long v, w;
} val[3][N + 1];
long long w[3][N + 1];

namespace sub6 {
	long long ma[3][N + 1];
	int f[3][N + 1], x, y, z;

	struct node {
		bool ok; int cnt;
		node (bool _ok = 1, int _cnt = 0) {
			ok = _ok;
			cnt = _cnt;
		}
	} st[4 * MAX + 1];

	void update (int pos, int val) {
		int i = 1, l = 1, r = MAX;
		while (l < r) {
			int mid = (l + r) >> 1;
			if (pos <= mid) r = mid, i <<= 1;
			else l = mid + 1, i = i << 1 | 1;
		}

		st[i].cnt += val;
		if (st[i].cnt < 0) st[i].cnt = 0;

		st[i].ok = (st[i].cnt <= 1);

		while (i >>= 1) {
			st[i].ok = st[i << 1].ok & st[i << 1 | 1].ok;
		}
	}

	bool dd[MAX + 1];

	int getR (int t) {
		int r = 1;
		for (; r <= n && !dd[val[t][r].v]; ++r) {
			dd[val[t][r].v] = 1;
		}
		r = min(r, n);
		for (int i(1); i <= r; ++i) dd[val[t][i].v] = 0;
		return r;
	}

	void setup (int t1, int t2, int r) {
		int t = (t1 == 0 && t2 == 1 ? 0 : t2 + 1);

		for (int i(1); i <= r; ++i) {
			update(val[t2][i].v, 1);
		}

		f[t][0] = r;
		for (int i(1); i <= n; ++i) {
			update(val[t1][i].v, 1);
			while (r > 0 && !st[1].ok) {
				update(val[t2][r].v, -1);
				--r;
			}
			f[t][i] = r;
		}

		for (int gay(1); gay <= 4 * MAX; ++gay) {
			st[gay] = node(1, 0);
		}
	}

	int rev[N + 1];

	void prep () {
		x = getR(0); y = getR(1); z = getR(2);
		setup(0, 1, y);
		setup(2, 0, x);
		setup(2, 1, y);

		for (int i(1); i <= n; ++i) rev[f[0][i]] = i;
		for (int i(n - 1); i >= 1; --i) rev[i] = max(rev[i], rev[i + 1]);
	}
	
	long long res[N + 2];

	void xuly () {
		long long sum = 0;
		for (int t(0); t < 3; ++t, sum = 0) for (int i(1); i <= n; ++i) {
			sum += val[t][i].w;
			ma[t][i] = max(ma[t][i - 1], sum);
		}

		int l = x, r = 0;

		/*for(int i = 1 ; i <= n ; i++) cout << w[0][i] << ' ' ;
        cout << endl ;
        for(int i = 1 ; i <= n ; i++)  cout << w[1][i] << ' ' ;
        cout << endl;
        for(int i = 1 ; i <= n ; i++)  cout << w[2][i] << ' ' ;
        cout << endl ;
*/
		long long ans = 0;
		for (int i(z); i >= 0; --i) {
			res[i] = res[i + 1];
			while (r <= x && r <= f[1][i]) {
				if (l < r) {
					res[i] = max(res[i], ma[0][r] + ma[1][f[0][r]]);
				}
				++r;
			}
			while (l >= 0 && f[0][l] <= f[2][i]) {
				if (l < r) {
					res[i] = max(res[i], ma[0][l] + ma[1][f[0][l]]);
				}
				--l;
			}
			if (f[2][i] <= f[0][f[1][i]]) {
				res[i] = max(res[i], ma[0][f[1][i]] + ma[1][f[2][i]]);
			} else {
				res[i] = max(res[i], ma[0][rev[f[2][i]]] + ma[1][f[2][i]]);
			}
			//cout << l << ' ' << r << ' ' << i << endl ;

			//cout << res[i] << ' ' << ma[2][i] << ' ' << ma[2][i] + res[i] << endl ; 
			ans = max(ans, res[i] + ma[2][i]);
		}

		//for(int i = 1 ; i <= n ; i++) cout << ma[0][i] << ' ' ; 

		cout << ans << '\n';
	}

	void solve () {
		prep();

		for (int t(0); t < 3; ++t) for (int i(1); i <= n; ++i) {
			val[t][i].w = w[t][i];
		}

		xuly();

		int e = 0, c = 0;
		while (--test) {
			cin >> e >> c;
			for (int t(0); t < 3; ++t) for (int i(1); i <= n; ++i) {
				val[t][i].w = (((w[t][i] + 1048576) ^ e) + c) % 2097152 - 1048576;
			}
			xuly();
		}
	}
}

int main () {
	#define PHILE ""
	ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if (fopen(PHILE".inp", "r")) {
		freopen(PHILE".inp", "r", stdin); freopen(PHILE".ans", "w", stdout);
	}

	cin >> test;
	cin >> n;
	for (int t(0); t < 3; ++t) {	
		for (int i(1); i <= n; ++i) cin >> val[t][i].v;
		for (int i(1); i <= n; ++i) cin >> w[t][i];
	}

	sub6 :: solve();

	cl();
	return 0;
}