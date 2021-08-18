#include <bits/stdc++.h>
using namespace std;
//#include <ext/rope>
//using namespace __gnu_cxx;
#include <ext/pb_ds/assoc_container.hpp>
#include <stdlib.h>
using namespace __gnu_pbds;

//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")
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
typedef pair<int, pi> trip;
typedef pair<pll, ll> tripll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
typedef vector<trip> vtrip;
typedef vector<tripll> vtripll;

const int INF = 1e9+1212;
const ll P = 9973, M = 1e9+9;
const int MM = 1e3+5; int mod = 1e9+7;//99824435

int n, m, grid[MM][MM];
int step[MM][MM][2], dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, -1, 1};

bool inbound(int x, int y){
    return x>=0&&x<n&&y>=0&&y<m;
}

int calc(int a, int  b){
    if(a==-1){
        return b;
    }
    if(b==-1){
        return a;
    }
    return min(a, b);
}

int main(){
    freopen("dream.in","r", stdin);
    freopen("dream.out","w", stdout);
    inputJunk

    cin>>n>>m;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            step[i][j][0] = -1;step[i][j][1] = -1;
            cin>>grid[i][j];
        }
    }
    queue<pair<pair<pi, int>, bool>> q;
    q.push({{{0, 0}, -1}, 0});
    step[0][0][0] = 0;
    while(!q.empty()){
        int curx = q.front().f.f.f, cury = q.front().f.f.s; bool isorange = q.front().s;
        int dir = q.front().f.s;
        //cout<<curx<<" "<<cury<<" "<<boolalpha<<" "<<isorange<<ell;
        q.pop();
        for(int i = 0;i<4;i++){
            if(dir!=-1&&i!=dir)continue;
            int newx = curx+dx[i], newy = cury+dy[i];
            if(inbound(newx, newy)&&step[newx][newy][isorange]==-1){
                bool neworange = isorange;
                if(grid[newx][newy]==0)continue;
                if(grid[newx][newy]==3&&!isorange)continue;
                if(grid[newx][newy]==2)neworange = true;
                if(grid[newx][newy]==4){
                    neworange = false;
                    step[newx][newy][neworange] = step[curx][cury][isorange]+1;
                    q.push({{{newx, newy}, i}, neworange});
                    continue;
                }
                step[newx][newy][neworange] = step[curx][cury][isorange]+1;
                q.push({{{newx, newy}, -1}, neworange});
            }
        }
    }
    cout<<calc(step[n-1][m-1][false], step[n-1][m-1][true])<<ell;
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
- check if things are used properly
- read the PROBLEM (directed vs undirected graph)
*/
/*
    freopen("time.in","r", stdin);
    freopen("time.out","w", stdout);
*/
