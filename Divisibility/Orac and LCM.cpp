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
const int MM = 1e5+5; int mod = 1e9+7;
 
ll n, arr[MM], p[MM], p2[MM];
 
int main(){
    inputJunk
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    p[0] = 1;
    p2[n+1] = 1;
    for(int i = 1;i<=n;i++){
        if(i==1) p[i] = arr[i-1];
        else p[i] = gcd(p[i-1],arr[i-1]);
    }
    ////for(int i = 0;i<=n;i++){
    //    cout<<p[i]<<" ";
    ///}cout<<endl;
    for(int i = n;i>=1;i--){
        if(i==n) p2[i] = arr[i-1];
        else p2[i] = gcd(p2[i+1],arr[i-1]);
    }
    ll ans = lcm(p[n-1], p2[2]);
    //cout<<ans<<ell;
    for(int i = 1;i<=n-2;i++){
        ans = lcm(ans, gcd(p[i], p2[i+2]));
    }
 
    //for(int i = 0;i<=n;i++){
    //    cout<<p2[i]<<" ";
    //}cout<<endl;
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
 
