#include <bits/stdc++.h>
using namespace std;

int cl () {
	cerr << "Time used: " << 1.0 * clock() / CLOCKS_PER_SEC << "s ";
	return 0;
}

const int N = (int)7e3, mod = 998244353;

void add (int &x, int y) {
	x += y;
	if (x >= mod) x -= mod;
}

int n;
string s;

int f[N + 1][N + 1];

namespace sub3 {
	bool check (int i, int j) {
		for (int t(i - j); t < i; ++t) {
			if (s[t] > s[t - j]) return true;
			if (s[t] < s[t - j]) return false;
		}
		return s[i - 1] > s[i - j - 1];
	}

	int solve () {
		for (int i(1); i <= n; ++i) f[i][i] = 1;
		for (int i(2); i <= n; ++i) for (int j(1); j < i; ++j) if (s[i - j] != '0') {
			for (int h(1), lim(min(j - 1, i - j)); h <= lim; ++h) {
				add(f[i][j], f[i - j][h]);
			}
			if (j <= i - j && check(i, j)) add(f[i][j], f[i - j][j]);
		}

		int ans = 0;
		for (int j(1); j <= n; ++j) add(ans, f[n][j]);
		cout << ans;

		return cl();
	}
}

int sum[N + 1][N + 1];

namespace sub4 {
	bool checksub () {
		for (int i(1); i < n; ++i) if (s[0] != s[i]) return false;
		return true;
	}

	int solve () {
		for (int i(1); i <= n; ++i) f[i][i] = 1;
		sum[1][1] = 1;
		for (int i(2); i <= n; ++i) for (int j(1); j <= i; ++j) {
			if (s[i - j] != '0') {
				add(f[i][j], sum[i - j][min(j - 1, i - j)]);
			}
			sum[i][j] = sum[i][j - 1];
			add(sum[i][j], f[i][j]);
		}

		cout << sum[n][n];

		return cl();
	}
}

namespace sub5 {
	const int sm[2] = {(int)1e9 + 21, (int)1e9 + 87}, base = 377;
	int has[2][N + 1], Pow[2][N + 1];

	void buildhash () {
		for (int t(0); t < 2; ++t) {
			Pow[t][0] = 1;
			for (int i(1); i <= n; ++i) {
				Pow[t][i] = 1ll * Pow[t][i - 1] * base % sm[t];
				has[t][i] = (1ll * has[t][i - 1] * base % sm[t] + s[i - 1]) % sm[t];
			}
		}
	}

	pair <int, int> gethash (int l, int r) {
		int fi = (has[0][r] - 1ll * has[0][l - 1] * Pow[0][r - l + 1] % sm[0] + sm[0]) % sm[0];
		int se = (has[1][r] - 1ll * has[1][l - 1] * Pow[1][r - l + 1] % sm[1] + sm[1]) % sm[1];
		return make_pair(fi, se);
	}

	bool check (int i, int j) {
		int l1 = i - j + 1, l2 = l1 - j;
		int l = i - j + 1, r = i, id = i - j;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (gethash(l1, mid) == gethash(l2, mid - j)) l = mid + 1, id = mid;
			else r = mid - 1;
		}
		return id < i && s[id] > s[id - j];
	}

	int solve () {
		buildhash();

		for (int i(1); i <= n; ++i) f[i][i] = 1;
		sum[1][1] = 1;
		for (int i(2); i <= n; ++i) for (int j(1); j <= i; ++j) {
			if (s[i - j] != '0') {
				add(f[i][j], sum[i - j][min(j - 1, i - j)]);
				if (j <= i - j && check(i, j)) add(f[i][j], f[i - j][j]);
			}
			sum[i][j] = sum[i][j - 1];
			add(sum[i][j], f[i][j]);
		}

		cout << sum[n][n];

		return cl();
	}
}

int main () {
	#define PHILE "split"
	ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if (fopen(PHILE".inp", "r")) {
		freopen(PHILE".inp", "r", stdin); freopen(PHILE".out", "w", stdout);
	}

	cin >> s;
	n = s.size();

	if (n <= 600) return sub3 :: solve();
	if (sub4 :: checksub()) return sub4 :: solve();
	return sub5 :: solve();
}