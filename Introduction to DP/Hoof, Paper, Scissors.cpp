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

const ll INF = 1e15+250;
const ll P = 9973, M = 1e9+9;
const int MM = 1e5+5; int mod = 1e9+7;//998244353

int n, arr[MM], dp[MM][22][3];
map<char, int> m = {{'H', 0}, {'P', 1}, {'S', 2}};
int sw;
int main(){
    inputJunk
    freopen("hps.in","r", stdin);
    freopen("hps.out","w", stdout);
    cin>>n>>sw;
    for(int i= 0;i<n;i++){
        char c; cin>>c; arr[i] = m[c];
    }
    for(int i = 1;i<=n;i++){
        for(int j = 0;j<=sw;j++){
            for(int k = 0;k<3;k++){
                dp[i][j][k] = dp[i-1][j][k]+(k==arr[i-1]);
                if(j==0)continue;
                dp[i][j][k] = max(dp[i][j][k], dp[i-1][j-1][(k+1)%3]+((k+1)%3==arr[i-1]));
                dp[i][j][k] = max(dp[i][j][k], dp[i-1][j-1][(k+2)%3]+((k+2)%3==arr[i-1]));
            }
        }
    }
    int ans = 0;
    for(int i = 0;i<3;i++){
        ans = max(ans, dp[n][sw][i]);
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
