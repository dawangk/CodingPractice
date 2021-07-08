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
const int MM = 3e2+5; int mod = 1e9+7;//998244353

struct state{
    int x1;
    int y1;
    int x2;
    int y2;
    int dir;
    int step;
};

int n; char grid[22][22];
pi dir[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
bool v[22][22][22][22][4];

bool valid2(int x, int y){
    return x>=0&&x<n&&y>=0&&y<n&&grid[x][y]!='H';
}

bool valid(state s){
    return !v[s.x1][s.y1][s.x2][s.y2][s.dir];
}

int main(){
    inputJunk
    freopen("cownav.in","r", stdin);
    freopen("cownav.out","w", stdout);
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>grid[n-i-1];
    }
    queue<state> q;
    q.push({0,0,0,0,0,0});
    while(!q.empty()){
        state cur = q.front(); q.pop();
        //cout<<cur.x1<<" "<<cur.y1<<" "<<cur.x2<<" "<<cur.y2<<" "<<cur.dir<<" "<<cur.step<<endl;
        if(cur.x1==n-1&&cur.x2==n-1&&cur.y1==n-1&&cur.y2==n-1){
            cout<<cur.step<<endl;
            return 0;
        }

        state news = cur;
        news.dir++; news.dir%=4;
        news.step++;
        if(valid(news)){
                //cout<<news.x1<<" "<<news.y1<<" "<<news.x2<<" "<<news.y2<<" "<<news.dir<<endl;
            q.push(news);
            v[news.x1][news.y1][news.x2][news.y2][news.dir] = true;
        }

        news = cur;
        news.dir+=3;news.dir%=4;
        news.step++;
        if(valid(news)){
            //cout<<news.x1<<" "<<news.y1<<" "<<news.x2<<" "<<news.y2<<" "<<news.dir<<endl;
            q.push(news);
            v[news.x1][news.y1][news.x2][news.y2][news.dir] = true;
        }

        news = cur;
        news.step++;
        if(valid2(news.x1+dir[news.dir].f, news.y1+dir[news.dir].s)&&!(news.x1==n-1&&news.y1==n-1)){
            news.x1+=dir[news.dir].f;
            news.y1+=dir[news.dir].s;
        }

        if(valid2(news.x2+dir[(news.dir+1)%4].f, news.y2+dir[(news.dir+1)%4].s)&&!(news.x2==n-1&&news.y2==n-1)){
            news.x2+=dir[(news.dir+1)%4].f;
            news.y2+=dir[(news.dir+1)%4].s;
        }

        if(valid(news)){

            q.push(news);
            v[news.x1][news.y1][news.x2][news.y2][news.dir] = true;
        }

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
