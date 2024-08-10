/*
* @Author: hungeazy
* @Date:   2024-08-01 22:00:26
* @Last Modified by:   hungeazy
* @Last Modified time: 2024-08-01 22:15:46
*/
#include <bits/stdc++.h>
// #pragma GCC optimize("O3")  
// #pragma GCC optimize("unroll-loops")  
// #pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")  
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int long long
#define ull unsigned long long
#define sz(x) x.size()
#define sqr(x) (1LL * (x) * (x))
#define all(x) x.begin(), x.end()
#define fill(f,x) memset(f,x,sizeof(f))
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define FOD(i,r,l) for(int i=r;i>=l;i--)
#define ii pair<int,int>
#define iii pair<int,ii>
#define di pair<ii,ii>
#define vi vector<int>
#define vii vector<ii>
#define mii map<int,int>
#define fi first
#define se second
#define pb push_back
#define MOD 1000000007
#define __lcm(a,b) (1ll * ((a) / __gcd((a), (b))) * (b))
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define MASK(i) (1LL << (i))
#define c_bit(i) __builtin_popcountll(i)
#define BIT(x,i) ((x) & MASK(i))
#define SET_ON(x,i) ((x) | MASK(i))
#define SET_OFF(x,i) ((x) & ~MASK(i))
#define oo 1e18
#define name "EXPER"
#define endl '\n'
#define time() cerr << endl << "-------------Time:" << 1000.0 * clock() / CLOCKS_PER_SEC << "ms.";
template<typename T> bool maximize(T &res, const T &val) { if (res < val){ res = val; return true; }; return false; }
template<typename T> bool minimize(T &res, const T &val) { if (res > val){ res = val; return true; }; return false; }
const int N = (int)1e6+10;
int a[N],n;
vi g[N];

namespace hungeazy {

	int dp[N][4],b[5],ans=-oo;

	void DFS(int u, int p)
	{
		for (int v : g[u])
			if (v != p)
			{
				DFS(v,u);
				b[3] = dp[u][3]+dp[v][2];
				b[0] = max(dp[u][0]+dp[v][2],dp[u][3]+dp[v][0]);
				b[1] = max(dp[u][1]+dp[v][2],dp[u][3]+dp[v][1]);
				b[2] = max({dp[u][3]+dp[v][2],dp[u][2]+dp[v][2],dp[u][0]+dp[v][1],dp[u][1]+dp[v][0]});
				ans = max(ans,b[2]);
				dp[u][0] = b[0]; dp[u][1] = b[1]; dp[u][2] = b[2]; dp[u][3] = b[3];
			}
	}

	void solve(void)
	{
		FOR(i,1,n) dp[i][0] = -a[i], dp[i][1] = a[i], dp[i][2] = 0;
    	dp[0][0] = dp[0][1] = -oo; dp[0][2] = 0;
		g[0].pb(1);
		DFS(0,-1);
		cout << ans;
	}
	
}

signed main()
{
    fast;
    if (fopen(name".inp","r"))
    {
    	freopen(name".inp","r",stdin);
    	freopen(name".out","w",stdout);
    }
    cin >> n;
    FOR(i,1,n) cin >> a[i];
    FOR(i,1,n-1)
    {
    	int u,v;
    	cin >> u >> v;
    	g[u].pb(v); g[v].pb(u);
    }
    hungeazy::solve();
    time();
    return 0;
}
// ██░ ██  █    ██  ███▄    █   ▄████
//▓██░ ██▒ ██  ▓██▒ ██ ▀█   █  ██▒ ▀█▒
//▒██▀▀██░▓██  ▒██░▓██  ▀█ ██▒▒██░▄▄▄░
//░▓█ ░██ ▓▓█  ░██░▓██▒  ▐▌██▒░▓█  ██▓
//░▓█▒░██▓▒▒█████▓ ▒██░   ▓██░░▒▓███▀▒
// ▒ ░░▒░▒░▒▓▒ ▒ ▒ ░ ▒░   ▒ ▒  ░▒   ▒
// ▒ ░▒░ ░░░▒░ ░ ░ ░ ░░   ░ ▒░  ░   ░
// ░  ░░ ░ ░░░ ░ ░    ░   ░ ░ ░ ░   ░
// ░  ░  ░   ░              ░       ░