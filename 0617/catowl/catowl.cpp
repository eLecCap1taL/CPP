//%^~
// #pragma GCC optimize(3)
// #pragma GCC optimize("Ofast")
// #include <bits/stdc++.h>

#pragma GCC optimize("unroll-loops","Ofast")

#include <cstdio>
#include <cstring>
#include <array>
#include <string>
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma GCC target("avx512f")
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <functional>
#include <limits>
#include <climits>
#include <bitset>
#include <cassert>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <random>
#include <chrono>
// #include "ext/pb_ds/assoc_container.hpp"
// #include "ext/pb_ds/tree_policy.hpp"
// #include "ext/pb_ds/priority_queue.hpp"
// #include <ext/rope>
// #define PBDS __gnu_pbds
// #include <bits/extc++.h>
#define MAXN 200005
#define eps 1e-10
#define foru(a, b, c) for (int a = (b); (a) <= (c); (a)++)
#define ford(a, b, c) for (int a = (b); (a) >= (c); (a)--)
#define uLL unsigned long long
#define LL long long
#define LXF int
#define RIN Cap1taLDebug::read()
#define RSIN Cap1taLDebug::rdstr()
#define RCIN Cap1taLDebug::rdchar()
#define HH printf("\n")
#define All(x) (x).begin(), (x).end()
#define fi first
#define se second
#define CA const auto&
#if defined(__clang__)
#define assume(expr) __builtin_assume(expr)
#elif defined(__GNUC__)
#define assume(expr) if (expr) {} else { __builtin_unreachable(); }
#elif defined(_MSC_VER)
#define assume(expr) __assume(expr)
#endif
#define likely(x) __builtin_expect(!!(x), 1) 
#define unlikely(x) __builtin_expect(!!(x), 0)
#define mkp(x,y) make_pair(x,y)
#define ast(x) if(!(x))	{cerr<<endl<<"err at"<<__LINE__<<endl;exit(1);}
#define sz(x) ((int)(x.size()))
using namespace std;

typedef __int128 i128;
typedef unsigned __int128 u128;
typedef long long i64;
typedef unsigned long long u64;
typedef int i32;
typedef unsigned u32;
typedef short i16;
typedef unsigned short u16;

class Cap1taLDebug{
public:
	#define DEBUGING

	ostream& buf;
	#ifndef DEBUGING
	static char fbuf[1<<21],*p1,*p2;
	#define getchar() (Cap1taLDebug::p1==p2&&(p1=(p2=fbuf)+fread(fbuf,1,1<<21,stdin),p1==p2)?EOF:*p2++)
	#endif
	Cap1taLDebug(ostream& out=cout):buf(out){}
	~Cap1taLDebug(){
		#ifdef DEBUGING
		buf.flush();
		#endif
	}
	static LXF read(){
		LXF x=0,w=1;char ch=0;
		while(!isdigit(ch)){
		if(ch=='-')	w=-1;
		ch=getchar();
		}
		while(isdigit(ch))	x=x*10+(ch^48),ch=getchar();
		return x*w;
	}
	static string rdstr(){
		string s;char c=getchar();
		while(c==' ' || c=='\r' || c=='\n')	c=getchar();	
		while(c!=' ' && c!='\r' && c!='\n' && c!=EOF)	s+=c,c=getchar();
		return s;
	}
	static char rdchar(){
		char c=getchar();
		while(c==' ' || c=='\r' || c=='\n')	c=getchar();
		return c;
	}
	static string i128ToString(i128 x){
		if(x==0)	return "0";
		string s="",w="";
		if(x<0)	w="-",x*=-1;
		while(x) s+=(char)('0'+(int)(x%10)),x/=10;
		reverse(All(s));
		return w+s;
	}
	static string u128ToString(u128 x){
		if(x==0)	return "0";
		string s="",w="";
		while(x) s+=(char)('0'+(int)(x%10)),x/=10;
		reverse(All(s));
		return w+s;
	}
	Cap1taLDebug& operator<<(const string val){
		#ifdef DEBUGING
		buf<<val;
		#endif
		return *this;
	}
	template<typename T1,typename T2>
	Cap1taLDebug& operator<<(const pair<T1,T2>& val){
		#ifdef DEBUGING
		(*this)<<"("<<val.first<<","<<val.second<<")";
		#endif
		return *this;
	}
	template<typename T,template<typename,typename...>class Container,typename...Args>
	Cap1taLDebug& operator<<(const Container<T, Args...>& container){
		#ifdef DEBUGING
		buf<<"{";
		bool fst=0;
		for(const auto& val:container){
			if(!fst)	fst=true;
			else	buf<<",";
			(*this)<<val;	
		}
		buf<<"}";
		#endif
		return *this;
	}
	Cap1taLDebug& operator<<(const i128& val){
		#ifdef DEBUGING
		buf<<i128ToString(val);
		#endif
		return *this;
	}
	Cap1taLDebug& operator<<(const u128& val){
		#ifdef DEBUGING
		buf<<u128ToString(val);
		#endif
		return *this;
	}
	template<typename T>
	Cap1taLDebug& operator<<(const T& val){
		#ifdef DEBUGING
		buf<<val;
		#endif
		return *this;
	}
	Cap1taLDebug& operator<<(ostream& (*manip)(ostream&)){
		#ifdef DEBUGING
		buf<<manip;
		#endif
		return *this;
	}
};
#ifndef DEBUGING
char Cap1taLDebug::fbuf[1<<21],*Cap1taLDebug::p1=nullptr,*Cap1taLDebug::p2=nullptr;
#endif
Cap1taLDebug cein(cout);
// Cap1taLDebug cein(cerr);
ostream& operator<<(ostream& os,i128 val){
	os<<Cap1taLDebug::i128ToString(val);
	return os;
}
ostream& operator<<(ostream& os,u128 val){
	os<<Cap1taLDebug::u128ToString(val);
	return os;
}

