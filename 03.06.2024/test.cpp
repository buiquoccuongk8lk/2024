/* ---------------------- *
 *   * Code by watbor     *
 *   * Need Her and VOI   *
 *   :>                   *
--------------------------*/
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define rep(i,a,b) for(int i(a) ; i <= b ; i++) 
#define repd(i,a,b) for(int i(a) ; i >= b ; i--)
typedef vector<int> vi ;
typedef pair<int,int> ii ;
typedef vector<ii> vii ; 

typedef long long int lli;

const lli maxn = lli(5e5)+5, base = 29, MOD = lli(1e9)+7;

string S[maxn];
pair<string, lli> tmp[maxn];
vector<lli> hsh[maxn];

lli LCP(lli a, lli b)
{
	lli L = 0, R = min(lli(S[a].size()), lli(S[b].size())), ans = -1;

	while(L <= R)
	{
		lli mid = (L+R)/2;
		if(hsh[a][mid] == hsh[b][mid]) L = mid+1, ans = max(ans, mid);
		else R = mid-1;
	}
	return ans;
}

signed main(void)
{
	#define TASK ""
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".INP","r") ) {
        freopen(TASK".INP","r",stdin) ; freopen(TASK".OUT","w",stdout);
    }
    int n , q ;
	cin >> n >> q ;
	for(lli i = 0;i < n;i++)
	{
		cin >> S[i];
		tmp[i] = {S[i], i};
	}
	sort(tmp, tmp+n), sort(S, S+n);
	lli ctr = 0;
	map<lli, lli> revmap;
	for(lli i = 0;i < n;i++) revmap[tmp[i].second] = ctr++;

	for(lli i = 0;i < n;i++)
	{
		lli cur = 1;
		hsh[i].push_back(cur);
		for(auto it: S[i])
		{
			cur *= base%MOD;
			cur %= MOD;
			cur += lli(it-'a');
			cur %= MOD;
			hsh[i].push_back(cur);
		}
	}

	while(q--)
	{
		int k, l, res = 0, idx;
		cin >> k >> l ;
		vector<lli> X;
		for(lli i = 0;i < k;i++)
		{
			cin >> idx ;
			idx--;
			X.push_back(revmap[idx]);
		}

		sort(X.begin(), X.end());

		for(lli i = 0;i <= k-l;i++)
		{
			lli tot = LCP(X[i], X[i+l-1]), diffA = 0, diffB = 0;
			if(i+l < k) diffA = LCP(X[i], X[i+l]);
			if(i) diffB = LCP(X[i-1], X[i]);

			res += tot-min(max(diffA, diffB), tot);
		}
		cout << res << '\n' ;
	}
}