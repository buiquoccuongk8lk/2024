/*[продолжатьипродолжать]*/
/* ---------------------- *
 *     Code by watbor     *
 *                        * 
--------------------------*/

#define         tct template<class MITSURII,class CHANN>

#include <bits/stdc++.h>
using namespace std ; 

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

const int N = 1e5 + 5 ;
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

string s ; 
int n ; 
int dp[105][105][105][2] ;
// dp[i][j][k][t] : số thao tác ít nhất để cố định i thằng 'F' đầu , j thằng 'C' đầu , k kí tự khác và
// t : 0 / 1 ( lần cuối có là 'F' ) hay không

vi pos_c[4] ; 

int calc(int l,int r,vi pos) {
    int cnt = 0 ;
    for(int i(l) ; i <= sz(pos) - 1 && pos[i] <= r ; i++) cnt++ ; 
    return cnt ; 
}

signed main() {
    #define TASK ""
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".inp","r") ) {
        freopen(TASK".inp","r",stdin) ; freopen(TASK".out","w",stdout);
    }
    cin >> n ;
    cin >> s ; s = '*' + s ; 
    FOR(i,1,n) {
        if(s[i]=='F') pos_c[0].pb(i) ; 
        else if(s[i]=='C') pos_c[1].pb(i) ; 
        else pos_c[2].pb(i) ; 
    }
    memset(dp,0x3f,sizeof dp) ; 

    dp[0][0][0][0] = 0 ;
    FOR(i,0,sz(pos_c[0])) {
        FOR(j,0,sz(pos_c[1])) {
            FOR(k,0,sz(pos_c[2])) {
                FOR(t,0,1) {
                    int cur = dp[i][j][k][t] ; 
                    if(i < sz(pos_c[0])) {
                        minimize(dp[i+1][j][k][1],cur + 
                            calc(j,pos_c[0][i],pos_c[1]) + calc(k,pos_c[0][i],pos_c[2]) ) ; 
                    }
                    if(j < sz(pos_c[1]) && !t) {
                        minimize(dp[i][j+1][k][0],cur + 
                            calc(i,pos_c[1][j],pos_c[0]) + calc(k,pos_c[1][j],pos_c[2]) ) ; 
                    }   
                    if(k < sz(pos_c[2])) {
                        minimize(dp[i][j][k+1][0],cur +
                            calc(i,pos_c[2][k],pos_c[0]) + calc(j,pos_c[2][k],pos_c[1]) );
                    }
                }
            }
        }
    }   
    int x = sz(pos_c[0]) , y = sz(pos_c[1]) , z = sz(pos_c[2]) ; 
    cout << min(dp[x][y][z][0] , dp[x][y][z][1]) ; 
    cerr << endl << "watborhihi : " << clock() << "ms" << endl;
    return 0 ;
}