#define OPERATOR_FOR_PUSHBACK(pb)\
template<typename T1,typename T2>\
pb<T1>& operator += (pb<T1>& x,const T2& y){x.push_back((T1)y);return x;}

#define OPERATOR_FOR_PUSH(p)\
template<typename T1,typename T2>\
p<T1>& operator += (p<T1>& x,const T2& y){x.push((T1)y);return x;}

#define OPERATOR_FOR_INSERT(i)\
template<typename T1,typename T2>\
i<T1>& operator += (i<T1>& x,const T2& y){x.insert((T1)y);return x;}

OPERATOR_FOR_PUSHBACK(vector)
OPERATOR_FOR_INSERT(unordered_set)
OPERATOR_FOR_INSERT(unordered_multiset)

template<typename T1,typename T2>
inline bool chkmax(T1& x,const T2& y){return x<(T1)y?x=(T1)y,true:false;}
template<typename T1,typename T2>
inline bool chkmin(T1& x,const T2& y){return (T1)y<x?x=(T1)y,true:false;}

class TIMECHKER{
public:
	~TIMECHKER(){
		cerr<<endl<<clock()*1.0/CLOCKS_PER_SEC<<endl;
	}
}TIMECHECKER;

constexpr int mod=998244353;
// constexpr int mod=1e9+7;

constexpr int& mdd(int& x){return x;}
template<class T1,class ...T2>
constexpr int& mdd(int& x,const T1& y,const T2& ...xr){
	x+=y;
	if(x>=mod)	x-=mod;
	return mdd(x,xr...);
}
constexpr int& mmv(int& x){return x;}
template<class T1,class ...T2>
constexpr int& mmv(int& x,const T1& y,const T2& ...xr){
	x-=y;
	if(x<0)	x+=mod;
	return mmv(x,xr...);
}
constexpr int& mll(int& x){return x;}
template<class T1,class ...T2>
constexpr int& mll(int& x,const T1& y,const T2& ...xr){
	x=(LL)x*y%mod;
	return mll(x,xr...);
}
constexpr int add(const int& x){return x;}
template<class ...T>
constexpr int add(const int& x,const T& ...xr){
	int ret=x+add(xr...);
	if(ret>=mod)	ret-=mod;
	return ret;
}
constexpr int mul(const int& x){return x;}
template<class ...T>
constexpr int mul(const int& x,const T& ...xr){
	return (LL)x*mul(xr...)%mod;
}
constexpr int rmv(int x,int y){
	x-=y;
	if(x<0)	x+=mod;
	return x;
}
constexpr int mev(const int& x){return mod-x;}

