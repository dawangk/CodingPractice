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
const int MM = 4e3+5; int mod = 1e9+7;//998244353

int w, h; char grid [MM][MM];
int ans = 0;
pi dir[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int dist[MM][MM];

bool valid(int x, int y){
    return x>=0&&x<w&&y>=0&&y<h&&grid[x][y]!='.'&&dist[x][y]==0;
}


int main(){
    inputJunk
    cin>>w>>h;
    for(int i= 0;i<w;i++){
        cin>>grid[i];
    }

    deque<pi> q;
    q.push_front({0, 0});
    dist[0][0] = 1;
    while(!q.empty()){
        int curx = q.front().f, cury = q.front().s;
        q.pop_front();

        for(int i = 0;i<4;i++){
            int newx = curx+dir[i].f, newy = cury+dir[i].s;

            if(valid(newx, newy)){
                if(grid[newx][newy]==grid[curx][cury]){
                    dist[newx][newy] = dist[curx][cury];
                    ans = max(ans, dist[newx][newy]);
                    q.push_front({newx, newy});
                }else{
                    dist[newx][newy] = dist[curx][cury]+1;
                    ans = max(ans, dist[newx][newy]);
                    q.push_back({newx, newy});
                }
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
