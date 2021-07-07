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
const int MM = 8e2+5; int mod = 1e9+7;//998244353

int n, k, sx, sy, ex, ey, dist[MM][MM]; char grid[MM][MM];
queue<pi> q; pi dir[4] {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
pi step[MM][MM];

bool vv(int a){
    return a>=0&&a<n;
}

bool valid(int x, int y){
    return vv(x)&&vv(y)&&(grid[x][y]=='G'||grid[x][y]=='M')&dist[x][y]==INF;
}

bool dfs(int t){
    queue<pi> q;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            step[i][j] = {-1, 0};
        }
    }
    step[sx][sy] = {t, 0};
    q.push({sx, sy});
    while(!q.empty()){
        int x = q.front().f, y = q.front().s; q.pop();
        for(int i = 0;i<4;i++){
            int newx = x+dir[i].f, newy = y+dir[i].s;
            int newt = (step[x][y].s+1==k)?step[x][y].f+1:step[x][y].f;
            int newused = (step[x][y].s+1)%k;
            //cout<<newx<<" "<<newy<<endl;
            if(vv(newx)&&vv(newy)&&(grid[newx][newy]=='G'||grid[newx][newy]=='D')&&newt<dist[newx][newy]&&step[newx][newy].f==-1){

                step[newx][newy] = {newt, newused};
                q.push({newx, newy});
            }
        }
    }
    //cout<<t<<ell;
    /*
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cout<<"("<<step[i][j].f<<" "<<step[i][j].s<<")"<<" ";
        }cout<<ell;
    }*/
    return step[ex][ey].f!=-1;
}

int main(){
    inputJunk
    cin>>n>>k;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin>>grid[i][j];
            dist[i][j] = INF;
            if(grid[i][j]=='M'){sx = i; sy = j;}
            else if(grid[i][j]=='D'){ex = i;ey = j;}
            else if(grid[i][j]=='H'){q.push({i, j}); dist[i][j] = 0;}
        }
    }

    while(!q.empty()){
        int curx = q.front().f, cury = q.front().s;q.pop();
        //cout<<curx<<" "<<cury<<" "<<endl;
        for(int i = 0;i<4;i++){
            int newx = curx+dir[i].f, newy = cury+dir[i].s;
            if(valid(newx, newy)){
                dist[newx][newy] = dist[curx][cury]+1;
                q.push({newx, newy});
            }
        }
    }
/*
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cout<<dist[i][j]<<" ";
        }cout<<ell;
    }*/
    dist[ex][ey] = INF;
    int lo = 0, hi = 10000000;
    if(!dfs(0)){
        cout<<-1<<endl;
        return 0;
    }
    //cout<<"BOB"<<dfss(2)<<ell;

    while(lo<hi){
        //cout<<lo<<" "<<hi<<endl;
        int mid = (lo+hi+1)/2;
        if(mid<dist[sx][sy]&&dfs(mid)){
            lo = mid;
        }else{
            hi = mid-1;
        }
    }
    cout<<lo<<endl;

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
*/
/*
    freopen("time.in","r", stdin);
    freopen("time.out","w", stdout);
*/
