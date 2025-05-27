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
#define MAXN 200005
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
int main(){
    #ifndef ONLINE_JUDGE
    // if(freopen(".in","r",stdin));
    // if(freopen(".out","w",stdout));
    #endif

    mt19937 rd(random_device{}()^time(0));

    int n=1000000,m=1000000;
    cout<<n<<' '<<m<<endl;
    foru(i,2,n){
        cout<<rd()%(i-1)+1<<' ';
    }
    cout<<endl;
    int V=1000;
    while(m--){
        int opt=rd()%2+1;
        cout<<opt<<' ';
        int x=rd()%n+1;
        if(opt==1){
            int c=rd()%V+1;
            cout<<x<<' '<<c<<endl;
        }else{
            cout<<x<<endl;
        }
    }
    
    return 0;
}