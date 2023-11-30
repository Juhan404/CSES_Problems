#include <bits/stdc++.h>
using namespace std;

void __print(int x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x)
{cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x)
{int f = 0; for (auto &i : x) cerr << (f++ ? "," : ""), __print(i);}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v)
{__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "Line " << __LINE__ << ": " << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define ll long long
#define sz(x) (int) x.size()
#define all(x) x.begin(), x.end()
#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define REFOR(i, a, b) for (int i = a; i >= b; --i)
#define pii pair <int, int>
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define fastsync() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vi vector <int>
#define vll vector <ll>
#define endl '\n'
#define pb push_back
#define fi first
#define se second
#define pob pop_back

const int MOD = 1e9 + 7;
const int MAX = 1e6 + 7;

void run_case() {
    string s;
    cin >> s;
    map <char, int> mp;
    for (char x : s) ++mp[x];
    int le = 0;
    for (auto x : mp) if (x.se & 1) ++le;
    if ((sz(s) & 1 && le == 1) || (sz(s) % 2 == 0 && le == 0)) {
        string temp;
        for (auto x : mp) if (x.se % 2 == 0) FOR(i, 1, x.se / 2) temp.pb(x.fi);
        cout << temp;
        for (auto x : mp) if (x.se & 1) FOR(i, 1, x.se) cout << x.fi;
        reverse(all(temp));
        cout << temp;
    }
    else cout << "NO SOLUTION";
}

int main() {
    fastsync();
    int test = 1;
    while (test -- > 0) {
        run_case();
    }
    cerr << "Time elapsed: " << fixed << setprecision(3) << TIME << "s.";
    return 0;
}