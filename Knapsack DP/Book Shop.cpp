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
const int MM = 1e5+5; int mod = 1e9+7;//998244353

int n, w, c[1005], v[1005], dp[1005][MM];

int main(){
    inputJunk
    cin>>n>>w;
    for(int i = 1;i<=n;i++){
        cin>>c[i];
    }
    for(int i = 1;i<=n;i++){
        cin>>v[i];
    }

    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=w;j++){
            dp[i][j] = dp[i-1][j];
            if(j-c[i]>=0){
                dp[i][j] = max(dp[i][j], dp[i-1][j-c[i]]+v[i]);
            }

        }
    }
    cout<<dp[n][w]<<ell;
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

