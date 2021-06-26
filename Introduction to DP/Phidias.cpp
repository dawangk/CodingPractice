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

const int INF = 1e9+1212;
const ll P = 9973, M = 1e9+9;
const int MM = 604+5; int mod = 1e9+7;//998244353

int w, h, n, dp[MM][MM];bool done[MM][MM];

int dpp(int ww, int hh){
    //cout<<ww<<" "<<hh<<ell;
    if(done[ww][hh])return dp[ww][hh];
    int ans = ww*hh;
    for(int i = 1;i<ww;i++){
        ans = min(ans, dpp(i, hh)+dpp(ww-i, hh));

    }
    for(int i = 1;i<hh;i++){
        ans = min(ans, dpp(ww, i)+dpp(ww, hh-i));
    }
    dp[ww][hh] = ans;
    done[ww][hh] = true;
    return ans;
}

int main(){
    inputJunk
    cin>>w>>h>>n;
    for(int i= 0;i<n;i++){
        int a, b; cin>>a>>b;
        dp[a][b] = 0; done[a][b] = true;
    }

    cout<<dpp(w, h);
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
