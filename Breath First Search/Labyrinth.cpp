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
 
const ll INF = 1e15+1;
const int MM = 1e3+5, mod = 1e9+7;
 
int n, m, step[MM][MM]; char grid[MM][MM], pre[MM][MM]; pi from, to; char dir[] = {'U', 'D', 'L', 'R'}; pi direction[] = {{-1, 0}, {1,0}, {0, -1}, {0, 1}};
bool v[MM][MM];
 
bool valid(int x, int y){
    return x>=0&&x<n&&y>=0&&y<m;
}
 
int main(){
    inputJunk
    //freopen("closing.in","r", stdin);
    //freopen("closing.out","w", stdout);
    cin>>n>>m;
    for(int i = 0;i<n;i++){
        memset(pre[i], '!', sizeof(pre[i]));
        cin>>grid[i];
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(grid[i][j] == 'A'){
                from = {i,j};
            }else if(grid[i][j]=='B'){
                to = {i,j};
            }
        }
    }
 
    queue<pi> q;
    q.push(from); step[from.f][from.s] = 0; v[from.f][from.s] = true; pre [from.f][from.s] = '!';
    while(!q.empty()){
        int curx = q.front().f, cury = q.front().s; q.pop();
        for(int i = 0;i<4;i++){
            int newx = curx+direction[i].f, newy = cury+direction[i].s;
 
            if(valid(newx, newy)){
                if(!v[newx][newy]&&grid[newx][newy]!='#'){
                    step[newx][newy] = step[curx][cury]+1;
                    pre[newx][newy] = dir[i];
                    v[newx][newy] = true;
                    q.push({newx, newy});
                }
            }
        }
    }
    int ex = to.f, ey = to.s;
    //cout<<ex<<" "<<ey<<ell;
    //for(int i = 0;i<n;i++){
    //    for(int j = 0;j<m;j++){
    //        cout<<pre[i][j];
    //    }cout<<ell;
    //}
 
    if(pre[ex][ey]=='!')cout<<"NO"<<ell;
    else{
        cout<<"YES"<<ell;
        cout<<step[ex][ey]<<ell;
        vector<char> ans;
        int i = ex, j = ey;
        while(pre[i][j]!='!'){
            ans.pb(pre[i][j]);
            for(int k = 0;k<4;k++){
                if(pre[i][j]==dir[k]){
                    i+=-(direction[k].f);
                    j+=-(direction[k].s);
                    break;
                }
            }
        }
        reverse(ans.begin(), ans.end());
        for(auto x: ans){
            cout<<x;
        }cout<<ell;
    }
 
 
 
}
 
