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

const string NAME = "test1";
const int N = 1e5+5;
const int maxTest = 100;
long long a[N] ; 
void create()
{
    ofstream inp ( (NAME + ".INP") . c_str() );
    int n = Rand(1,10) ; 
    inp << n <<" " ; 
    int q = Rand(1,10) ; 
    inp << q << endl ; 
    FOR(i,1,n)
    {
        a[i] = Rand(-1e9,1e9) ; 
        inp << a[i] <<" " ;
    }
    inp << endl ; 
    FOR(i,1,q)
    {
        int t , l ,r , x ;
        t = Rand(1,2) ; 
        if(t==1)
        {
            l = Rand(1,n) ;
            r = Rand(l,n) ; 
            x = Rand(-1e9,1e9) ; 
            inp<< t <<" " << l <<" " << r <<" "<< x << endl ;
        }else
        {
            l = Rand(1,n) ;
            r = Rand(l,n) ; 
             inp<< t <<" " << l <<" " << r << endl ;
        }
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
