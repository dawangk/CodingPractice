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
const int MM = 3e3+5; int mod = 1e9+7;//998244353

int n, bfs[MM], dfs[MM]; vi adj[MM];
set<pi> s;
int main(){
    inputJunk
    cin>>n;
    if(n==1){cout<<0<<ell; return 0;}
    for(int i = 0;i<n;i++){
        cin>>bfs[i];
    }
    for(int i = 0;i<n;i++){
        cin>>dfs[i];
    }

    if(bfs[1]!=dfs[1]){
        cout<<-1<<ell;
        return 0;
    }

    cout<<2*n-3<<ell;
    for(int i = 1;i<n;i++){
        cout<<dfs[i-1]<<" "<<dfs[i]<<ell;
    }
    for(int i = 2;i<n;i++){
        cout<<1<<" "<<bfs[i]<<ell;
    }



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