constexpr int qpow(int x,int y){
	int ret=1;
	while(y){
		if(y&1)	mll(ret,x);
		mll(x,x),y>>=1;
	}
	return ret;
}

/*

*/
int n,m,k;

vector<int> e[MAXN];

class CatGirl{
public:	
	int r,c;
};

vector<CatGirl> cls[MAXN];

int dep[MAXN];
int st[20][MAXN];
int sfa[MAXN],dfn[MAXN],DFN;
int getd(int x,int y){
	return dfn[x]<dfn[y]?x:y;
}
void pre(int u,int fath){
	sfa[u]=fath;
	dep[u]=dep[fath]+1;
	dfn[u]=++DFN;
	st[0][dfn[u]]=sfa[u];
	for(auto v:e[u]){
		if(v==sfa[u])	continue;
		pre(v,u);
	}
}
int LCA(int u,int v){
	if(u==v)	return u;
	if((u=dfn[u])>(v=dfn[v]))	swap(u,v);
	int k=__lg(v-u++);
	return getd(st[k][u],st[k][v-(1<<k)+1]);
}
int dis(int u,int v){
	return dep[u]+dep[v]-2*dep[LCA(u,v)];
}

bool vis[MAXN];
int sz[MAXN],totsz;
int RT;

void updsz(int u,int fath){
	sz[u]=1;
	for(auto v:e[u]){
		if(v==fath || vis[v])	continue;
		updsz(v,u);
		sz[u]+=sz[v];
	}
}
pair<int,int> findroot(int u,int fath){
	pair<int,int> ret(INT_MAX,0);
	int mxsz=INT_MIN;

	for(auto v:e[u]){
		if(v==fath || vis[v])	continue;
		chkmin(ret,findroot(v,u));
		chkmax(mxsz,sz[v]);
	}
	chkmax(mxsz,totsz-sz[u]);
	chkmin(ret,mkp(mxsz,u));

	return ret;
}

vector<int> g[MAXN];
int fa[MAXN];
int bl[MAXN];
int chid_cnt=0;
int chid[MAXN];
void build_dfz(int u){
	// cerr<<"dfz "<<u<<endl;
	vis[u]=1;
	for(auto v:e[u]){
		if(vis[v])	continue;
		updsz(v,u);
		totsz=sz[v];
		int rt=findroot(v,u).se;
		g[u]+=rt;
		fa[rt]=u;

		bl[rt]=v;
		chid[rt]=++chid_cnt;
		build_dfz(rt);		
	}
}

int dceil(int x,int y){
	return (x+y-1)/y;
}

unordered_map<int,LL> mp[MAXN];
LL fix[MAXN];
unordered_map<int,LL> mp_ch[MAXN];
LL fix_ch[MAXN];

LL up[MAXN];

LL d[MAXN];
LL ans;

LL fetch(unordered_map<int,LL>& dat,int key){
	auto it=dat.find(key);
	if(it==dat.end())	return 0;
	return it->se;
}

void push(int u,int fath,int dep,unordered_map<int,LL>& tot,unordered_map<int,LL>& rm){
	LL val=fetch(tot,dep)-fetch(rm,dep);
	d[dep%k]+=val;
	// if(fetch(tot,dep)-fetch(rm,dep)<0){
	// 	cerr<<u<<' '<<dep<<' '<<fetch(tot,dep)<<' '<<fetch(rm,dep)<<endl;
	// }
	// assert(fetch(tot,dep)-fetch(rm,dep)>=0);
	ans+=d[dep%k];

	up[u]+=ans;
	
	for(auto v:e[u]){
		if(v==fath || vis[v])	continue;
		push(v,u,dep+1,tot,rm);
	}

	ans-=d[dep%k];
	d[dep%k]-=val;
}
void push_dfz(int u){
	vis[u]=1;
	for(auto rt:g[u]){
		int v=bl[rt];
		int id=chid[rt];

		LL val=fetch(mp[u],0)-fetch(mp_ch[id],0);
		ans+=fix[u]-fix_ch[id];
		d[0]+=val;
		// assert(mp[u][0]-mp_ch[id][0]>=0);
		ans+=d[0];
		// cerr<<"Push "<<u<<"->"<<v<<' '<<id<<endl;
		push(v,0,1,mp[u],mp_ch[id]);
		ans-=d[0];
		d[0]-=val;
		ans-=fix[u]-fix_ch[id];
	}
	for(auto v:g[u]){
		push_dfz(v);
	}
}

