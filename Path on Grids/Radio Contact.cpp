#include <bits/stdc++.h>
using namespace std;
#define inputJunk ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define debug cout<<"HERE"<<endl;
#define ell "\n"

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef pair<pi, int> trip;
typedef pair<pll, ll> tripll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
typedef vector<trip> vtrip;

const int INF = 1e9+250;
const ll P = 9973, M = 1e9+9;
const int MM = 1e3+5; int mod = 1e9+7;//998244353

int a, b, x1, y11, x2, y2, dp[MM][MM];
vpi fj, be;
map<char, pi> m = {{'N', {0, 1}}, {'E', {1, 0}}, {'S', {0, -1}}, {'W', {-1, 0}}};

int dist(pi a, pi b){
    return abs(a.f-b.f)*abs(a.f-b.f) + abs(a.s-b.s)*abs(a.s-b.s);
}

int main(){
    inputJunk
freopen("radio.in","r", stdin);
freopen("radio.out","w", stdout);
    cin>>a>>b>>x1>>y11>>x2>>y2;
    string s1, s2;
    cin>>s1>>s2;
    for(int i = 0;i<a;i++){
        fj.pb({x1, y11});
        x1+=m[s1[i]].f;
        y11+=m[s1[i]].s;
    }fj.pb({x1, y11});
    for(int i = 0;i<b;i++){
        be.pb({x2, y2});
        x2+=m[s2[i]].f;
        y2+=m[s2[i]].s;
    }be.pb({x2, y2});

    dp[0][0] = dist(fj[0], be[0]);
    for(int i = 1;i<=a;i++){
        dp[i][0] = dp[i-1][0]+ dist(be[0], fj[i]);
    }
    for(int i = 1;i<=b;i++){
        dp[0][i] = dp[0][i-1]+ dist(be[i], fj[0]);
    }
    for(int i = 1;i<=a;i++){
        for(int j = 1;j<=b;j++){
            dp[i][j] = min(dp[i-1][j-1]+dist(fj[i], be[j]), min(dp[i-1][j]+dist(fj[i], be[j]), dp[i][j-1]+dist(fj[i], be[j])));
        }
    }
    /*
    for(int i = 0;i<=a;i++){
        for(int j = 0;j<=b;j++){
            cout<<dp[i][j]<<" ";
        }cout<<ell;
    }*/
    cout<<dp[a][b]-dp[0][0]<<ell;
}


/*CUSTOM TEST CASE 1
*/

/*CUSTOM TEST CASE 2

*/

/*CUSTOM TEST CASE 3

*/
/*Comments of Shame
- floating error (use integer division instead)
- cin vs getline
- upperbound and lowerbound returns iterators
- use long long when number is big enough
*/

//freopen("time.in","r", stdin);
//freopen("time.out","w", stdout);

