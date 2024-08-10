/*[продолжатьипродолжать]*/
/* ---------------------- *
 *     Code by watbor     *
 *                        * 
--------------------------*/

#define 		tct template<class MITSURII,class CHANN>

#include <bits/stdc++.h>
using namespace std ; 

#define 		ll long long 
#define 		fi first
#define 		se second
#define 		pb push_back
#define 		ii pair<int,int>
#define 		vii vector<ii>
#define 		vi vector<int>
#define 		endl '\n' 
#define 		sz(a) (int)a.size()
#define 		all(a) a.begin(),a.end()
#define 		FOR(i,a,b) for(int i(a) ; i <= b ; i++)
#define 		FORD(i,a,b) for(int i(a) ; i >= b ; i--)
#define 		FORN(i,a,b) for(int i(a) ; i < b ; i++)
#define 		uni(a) sort(all(a)) , a.resize(unique(a.begin(),a.end())-a.begin()) 

const int N = (int)(1 << 21) + 1 ;
const int LO = 17 ;
const int base = 311 ;
const int M = 1e3 + 5 ; 
const int oo = 2e9 ; 
const int mod = 1e9 + 7 ;
const long long inf = 1e18 ;

const int dx[] = {-1,1,0,0} ;
const int dy[] = {0,0,-1,1} ; 

tct bool minimize(MITSURII &x,const CHANN &y) {if(x > y) {x = y ; return true ; }else return false ;}
tct bool maximize(MITSURII &x,const CHANN &y) {if(x < y) {x = y ; return true ; }else return false ;}

int n ; 
int a[N] ; 
map<int,int> cnt ; 
int st[4*N + 5] ; 
int L[N] , R[N] ; 

void build(int id,int l,int r) {
    L[id] = l ; 
    R[id] = r ; 
    if(l==r) {
        st[id] = a[l] ; 
        return ; 
    }
    int mid = (l+r)>>1 ; 
    build(id<<1,l,mid) ; 
    build(id<<1|1,mid+1,r) ; 
    st[id] = st[id<<1] + st[id<<1|1] ; 
}

void hai(int i) {
    if(L[i]!=R[i]) {
        if(st[i << 1] >= st[i << 1 | 1]) hai(i << 1) ; 
        else hai(i << 1 | 1) ; 
        st[i] = st[i<<1] + st[i<<1|1] ; 
    } else {
        cout << L[i] << ' ' ; 
        st[i] = 0 ; 
    }
}

signed main() {
    #define TASK ""
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".inp","r") ) {
        freopen(TASK".inp","r",stdin) ; freopen(TASK".out","w",stdout);
    }
    cin >> n ; 
    FOR(i,1,pow(2,n)) cin >> a[i] ;
    FOR(i,1,pow(2,n)) {
        if(a[i] > 2 || a[i] < 1) {
            cout << 0 ; 
            return 0 ; 
        }
        cnt[a[i]]++ ; 
    } 
    n = pow(2,n) ; 
    if(cnt[2] > 1) {
        cout << 0 ; 
        return 0 ; 
    }
    cout << n << endl ; 
    build(1,1,n) ;
    FOR(i,1,n) hai(1) ; 
    cerr << endl << "watborhihi : " << clock() << "ms" << endl;
    return 0 ;
}