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

const int N = 1e6 + 5 , LO = 17 , base = 311 ;
const long long inf = 1e18 , MOD = 1e9 + 7 ;

template<class X, class Y> bool minimize(X &x, const Y &y) {if (x > y) {x=y;return true;} else return false;}
template<class X, class Y> bool maximize(X &x, const Y &y) {if (x < y) {x=y;return true;} else return false;}

int n ; 
int a[N] , maL[N] , maR[N] , L[N] , R[N];

signed main(void) {
    #define TASK ""
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".INP","r") ) {
        freopen(TASK".INP","r",stdin) ; freopen(TASK".OUT","w",stdout);
    }
    cin >> n ; 
    rep(i,1,n) cin >> a[i] ; 
    long long ans = 0 ;

   	rep(i,1,n) {
   		maL[i] = max(maL[i-1],a[i]) ; 
   	} 
   	repd(i,n,1) {
   		maR[i] = max(maR[i+1],a[i]) ; 
   	}
   	rep(i,1,n) {
   		ans+= min(maL[i],maR[i]) - a[i] ; 
   	}

   	deque<int>dq ;

   	rep(i,1,n) {
   		while(!dq.empty() and a[dq.front()] <= a[i]) dq.pop_front() ; 
   		if(dq.empty()) L[i] = i ; 
   		else L[i] = dq.front() + 1; 
   		dq.push_front(i) ; 
   	}

   	while(!dq.empty()) dq.pop_front() ; 

   	repd(i,n,1) {
   		while(!dq.empty() and a[dq.front()] <= a[i]) dq.pop_front() ; 
   		if(dq.empty()) R[i] = i ;
   		else R[i] = dq.front() - 1; 
   		dq.push_front(i) ; 
   	}

   	int res = 0 ;
   	rep(i,1,n) {
   		if( (L[i]==i and R[i]==i)) continue ;
   		if(L[i]==i) maximize(res,R[i]-i) ; 
   		else maximize(res,i-L[i]) ; 
   	}
   	cout << ans + res ; 
    cerr << endl << "watborhihi : " << 1.0 * clock() / CLOCKS_PER_SEC << "s  " << endl;
    return 0;
}