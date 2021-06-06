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
const int MM = 1e6+5; int mod = 998244353;//1e9+7

int n, freq[MM], hax[MM];
vi p[MM];
ll add (ll a, ll b){
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
    cin>>n;
    for(int i = 0;i<n;i++){
        int k; cin>>k;
        for(int j = 0;j<k;j++){
            int x; cin>>x;
            freq[x]++;
            p[i].pb(x);
        }
    }

    for(int i = 0;i<MM;i++){
        hax[i] = binpow(i, mod-2);
    }
    ll ans = 0;
    ll mc2 = hax[n];
    for(int i = 0;i<n;i++){
        ll mc = hax[p[i].size()];
       for(int j = 0;j<p[i].size();j++){
            ans = add(ans, mult(mult(freq[p[i][j]], mc2) , mult(mc, mc2)));
       }
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
*/

//freopen("time.in","r", stdin);
//freopen("time.out","w", stdout);

