#include <bits/stdc++.h>
using namespace std;
#define uwu "estimation"

typedef long long ll;
#define int long long
#define pb push_back
#define endl '\n'
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
const int N = 2000 + 3;
const int INF = 1e9 + 7;

int n, k, a[N], b[N];
vector <int> val;

int num[N];
int sum[N];

ll cost[N][N];

ll dp[N][30];

void update(int p, int val){
	for(; p <= n; p += p & (-p)){
		num[p]++; sum[p] += val;
	} 
}
int getnum(int p){
	int ans = 0;
	for(; p > 0; p -= p & (-p)) ans += num[p];
	return ans;
}
int getsum(int p){
	int ans = 0;
	for(; p > 0; p -= p & (-p)) ans += sum[p];
	return ans;
}
void compress(){
	FOR(i, 1, n) val.pb(a[i]);
	sort(val.begin(), val.end());
	val.resize(unique(val.begin(), val.end()) - val.begin());
	FOR(i, 1, n) b[i] = upper_bound(val.begin(), val.end(), a[i]) - val.begin();
}
void solve(void){
	compress();


	FOR(l, 1, n){
		FOR(i, 1, n) num[i] = sum[i] = 0;

		int s = 0;
		FOR(r, l, n){
			update(b[r], a[r]); s += a[r]; 
			// if (r == l) continue;

			int tmp = (r - l) / 2 + 1;

			int d = 1, c = n, res = -1;
			while(d <= c){
				int mid = (d + c) / 2;
				if (getnum(mid) >= tmp) res = mid, c = mid - 1;
				else d = mid + 1;
			}


			ll m = val[res - 1]; 
			cost[l][r] = (s - getsum(res)) - m * (r - l + 1 - getnum(res)) +  m * getnum(res - 1) - getsum(res - 1);
// 			cout << l << ' ' << r << " " << cost[l][r] << endl;
		}
	}
	FOR(i,1,n) FOR(j,1,n) {
 		cout << i << ' ' << j << ' ' << cost[i][j] << endl ;
 	}
	memset(dp, 0x3f, sizeof(dp)); dp[0][0] = 0;
	FOR(i, 1, n) FOR(j, 1, k) FOR(t, 1, i) dp[i][j] = min(dp[i][j], dp[t - 1][j - 1] + cost[t][i]);
	FOR(i,1,n) {
		FOR(j,1,k) {
			cout << i << ' ' << j << ' ' << dp[i][j] << endl ; 
		}
	}
	cout << dp[n][k]; 
}
signed main(){
 	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	if(fopen(uwu".inp","r")){
		freopen(uwu".inp","r",stdin);
		freopen(uwu".ans","w",stdout);
	}

	cin >> n >> k;
	FOR(i, 1, n) cin >> a[i];

	solve();

	cerr << "\nTime used: " << clock() << "ms\n";
	return 0;
}