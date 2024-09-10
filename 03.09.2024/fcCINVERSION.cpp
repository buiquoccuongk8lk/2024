// 29 . 03 . 2008 
#include <bits/stdc++.h>
using namespace std ;
//#define int long long
typedef long long ll ;
typedef vector<int> vi ;
typedef vector<pair<int,int>> vii ;
typedef pair<int,int> ii ;
#define FOR(i,a,b) for(int i(a) ; i <= (int)b ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= (int)b ; i--)
#define all(a) a.begin() , a.end()
#define pb push_back
#define fi first
#define se second

template<class T> bool maxi(T &x,T y) { if (x < y) { x = y ; return true ;} return false ;}
template<class T> bool mini(T &x,T y) { if (x > y) { x = y ; return true ;} return false ;}

const int MAXN = 20 ;

ll L , R ;
void init() {
	cin >> L >> R ;
}

vi digits[MAXN] ;

// ta biểu diễn lại x = d0 d1 d2 .. .dn 
ll dp[MAXN][2][2] ; // số lượng cặp nghịch thế thỏa
ll cntArr[MAXN][2][2] ; // số lượng dãy 
ll cntNum[MAXN][2][2] ; // tổng số chữ số a trong tất cả các dãy
// chiều thứ 3 (lead) cho biết dãy có đang toàn số 0 hay không

vi toVector(ll x) {
	vi res ; 
	while(x > 0) {
		res.pb(x%10) ; x/= 10 ; 
	}
	if(res.empty()) res.pb(0) ;
	reverse(all(res)) ; 
	return res ;
}

ll calc(ll x) {
	ll ans = 0 ; 
	vi s = toVector(x) ; 
	int n = s.size() ;	 

	FOR(a,0,9) {
		FOR(len,0,n) FOR(lo,0,1) {
			FOR(lead,0,1) {
				dp[len][lo][lead] = cntArr[len][lo][lead] = cntNum[len][lo][lead] = 0 ;
			}
		}
		cntArr[0][0][0] = 1 ;
		FOR(len,0,n-1) {
			FOR(lo,0,1) FOR(lead,0,1) {
				int lim = lo ? 9 : s[len] ; 
				FOR(d,0,lim) {
					int nxtLo = lo | (d < s[len]) ;
					int nxtLead = lead | (d > 0) ; 

					dp[len+1][nxtLo][nxtLead]+= dp[len][lo][lead] ;
					cntArr[len+1][nxtLo][nxtLead]+= cntArr[len][lo][lead] ;
					cntNum[len+1][nxtLo][nxtLead]+= cntNum[len][lo][lead] ;

					if(d == a && (d > 0 || lead == 1) ) {
						cntNum[len+1][nxtLo][nxtLead]+= cntArr[len][lo][lead] ;
					} 

					if(d > a) {
						dp[len+1][nxtLo][nxtLead]+= cntNum[len][lo][lead] ;
					}
				}
			}
		}
		FOR(lo,0,1) FOR(lead,0,1) ans+= dp[n][lo][lead] ;
	}	
	return ans ;
}

void solve() {
	cout << calc(R) - calc(L-1) << '\n' ;
}

signed main() {
    #define task ""
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin) ; freopen(task".out","w",stdout) ; 
    }
    int test ; cin >> test ;
    while(test--) {
    	init() ;
    	solve() ;
	}
    cerr << "TIME : " << clock() * 0.001 << "s" << endl ;
    return 0 ; 
}
/* Watbor */