struct point{
    ll x, y;
    void read(){
        cin>>x>>y;
    }
    point operator - (const point& b)const{
        return point{x-b.x, y-b.y};
    }
    void operator -= (const point& b){
        x-= b.x;
        y-= b.y;
    }
    ll operator *(const point& b) const{
        return (ll) x*b.y-(ll)y*b.x;
    }
    ll cross(const point& b, const point& c) const{
        return (b -*this)*(c-*this);
    }
    bool operator <(const point& b) const{
        return make_pair(x,y)<make_pair(b.x, b.y);
    }
    bool operator ==(const point& b)const{
        return make_pair(x,y)==make_pair(b.x, b.y);
    }
};
