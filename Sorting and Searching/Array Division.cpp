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
#define FOR(i, a, b) for (auto i = a; i <= b; ++i)
#define REFOR(i, a, b) for (auto i = a; i >= b; --i)
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

bool check(ll a[], ll n, ll k, ll mid) {
    ll s = 0, cnt = 0;
    FOR(i, 1, n) {
        if (a[i] > mid) return false;
        if (s + a[i] > mid) {
            ++cnt;
            s = 0;
        }
        s += a[i];
    }
    if (s > 0) ++cnt;
    return cnt <= k;
}

void run_case() {
    ll n, k;
    cin >> n >> k;
    ll a[n + 1];
    FOR(i, 1, n) cin >> a[i];
    ll l = *max_element(a + 1, a + n + 1);
    ll r = l * n, res = -1;
    while (l <= r) {
        ll mid = (l + r) / 2;
        if (check(a, n, k, mid)) {
            res = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << res;
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