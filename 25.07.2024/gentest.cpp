#include<bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i,a,b) for(int i = a ; i <= b ; i++)
#define FORD(i,a,b) for(int i = a ; i <= b ; i++)
#define fi first
#define se second
#define endl '\n'

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
int Rand(int l,int r)
{
    return l + rd()%(r-l+1);
}

const string NAME = "estimation";
const int N = 1e5+5;
const int maxTest = 100;

int n , k ;
int a[N] ;
void create()
{
    ofstream inp ( (NAME + ".INP") . c_str() );
    n = Rand(5,5) , k = Rand(3,min(n,1ll*30)) ;
    inp << n << ' ' << k << endl ;
    FOR(i,1,n) {
        a[i] = Rand(-109,100) ; 
        inp << a[i] << ' ' ; 
    } 
    inp.close();
}

void check()
{
    system( (NAME + ".exe") . c_str() );
    system( (NAME + "_trau.exe").c_str() );

    if( system ( ("fc " + NAME + ".OUT " + NAME + ".ANS").c_str())!=0 )
    {
        cout << "Wrong!!";
        return;
    }
    cout << "Correct" << endl;
}

signed main()
{
    ios_base::sync_with_stdio();
    cin.tie(0);cout.tie(0);
    srand(time(NULL));	
    FOR(iTest,1,maxTest)
    {
        create();
         system( (NAME + ".exe") . c_str() );
        system( (NAME + "_trau.exe").c_str() );

        if( system ( ("fc " + NAME + ".OUT " + NAME + ".ANS").c_str())!=0 )
        {
            cout << "Wrong!!";
            return 0 ;
        }
        cout << "Correct" << endl;
    }
}
