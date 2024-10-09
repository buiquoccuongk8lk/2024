/* 29 . 03 . 2008 */
#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef vector<int> vi ;
typedef vector<pair<int,int>> vii ;
typedef pair<int,int> pii ;
typedef pair<ll,int> pli ;
typedef pair<int,ll> pil ;
typedef pair<ll,ll> pll ;
#define FOR(i,a,b) for(int i(a) ; i <= (int)b ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= (int)b ; i--)
#define FORN(i,a,b) for(int i(a) ; i < (int)b ; i++)
#define all(a) a.begin() , a.end()
#define pb push_back
#define fi first
#define se second
#define endl '\n'
#define BIT(mask,i) ((mask>>i)&1)
#define builtin_popcount builtin_popcountll
#define MASK(a) (1ll << a)

template <class T> bool maxi(T &x,T y) { if (x < y) { x = y ; return true ;} return false ;}
template <class T> bool mini(T &x,T y) { if (x > y) { x = y ; return true ;} return false ;}

const int N = 55 ;

int n, m ;
string s ;

void init() {
    cin >> n ;
    cin >> s ;
    cout << n << endl ;
    m = s.size() ; s = "*" + s ;
}

namespace subtask_1 {
    char a[N] ;
    unordered_map<string, int> cnt ;

    void Try(int i) {
        if(i > m) {
            string t = "" ;
            FOR(i, 1, m) t.push_back(a[i]) ;
            cnt[t]++ ;
            return ;
        }
        if(s[i] == '*') {
            for(char j = '0'; j <= '1'; j++) {
                a[i] = j ;
                Try(i + 1) ;
            }
        } else {
            a[i] = s[i] ;
            Try(i + 1) ;
        }
    }

    void solve() {
        Try(1) ;

        int ans = 0 ;

        FOR(mask, 0, (1 << n) - 1) {
            string t = "" ;
            FOR(j, 0, n - 1) {
                if(BIT(mask, j)) t.push_back('1') ;
                else t.push_back('0') ;
            }
            FOR(i, 0, t.size() - m) {
                if(cnt[t.substr(i, m)]) {
                    ans++ ;
                    break ;
                }
            }
        }
        cout << ans ;
    }
}

signed main() {
    #define task "seed"
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
    if(fopen(".inp","r")) {
        freopen(".inp","r",stdin) ; freopen(".out","w",stdout) ;
    }
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin) ; freopen(task".out","w",stdout) ;
    }
    init() ;
    if(n <= 20) return subtask_1::solve(),0 ;
    cerr << "\nTime : " << clock() * 0.001 << "s" << endl ;
    return 0 ;
}
/* Watbor */
