/* ---------------------- *
 *   * Code by watbor     *
 *   * Need Her and VOI   *
 *   :>                   *
--------------------------*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
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
#define uni(a) sort(all(a)) , a.resize(unique(a.begin(),a.end())-a.begin()) 

const int N = 5e4 ;
const int LO = 17 ;
const int base = 311 ;
const int M = 1e3 + 5 ; 
const int oo = 2e9 ; 
const long long inf = 1e18 ;
const long long MOD = 1e9 + 7 ;

template<class X, class Y> bool minimize(X &x, const Y &y) {if(x>y){x=y;return true;}else return false;}
template<class X, class Y> bool maximize(X &x, const Y &y) {if(x<y){x=y;return true;}else return false;}

int n ; 
string s[N + 2] ; 

void init(void) {
    cin >> n ; 
    FOR(i,1,n) cin >> s[i] ; 
}

namespace sub {
    int trie[40*N + 2][26] ; 
    int node = 1 ; 
    ll pw[N] ;
    int f[40*N + 2] ; // là độ dài của xâu mà nút r quản lí
    int End[40*N + 2] ;
    ll dp[40*N + 2] ; // là chi phí để nén cây nhánh u 
    void add(string s) {
        int root = 1 ; 
        for(auto c : s) {
            int j = c - 'a' ; 
            if(trie[root][j]==-1) {
                trie[root][j] = ++node ; 
                f[trie[root][j]] = f[root] + 1 ; 
            } 
            root = trie[root][j] ; 
        }
        End[root] = 1 ; 
    }
    void DFS(int u) {
        if(u==1) dp[u] = inf ; 
        else dp[u] = pw[40-f[u]] ; 
        ll sum = 0 ;
        FOR(j,0,25) {
            int v = trie[u][j] ; 
            if(v==-1) continue ; 
            DFS(v) ;
            sum+=dp[v] ;
        }
        if(!End[u]) minimize(dp[u] , sum) ;
    }
    void solve(void) {
        memset(trie,-1,sizeof(trie)) ; 
        FOR(i,1,n) {
            add(s[i]) ; 
        }
        pw[0] = 1 ;
        FOR(i,1,40) pw[i] =(pw[i-1] * 2) ;
        FOR(i,1,node) dp[i] = inf ;
        DFS(1) ; 
        cout << dp[1] ; 
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
    sub::solve() ; 
    cerr << endl << "watborhihi : " << 1.0 * clock() / CLOCKS_PER_SEC << "s  " << endl;
    return 0;
}