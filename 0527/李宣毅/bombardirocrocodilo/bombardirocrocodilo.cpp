#include <bits/stdc++.h>
#define fi first
#define se second 
#define foru(a,b,c) for(int a=(b);a<=(c);a++)
#define All(x) x.begin(),x.end()
#define LL long long
#define u64 unsigned long long
#define u32 unsigned
#define RIN read()
#define LXF int
#define MAXN 50005
#define mkp(x,y) make_pair(x,y)
using namespace std;
LXF read(){
    LXF ret=0;
    int w=1;
    char c=getchar();
    while(!isdigit(c)){
        if(c=='-')  w=-1;
        c=getchar();
    }
    while(isdigit(c)){
        ret=ret*10+(c^48);
        c=getchar();
    }
    return ret*w;
}
template<typename T>
vector<T>& operator += (vector<T>& ls,const T& x){
    ls.push_back(x);
    return ls;
}
template<typename T1,typename T2>
bool chkmax(T1& x,const T2& y){
    return y>x?x=y,true:false;
}
template<typename T1,typename T2>
bool chkmin(T1& x,const T2& y){
    return y<x?x=y,true:false;
}

int n,m;

class Point{
public:
    int x,y;
};

class VPoint : public Point{
public:
    int c;
}a[MAXN];

namespace SUB1{
    LL cnt[MAXN];
    void work(){
        while(m--){
            LL A=RIN,B=RIN,C=RIN;
            foru(i,1,n){
                cnt[i]=0;
            }
            foru(i,1,n){
                // cout<<A<<" "<<B<<" "<<C<<' '<<a[i].x<<' '<<a[i].y<<' '<<A*a[i].x+B*a[i].y+C<<endl;
                if(A*a[i].x+B*a[i].y+C<0){
                    cnt[a[i].c]++;
                }
            }
            LL ans=0;
            foru(i,1,n){
                LL x=cnt[i];
                ans+=x*x;
            }
            printf("%lld\n",ans);
        }
    }
}

int main(){
    #ifndef ONLINE_JUDGE
    // if(freopen("sample1.in","r",stdin));
    if(freopen("bombardirocrocodilo.in","r",stdin));
    if(freopen("bombardirocrocodilo.out","w",stdout));
    #endif

    n=RIN,m=RIN;
    
    foru(i,1,n){
        a[i].x=RIN;
        a[i].y=RIN;
        a[i].c=RIN;
    }

    if(n<=1000 && m<=1000){
        SUB1::work();
        return 0;
    }
    
    return 0;
}