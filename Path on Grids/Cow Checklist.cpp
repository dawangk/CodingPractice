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
const int MM = 1e3+5; int mod = 1e9+7;//998244353

int h, g, dp[MM][MM][2]; pi hs[MM], gs[MM];

int dist(pi a, pi b){
    return abs(a.f-b.f)*abs(a.f-b.f) + abs(a.s-b.s)*abs(a.s-b.s);
}

int main(){
    inputJunk
    freopen("checklist.in","r", stdin);
    freopen("checklist.out","w", stdout);
    cin>>h>>g;
    for(int i = 1;i<=h;i++){
        int a, b;
        cin>>a>>b;
        hs[i] = {a,b};
    }
    for(int i = 1;i<=g;i++){
        int a, b;
        cin>>a>>b;
        gs[i] = {a,b};
    }
    dp[1][0][0] = 0;
    for(int i = 0;i<=h;i++){
        for(int j = 0;j<=g;j++){
            if(i==0){
                dp[i][j][0] = INF;
                dp[i][j][1] = INF;
                continue;
            }else if(j==0){
                if(i>1)dp[i][j][0] = min(dp[i-1][j][0]+dist(hs[i], hs[i-1]), dp[i-1][j][1]+dist(hs[i], gs[i-1]));
                dp[i][j][1] = INF;
                continue;
            }
            dp[i][j][0] = min(dp[i-1][j][0]+dist(hs[i], hs[i-1]), dp[i-1][j][1]+dist(hs[i], gs[j]));
            dp[i][j][1] = min(dp[i][j-1][0]+dist(gs[j], hs[i]), dp[i][j-1][1]+dist(gs[j], gs[j-1]));
        }
    }
    //cout<<dp[2][0][0]<<" "<<dp[1][0][0]<<dist(hs[2], hs[1])<<endl;
    /*for(int i = 0;i<=h;i++){
        for(int j = 0;j<=g;j++){
            cout<<dp[i][j][0]<<" ";
        }cout<<ell;
    }
    for(int i = 0;i<=h;i++){
        for(int j = 0;j<=g;j++){
            cout<<dp[i][j][1]<<" ";
        }cout<<ell;
    }*/

    cout<<dp[h][g][0]<<ell;
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

