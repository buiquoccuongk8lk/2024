#include<bits/stdc++.h>
using namespace std ;
#define FOR(i,a,b) for(int i = a ; i <= b ; i++)
#define FORD(i,a,b) for(int i = a ; i >= b ; i--)
const int N = 1e5 + 5 ; 
#define int long long

int n ; 
struct DL {
	int x , y ; 
} a[N] ; 
unordered_map<int,int>pos ; 
int st[4*N][3] ; 

void update(int id,int l,int r,int pos,int val,int t) {
	if(l==r) {
		st[id][t]= max(st[id][t],val) ; 
		return ; 
	}
	int mid = (l+r)/2 ; 
	update(id<<1,l,mid,pos,val,t) ; 
	update(id<<1|1,mid+1,r,pos,val,t) ; 
	st[id][t] = max(st[id<<1][t],st[id<<1|1][t]) ; 
}

int get(int id,int l,int r,int u,int v,int t) {
	if(l > v || r < u) return -2e9 ; 
	if(l >= u && r <= v) return st[id][t] ; 
	int mid = (l+r)/2 ; 
	return max(get(id<<1,l,mid,u,v,t),get(id<<1|1,mid+1,r,u,v,t)) ; 
}


signed main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0) ; 
	// freopen(".inp","r",stdin) ; 
	// freopen(".out","w",stdout) ;
	cin >> n ; 
	FOR(i,1,n)cin>>a[i].x>>a[i].y ;

	vector<int> v ; 
	FOR(i,1,n)v.push_back(a[i].y) ; 
	sort(v.begin(),v.end()) ; 
	v.resize(unique(v.begin(),v.end())-v.begin()) ;
	FOR(i,0,(int)v.size()-1)pos[v[i]] = i + 1 ; 
	int VAL = v.size() ; 

	sort(a+1,a+1+n,[](DL u,DL v) {
		return u.x < v.x ; 
	}) ; 

	FOR(i,1,4*VAL) st[i][0] = st[i][1] = -2e9 ; 

	long long ans = 0 ; 
	FOR(i,1,n) {
		ans = max(ans,1ll * (a[i].x + a[i].y + get(1,1,VAL,1,pos[a[i].y],1)) ) ;
		update(1,1,VAL,pos[a[i].y],-a[i].x - a[i].y,1) ;
		ans = max(ans,1ll * (a[i].x - a[i].y + get(1,1,VAL,pos[a[i].y],VAL,2) )) ;
		update(1,1,VAL,pos[a[i].y],-a[i].x + a[i].y,2) ;    
	}

	sort(a+1,a+1+n,[](DL u,DL v) {
		return u.x > v.x ; 
	}) ; 

	FOR(i,1,4*VAL) st[i][0] = st[i][1] = -2e9 ; 

	FOR(i,1,n) {
		ans = max(ans,1ll * (-a[i].x + a[i].y + get(1,1,VAL,1,pos[a[i].y],1)) ) ;
		update(1,1,VAL,pos[a[i].y],a[i].x - a[i].y,1) ;
		ans = max(ans,1ll * (-a[i].x - a[i].y + get(1,1,VAL,pos[a[i].y],VAL,2) )) ;
		update(1,1,VAL,pos[a[i].y],a[i].x + a[i].y,2) ;    
	}

	cout << ans ; 

	return 0 ; 
}