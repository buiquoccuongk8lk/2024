#include <bits/stdc++.h>
using namespace std ;
#define ll long long
#define pb push_back
#define all(a) a.begin(),a.end()
#define FOR(i,a,b) for(int i(a) ; i <= b ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= b ; i--)
#define TIME 1.0 * clock() / CLOCKS_PER_SEC

const int maxn = 1e5 + 5 ;
const ll inf = 1e18 ;

int n ;
int a[maxn] ;

void init(void) {
    cin >> n ;
    FOR(i,1,n) cin >> a[i] ;
}

namespace sub1 {

    ll w[2005][2005] ; // đường đi từ i->j
    ll f[maxn] ;

    void solve(void) {

        FOR(i,1,n) f[i] = inf ;

        f[0] = 0 ;

        FOR(i,1,n) {
            w[i][i] = 0 ;
            FOR(j,i+1,n) {
                w[i][j] = w[i][j-1] + abs(a[j] - a[j-1]) ;
            }
        }

        f[1] = abs(a[1]) ;
        //cout << w[1][3] ;
        FOR(i,2,n) {
            //f[i] = w[1][i] ;
            FOR(j,1,i-1) {
                f[i] = min(f[i] , f[j] + abs(a[i] - a[j-1]) + w[j][i-1] ) ;
            }
        }

        ll ans = inf ;
        FOR(i,1,n) ans = min(ans , f[i] + w[i][n]) ;
        cout << ans ;
    }

}

namespace sub2 {

    ll dp[maxn] ;
    ll st[4*maxn][3] ;
    ll sum[maxn] ;
    ll w[2005][2005] ;

    void update(int id,int l,int r,int pos,ll val,int t) {
        if(pos < l or pos > r) return ;
        if(l==r) {
            st[id][t] = min(st[id][t],val) ;
            return ;
        }
        int mid = (l+r)>>1 ;
        update(id<<1,l,mid,pos,val,t) ;
        update(id<<1|1,mid+1,r,pos,val,t) ;
        st[id][t] = min(st[id<<1][t],st[id<<1|1][t]) ;
    }

    ll get(int id,int l,int r,int u,int v,int t) {
        if(l > v or r < u) return inf ;
        if(l >= u and r <= v) return st[id][t] ;
        int mid = (l+r)>>1 ;
        return min(get(id<<1,l,mid,u,v,t),get(id<<1|1,mid+1,r,u,v,t)) ;
    }

    unordered_map<int,int>mp ;

    void solve(void) {

        FOR(i,1,n) dp[i] = inf ;

        vector<int> vec ;

        FOR(i,1,n) sum[i] = sum[i-1] + abs(a[i] - a[i-1]) ;

        dp[0] = 0 ;

        FOR(i,0,n) vec.pb(a[i]) ;

        sort(all(vec)) ;

        vec.resize(unique(all(vec)) - vec.begin()) ;

        FOR(i,0,(int)vec.size()-1) mp[vec[i]] = i + 1 ;

        FOR(i,1,4*n) st[i][1] = st[i][2] = inf ;

        dp[1] = abs(a[1]) ;

        update(1,1,n + 2,mp[a[0]],dp[1] + a[0] - sum[1],1) ;

        update(1,1,n + 2,mp[a[0]],dp[1] - a[0] - sum[1],2) ;

        FOR(i,2,n) {
            dp[i] = sum[i-1] - a[i] + get(1,1,n + 2,mp[a[i]],n + 2,1) ;
            dp[i] = min(dp[i] , a[i] + sum[i-1] + get(1,1,n + 2,1,mp[a[i]],2) ) ;
            update(1,1,n + 2,mp[a[i-1]],dp[i] + a[i-1] - sum[i],1) ;
            update(1,1,n + 2,mp[a[i-1]],dp[i] - a[i-1] - sum[i],2) ;
        }

        ll ans = inf ;

        FOR(i,1,n) ans = min(ans,dp[i] + sum[n] - sum[i]) ;

        cout << ans ;
    }

}

signed main(void) {
    #define TASK ""
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".INP","r") ) {
        freopen(TASK".INP","r",stdin) ; freopen(TASK".OUT","w",stdout);
    }
    init() ;
    //sub1::solve() ;
    //cout << endl ;
    sub2::solve() ;
    cerr << endl << "watborhihi : " << TIME << "s  " << endl;
    return (0 ^ 0) ;
}
