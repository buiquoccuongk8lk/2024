#pragma GCC optimize("trapv")
#include <fstream>
#include <vector>
#include <iostream>
#include <cstring>
#include <set>
#include <tuple>
#include <algorithm>
#include <cassert>
#include <map>

using namespace std;

#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef long double ld;

const ll SZ = 2e5 + 100, MOD = 998244353;

ll n, k;
vector<ll> vec, sml, lrg;
ll ans = 1;
ll fact[SZ];

ll bpow(ll a, ll p) {
	if (p == 0) return 1ll;
	if (p % 2) {
		return (bpow(a, p - 1) * a) % MOD;
	}

	ll b = bpow(a, p / 2);
	return (b * b) % MOD;
}

int main()
{
	fastInp;

	cin >> n >> k;
	vec.resize(n);

	for (auto& c : vec) cin >> c;

	map<ll, ll> calc;
	fact[0] = 1;
	for (auto c : vec) calc[c]++;
	for (int i = 1; i < SZ; i++) fact[i] = (fact[i - 1] * i) % MOD;

	for (auto c : vec) {
		if (c + c < k) {
			sml.push_back(c);
		} else {
			lrg.push_back(c);
		}
	}

	ll closes = 2;
	sort(lrg.begin(), lrg.end());
	sort(sml.begin(), sml.end());
	ll checked = 0;

	for (auto c : sml) {
		while (!lrg.empty() && lrg.back() + c >= k) {
			closes++;
			lrg.pop_back();
		}

		checked++;
		if (closes == 2) {
			closes = 0;
			if (lrg.size() != 0) {
				cout << "0\n";
				return 0;
			}
			if (checked != sml.size()) {
				cout << "0\n";
				return 0;
			}
		} else {
			ans *= (closes - 2) * (closes - 3) % MOD + 2 * (closes - 2);
			ans %= MOD;
			closes--;
		}
	}

	closes += lrg.size();

	ll cc = 1;
	if (closes != 0) {
		cc = fact[closes - 2];
	}
	ans *= cc;
	ans %= MOD;

	for (auto c : calc) {
		ans *= bpow(fact[c.second], MOD - 2);
		ans %= MOD;
	}

	cout << ans << "\n";
	
	return 0;
}