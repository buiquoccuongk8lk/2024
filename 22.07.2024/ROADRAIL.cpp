/* Code By Watbor */
#include <bits/stdc++.h>
using namespace std ; 
#define MAX (int)2e5 + 5 

int numCity,numRoad,numRail ;
struct Edge {
	int u , v ; 
} eRoad[MAX] , eRail[MAX] ;
int mstRoadID[MAX] , mstRailID[MAX] , par[MAX] ; 
unordered_map<int,int>mp[MAX] ;

void init(void) {
	cin >> numCity >> numRoad >> numRail ; 
	for(int i(1) ; i <= numRoad ; i++) cin >> eRoad[i].u >> eRoad[i].v ; 
	for(int i(1) ; i <= numRail ; i++) cin >> eRail[i].u >> eRail[i].v ; 
}

int acs(int u) {return par[u] == u ? u : par[u] = acs(par[u]) ;} 
bool join(int u,int v) {
	int x = acs(u) ; int y = acs(v) ; 
	if(x==y) return 0 ; 
	par[y] = x ; 
	return 1 ; 
}

void solve(void) {
	for(int i(1) ; i <= numCity ; i++) par[i] = i ; 
	for(int i(1) ; i <= numRoad ; i++) join(eRoad[i].u,eRoad[i].v) ; 
	for(int i(1) ; i <= numCity ; i++) mstRoadID[i] = acs(i) ; 

	for(int i(1) ; i <= numCity ; i++) par[i] = i ;
	for(int i(1) ; i <= numRail ; i++) join(eRail[i].u,eRail[i].v) ; 
	for(int i(1) ; i <= numCity ; i++) mstRailID[i] = acs(i) ; 

	for(int i(1) ; i <= numCity ; i++) mp[mstRoadID[i]][mstRailID[i]]++ ; 
	for(int i(1) ; i <= numCity ; i++) cout << mp[mstRoadID[i]][mstRailID[i]] << ' ' ; 
}

signed main(void) {
    #define mitsuri ""
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if( fopen(mitsuri".INP","r") ) {
        freopen(mitsuri".INP","r",stdin) ; freopen(mitsuri".OUT","w",stdout);
    }
    init() ;
    solve() ; 
    cerr << endl << "watborhihi : " << clock() << "ms " << endl;
    return 0 ;
}