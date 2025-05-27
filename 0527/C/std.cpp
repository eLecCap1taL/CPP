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
int main(){
    ifstream fin("prog");
    char c;
    while((c=fin.get())!=EOF){
        cout<<c;
    }
    return 0;
}