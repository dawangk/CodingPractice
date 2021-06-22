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

const int INF = 1e9+1212;
const ll P = 9973, M = 1e9+9;
const int MM = 1e5+5; int mod = 1e9+7;//998244353

int n, m, c,arr[1005], dp[1005][1005];
vi adj[MM];
bool reachable[1005][1005];
int main(){
    inputJunk
    freopen("time.in","r", stdin);
    freopen("time.out","w", stdout);
    cin>>n>>m>>c;
    for(int i = 1;i<=n;i++)cin>>arr[i];
    for(int i = 0;i<m;i++){
        int a, b; cin>>a>>b;
        adj[a].pb(b);
    }
    reachable[0][1] = true;
    for(int i = 0;i<=1000;i++)
        for(int j = 0;j<=n;j++)
            dp[i][j] = -INF;
    dp[0][1] = 0;
    for(int i = 0;i<=1000;i++){
        for(int j = 1;j<=n;j++){
            if(reachable[i][j]){
                for(int x: adj[j]){
                    dp[i+1][x]=max(dp[i+1][x], dp[i][j]+arr[x]);
                    reachable[i+1][x] = true;
                }
            }
        }
    }
    int ans =0 ;

    for(int i= 0;i<=1000;i++){
        ans = max(ans, dp[i][1]-c*i*i);
    }
    cout<<ans<<ell;
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
- for dp invalid cases needs to be skipped
- some base cases won't work (review cow poetry)
- always check bounds, some TLE are due to incorrect bounds!
- dont mess up return types
= RESET ARRAYS!!!!!!!!!!
- USE UR BRAIN
*/
/*
    freopen("time.in","r", stdin);
    freopen("time.out","w", stdout);
*/
