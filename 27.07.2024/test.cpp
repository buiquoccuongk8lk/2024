/*[продолжатьипродолжать]*/
/* ---------------------- *
 *     Code by watbor     *
 *                        * 
--------------------------*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define fi first
#define se second
#define pb push_back
#define ii pair<int,int>
#define vii vector<ii>
#define vi vector<int>
#define endl '\n' 
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define FOR(i,a,b) for(int i(a) ; i <= b ; i++)
#define FORD(i,a,b) for(int i(a) ; i >= b ; i--)
#define uni(a) sort(all(a)) , a.resize(unique(a.begin(),a.end())-a.begin()) 

const int N = 1e6 + 5 ;
const int LO = 17 ;
const int base = 311 ;
const int M = 1e3 + 5 ; 
const int oo = 2e9 ; 
const long long inf = 1e18 ;
const long long MOD = 1e9 + 7 ;

template<class X, class Y> bool minimize(X &x, const Y &y) {if(x>y){x=y;return true;}else return false;}
template<class X, class Y> bool maximize(X &x, const Y &y) {if(x<y){x=y;return true;}else return false;}

int n , m , q ; 
struct station {
	int R ; 
	int C ; 
	ll W ; 
} sta[N] ; 

void init(void) {
	cin >> n >> m >> q ; 
	FOR(i,1,m) {
		cin >> sta[i].R >> sta[i].C >> sta[i].W ; 
	}
}

namespace sub1 {
	ll a[505][505] ;
	ll sum_row[505] ; 
	ll sum_col[505] ; 
	void solve(void) {
		memset(a,0,sizeof(a)) ; 
		FOR(i,1,m) {
			a[sta[i].R][sta[i].C] = sta[i].W ; 
		}
		ll ans = 0 ; 
		FOR(i,1,n) {
			FOR(j,1,n) sum_row[i] += a[i][j] ; 
		}
		FOR(i,1,n) {
			FOR(j,1,n) sum_col[i] += a[j][i] ; 
		}
		FOR(fir,1,n) {
		FOR(sec,1,n) {
			FOR(thi,1,n) {
				if(fir!=sec and fir!=thi and sec!=thi) {
					maximize(ans , sum_row[fir] + sum_row[sec] + sum_row[thi]) ; 
					maximize(ans , sum_col[fir] + sum_col[sec] + sum_col[thi]) ; 
				}
			}
		}
		FOR(sec,1,n) {
			FOR(thi,1,n) {
				if(sec!=thi) {
					maximize(ans , sum_row[fir] + sum_col[sec] + sum_col[thi] - a[fir][sec] - a[fir][thi] ) ;
				}
			}
		}
		FOR(sec,1,n) {
			FOR(thi,1,n) {
					if(sec!=fir) {
						maximize(ans , sum_row[fir] + sum_row[sec] + sum_col[thi] - a[fir][thi] - a[sec][thi]) ; 
					}
				}
			}
		}
		cout << ans  << '\n' ; 
		FOR(i,1,n) sum_row[i] = sum_col[i] = 0 ;
		while(q--) {
			ll t , d ;
			cin >> t >> d ; 
			a[sta[t].R][sta[t].C] += d ;
			ll ans = 0 ; 
			FOR(i,1,n) {
				FOR(j,1,n) sum_row[i] += a[i][j] ; 
			}
			FOR(i,1,n) {
				FOR(j,1,n) sum_col[i] += a[j][i] ; 
			}
			FOR(fir,1,n) {

				FOR(sec,1,n) {
					FOR(thi,1,n) {
						if(fir!=sec and fir!=thi and sec!=thi) {
							maximize(ans , sum_row[fir] + sum_row[sec] + sum_row[thi]) ; 
							maximize(ans , sum_col[fir] + sum_col[sec] + sum_col[thi]) ; 
						}
					}
				}

				FOR(sec,1,n) {
					FOR(thi,1,n) {
						if(sec!=thi) {
							maximize(ans , sum_row[fir] + sum_col[sec] + sum_col[thi] - a[fir][sec] - a[fir][thi] ) ;
						}
					}
				}
				FOR(sec,1,n) {
					FOR(thi,1,n) {
						if(sec!=fir) {
							maximize(ans , sum_row[fir] + sum_row[sec] + sum_col[thi] - a[fir][thi] - a[sec][thi]) ; 
						}
					}
				}
			}
			cout << ans  << '\n' ; 
			a[sta[t].R][sta[t].C] -= d ; 
			FOR(i,1,n) sum_row[i] = sum_col[i] = 0 ;
		}
	}

}

namespace sub2 {
	ll a[505][505] ;
	ll sum_row[505] ; 
	ll sum_col[505] ; 
	void solve(void) {
		memset(a,0,sizeof(a)) ; 
		FOR(i,1,m) {
			a[sta[i].R][sta[i].C] = sta[i].W ; 
		}
		ll ans = 0 ; 
		FOR(i,1,n) {
			FOR(j,1,n) sum_row[i] += a[i][j] ; 
		}
		FOR(i,1,n) {
			FOR(j,1,n) sum_col[i] += a[j][i] ; 
		}
		FOR(fir,1,n) {
		FOR(sec,1,n) {
			FOR(thi,1,n) {
				if(fir!=sec and fir!=thi and sec!=thi) {
					maximize(ans , sum_row[fir] + sum_row[sec] + sum_row[thi]) ; 
					maximize(ans , sum_col[fir] + sum_col[sec] + sum_col[thi]) ; 
				}
			}
		}
		FOR(sec,1,n) {
			FOR(thi,1,n) {
				if(sec!=thi) {
					maximize(ans , sum_row[fir] + sum_col[sec] + sum_col[thi] - a[fir][sec] - a[fir][thi] ) ;
				}
			}
		}
		FOR(sec,1,n) {
			FOR(thi,1,n) {
					if(sec!=fir) {
						maximize(ans , sum_row[fir] + sum_row[sec] + sum_col[thi] - a[fir][thi] - a[sec][thi]) ; 
					}
				}
			}
		}
		cout << ans  << '\n' ; 
		FOR(i,1,n) sum_row[i] = sum_col[i] = 0 ;
		while(q--) {
			ll t , d ; 
			cin >> t >> d ; 
			a[sta[t].R][sta[t].C] += d ; 
			ll res = 0 ; 
			FOR(i,1,n) {
				FOR(j,1,n) sum_row[i] += a[i][j] ; 
			}
			FOR(i,1,n) {
				FOR(j,1,n) sum_col[i] += a[j][i] ; 
			}
			int fir = sta[t].R ; 
			// khi chọn fir làm hàng
			FOR(sec,1,n) {
				FOR(thi,1,n) {
					if(sec!=fir and sec!=thi and fir!=thi) {
						maximize(res , sum_row[fir] + sum_row[sec] + sum_row[thi]) ; 
					}
				}
			}
			FOR(sec,1,n) {
				FOR(thi,1,n) {
					if(sec!=thi) {
						maximize(res, sum_row[fir] + sum_col[sec] + sum_col[thi] - a[fir][sec] - a[fir][thi]) ; 
					}
				}
			}
			FOR(sec,1,n) {
				FOR(thi,1,n) {
					if(sec!=fir) {
						maximize(res, sum_row[fir] + sum_row[sec] + sum_col[thi] - a[fir][thi] - a[sec][thi]) ; 
					}
				}
			}
			fir = sta[t].C ; 
			// khi chọn fir làm cột
			FOR(sec,1,n) {
				FOR(thi,1,n) {
					if(sec!=fir and sec!=thi and fir!=thi) {
						maximize(res, sum_col[fir] + sum_col[sec] + sum_col[thi]) ; 
					}
				}
			}
			FOR(sec,1,n) {
				FOR(thi,1,n) {
					if(thi!=fir) {
						maximize(res, sum_col[fir] + sum_col[thi] + sum_row[sec] - a[sec][fir] - a[sec][thi]) ; 
					}
				}
			}
			FOR(sec,1,n) {
				FOR(thi,1,n) {
					if(thi!=sec) {
						maximize(res, sum_col[fir] + sum_row[sec] + sum_row[thi] - a[thi][fir] - a[sec][fir]) ; 
					}
				}
			}
			cout << max(ans ,res ) << '\n' ; 
			a[sta[t].R][sta[t].C] -= d ; 
			FOR(i,1,n) sum_row[i] = sum_col[i] = 0 ;
		}

	}

}

signed main(void) {
    #define TASK "THREE"
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    if( fopen(TASK".INP","r") ) {
        freopen(TASK".INP","r",stdin) ; freopen(TASK".OUT","w",stdout);
    }
   	int T ; 
   	cin >> T ;
   	while(T--) {
    	init() ; 
    	if(n <= 40 and q <= 40 and m <= 40 ) sub1::solve() ; 
    	else if(n <= 500 and q <= 500 and m <= 500 ) sub2::solve() ;
    }
    cerr << endl << "watborhihi : " << 1.0 * clock() / CLOCKS_PER_SEC << "s  " << endl;
    return 0;
}