LL minans=LLONG_MAX;

void pull(int u,int fath,int D,LL& val){
	for(auto [r,c]:cls[u]){
		val+=(LL)c*dceil(max(0,D-r),k);
	}
	for(auto v:e[u]){
		if(v==fath || vis[v])	continue;
		pull(v,u,D+1,val);
	}
}

void calc_dfz(int u){
	vis[u]=1;

	LL mn=up[u];
	for(auto v:e[u]){
		if(vis[v])	continue;
		pull(v,u,1,mn);
	}

	// cerr<<"u "<<u<<' '<<up[u]<<endl;
	// cerr<<"d "<<u<<' '<<mn-up[u]<<endl;

	chkmin(minans,mn);

	for(auto v:g[u]){
		calc_dfz(v);
	}
}

void solve(bool SPE){ 
	n=RIN,m=RIN,k=RIN;

	foru(i,1,n-1){
		int u=RIN,v=RIN;
		e[u]+=v;
		e[v]+=u;
	}

	foru(i,1,m){
		int p=RIN,r=RIN,c=RIN;
		cls[p]+=CatGirl{r,c};
	}

	pre(1,0);
	for(int i=1;(1<<i)<=n;i++){
		for(int j=1;j+(1<<i)-1<=n;j++){
			st[i][j]=getd(st[i-1][j],st[i-1][j+(1<<(i-1))]);
		}
	}

	totsz=n;
	updsz(1,0);
	RT=findroot(1,0).se;

	build_dfz(RT);

	foru(x,1,n){
		for(auto [r,c]:cls[x]){
			mp[x][r+1]+=c;
			fix[x]+=0;

			int lst=chid[x];
			int u=fa[x];
			while(u!=0){
				int D=dis(x,u);

				int fst=0,add=0;
				if(r>=D){
					fst=r-D+1;
					add=0;
				}else{
					int t=dceil(D-r-1,k);
					fst=r+t*k+1-D;
					add=t;
				}

				if(fst<n){
					mp[u][fst]+=c;
					fix[u]+=(LL)add*c;
					mp_ch[lst][fst]+=c;
					fix_ch[lst]+=(LL)add*c;
				}

				// if(u==10){
				// cerr<<"RES "<<u<<' '<<lst<<" do "<<"("<<fst<<','<<add<<") from "<<x<<' '<<r<<' '<<c<<endl;
				// }
				// if(lst==7){
				// cerr<<"RES "<<u<<' '<<lst<<" do "<<"("<<fst<<','<<add<<") from "<<x<<' '<<r<<' '<<c<<endl;
				// }

				lst=chid[u];
				u=fa[u];
			}
		}
	}

	foru(i,1,n)	vis[i]=0;
	push_dfz(RT);
	
	foru(i,1,n)	vis[i]=0;
	calc_dfz(RT);

	cout<<minans;
	
	return ;
}
/*
检查文件读写
检查多测清空
检查数组大小
*/
signed main()
{
	// #define MULTITEST
	
	#ifndef CPEDITOR
	if(freopen("catowl2.in","r",stdin));
	// if(freopen("catowl.out","w",stdout));
	#ifdef ONLINE_JUDGE
	if(freopen("catowl.in","r",stdin));
	if(freopen("catowl.out","w",stdout));
	#endif
	#endif
	
	#ifdef MULTITEST
	int T=RIN;
	#else
	int T=1;
	#endif
	
	for(int i=1;i<=T;i++){
		solve(i==0);
	}
	return 0;
}