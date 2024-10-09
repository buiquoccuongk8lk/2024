#include<bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define ALL(v) (v).begin(), (v).end()
#define IS_INF(x)   (std::isinf(x))
#define IS_NAN(x)   (std::isnan(x))
#define fi   first
#define se   second
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define div   ___div
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
#define __builtin_popcount __builtin_popcountll
using namespace std;
template<class X, class Y>
    bool minimize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x > y + eps) {
            x = y;
            return true;
        } else return false;
    }
template<class X, class Y>
    bool maximize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x + eps < y) {
            x = y;
            return true;
        } else return false;
    }
template<class T>
    T Abs(const T &x) {
        return (x < 0 ? -x : x);
    }

/* Author: Van Hanh Pham */

/** END OF TEMPLATE. DRINK A CUP OF TIGERSUGAR BEFORE READING MY CODE. **/

struct Query {
    int oldRow, oldCol, newRow, newCol;

    Query() {
        oldRow = oldCol = newRow = newCol = 0;
    }

    void input(void) {
        scanf("%d%d%d%d", &oldRow, &oldCol, &newRow, &newCol);
    }
};

struct Piece {
    int row, col, value;

    Piece() {
        row = col = value = 0;
    }

    void input(void) {
        scanf("%d%d%d", &row, &col, &value);
    }
};

#define MAX   600600
vector<int> rows, cols;
int boardSize, numPiece, numQuery;
Piece pieces[MAX];
Query queries[MAX];

unordered_map<int, int> values[MAX];
int xorRow[MAX], xorCol[MAX];
unordered_map<int, int> cntRow, cntCol;
long long res;

void init(void) {
    scanf("%d%d%d", &boardSize, &numPiece, &numQuery);
    FOR(i, 1, numPiece) {
        pieces[i].input();
        rows.push_back(pieces[i].row);
        cols.push_back(pieces[i].col);
    }
    FOR(i, 1, numQuery) {
        queries[i].input();
        rows.push_back(queries[i].oldRow);
        cols.push_back(queries[i].oldCol);
        rows.push_back(queries[i].newRow);
        cols.push_back(queries[i].newCol);
    }
}

void prepare(void) {
    sort(ALL(rows));
    rows.resize(unique(ALL(rows)) - rows.begin());
    sort(ALL(cols));
    cols.resize(unique(ALL(cols)) - cols.begin());

    FOR(i, 1, numPiece) {
        pieces[i].row = lower_bound(ALL(rows), pieces[i].row) - rows.begin() + 1;
        pieces[i].col = lower_bound(ALL(cols), pieces[i].col) - cols.begin() + 1;
        cout << pieces[i].row << ' ' << pieces[i].col << endl ;
    }
    FOR(i, 1, numQuery) {
        queries[i].oldRow = lower_bound(ALL(rows), queries[i].oldRow) - rows.begin() + 1;
        queries[i].oldCol = lower_bound(ALL(cols), queries[i].oldCol) - cols.begin() + 1;
        queries[i].newRow = lower_bound(ALL(rows), queries[i].newRow) - rows.begin() + 1;
        queries[i].newCol = lower_bound(ALL(cols), queries[i].newCol) - cols.begin() + 1;
        cout << queries[i].oldRow << ' ' << queries[i].oldCol << ' ' << queries[i].newRow << ' ' << queries[i].newCol << endl ;
    }
}

int getMap(const unordered_map<int, int> &mp, int key) {
    __typeof(mp.begin()) it = mp.find(key);
    return it == mp.end() ? 0 : it->second;
}
void setMap(unordered_map<int, int> &mp, int key, int delta) {
    int &x = mp[key];
    x += delta;
    if (x == 0) mp.erase(key);
}

void update(int xorRow[], unordered_map<int, int> &cntRow, const unordered_map<int, int> &cntCol, int key, int value) {
    int oldValue = xorRow[key];
    xorRow[key] ^= value;
    int newValue = xorRow[key];
    res -= getMap(cntCol, oldValue);
    res += getMap(cntCol, newValue);
    setMap(cntRow, oldValue, -1);
    setMap(cntRow, newValue, +1);
}

void query(int oldRow, int oldCol, int newRow, int newCol) {
    __typeof(values[oldRow].begin()) it = values[oldRow].find(oldCol);
    int tmp = it->se;
    values[oldRow].erase(it);
    values[newRow][newCol] = tmp;

    if (oldRow != newRow) {
        update(xorRow, cntRow, cntCol, oldRow, tmp);
        update(xorRow, cntRow, cntCol, newRow, tmp);
    }

    if (oldCol != newCol) {
        update(xorCol, cntCol, cntRow, oldCol, tmp);
        update(xorCol, cntCol, cntRow, newCol, tmp);
    }

    printf("%lld ", 1LL * boardSize * boardSize - res);
}

void process(void) {
    cntRow[0] = boardSize;
    cntCol[0] = boardSize;
    res = 1LL * boardSize * boardSize;
    FOR(i, 1, numPiece) {
        values[pieces[i].row][pieces[i].col] = pieces[i].value;
        update(xorRow, cntRow, cntCol, pieces[i].row, pieces[i].value);
        update(xorCol, cntCol, cntRow, pieces[i].col, pieces[i].value);
    }


    FOR(i, 1, numQuery) query(queries[i].oldRow, queries[i].oldCol, queries[i].newRow, queries[i].newCol);
    printf("\n");
}

int main(void) {
    freopen("topovi.inp", "r", stdin);
    freopen("topovi.out", "w", stdout);
    init();
    prepare();
    process();
    return 0;
}

/*** BUBBLE TEA IS GREAT. MY CODE IS AMAZING :D ***/