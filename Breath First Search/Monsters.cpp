#include <bits/stdc++.h>
using namespace std;
#define inputJunk ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
#define f first
#define s second
#define debug cout<<"HERE"<<endl;
#define ell "\n"
 
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
 
 
const ll INF = 1e15+250;
const int MM = 1e3+5; int mod = 1e9+7;
 
int n, m, step[MM][MM], step2[MM][MM]; char grid[MM][MM], grid2[MM][MM];
pi dir[4] = {{1,0},{-1,0},{0,1},{0,-1}};
char dirc[4] = {'D', 'U', 'R','L'};
int sx, sy;
 
bool valid(int x, int y){
    return (x>=0)&&(y>=0)&&(x<n)&&(y<m)&&grid[x][y]=='.';
}
 
int main(){
    inputJunk
    cin>>n>>m;
    queue<pi> q;
    for(int i = 0;i<n;i++){
        string s;cin>>s;
        for(int j = 0;j<m;j++){
            grid[i][j] = s[j];
            step[i][j] = mod;step2[i][j] = -1;
            if(grid[i][j]=='A'){
                sx=i;sy=j;
            }else if(grid[i][j]=='M'){
                q.push({i,j});
                step[i][j] = 0;
            }
        }
    }
 
    if(sx==0||sx==n-1||sy==0||sy==m-1){
        cout<<"YES"<<ell;
        cout<<0<<ell;
        return 0;
    }
 
    while(!q.empty()){
        auto cur = q.front();q.pop();
        int curx = cur.f, cury = cur.s;
        for(auto x: dir){
            int newx = x.f+curx, newy = x.s+cury;
            if(valid(newx,newy)&&step[newx][newy]==mod){
                q.push({newx,newy});
                step[newx][newy] = step[curx][cury]+1;
            }
        }
    }
    /*
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cout<<step[i][j]<<" ";
        }cout<<ell;
    }*/
 
 
    q.push({sx,sy});
    grid2[sx][sy] = 'A';
    step2[sx][sy] = 0;
    while(!q.empty()){
        auto cur = q.front();q.pop();
        int curx = cur.f, cury = cur.s;
        for(int x = 0;x<4;x++){
            int newx = dir[x].f+curx, newy = dir[x].s+cury;
            if(valid(newx,newy)&&step2[newx][newy]==-1&&step[newx][newy]>(step2[curx][cury]+1)){
                //cout<<step[newx][newy]<<" "<<step2[curx][cury]+1<<ell;
                if(newx==0||newx==n-1||newy==0||newy==m-1){
                    cout<<"YES"<<ell;
                    cout<<step2[curx][cury]+1<<ell;
                    stack<char> ans;
                    ans.push(dirc[x]);
                    newx-=(dir[x].f);
                    newy-=(dir[x].s);
                    while(grid2[newx][newy]!='A'){
                        for(int i = 0;i<4;i++){
                            if(grid2[newx][newy]==dirc[i]){
                                ans.push(dirc[i]);
                                newx-=(dir[i].f);
                                newy-=(dir[i].s);
                            }
                        }
                    }
                    while(!ans.empty()){
                        cout<<ans.top();
                        ans.pop();
                    }
                    return 0;
                }
                step2[newx][newy] = step2[curx][cury]+1;
                grid2[newx][newy] = dirc[x];
                q.push({newx, newy});
            }
        }
    }
    /*for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cout<<grid2[i][j];
        }cout<<ell;
    }*/
 
    cout<<"NO"<<ell;
 
 
}
//freopen("time.in","r", stdin);
//freopen("time.out","w", stdout);
