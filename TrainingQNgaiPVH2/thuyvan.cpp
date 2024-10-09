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

const int N = 1e6 + 5 ;
const int LO = 17 ;
const int base = 31 ;
const int M = 1e3 + 5 ; 
const int oo = 2e9 ; 
const long long inf = 1e18 ;
const int MOD1 = 1e9 + 7 ;
const int MOD2 = 1e9 + 3 ; 

const int dx[] = {-1,1,0,0} ;
const int dy[] = {0,0,-1,1} ; 

tct bool minimize(WORK &x,const HARD &y) {if(x > y) {x = y ; return true ; }else return false ;}
tct bool maximize(WORK &x,const HARD &y) {if(x < y) {x = y ; return true ; }else return false ;}

int n , k ;
string s[N] ;
ii pw[N] ;
pair<ll,ll> hashS[52][200005] ; 

void init(void) {
	cin >> n >> k ;
	FOR(i,1,n) {
		cin >> s[i] ;
		s[i] = "*" + s[i] ; 
	}
}
string res ;

pair<ll,ll> get_hash(int i,int j,int dir) {
	
	ll hash_code1 = (hashS[dir][j].fi - hashS[dir][i-1].fi * pw[j-i+1].fi + MOD1*MOD1)%MOD1 ;

	ll hash_code2 = (hashS[dir][j].se - hashS[dir][i-1].se * pw[j-i+1].se + MOD2*MOD2)%MOD2 ;

	return {hash_code1,hash_code2} ;
}	

bool Check(int mid) {
	map<ii,int>mp ;
	FOR(i,1,n) {
		map<ii,int> dd ; 
		FOR(j,1,sz(s[i]) - mid) {
			pair<ll,ll> t = get_hash(j,j+mid-1,i) ; 
			if(dd[{t.fi,t.se}]==0) {
				mp[{t.fi,t.se}]++ ;
				dd[{t.fi,t.se}] = 1 ; 
			}
			if(mp[{t.fi,t.se}] >= k) {
				return 1 ;
			}
		}
	}
	return 0 ;
}

void process(void) {   
	pw[0].fi = 1 ; 
	pw[0].se = 1 ; 
	FOR(i,1,2e5) {
		pw[i].fi = (pw[i-1].fi*base)%MOD1 ;
		pw[i].se = (pw[i-1].se*base)%MOD2 ;
	}
	FOR(i,1,n) {
		FOR(j,1,sz(s[i])-1) {
			hashS[i][j].fi = (hashS[i][j-1].fi*base + s[i][j] - 'A' + 1)%MOD1 ;
			hashS[i][j].se = (hashS[i][j-1].se*base + s[i][j] - 'A' + 1)%MOD2 ; 
		}
	}

	int maxi_len = 0 ; 
	FOR(i,1,n) maximize(maxi_len,sz(s[i])) ; 
	int l = 0 ; 
	int r = maxi_len ; 	
	int ans = -1 ;
	while(l <= r) {
		int mid = (l+r)>>1 ;
		if(Check(mid)) {
			ans = mid ; 
			l = mid + 1 ; 
		}else r = mid - 1 ; 
	}
    map<ii,int> mp ;
    FOR(i,1,n) {
		map<ii,int> dd ; 
		FOR(j,1,sz(s[i]) - ans) {
			pair<ll,ll> t = get_hash(j,j+ans-1,i) ; 
			if(dd[{t.fi,t.se}]==0) {
				mp[{t.fi,t.se}]++ ;
				dd[{t.fi,t.se}] = 1 ; 
			}
			if(mp[{t.fi,t.se}] >= k) {
				res = s[i].substr(j,ans) ;
				cout << res ;
				return ;
			}
		}
	}
}

signed main(void) {
    #define TASK "thuyvan"
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".INP","r") ) {
        freopen(TASK".INP","r",stdin) ; freopen(TASK".OUT","w",stdout);
    }
    init() ; 
    process() ; 
    cerr << endl << "watborhihi : " << 1.0 * clock() / CLOCKS_PER_SEC << "s  " << endl;
    return 0;
}