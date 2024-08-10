/* ---------------------- *
 *   * Code by watbor     *
 *   :>                   *
--------------------------*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define myClass class WORK,class HARD
#define tct template<myClass>
#define ll long long 
#define fi first
#define se second
#define pb push_back
#define ii pair<int,int>
#define vii vector<ii>
#define vi vector<int>
#define endl '\n' 
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define FOR(i,a,b) for(int i(a) ; i <= b ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= b ; i--)
#define FORN(i,a,b) for(int i(a) ; i < b ; i++)
#define uni(a) sort(all(a)) , a.resize(unique(a.begin(),a.end())-a.begin()) 

const int N = 3e5 + 5 ;
const int LO = 17 ;
const int base = 311 ;
const int M = 1e3 + 5 ; 
const int oo = 2e9 ; 
const long long inf = 1e18 ;
const long long MOD = 1e9 + 7 ;

const int dx[] = {-1,1,0,0} ;
const int dy[] = {0,0,-1,1} ; 

tct bool minimize(WORK &x,const HARD &y) {if(x > y) {x = y ; return true ; }else return false ;}
tct bool maximize(WORK &x,const HARD &y) {if(x < y) {x = y ; return true ; }else return false ;}

int n , k ; 
int a[N] ; 

void init(void) {
	cin >> n >> k ; 
	FOR(i,1,n) cin >> a[i] ; 
}


namespace sub1 {

	ll dp[35][35] ; 
    ll pre[35] ; 

	void solve(void) {

        FOR(i,1,n) {
            FOR(j,0,k) dp[i][j] = -inf ; 
        }

        FOR(i,1,n) pre[i] = pre[i-1] + a[i] ; 

        dp[0][0] = 0 ;

        FOR(i,1,n) {
            dp[i][1] = pre[i] ; 
        }

        FOR(i,1,n) {
            FOR(j,1,k) {
                FOR(v,1,i-1) {
                    FOR(u,v+1,i-1) {
                         maximize(dp[i][j],dp[v][j-1] + (pre[i] - pre[u-1]) ) ; 
                    }
                }
            }
        }   

        ll ans = 0 ; 
        FOR(i,1,n) FOR(j,0,k) maximize(ans,dp[i][j]) ; 

        cout << ans ; 
	}

}

namespace sub2 {
    ll dp[505][505] ;
    ll pre[505] ;
    const int Lomini = __lg(500) + 1 ;
    ll rmq[505][Lomini] ; 

    ll get_min(int l,int r) {
        int K = __lg(r-l+1) ; 
        return min(rmq[l][K],rmq[r-(1<<K)+1][K]) ; 
    }

    void solve(void) {

        FOR(i,1,n) pre[i] = pre[i-1] + a[i] ;

        FOR(i,0,n) FOR(j,0,k) dp[i][j] = -inf ; 

        FOR(i,0,n) dp[i][1] = pre[i] ; 
        FOR(i,1,n) dp[i][0] = 0 ;

        FOR(i,1,n) rmq[i][0] = pre[i] ; 

        for(int j(1) ; (1<<j) <= n ; j++) {
            for(int i(1) ; i + (1<<j) - 1 <= n ; i++) {
                rmq[i][j] = min(rmq[i][j-1],rmq[i+(1<<(j-1))][j-1]) ; 
            }
        }

        FOR(i,1,n) FOR(j,1,k) {
            FOR(v,1,i-1) {
                ll mini = get_min(v,i) ; 
                maximize(dp[i][j],dp[v][j-1] + pre[i] - mini) ;
            }
        }

        ll ans = 0 ; 

        FOR(i,1,n) FOR(j,0,k) maximize(ans,dp[i][j]) ; 

        cout << ans ;

    }

}

namespace sub3 {

    ll dp[2005][2005] ;
    const int Lomini = __lg(2000) + 1 ;

    ll pre[2005] ;
    ll rmq[2005][Lomini] ; 

    ll get_min(int l,int r) {
        int K = __lg(r-l+1) ; 
        return min(rmq[l][K],rmq[r-(1<<K)+1][K]) ; 
    }


    void DAC(int kk, int L,int R,int opL,int opR) {
        if(L>R) return ;
        int mid = (L+R)>>1;
        int pos = mid ; 
        FOR(i,opL,min(mid,opR)) {
            if(dp[mid][kk] < dp[i][kk-1] + pre[mid] - get_min(i,mid)) {
                pos = i;
                dp[mid][kk] = dp[i][kk-1] + pre[mid] - get_min(i,mid) ; 
            }
        }
        DAC(kk,L,mid-1,opL,pos);
        DAC(kk,mid+1,R,pos,opR);
    }

    void solve(void) {

        FOR(i,1,n) pre[i] = pre[i-1] + a[i] ;

        FOR(i,0,n) FOR(j,0,k) dp[i][j] = -inf ; 

        FOR(i,0,n) dp[i][1] = pre[i] ; 

        FOR(i,0,n) dp[i][0] = 0 ;

        FOR(i,1,n) rmq[i][0] = pre[i] ; 

        for(int j(1) ; (1<<j) <= n ; j++) {
            for(int i(1) ; i + (1<<j) - 1 <= n ; i++) {
                rmq[i][j] = min(rmq[i][j-1],rmq[i+(1<<(j-1))][j-1]) ; 
            }
        }

        ll ans = 0 ;

        FOR(l,1,k) DAC(l,1,n,1,n) ;

        FOR(i,1,n) maximize(ans,dp[i][k]) ; 

        cout << ans ;
    }

}

namespace sub4 {
    ll pre[N] , mini[N] ; 
    void solve(void) {
        FOR(i,1,n) pre[i] = pre[i-1] + a[i] ;
        ll ans = 0 ;
        FOR(i,1,n) {
            mini[i] = min(mini[i-1],pre[i]) ; 
            maximize(ans,pre[i] - mini[i]) ; 
        }
        cout << ans ; 
    }
}

namespace sub5 {

    void solve(void) {
        ll ans = 0 ;
        FOR(i,1,n) ans+= a[i] ; 
        cout << ans ; 
    }

}

bool CheckSubOneAm() {
    int cnt = 0 ;
    FOR(i,1,n) cnt+=(a[i] < 0) ; 
    return (cnt <= 1) ;
}

namespace sub6 {
    ll pre[N] ;
    void solve(void) {
        int pos = -1 ; 
        FOR(i,1,n) if(a[i]<0) pos = i ;
        FOR(i,1,n) pre[i] = pre[i-1] + a[i] ; 
        if(k==1) {
            cout << max(pre[n] - pre[pos] , pre[pos-1] ) ; 
        } else {
            cout << pre[n] - pre[pos] + pre[pos-1] ; 
        }
    }
}

namespace sub7 {

    ll pre[N] ;
    struct cmp {
        bool operator()(ll a,ll b) {
            return a < b;
        }
    };
    priority_queue <ll,vector<ll>,cmp> h;
    stack <pair<ll,ll>> s;
    void solve(void) {
        int mua=1,ban=0;
        FOR(i,1,n) pre[i] = pre[i-1] + a[i] ;
        FOR(i,1,n) a[i] = pre[i] ; 
        while(ban<n) {
            mua = ban ;
            while (mua<n and a[mua]>=a[mua+1]) mua++;
            ban=mua+1;
            while (ban<=n and a[ban]>=a[ban-1]) ban++;
            ban--;
            while (!s.empty() and a[mua]<a[s.top().fi]) {
                h.push(a[s.top().se]-a[s.top().fi]);
                s.pop();
            }
            while (!s.empty() and a[ban]>=a[s.top().se]) {
                h.push(a[s.top().se]-a[mua]);
                mua=s.top().fi;
                s.pop();
            }
            s.push({mua,ban});
        }
        while (!s.empty()) {
            h.push(a[s.top().se]-a[s.top().fi]);
            s.pop();
        }
        ll res=0;
        FOR(i,1,k) {
            if (h.empty())  break;
            res+=h.top();
            h.pop();
        }
        cout<<res;
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
    /*if(n <= 30) sub1::solve() ; 
    else if(n <= 300) sub2::solve() ;
    else if(n <= 2000) sub3::solve() ;
    else if(k==1) sub4::solve() ; 
    else if(*min_element(a+1,a+1+n) >= 0) sub5::solve() ; 
    else if(CheckSubOneAm()) sub6::solve() ; 
    else*/ sub7::solve() ; 
    cerr << endl << "watborhihi : " << 1.0 * clock() / CLOCKS_PER_SEC << "s  " << endl;
    return (0 ^ 0) ; 
}