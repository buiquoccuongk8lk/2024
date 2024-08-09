#include <bits/stdc++.h>
#define tct template<class MITSURII,class CHANN>
#define FOR(i,a,b) for(int i(a) ; i <= (b) ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= (b) ; i--)
using namespace std ; 
tct bool maxi(MITSURII &x,const CHANN &y) {if(x < y) {x = y ; return 1 ; } else return 0 ; }
tct bool mini(MITSURII &x,const CHANN &y) {if(x > y) {x = y ; return 1 ; } else return 0 ; }


signed main() {
    #define task ""
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin) ; freopen(task".out","w",stdout) ; 
    }
    string s ; cin >> s ;
    stack<char> st1 , st2 ; 
    for(auto c : s) {
        if(c == '<') {
            if(!st1.empty()) {
                st2.push(st1.top()) ; 
                st1.pop() ; 
            }
        } else if(c == '>') {
            if(!st2.empty()) {
                st1.push(st2.top()) ;
                st2.pop() ;  
            }
        } else if(c == '-') {
            if(!st1.empty()) st1.pop() ; 
        } else {
            st1.push(c) ; 
        }
    } 
    while(!st2.empty()) st1.push(st2.top()) , st2.pop() ;
    vector<char> ans ; 
    while(!st1.empty()) {
        ans.push_back(st1.top()) ; st1.pop() ; 
    }
    reverse(ans.begin(),ans.end()) ; 
    for(auto c : ans) cout << c ;
    cerr << "TIME : " << clock() * 0.001 << "s" << endl ;
    return 0 ; 
}