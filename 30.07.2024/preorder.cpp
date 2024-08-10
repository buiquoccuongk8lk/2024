/*[продолжатьипродолжать]*/
/* ---------------------- *
 *     Code by watbor     *
 *                        * 
--------------------------*/

#define         tct template<class MITSURII,class CHANN>

#include <bits/stdc++.h>
using namespace std ; 


#define         ll long long 
#define         fi first
#define         se second
#define         pb push_back
#define         ii pair<int,int>
#define         vii vector<ii>
#define         vi vector<int>
#define         endl '\n' 
#define         sz(a) (int)a.size()
#define         all(a) a.begin(),a.end()
#define         FOR(i,a,b) for(int i(a) ; i <= b ; i++)
#define         FORD(i,a,b) for(int i(a) ; i >= b ; i--)
#define         FORN(i,a,b) for(int i(a) ; i < b ; i++)
#define         uni(a) sort(all(a)) , a.resize(unique(a.begin(),a.end())-a.begin()) 

const int N = 2e5 + 5 ;
const int LO = 17 ;
const int base = 311 ;
const int M = 1e3 + 5 ; 
const int oo = 2e9 ; 
const int mod = 1e9 + 7 ;
const long long inf = 1e18 ;

const int dx[] = {-1,1,0,0} ;
const int dy[] = {0,0,-1,1} ; 

const int mod1 = pow(2,21) ; 
const int mod2 = pow(2,20) ; 

tct bool minimize(MITSURII &x,const CHANN &y) {if(x > y) {x = y ; return true ; }else return false ;}
tct bool maximize(MITSURII &x,const CHANN &y) {if(x < y) {x = y ; return true ; }else return false ;}

int n ; 
int a[N] , wa[N] , b[N] , wb[N] , c[N] , wc[N] ; 
ll preA[N] , preB[N] , preC[N] , maC[N] , maA[N] , maB[N] , res[N] ; 
int WA[N] , WB[N] , WC[N] ;
int cnt[30 * N] ; 
int mxA,mxB,mxC ; 
int fAB[N] , fCB[N] , fCA[N] , rev[N] ; 
int T ;

void init() {
    cin >> n ; 
    FOR(i,1,n) cin >> a[i] ; 
    FOR(i,1,n) {
        cin >> WA[i] ; 
        wa[i] = WA[i] ;
    }
    FOR(i,1,n) cin >> b[i] ;
    FOR(i,1,n) {
        cin >> WB[i] ;
        wb[i] = WB[i] ;
    } 
    FOR(i,1,n) cin >> c[i] ; 
    FOR(i,1,n) {
        cin >> WC[i] ;
        wc[i] = WC[i] ; 
    } 
}


void prepareMX() {
    mxA = n , mxB = n , mxC = n ; 
    FOR(i,1,n) {
        if(!cnt[a[i]]) {
            cnt[a[i]] = 1 ; 
        } else {
            mxA = i - 1 ; 
            break ; 
        }
    }
    FOR(i,1,n) cnt[a[i]] = 0 ;
    FOR(i,1,n) {
        if(!cnt[b[i]]) {
            cnt[b[i]] = 1 ;  
        } else {
            mxB = i - 1 ; 
            break ; 
        }
    }
    FOR(i,1,n) cnt[b[i]] = 0 ; 
    FOR(i,1,n) {
        if(!cnt[c[i]]) {
            cnt[c[i]] = 1 ; 
        } else {
            mxC = i - 1 ; 
            break ; 
        }
    }
}

void prepareMANG() {
    FOR(i,1,n) cnt[a[i]] = cnt[b[i]] = cnt[c[i]] = 0 ; 

    fAB[0] = mxB ; 
    fCA[0] = mxA ; 
    fCB[0] = mxB ; 

    // fAB
    int l = mxB ; 
    FOR(i,1,mxB) cnt[b[i]] = 1 ; 
    FOR(i,1,mxA) {
        while(l >= 0 && cnt[a[i]]==1) {
            cnt[b[l]] = 0 ;
            l-- ; 
        }
        fAB[i] = l ; 
    }

    // fCA
    l = mxA ;
    FOR(i,1,mxB) cnt[b[i]] = 0 ; 
    FOR(i,1,mxA) cnt[a[i]] = 1 ; 
    FOR(i,1,mxC) {
        while(l >= 0 && cnt[c[i]]==1) {
            cnt[a[l]] = 0 ; 
            l-- ;  
        }
        fCA[i] = l ;
    }

    // fCB 
    l = mxB ;
    FOR(i,1,mxA) cnt[a[i]] = 0 ; 
    FOR(i,1,mxB) cnt[b[i]] = 1 ; 

    FOR(i,1,mxC) {
        while(l >= 0 && cnt[c[i]]==1) {
            cnt[b[l]] = 0 ; 
            l-- ; 
        }
        fCB[i] = l ;
    }

    FOR(i,0,mxA) {
        rev[fAB[i]] = i ; 
    }

    FORD(i,mxB-1,1) {
        rev[i] = max(rev[i],rev[i+1]) ; 
    }
}

namespace sub {

    void xuly() {
        ll ans = 0 ;
        ll sumA = 0 , sumB = 0 , sumC = 0 ;

        FOR(i,1,n) {
            sumA+= wa[i] ; 
            sumB+= wb[i] ;
            sumC+= wc[i] ; 
            maA[i] = max(maA[i-1],sumA) ; 
            maB[i] = max(maB[i-1],sumB) ; 
            maC[i] = max(maC[i-1],sumC) ;
        }

        int l = mxA ; 
        int r = 0 ; 

        FORD(i,mxC,0) {
            res[i] = res[i+1] ;
            while (r <= mxA && r <= fCA[i]) {
                if (l < r) {
                    res[i] = max(res[i], maA[r] + maB[fAB[r]]);
                }
                ++r;
            }
            while (l >= 0 && fAB[l] <= fCB[i]) {
                if (l < r) {
                    res[i] = max(res[i], maA[l] + maB[fAB[l]]);
                }
                --l;
            }
            if (fCB[i] <= fAB[fCA[i]]) {
                res[i] = max(res[i], maA[fCA[i]] + maB[fCB[i]]);
            } else {
                res[i] = max(res[i], maA[rev[fCB[i]]] + maB[fCB[i]]);
            }
            ans = max(ans,res[i] + maC[i]) ; 
        }

        FOR(i,1,n) res[i] = 0 ;
        FOR(i,1,n) maA[i] = maB[i] = maC[i] = 0 ;

        cout << ans << '\n' ; 
    }

    void solve() {
        int e = 0 , s = 0 ;
        while(--T) {    
            cin >> e >> s ;
            FOR(i,1,n) { 
                wa[i] = (((WA[i] + 1048576) ^ e) + s) % 2097152 - 1048576;
                wb[i] = (((WB[i] + 1048576) ^ e) + s) % 2097152 - 1048576;
                wc[i] = (((WC[i] + 1048576) ^ e) + s) % 2097152 - 1048576;
            }
            xuly() ;
        }
    }

}
signed main() {
    #define TASK ""
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".inp","r") ) {
        freopen(TASK".inp","r",stdin) ; freopen(TASK".out","w",stdout);
    }
    cin >> T ;
    init() ; 
    prepareMX() ; 
    prepareMANG() ; 
    sub::xuly() ; 
    sub::solve() ; 
    cerr << endl << "watborhihi : " << clock() << "ms" << endl;
    return 0 ;
}