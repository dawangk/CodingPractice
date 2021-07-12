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
const int MM = 101; int mod = 1e9+7;//998244353

int n, t;
int dx[] = {0, 1, 2, 3, 2, 1, 0, -1, -2, -3, -2, -1, -1, 1, 0, 0};
int dy[] = {3, 2, 1, 0, -1, -2, -3, -2, -1, 0, 1, 2, 0, 0, -1, 1};



int main(){
    inputJunk
    freopen("visitfj.in","r", stdin);
    freopen("visitfj.out","w", stdout);
    cin>>n>>t;
    vector<vector<int>> grid(n, vector<int>(n));
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    vector<vector<int>> dist(n, vector<int>(n, INF));
    int ans = INF;
    priority_queue<pair<int, pair<int , int>>> q;
    q.push({0, {0,0}});
    dist[0][0] = 0;
    while(!q.empty()){
        int d = -q.top().f;
        int curx = q.top().s.f, cury = q.top().s.s;q.pop();

        if(d!=dist[curx][cury])continue;

        int distdest = abs(n-1-curx)+abs(n-1-cury);
        if(distdest<=2){
            ans = min(ans, d+t*distdest);
        }

        for(int i = 0;i<16;i++){
            int newx = curx+dx[i];
            int newy = cury+dy[i];
            int cost = 3*t+grid[newx][newy];
            if (newx < 0 || newy >= n || newy < 0 || newx >= n) {
                continue;}
            if(dist[curx][cury]+cost<dist[newx][newy]){
                dist[newx][newy] = dist[curx][cury]+cost;
                q.push({-(dist[curx][cury]+cost), {newx, newy}});
            }
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
- upperbound and lowerbound returns iteratorsf
- use long long when number is big enough
- for dp invalid cases needs to be skipped
- some base cases won't work (review cow poetry)
- always check bounds, some TLE are due to incorrect bounds!
- dont mess up return types
= RESET ARRAYS!!!!!!!!!!
- USE UR BRAIN
- INF setting problems
- push vs pb
*/
/*
    freopen("time.in","r", stdin);
    freopen("time.out","w", stdout);
*/
