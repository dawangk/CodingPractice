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
const int MM = 1e6+5; int mod = 1e9+7;//998244353

ll frac[2*MM], inv[MM], ans = 0;

ll add (ll a, ll b, ll mod){
    while(a<0)a+=mod;
    while(b<0)b+=mod;
    return (a+b)%mod;
}

ll mult (ll a, ll b, ll mod){
    return (a%mod*b%mod)%mod;
}

ll binpow(ll a, ll b, ll mod) {
	ll res = 1;
	while (b) {
		if (b & 1) res = mult(res, a, mod);
		a = mult(a, a, mod);
		b >>= 1;
	}
	return res;
}

int main(){
    inputJunk
    int n; cin>>n;
    ll num = 1,  sum = 1,num2 = 1, prod = 1;
    for(int i = 0;i<n;i++){
        ll a, b;
        cin>>a>>b;
        num = mult(num, b+1, mod);
        sum = mult(sum, mult(binpow(a, b+1, mod)-1, binpow(a-1, mod-2, mod), mod), mod);
        prod = mult(binpow(prod, b+1, mod), binpow(binpow(a,(b)*(b+1)/2,mod), num2, mod), mod);
        num2 = mult(num2, b+1, mod-1);

    }
    cout<<num<<" "<<sum<<" "<<prod<<ell;
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

