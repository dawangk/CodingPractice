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
const int MM = 5e6+5; int mod = 1e9+7;//998244353

int t, a, b; bool dp[MM];

int main(){
    inputJunk
    freopen("feast.in","r", stdin);
    freopen("feast.out","w", stdout);
    cin>>t>>a>>b;
    dp[a] = 1;
    dp[b] = 1;
    for(int i = 1;i<=t;i++){
        if(i>=a)dp[i]|=dp[i-a];
        if(i>=b)dp[i]|=dp[i-b];
    }

    for(int i = 1;i<=t;i++){
        dp[i/2] |= dp[i];
    }
    for(int i = 1;i<=t;i++){
        if(i>=a)dp[i]|=dp[i-a];
        if(i>=b)dp[i]|=dp[i-b];
    }
    for(int i = t;i>=1;i--){
        if(dp[i]){cout<<i<<ell; return 0;}
    }
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

