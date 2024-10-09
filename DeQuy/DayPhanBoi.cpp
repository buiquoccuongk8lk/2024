// Thế giới rất đông người, đã gặp được em. Nếu có thể hãy ở lại nhé 

#include<bits/stdc++.h>

using namespace std;

#define int long long
#define FOR(i,a,b) for(int i = a ; i <= b ; i++)
#define FORD(i,a,b) for(int i = a ; i >= b ; i--)
#define endl '\n'
#define fi first
#define se second

void Clock(){
    cerr << endl;
    cerr << "Time Elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s ";
}

const int N = 1e6+5;

int ans = 1,n ;
pair<int,int> c[N];
int a[N];
int b[N];
void ql(int pos){
    if(pos > n ){
        int  m = 0;

        FOR(i,1,n){
            if(b[i]==1){
                m++;
                c[m].fi = a[i];
                c[m].se = i;
            }
        }

        FOR(i,2,m){
            if(c[i].fi <= c[i-1].fi) {
                return;
            }
        }

        FOR(i,1,m){
            FOR(j,1,i-1){
                if(c[i].se % c[j].se ==0 ) return;
            }
        }
        ans = max(ans, m);

    }else{
        FOR(j,0,1) {
            b[pos] = j;
            ql(pos+1);
        }
    }

}

void Solve(){
    ql(1);
    cout << ans;
}

signed main(){
    #define TASK ""
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    if(fopen(TASK".INP","r") ) {freopen(TASK".INP","r",stdin);freopen(TASK".OUT","w",stdout);}       
    cin >> n ;
    FOR(i,1,n) cin >> a[i];
    Solve();
    Clock();
    return 0;
}