// 29 . 03 . 2008 
#include <bits/stdc++.h>
using namespace std ;
#define int long long
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

const int MAXN = 2e5 + 5 ;

int T ;

void init() {
	cin >> T ;
}

int ma[MAXN] , mi[MAXN] , D1[MAXN] , D2[MAXN] ; 

int pt(int a) {
	int cnt = 0 ;
	while(a>0) {
		cnt++ ;
		a/=10 ; 
	}
	return cnt ; 
}

int check1(int mid) {
	int i = pt(mid) ; 
	return D2[i-1] + (mid-mi[i]+1)*D1[i-1] + i * (mid - mi[i] + 1 + 1) * (mid - mi[i] + 1) / 2 ; 
}

int check2(int mid) {
	int i = pt(mid) ; 
	return D1[i-1] + (mid - mi[i] + 1) * i ;
}

int get(int a,int b){
    int sz = pt(a);
    b=sz-b+1;
    while(b>1) {
        a/=10;
        b-=1;
    }
    return a%10;
}

void solve() {
	mi[1] = 1 ;
	D1[1] = 9 ;
	D2[1] = 45 ;
	ma[1] = 9 ;
	FOR(i,2,10) {
		mi[i] = mi[i-1] * 10 ;
		ma[i] = mi[i] * 10 - 1 ;
		D1[i] = D1[i-1] + (ma[i] - mi[i] + 1) * i ;
		D2[i] = D2[i-1] + (ma[i]-mi[i]+1)*D1[i-1] + i * (ma[i] - mi[i] + 2) * (ma[i] - mi[i] + 1) / 2 ;
	}
	while(T--) {
		int k ; 
		cin >> k ; 
		int l = 1 , r = 1e9 , pos = 0 ;
		while(l <= r) {
			int mid =(l+r)/2 ; 
			if(check1(mid)>=k) pos = mid , r = mid - 1 ; 
			else l = mid + 1 ; 
		}
		k-= check1(pos-1) ;
		l = 1 , r = pos ;
		while(l <= r) {
			int mid = (l+r)/2 ; 
			if(check2(mid)>=k) pos = mid , r = mid - 1 ; 
			else l = mid + 1 ; 
		}
		k-= check2(pos-1) ;
		cout << get(pos,k) << '\n' ;
	}
}

signed main() {
    #define task ""
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin) ; freopen(task".out","w",stdout) ; 
    }
    init() ;
    solve() ;
    cerr << "TIME : " << clock() * 0.001 << "s" << endl ;
    return 0 ; 
}
/* Watbor */