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

ll n, m, k, dp[MM], ways[MM];
map<ll, ll> ma, freq;
map<ll, vll> things;

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
    freopen("poetry.in","r", stdin);
    freopen("poetry.out","w", stdout);
    cin>>n>>m>>k;
    for(int i = 0;i<n;i++){
        int a, b; cin>>a>>b;
        things[b].pb(a);
        ma[a]++;
    }
    for(int i = 0;i<m;i++){
        char c; cin>>c;
        freq[c-'A']++;
    }
    dp[0]=1;
    for(int i = 1;i<=k;i++){
        for(auto y: ma){
            if(i>=y.f)dp[i] = add(dp[i],mult(dp[i-y.f],y.s));
        }
    }
    int curr = 0;
    for(auto y: things){
        for(int x: y.s){
            if(k>=x)ways[curr]=add(ways[curr], dp[k-x]);
        }
        curr++;
    }

    ll ans = 1;
    for(auto x:freq){
        ll t = x.s;
        ll cur = 0;
        for(int i = 0;i<curr;i++){
            cur = add(cur, binpow(ways[i], t));
            //cout<<i<<" " <<ways[i]<<ell;
        }
        ans = mult(ans, cur);
    }


    cout<<ans<<ell;
}
/*Comments of Shame
- floating error (use integer division instead)
- cin vs getline
- upperbound and lowerbound returns iterators
- use long long when number is big enough
- for dp invalid cases needs to be skipped
- 
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

