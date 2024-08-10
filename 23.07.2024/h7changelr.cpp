/*[продолжатьипродолжать]*/
#include <bits/stdc++.h>
using namespace std ; 
const int MAX = 3e5 + 5 ;
const int oo = 2e9 ;

int n ;
int a[MAX] , b[MAX] , c[MAX] ;
struct BG {
    int L , R , T ; 
};
void init(void) {
    cin >> n ; 
    for(int i = 1 ; i <= n ; i++) cin >> a[i] ; 
    for(int i = 1 ; i <= n ; i++) cin >> b[i] ; 
}

void solve(void) {
    unordered_map<int,int>mp ;
    for(int i = 1 ; i <= n ; i++) mp[a[i]]++ ; 
    for(int i = 1 ; i <= n ; i++) if(!mp[b[i]]) {
        cout << -1 ; 
        return ; 
    }
    int m = 0 ;
    for(int i = 1 ; i <= n ; i++) if(b[i]!=b[i-1]) {
        c[++m] = b[i] ; 
    }
    int l = 1 ;
    for(int i = 1 ; i <= n ; i++) {
        if(c[l]==a[i]) l++ ;
    }
    if(l <= m) {
        cout << -1 ; 
        return ; 
    }
    l = 1 ;
    vector<BG> C , B , vec ; 
    for(int i = 1 ; i <= n ; i++) {
        int r = l ; 
        while(r <= n && b[r]==a[i]) r++ ;   
        int L = l , R = r - 1 ;
        if(L <= R) {
            if(i < L) {
                B.push_back({i , R , 1}) ; 
            } else if(i > R) {
                C.push_back({L , i , 2}) ; 
            } else {
                C.push_back({L , i , 2}) ; 
                B.push_back({i , R , 1}) ; 
            }
            l = r ; 
        }
    }
    reverse(B.begin(),B.end()) ; 
    reverse(C.begin(),C.end()) ; 
    for(auto x : B) if(x.L!=x.R) vec.push_back({x.L,x.R,1}) ; 
    for(auto x : C) if(x.L!=x.R) vec.push_back({x.L,x.R,2}) ; 
    cout << vec.size() << endl ;
}

signed main(void) {
    #define NAME "H7CHANGELR"
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(NAME".inp","r") ) {
        freopen(NAME".inp","r",stdin) ; freopen(NAME".out","w",stdout);
    }
    init() ; 
    solve() ; 
    cerr << endl << "watborhihi : " << clock() << "ms" << endl;
    return 0 ;
}