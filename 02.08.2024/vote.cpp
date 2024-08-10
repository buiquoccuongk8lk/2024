#include<bits/stdc++.h>
using namespace std ;
#define int long long
#define FOR(i,a,b) for(int i(a) ; i <= (b) ; i++) 
#define FORD(i,a,b) for(int i(a) ; i >= (b) ; i--)
const int N = 1e5 + 5 ;
int n ;
struct DL {
	int x , y ; 
} a[N + 5] ;
int bit[N + 5][3] ;
vector<int> votes[N + 5] ; 
struct {
	void up(int u,int v,int t) {
		u++ ;
		for(int i(u) ; i <= N ; i+=i&-i)bit[i][t]+=v ; 
	}	
	int get(int u,int t) {
		u++ ;
		int ret = 0 ; 
		for(int i(u) ; i ; i-=i&-i) ret+=bit[i][t] ; 
		return ret ; 
	}
	int bup(int lim) {
		int sum = 0, pos = 0;
	    for(int i= __lg(N) ; i>= 0 ; i--) {
	        int nxtpos = pos + (1<<i) ;
	        if(nxtpos < N && sum + bit[nxtpos][1] < lim) {
	            pos = nxtpos, sum+= bit[nxtpos][1];
	        }
	    }
	    return pos;	
	}
} BIT ; 

signed main() {
	ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
	// freopen(".inp","r",stdin) ; 
	// freopen(".out","w",stdout) ; 

	cin >> n ; 
	FOR(i,1,n) cin>>a[i].x>>a[i].y ; 

	priority_queue<pair<int,int>,vector<pair<int,int>>>pq ;
	int cur_vote = 0 ;

	FOR(i,1,n) {
		if(a[i].x==1) cur_vote++ ; 
		else votes[a[i].x].push_back(a[i].y) ; 
	}	

	FOR(i,2,N) {
		if(votes[i].empty()) continue ; 
		sort(votes[i].begin(),votes[i].end()) ; 
		reverse(votes[i].begin(),votes[i].end()) ; 
		for(int v : votes[i]) {
			BIT.up(v,v,0) ; 
			BIT.up(v,1,1) ;
		}
		pq.push({votes[i].size(),i}) ; 
	}

	long long sum = 0 , ans = 1e18 ; 

	FORD(i,n,0) {
		while(!pq.empty() && pq.top().first >= i) {
			int j = pq.top().second ; pq.pop() ; 
			while((int)votes[j].size() >= i) {
				int v = votes[j].back() ; 
				votes[j].pop_back() ; 
				cur_vote++ ; 
				sum+= v ; 
				BIT.up(v,-v,0) ; 
				BIT.up(v,-1,1) ; 
			}
			pq.push({votes[j].size(),j}) ; 
		}
		if(cur_vote >= i) {
			ans = min(ans,sum) ; break ; 
		} else {
			int j = BIT.bup(i - cur_vote) ; 
			int sl = BIT.get(j-1,1) ; 
			long long c = sum + BIT.get(j-1,0) +  1LL * j * (i - cur_vote - sl) ;
			ans = min(ans,c) ; 
		}
	}
	cout << ans ;
	return 0 ; 
}