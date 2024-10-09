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
typedef pair<int,int> ii ;
typedef vector<int> vi ;
typedef vector<pair<int,int>>vii ;

const int N = 1e5 + 5 , LO = 17 , base = 311 ;
const long long inf = 1e18 , MOD = 1e9 + 7 ;

template<class X, class Y> bool minimize(X &x, const Y &y) {if (x > y) {x=y;return true;} else return false;}
template<class X, class Y> bool maximize(X &x, const Y &y) {if (x < y) {x=y;return true;} else return false;}

int n , q ; 
int a[N] ; 
ii st[30][4*N] ; 

void build(int id,int l,int r) {
    if(l==r) {
        rep(i,0,29) if( (a[l]>>i)&1 ) st[i][id].fi = 1 ; 
        return ; 
    }
    int mid = (l+r) >> 1 ; 
    build(id<<1,l,mid) ; 
    build(id<<1|1,mid+1,r) ; 
    rep(i,0,29) st[i][id].fi = st[i][id<<1].fi + st[i][id<<1|1].fi ; 
}
void fix(int pos,int id,int len) {
    st[pos][id].fi = len - st[pos][id].fi ; 
    st[pos][id].se ++ ; 
}

void down(int pos,int id,int l,int r) {
    int mid = (l+r) >> 1 ; 
    if(st[pos][id].se&1) {
        fix(pos,id<<1,mid-l+1) ; 
        fix(pos,id<<1|1,r-mid) ; 
        st[pos][id].se = 0 ;
    }
}

void update(int id,int l,int r,int u,int v,int pos) {
    if(l > v or r < u) return ; 
    if(l >= u and r <= v) {
        fix(pos,id,r-l+1) ; 
        return ; 
    }
    down(pos,id,l,r) ; 
    int mid = (l+r)>>1 ;
    update(id<<1,l,mid,u,v,pos) ; 
    update(id<<1|1,mid+1,r,u,v,pos) ; 
    st[pos][id].fi = st[pos][id<<1].fi + st[pos][id<<1|1].fi ; 
}

int get(int id,int l,int r,int u,int v,int pos) {
    if(l > v or r < u) return 0 ; 
    if(l >= u and r <= v) return st[pos][id].fi ; 
    down(pos,id,l,r) ; 
    int mid = (l+r) >> 1 ;
    return get(id<<1,l,mid,u,v,pos) + get(id<<1|1,mid+1,r,u,v,pos) ; 
}

signed main(void) {
    #define TASK ""
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".INP","r") ) {
        freopen(TASK".INP","r",stdin) ; freopen(TASK".OUT","w",stdout);
    }
    cin >> n >> q ; 
    rep(i,1,n) cin >> a[i] ; 
    build(1,1,n) ; 
    while(q--) {
        int t , l , r ,x ; 
        cin >> t >> l >> r >> x ; 
        if(t==1) {
            rep(pos,0,29) {
                if((x>>pos)&1) update(1,1,n,l,r,pos) ; 
            }
        }else if(t==2) {
            long long ans = 0 ;
            rep(pos,0,29) {
                if( ( get(1,1,n,l,r,pos) + ( (x>>pos &1))) & 1) ans+= (1<<pos) ; 
            }
            cout << ans << '\n' ; 
        }else if(t==3) {
            long long ans = 0 ;
            rep(pos,0,29) {
                if( (get(1,1,n,l,r,pos)+ ((x>>pos)&1)) == r - l + 2 ) ans+= (1<<pos) ; 
            }
            cout << ans << '\n' ;  
        }else if(t==4) {
            long long ans = 0 ;
            rep(pos,0,29) {
                if( ( get(1,1,n,l,r,pos) + ((x>>pos)&1) ) > 0 ) ans+= (1<<pos) ; 
            }
            cout << ans << '\n' ; 
        }
    }
    cerr << endl << "watborhihi : " << 1.0 * clock() / CLOCKS_PER_SEC << "s  " << endl;
    return 0;
}