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
const int MM = 1e4+5; int mod = 1e9+7;//998244353

int n, x;ll dp[55][10005], p[55][10005];
int arr[105];

int main(){
    inputJunk
    cin>>n>>x;
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr, arr+n);
    p[0][5000] = 1;
    for(int i = 1;i<=n;i++){
        for(int j = 0;j<=50;j++){
            for(int k = 0;k<=10000;k++){
                dp[j][k] += 1LL*p[j][k];
                dp[j][k] += 1LL*j*p[j][k];
                dp[j][k] += 1LL*(j+1)*p[j+1][k-arr[i-1]];
                if(j!=0)
                    dp[j][k] += 1LL*p[j-1][k+arr[i-1]];
                dp[j][k]%=mod;
            }
        }
        for(int j = 0;j<=50;j++){
            for(int k = 0;k<=10002;k++){
                p[j][k] = dp[j][k];
                dp[j][k] = 0;
            }
        }
    }
    ll ans = 0;
    for(int i = 5000;i<=5000+x;i++){
        ans+=p[0][i];
        ans%=mod;
    }
    cout<<ans<<ell;
}
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

/*CUSTOM TEST CASE 1
*/

/*CUSTOM TEST CASE 2

*/

/*CUSTOM TEST CASE 3
*/



//freopen("time.in","r", stdin);
//freopen("time.out","w", stdout);

