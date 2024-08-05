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
int n ; ll k ; 
int cnt[N] ;

signed main() {
    #define TASK ""
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".inp","r") ) {
        freopen(TASK".inp","r",stdin) ; freopen(TASK".out","w",stdout);
    }
	cin >> n >> k ; 
	cin >> s ; s = "*" + s ; 
	ll sum = 0 ;
	ll ans = 0 ;
	int j = 0 ;
	FOR(i,1,n) {
		while(j <= n && sum <= k) {
			j++ ; 
			sum-= 1ll * cnt[s[j] - '0'] * cnt[s[j] - '0'] ; 
			cnt[s[j] - '0']++ ; 
			sum+= 1ll * cnt[s[j] - '0'] * cnt[s[j] - '0'] ; 
		}
		sum-= 1ll * cnt[s[i]-'0'] * cnt[s[i]-'0'] ; 
		cnt[s[i]-'0']-- ; 
		sum+= 1ll * cnt[s[i]-'0'] * cnt[s[i]-'0'] ;
		ans+= j - i ;	
	}
	cout << ans ;
    cerr << endl << "watborhihi : " << clock() << "ms" << endl;
    return 0 ;
}