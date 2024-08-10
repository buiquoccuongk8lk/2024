#include <bits/stdc++.h>
using namespace std ; 
#define int long long
#define ll long long 
#define pb push_back
#define all(a) a.begin(),a.end()
#define FOR(i,a,b) for(int i(a) ; i <= b ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= b ; i--)
#define TIME 1.0 * clock() / CLOCKS_PER_SEC 

const int max_mitsurii = 1e6 + 5 ;

int n,m,h,w ; 
vector<vector<int>> a ;

void mitsuri_read(void) {
	cin >> n >> m ; 
	a.resize(n+5,vector<int>(m+5,0)) ; 
	cin >> h >> w ; 
	FOR(i,1,n) FOR(j,1,m) cin >> a[i][j] ; 
}

namespace mitsuri1 {
	int cnt[max_mitsurii] ; 
	void solve(void) {
		int ans = 0 ; 
		vector<int> vec ; 
		FOR(i,1,n) FOR(j,1,m) vec.pb(a[i][j]) ; 
		sort(all(vec)) ; 
		vec.resize(unique(all(vec)) - vec.begin()) ; 
		FOR(i,1,n) FOR(j,1,m) {
			a[i][j] = lower_bound(all(vec),a[i][j]) - vec.begin() + 1 ; 
		}
		FOR(i,1,n-h+1) {
			FOR(j,1,m-w+1) {
				bool OK = true ;
				FOR(u,i,i+h-1) {
					bool ok = true ;
					FOR(v,j,j+w-1) {
						cnt[a[u][v]]++ ; 
						if(2 * cnt[a[u][v]] > (h*w) ) {
							ok = false ; 
							OK = false ; 
							break ; 
						}
					}
					if(!ok) break ; 
				}
				ans+=OK ; 
				FOR(u,i,i+h-1) {
					FOR(v,j,j+w-1) {
						cnt[a[u][v]] = 0 ;
					}
				}
			}
		}
		cout << ans ; 
	}
}

namespace mitsuri2 {

	int st[4*max_mitsurii] ; 
	int b[max_mitsurii] ; 

	void update(int id,int l,int r,int pos,int val) {
		if(pos < l or pos > r) return ;
		if(l==r) {
			st[id]+=val ;
			return ;
		}
		int mid = (l+r)>>1 ; 
		update(id<<1,l,mid,pos,val) ; 
		update(id<<1|1,mid+1,r,pos,val) ; 
		st[id] = max(st[id<<1],st[id<<1|1]) ; 
	}

	void solve(void) {
		int ans = 0 ; 
		vector<int> vec ; 
		FOR(i,1,n) FOR(j,1,m) vec.pb(a[i][j]) ; 
		sort(all(vec)) ; 
		vec.resize(unique(all(vec)) - vec.begin()) ; 
		FOR(i,1,n) FOR(j,1,m) {
			a[i][j] = lower_bound(all(vec),a[i][j]) - vec.begin() + 1 ; 
		}
		FOR(i,1,m) b[i] = a[1][i] ;   
		int VAL = vec.size() ; 
		FOR(i,1,w) {
			update(1,1,VAL,b[i],1) ; 
		}
		ans+=(2*st[1] <= w) ;
		FOR(i,2,m-w+1) {
			update(1,1,VAL,b[i-1],-1) ; 
			update(1,1,VAL,b[i+w-1],1) ; 
			ans+= (2*st[1] <= w) ; 
		}
		cout << ans ; 
	}
}

bool CheckSub3() {
	int maxi = 0 ; 
	FOR(i,1,n) FOR(j,1,m) maxi = max(maxi,a[i][j]) ; 
	return (maxi <= 500) ; 
}

namespace mitsuri3 {
	int VAL ;
	int st[4*max_mitsurii] ; 

	void update (int id,int l,int r,int p, int val) {
		int i = 1 ;
		l = 1, r = VAL;
		while (l < r) {
			int m = (l + r) >> 1 ; 
			if (p <= m) r = m, i = i << 1;
			else l = m + 1, i = i << 1 | 1;
		}
		st[i]+=val ; 
		while (i > 1) {
			i >>= 1;
			st[i] = max(st[i << 1], st[i << 1 | 1]);
		}
	}

	void solve(void) {	
		int ans = 0 ; 
		vector<int> vec ; 
		FOR(i,1,n) FOR(j,1,m) vec.pb(a[i][j]) ; 
		sort(all(vec)) ; 
		vec.resize(unique(all(vec)) - vec.begin()) ; 
		FOR(i,1,n) FOR(j,1,m) {
			a[i][j] = lower_bound(all(vec),a[i][j]) - vec.begin() + 1 ; 
		} 
		VAL = vec.size() ; 
		FOR(Col1 , 1 , m - w + 1 ) {
			int Col2 = Col1 + w - 1 ; 
			FOR(row , 1 , n - h + 1) {
				if(row==1) {
					FOR(i,row,row + h - 1) {
						FOR(j,Col1,Col2) {
							update(1,1,VAL,a[i][j],1) ; 
						}
					}
				} else {
					FOR(j,Col1,Col2) update(1,1,VAL,a[row-1][j],-1) ; 	
					FOR(j,Col1,Col2) update(1,1,VAL,a[row+h-1][j],1) ; 
				}
				ans+=(2 * st[1] <= w*h) ; 
				if(row==n-h+1) {
					FOR(i,row,row+h-1) {
						FOR(j,Col1,Col2) {
							update(1,1,VAL,a[i][j],-1) ; 
						}
					}
				}
			}
		}
		cout << ans ; 
	}
}

namespace mitsuri4 {

	void solve(void) {
		
	}
	
}
signed main(void) {
    #define mitsurichannn ""
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(mitsurichannn".INP","r") ) {
        freopen(mitsurichannn".INP","r",stdin) ; freopen(mitsurichannn".OUT","w",stdout);
    }
    mitsuri_read() ; 
    if(n * m <= 1000) mitsuri1::solve() ; 
    else if(n==1) mitsuri2::solve() ; 
    else if(CheckSub3()) mitsuri3::solve() ;
    else mitsuri4::solve() ;  
    cerr << endl << "watborhihi : " << TIME << "s  " << endl;
    return (0 ^ 0) ; 
}
