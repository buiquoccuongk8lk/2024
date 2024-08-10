#include <bits/stdc++.h>
using namespace std ; 
#define ll long long 
#define pb push_back
#define all(a) a.begin(),a.end()
#define FOR(i,a,b) for(int i(a) ; i <= b ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= b ; i--)
#define TIME 1.0 * clock() / CLOCKS_PER_SEC 

template<class X,class Y> bool maximize(X &x,const Y &y) {
	if(x < y) {
		x = y ; 
		return true ; 
	} else return false ; 
}

const int maxn = 1e5 + 5 ;

int n , k ;
int a[maxn] ;

void solve(void) {
	queue<int> q ;
	int lim = n - 1 ;
	
	while(1) { 
		if((int)q.size()==n) break ;
		int maxi = 0 ;
		int pos = 0 ; 
		for(int val = k ; val <= lim ; val+=k) {
			if(maximize(maxi,a[val])) {
				pos = val ; 
			}
		}
		q.push(a[pos]) ;
		FOR(i,pos+1,lim) {
			a[i-1] = a[i] ; 
			a[i] = 0 ; 
		}
		lim-- ;
	}

	while(!q.empty())  {
		cout << q.front() << ' ' ;
		q.pop() ; 
	}
	
}

signed main(void) {
    #define TASK ""
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".INP","r") ) {
        freopen(TASK".INP","r",stdin) ; freopen(TASK".OUT","w",stdout);
    }
	cin >> n >> k ; 
	FOR(i,0,n-1) cin >> a[i] ; 
	solve() ;     
    cerr << endl << "watborhihi : " << TIME << "s  " << endl;
    return (0 ^ 0) ; 
}