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
const int MM = 1e5+5; int mod = 1e9+7;//998244353

int n, dist[MM];
unordered_map<int, vi> lines[2];//0 = vertical, 1 = horizontal
pi points[MM];

int main(){
    inputJunk
    freopen("lasers.in","r", stdin);
    freopen("lasers.out","w", stdout);
    cin>>n;
    for(int i = 0;i<n+2;i++){
        int a, b; cin>>a>>b;
        points[i] = {a,b};
        lines[0][a].pb(i); lines[1][b].pb(i);
    }
    queue<pair<int, bool>> q;
    q.push({0, 0});
    q.push({0, 1});
    for(int i = 0;i<=n+2;i++){
        dist[i] = INF;
    }
    dist[0] = 0;
    while(!q.empty()){
        int cur =  q.front().f; bool dir = q.front().s;
        q.pop();

        int direct = (dir?1:0);
        int p = (dir?points[cur].s:points[cur].f);
        for(int x: lines[direct][p]){
            if(dist[x]==INF){
                dist[x] = dist[cur]+1;
                q.push({x, !direct});
            }
        }
    }
    cout<<((dist[1]==INF)?-1:dist[1]-1)<<ell;

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
