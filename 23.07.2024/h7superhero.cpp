/*[продолжатьипродолжать]*/
#include <bits/stdc++.h>
using namespace std ; 
const int MAX = 1e5 + 5 ;

int n ; 
pair<int,int> a[MAX] ;
void init(void) {
	cin >> n ; 
	for(int i = 1 ; i <= n ; i++) cin >> a[i].first ;
	for(int i = 1 ; i <= n ; i++) cin >> a[i].second ; 
}

namespace sub1 {

	void solve(void) {

		int ans = 0 ; 

		for(int mask = 0 ; mask <= (1<<n) - 1 ; mask++) {

			vector<int> ones , zeros ; 
			long long sum = 0 ;

			for(int i = 0 ; i <= n - 1 ; i++) {
				if((mask>>i)&1) {
					ones.push_back(a[i+1].first) ; 
				} else zeros.push_back(a[i+1].second) ; 
			}

			sort(zeros.begin(),zeros.end()) ;
			for(auto x : ones) sum+=x ; 

			int cnt = 0 ; 

			for(auto x : zeros) {
				if(sum >= x) {
					sum-= x ;
					cnt++ ; 
				}
			}

			if(cnt >= (__builtin_popcount(mask) )) ans = max(ans,__builtin_popcount(mask) ) ;
		}

		cout << ans ; 

	}

}

namespace sub2 {
	
	bool check(int mid) {

		set<pair<int,int>> setAB,setA,setB ; 

		long long sum = 0 ;

		for(int i = 1 ; i <= n ; i++) {
			if(i <= 2 * mid) {
				sum+= a[i].first ;
				setA.insert({a[i].first,i}) ; 
				setAB.insert({a[i].second - a[i].first,i}) ;
			} else {
				setB.insert({a[i].second,i}) ;  
			}
		}
		
		int cnt = 0 ; 

		while(!setAB.empty()) {
			long long x = (*setAB.begin()).first ;
			long long y = 1e18 ;
			if(!setA.empty() && !setB.empty()) {
				y = (*setB.begin()).first - (*setA.rbegin()).first ; 
			}	
			sum+= min(x,y) ; 
			cnt++ ; 
			if(cnt==mid) return sum <= 0 ; 
			if(x <= y) {
				int id = (*setAB.begin()).second ; 
				setAB.erase({x,id}) ; 
				setA.erase({a[id].first,id}) ;
			} else {
				int id1 = (*setB.begin()).second ; 
				setB.erase({a[id1].second,id1}) ; 

				int id2 = (*setA.rbegin()).second ; 
				setA.erase({a[id2].first,id2}) ;
				setAB.erase({a[id2].second - a[id2].first,id2}) ; 

				setB.insert({a[id2].second,id2}) ;  
			}
		}

		return 0 ;  
	}

	void solve(void) {
		for(int i = 1 ; i <= n ; i++) a[i].first*=-1 ;
		sort(a+1,a+1+n) ; 
		int l = 1 , r = n / 2 , ans = 0 ; 
		while(l <= r) {
			int mid = (l+r)>>1 ; 
			if(check(mid)) {
				ans = mid ; 
				l = mid + 1 ; 
			} else r = mid - 1 ; 
		}
		cout << ans ;
	}

}

namespace sub3 {
	#define fi first
	#define se second
	long long pre[MAX] , suf[MAX] ; 

	bool check(int mid) {

		priority_queue<int,vector<int>,greater<int>> pq_min ; 
		priority_queue<int,vector<int>> pq_max ; 

		long long sum = 0 ;
		for(int i = 1 ; i <= n ; i++) {
			pq_min.push(a[i].fi) ; 
			sum+= a[i].fi ; 
			if((int)pq_min.size() > mid) {
				sum-= pq_min.top() ; 
				pq_min.pop() ; 
			}
			pre[i] = sum ; 
		}

		sum = 0 ;

		for(int i = n ; i >= 1 ; i--) {
			pq_max.push(a[i].se) ; 
			sum+= a[i].se ; 
			if((int)pq_max.size() > mid) {
				sum-= pq_max.top() ; 
				pq_max.pop() ; 
			}
			suf[i] = sum ; 
		}

		for(int i = mid ; i <= n - mid ; i++) {
			if(pre[i] >= suf[i+1]) return 1 ;
		}
		
		return 0 ; 
	}
	void solve(void) {
		sort(a+1,a+1+n,[](pair<int,int> u,pair<int,int> v) {
			return u.fi + u.se > v.fi + v.se ; 
		}) ;  
		int l = 1 , r = n / 2 , ans = 0 ; 
		while(l <= r) {
			int mid = (l+r)>>1 ; 
			if(check(mid)) {
				ans = mid ; 
				l = mid + 1 ; 
			} else r = mid - 1 ; 
		}
		cout << ans ;
	}

}

signed main(void) {
    #define NAME ""
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(NAME".inp","r") ) {
        freopen(NAME".inp","r",stdin) ; freopen(NAME".out","w",stdout);
    }
    init() ;
    if(n <= 20) sub1::solve() ;
    else if(n <= 5000) sub2::solve() ;
    else sub3::solve() ;   
    cerr << endl << "watborhihi : " << clock() << "ms" << endl;
    return 0 ;
}