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
 
int n; ll prod = 1; vi ans;
 
int main(){
    inputJunk
    cin>>n;
    for(int i = 1;i<n;i++){
        if(__gcd(i, n)==1){
            prod=(prod*i)%n;
            ans.pb(i);
        }
    }
    //cout<<prod<<endl;
    if(prod!=1){
        ans.erase(find(all(ans), prod));
    }
    cout<<ans.size()<<ell;
    for(int x: ans){
        cout<<x<<" ";
    }cout<<ell;
 
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
*/
 
//freopen("time.in","r", stdin);
//freopen("time.out","w", stdout);
