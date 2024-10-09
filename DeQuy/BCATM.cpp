#include<bits/stdc++.h>
using namespace std;
#define         ll long long
#define         goi5gviettel ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define         fr(i,a,b) for(i=a;i<=b;i++)
#define         fd(i,b,a) for(i=b;i>=a;i--)



ll n,k;
ll a[31];
ll t[31];
void Doc() {
    cin >> n >> k;
    int i;
    fr(i,1,n) cin >> t[i]; 
    
}
ll ans=2e9;
ll sum = 0;
ll cnt = 0;
void capnhatkq(){
    ll cnt =0;
    ll i;
    ll sum=0;
    fr(i,1,n) sum+=t[i]*a[i];
    fr(i,1,n){
        cnt+= (a[i]==1);
    }
    if(sum==k) ans = min(ans,cnt);
}

void ql(ll pos){
    ll j;
    fr(j,0,1){
        a[pos] = j;
        if(pos==n){
            capnhatkq();
        }else{
            ql(pos+1);
        }
    }
}
void Sol(){
  ql(1);
  if(ans==2e9) cout << -1;
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
