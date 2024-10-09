
#include<bits/stdc++.h>
using namespace std;
#define         ll long long
#define         goi5gviettel ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define         fr(i,a,b) for(i=a;i<=b;i++)
#define         fd(i,b,a) for(i=b;i>=a;i--)
const ll SIZE =1e7;

ll gcd(ll a,ll b) {ll temp;while(b!=0) {temp = a%b;a=b;b=temp;}return a;}
ll lcm(ll a,ll b) {return a/gcd(a,b) *b;}
ll c,n,i,j;
ll a[17];
void Doc() {
    cin >> c >> n;
    fr(i,1,n) cin >> a[i];
}
ll ans = -2e9;
void ql(ll pos,ll sum){
    if(sum>c) return ;
    if(pos>n){
        if(sum<=c){
            ans = max(ans,sum);
        }
        return ;
    }
    ql(pos+1,sum);
    ql(pos+1,sum+a[pos]);
}
void Sol(){
    ql(0,0);
    cout << ans;
    
}
void LamMau(){
    cerr<< endl<<  "Time:" <<" " << 0.001*clock() << "s" << endl;
    cerr<< " WatborInDaHood " << endl; 
}
int main(){
    goi5gviettel
    
    Doc();
    Sol();
    LamMau();
}