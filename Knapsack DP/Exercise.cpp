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

ll n, dp[1333][MM];
vi primes; bool isc[MM];

ll add (ll a, ll b){
    while(a<0)a+=mod;
    while(b<0)b+=mod;
    return (a+b)%mod;
}

ll mult (ll a, ll b){
    return (a*b)%mod;
}
ll binpow(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b & 1) res = mult(res, a);
		a = mult(a, a);
		b >>= 1;
	}
	return res;
}

int main(){
    inputJunk
    freopen("exercise.in","r", stdin);
    freopen("exercise.out","w", stdout);
    cin>>n>>mod;
    for(int i = 2;i<=n;i++){
        if(!isc[i]){
            primes.pb(i);
            for(int j = 2*i;j<=n;j+=i){
                isc[j] = true;
            }
        }
    }
    //for(int x: primes)cout<<x<<" ";
    //cout<<ell;

    if(primes.size()==0){cout<<1<<ell;return 0;}
    for(int i = 0;i<=n;i++){
        dp[0][i] = 1;
    }

    for(int i = 1;i<=primes.size();i++){
        for(int j = 0;j<=n;j++){
            dp[i][j] = dp[i-1][j];
            int cur = primes[i-1];
            while(cur<=j){
                dp[i][j] = add(dp[i][j], mult(cur,dp[i-1][j-cur]));
                cur*=primes[i-1];
            }
            //cout<<dp[i][j]<<" ";
        }//cout<<ell;
    }
    cout<<dp[primes.size()][n]<<ell;
}
/*Comments of Shame
- floating error (use integer division instead)
- cin vs getline
- upperbound and lowerbound returns iterators
- use long long when number is big enough
- for dp invalid cases needs to be skipped
- some base cases won't work (review cow poetry)
- always check bounds, some TLE are due to incorrect bounds!
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

