
#include<bits/stdc++.h>
using namespace std;
#define         ll long long
#define         goi5gviettel ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define         fr(i,a,b) for(i=a;i<=b;i++)
#define         fd(i,b,a) for(i=b;i>=a;i--)
const ll SIZE =1e7;

ll gcd(ll a,ll b) {ll temp;while(b!=0) {temp = a%b;a=b;b=temp;}return a;}
ll lcm(ll a,ll b) {return a/gcd(a,b) *b;}
ll x;
ll a[10];
vector<ll> v;
ll n;
ll f1[10];
ll f2[10];
ll temp;
void Doc() {
    cin >> x;
     temp = x;
    while(x!=0){
        v.push_back(x%10);
        f1[x%10]++;
        x/=10;
    }
    reverse(v.begin(),v.end());
     n = v.size();
}
ll ans = 2e9;
void ql(ll pos){
    if(pos >n ){
        ll i ;
        ll sum = 0;
        ll check = 1;
        fr(i,1,n) f2[a[i]]++;
        fr(i,1,n){
            if(f2[a[i]]!=f1[a[i]]){
                check =0;
                break;
            }else {
                sum = sum*10 + a[i];
                if(sum>ans) {
                    check = 0;
                    break;
                }
            }
        }
        if(check==1) {
            if(sum>temp) ans= min(ans,sum);
        }
        fr(i,1,n) f2[a[i]] =0;
    }   
    else{
        ll j;
        fr(j,0,n-1){
            a[pos] = v[j];
            ql(pos+1);
        }
    }

}
void Sol(){
    ql(1);
    if(ans == 2e9) cout << 0;
    else cout << ans;
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