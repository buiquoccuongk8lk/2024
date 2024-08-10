#include <bits/stdc++.h>
using namespace std ;
#define int long long
#define ll long long
#define pb push_back
#define all(a) a.begin(),a.end()
#define FOR(i,a,b) for(int i(a) ; i <= b ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= b ; i--)
#define TIME 1.0 * clock() / CLOCKS_PER_SEC

const int maxn = 1e5 + 5 ;
const int mod = 1e9 + 7 ;

int n ;
int a[maxn] ;

void init(void) {
    cin >> n ;
    FOR(i,1,n) cin >> a[i] ;
}

namespace sub1 {
    void solve(void) {

        int ans = 0 ;

        FOR(mask,0,(1<<n)-1) {
            vector<int> ones ;
            FOR(i,0,n-1) if((mask>>i)&1) ones.pb(i+1) ;
            bool ok = true ;
            for(auto i : ones) {
                for(auto j : ones) {
                    for(auto k : ones) {
                        if(i < j and j < k) {
                            if( (a[i]-a[j]) * (a[j]-a[k]) < 0) {
                                ok = false ;
                                break ;
                            }
                        }
                        if(!ok) break ;
                    }
                }
                if(!ok) break ;
            }
            ans+=ok ;
            ans%=mod ; 
        }
        cout << ans ;
    }
}

namespace sub2 {

    int dp[1005][1005] ;

    void solve(void) {
        FOR(i,1,n) FOR(j,i,n) dp[i][j] = 1 ;
        FOR(i,1,n) {
            FOR(j,i+1,n) {
                FORD(k,i-1,1) {
                    if( (a[k]-a[i])*(a[i]-a[j]) >= 0) {
                        dp[i][j] = (dp[i][j] + dp[k][i])%mod ;
                    }
                }
            }
        }
        int ans = 0 ;
        FOR(i,1,n) FOR(j,i,n) ans = (ans + dp[i][j])%mod ;
        cout << (ans + 1)%mod ;
    }

}

namespace sub3 {

    ll st[4*maxn] , dp[maxn] ;

    void update(int id,int l,int r,int pos,ll val) {
        if(pos < l or pos > r) return ;
        if(l==r) {
            st[id]+=val ;
            st[id]%=mod ;
            return ;
        }
        int mid = (l+r)>>1 ;
        update(id<<1,l,mid,pos,val) ;
        update(id<<1|1,mid+1,r,pos,val) ;
        st[id] = (st[id<<1] + st[id<<1|1])%mod ;
    }

    ll get(int id,int l,int r,int u,int v) {
        if(l > v or r < u) return 0 ;
        if(l >= u and r <= v) return st[id] ;
        int mid = (l+r)>>1 ;
        return (get(id<<1,l,mid,u,v) + get(id<<1|1,mid+1,r,u,v))%mod ;
    }

    void solve(void) {

        vector<int> vec ;
        FOR(i,1,n) vec.pb(a[i]) ;
        sort(all(vec)) ;
        vec.resize(unique(all(vec)) - vec.begin()) ;
        FOR(i,1,n) a[i] = lower_bound(all(vec),a[i]) - vec.begin() + 1 ;

        ll ans = 0 ;
        FOR(i,1,n) {
            dp[i] = 1 ;
            dp[i]+= get(1,1,n,1,a[i]) ;
            update(1,1,n,a[i],dp[i]) ;
        }

        FOR(i,1,n) ans = (ans + dp[i])%mod ;
        ans-=n ;
        //cout << ans << endl ;

        FOR(i,1,4*n) st[i] = 0 ;
        FOR(i,1,n) dp[i] = 0 ;

        FOR(i,1,n) {
            dp[i] = 1 ;
            dp[i]+= get(1,1,n,a[i],n) ;
            update(1,1,n,a[i],dp[i]) ;
        }

        FOR(i,1,n) ans = (ans + dp[i])%mod ;

        cout << ( ans + 1 ) %mod ;
    }

}

signed main(void) {
    #define mitsurichannn ""
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(mitsurichannn".INP","r") ) {
        freopen(mitsurichannn".INP","r",stdin) ; freopen(mitsurichannn".OUT","w",stdout);
    }
    init() ;
    if(n <= 20) sub1::solve() ;
    else if(n <= 1005) sub2::solve() ;
    else sub3::solve() ; 
    cerr << endl << "watborhihi : " << TIME << "s  " << endl;
    return (0 ^ 0) ;
}