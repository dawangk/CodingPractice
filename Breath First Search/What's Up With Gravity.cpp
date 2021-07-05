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
const int MM = 5e2+5; int mod = 1e9+7;//998244353

int n, m, step[MM][MM][2]; char grid[MM][MM];
int sx, sy, ex, ey;
int t[2] = {1, -1};
bool programend = false;
bool valid(int x, int y, int grav){
    int gravityindex = (grav==-1)?1:0;
    //cout<<" "<<x<<" "<<y<<" "<<grav<<" "<<grid[x][y]<<" "<<step[x][y][gravityindex]<<ell;
    return x>=0&&x<n&&y>=0&&y<m&&grid[x][y]!='#'&&step[x][y][gravityindex]==INF;
}

bool travel(int &x, int y, int grav, int steps){
    int gravityindex = (grav==-1)?1:0;
    while(true){
        //cout<<" "<<x<<" "<<y<<" "<<grav<<ell;
        if(grid[x+grav][y]=='D'){
            cout<< steps+1<<ell;;
            programend = true;
        }
        if(x+grav==n||x+grav<0)return false;

        if(grid[x+grav][y]=='#'){
            break;
        }
        x+=grav;
    }
    return true;
}

int main(){
    inputJunk
    //freopen("gravity.in","r", stdin);
    //freopen("gravity.out","w", stdout);
    cin>>n>>m;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            step[i][j][0] = INF;
            step[i][j][1] = INF;
            cin>>grid[i][j];
            if(grid[i][j]=='C'){
                sx = i; sy = j;
            }else if(grid[i][j]=='D'){
                ex = i; ey = j;
            }
        }
    }
    deque<trip> q;
    if(!travel(sx, sy, t[0], -1)){
        if(programend)return 0;
        cout<<-1<<ell; return 0;
    }

    step[sx][sy][0] = 0;
    q.pb({{sx, sy}, t[0]});
    while(!q.empty()){
        int curx = q.front().f.f, cury = q.front().f.s, gravity = q.front().s; q.pop_front();
        int gravityindex = (gravity==-1)?1:0;
        //cout<<curx<<" "<<cury<<" "<<gravity<<" "<<step[curx][cury][gravityindex]<<endl;
        //left
        for(int i = 0;i<2;i++){
            int newx = curx, newy = cury+t[i];
            bool f = false;
            if(valid(newx,newy,gravity))f = travel(newx, newy, gravity, step[curx][cury][gravityindex]-1);
            if(programend)return 0;
            //cout<<newx<<" "<<newy<<" "<<gravity<<" "<<boolalpha<<valid(newx,newy,gravity)<<" "<<f<<ell;
            if(valid(newx, newy, gravity)&&f){
                q.push_front({{newx, newy}, gravity});
                step[newx][newy][gravityindex] = step[curx][cury][gravityindex];
            }
        }
        //flip gravity
        int prex = curx, prey = cury;
        bool f = travel(curx, cury, -gravity, step[curx][cury][gravityindex]);
        if(programend)return 0;
        if(valid(curx, cury, -gravity)&&f){
            step[curx][cury][(gravityindex+1)%2] = step[prex][prey][gravityindex]+1;
            q.push_back({{curx, cury},-gravity});
        }

        /*for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                cout<<step[i][j][0]<<" ";
            }cout<<ell;
        }
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                cout<<step[i][j][1]<<" ";
            }cout<<ell;
        }*/

    }
    int ans = min(step[ex][ey][0], step[ex][ey][1]);
    if(ans==INF)cout<<-1<<ell;
    else cout<<ans<<ell;
}
/*CUSTOM TEST CASE 1
10 10
##......D.
C.##......
....##....
......##..
.........#
.......##.
.....##...
...##.....
.##.......
#.........
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
