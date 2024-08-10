#include<bits/stdc++.h>
#define FORU(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define MASK(x) (1LL << (x))
#define BIT(x, i) (((x) >> (i)) & 1)
#define ALLONE(x) (MASK(x) - 1)
#define ALL(v) (v).size()
#define SZ(v) (int)(v).size()
#define ll long long
#define fi first
#define se second
#define TASK "COUNTRY"
#define NMAX 200005
#define INF 1000000007
using namespace std;

#define         tct template<class MITSURII,class CHANN>
tct bool minimize(MITSURII &x,const CHANN &y) {if(x > y) {x = y ; return true ; }else return false ;}
tct bool maximize(MITSURII &x,const CHANN &y) {if(x < y) {x = y ; return true ; }else return false ;}

 
int N, K, used[NMAX];
pair<int, int> dp[NMAX];
vector<int> adj[NMAX];
 
void dfs(int u, int p, int LIM) {
        used[u] = false;
 		int cnt = 0 ;
        int d = 0 ;
        for(int v : adj[u]) if(v != p) {
                dfs(v, u, LIM);
                d++ ; 
        }
 
        if(d==0) {
                dp[u] = make_pair(0, 0);
                return;
        }
 
        int need = 0, base = INF;
        for(int v : adj[u]) if(v != p) {
                if(dp[v].fi == 0) maximize(need,dp[v].se + 1);
                else minimize(base, dp[v].se + 1);
        }
 
        if(need + base <= LIM) dp[u] = make_pair(1, base);
        else {
                dp[u] = make_pair(0, need);
                if(need == LIM) {
                    used[u] = true;
                    cnt++ ;
                    if(cnt > K) return ; 
                    dp[u] = make_pair(1, 0);
                }
        }
}
 
bool chk(int LIM) {
        dfs(1, 0, LIM);
 
        if(dp[1].fi == 0) used[1] = true;
        int cnt = 0;
        FORU(i, 1, N) cnt += used[i];
 
        return cnt <= K;
}
 
int main(void) {
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
        cin >> N >> K;
        FORU(i, 1, N - 1) {
                int u, v; cin >> u >> v;
                adj[u].push_back(v);
                adj[v].push_back(u);
        }
 
        int lo = 1, hi = N / 10 + 10 , res;
        while(lo <= hi) {
                int mid = (lo + hi) >> 1 ;
                if(chk(mid)) {
                        res = mid;
                        hi = mid - 1;
                }
                else lo = mid + 1;
        }
 
        cout << res;
}