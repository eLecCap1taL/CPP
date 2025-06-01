//%^~
// #pragma GCC optimize(3)
// #pragma GCC optimize("Ofast")
// #include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <array>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
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
#define MAXN 300005
#define eps 1e-10
#define foru(a, b, c) for (int a = (b); (a) <= (c); (a)++)
#define ford(a, b, c) for (int a = (b); (a) >= (c); (a)++)
#define uLL unsigned long long
#define LL long long
#define LXF LL
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
using namespace std;
// const int RANDOM = time(0);
// template<class T1,class T2>
// class tr1::hash<pair<T1,T2>>{
// public:
	// size_t operator () (pair<T1,T2> x)const{
		// tr1::hash<T1> H1;
		// tr1::hash<T2> H2;
		// return H1(x.fi)^H2(x.se)^RANDOM;
	// }
// };
typedef __int128 i128;
typedef unsigned __int128 u128;
typedef long long i64;
typedef unsigned long long u64;
typedef int i32;
typedef unsigned u32;
typedef short i16;
typedef unsigned short u16;
typedef char i8;
int ID;
class Cap1taLDebug{
	#ifdef LXF
	#define READTYPE LXF
	#else
	#define READTYPE int
	#endif
	#define DEBUGING
private:
	ostream& buf;
	#ifndef DEBUGING
	static char fbuf[1<<21],*p1,*p2;
	#define getchar() (Cap1taLDebug::p1==p2&&(p1=(p2=fbuf)+fread(fbuf,1,1<<21,stdin),p1==p2)?EOF:*p2++)
	#endif
public:
	Cap1taLDebug(ostream& out=cout):buf(out){}
	~Cap1taLDebug(){
		#ifdef DEBUGING
		buf.flush();
		#endif
	}
	static READTYPE read(){
		READTYPE x=0,w=1;char ch=0;
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
template<typename T>
class Stack : public stack<T>{
public:
	void clear(){
		while(!this->empty())	this->pop();
	}
	void popuntil(const function<bool(T)>& func){
		while(!this->empty() && !func(this->top()))	this->pop();
	}
};
template<typename T>
vector<T>& operator += (vector<T>& x,const T& y){
	x.push_back(y);
	return x;
}
template<typename T>
set<T>& operator += (set<T>& x,const T& y){
	x.insert(y);
	return x;
}
template<typename T1,typename T2>
inline bool chkmax(T1& x,const T2& y){return (T1)x<y?x=(T1)y,true:false;}
template<typename T1,typename T2>
inline bool chkmin(T1& x,const T2& y){return (T1)y<x?x=(T1)y,true:false;}
class TIMECHKER{
	public:
		~TIMECHKER(){
			cerr<<endl<<clock()*1.0/CLOCKS_PER_SEC<<endl;
		}
	}TIMECHECKER;
/*

*/
int n,q;
vector<int> e[MAXN];

int fa[MAXN],dep[MAXN],son[MAXN],sz[MAXN],top[MAXN],id[MAXN],DFN;
int rid[MAXN];
namespace SLPF{
	void dfs1(int u,int fath){
		// cerr<<u<<' '<<fath<<endl;
		fa[u]=fath;
		dep[u]=dep[fa[u]]+1;
		sz[u]=1;
		for(auto v:e[u]){
			if(v==fa[u])	continue;
			dfs1(v,u);
			sz[u]+=sz[v];
			if(sz[v]>sz[son[u]])	son[u]=v;
		}
	}
	void dfs2(int u,int topf){
		top[u]=topf;
		id[u]=++DFN;
		rid[id[u]]=u;
		if(!son[u])	return ;
		dfs2(son[u],topf);
		for(auto v:e[u]){
			if(v==fa[u] || v==son[u])	continue;
			dfs2(v,v);
		}
	}
	void find(int u,int v,function<void(int,int)> callback){
		while(top[u]!=top[v]){
			if(dep[top[u]]<dep[top[v]])	swap(u,v);
			callback(id[top[u]],id[u]);
			u=fa[top[u]];
		}
		if(dep[u]>dep[v])	swap(u,v);
		callback(id[u],id[v]);
	}
}

class Node{
public:
	LL v;
	LL l,r;
	Node(LL v=0,LL l=0,LL r=0):v(v),l(l),r(r){}
	bool operator < (const Node& x)const{
		return v<x.v;
	}
};
ostream& operator << (ostream& os,const Node& x){
	os<<"{"<<x.v<<' '<<x.l<<' '<<x.r<<"}";
	return os;
}
class Box{
public:
	static const LL V=1e18;
	set<Node> ls;
	LL R;
	void init(){
		ls.clear();
		ls+=Node(0,0,V);
	}
	void add(LL k){
		R=min(R+k,V);

		set<Node> nls;
		for(auto [v,l,r]:ls){
			if(v+k>=r)	continue;
			nls+=Node(v+k,max(l,v+k),r);
		}
		swap(ls,nls);
	}
	pair<LL,LL> qry(LL w){
		if(w>R)	return mkp(-1,-1);
		if(ls.empty())	return mkp(w,w);
		auto it=ls.lower_bound(Node(w+1,0,0));
		if(it==ls.begin())	return mkp(w,w);
		it--;
		if(it->v==w)	return mkp(it->l,it->r);
		return mkp(it->r+w-it->v,it->r+w-it->v);
	}
	void rmv(LL k){

		set<Node> nls;
		LL zr=qry(k).se;
		R=max(R-k,0ll);

		if(zr==-1){
			nls+=Node(0,0,V);
			swap(ls,nls);
			return ;
		}

		if(zr>0)	nls+=Node(0,0,zr);
		auto it=ls.lower_bound(Node(k+1,0,0));
		while(it!=ls.end()){
			nls+=Node(it->v-k,it->l,it->r);
			it++;
		}

		swap(ls,nls);
	}
};

const int mod=998244353;
constexpr int qpow(LL x,int y){
	LL ret=1;
	while(y){
		if(y&1)	ret=ret*x%mod;
		x=x*x%mod,y>>=1;
	}
	return ret;
}

// constexpr int _6=qpow(6,mod-2);
constexpr LL _2=qpow(2,mod-2);

int calc(pair<LL,LL> a){
	if(a.fi==a.se)	return a.fi%mod;
	return (a.fi+a.se)%mod*((a.se-a.fi+1)%mod)%mod*_2%mod;
}

namespace SUB1{
	Box a[MAXN];
	void work(){
		foru(i,1,n){
			a[i].init();
		}
		foru(o,1,q){
			// cerr<<"opt "<<o<<endl;
			int ty=RIN;
			if(ty==1){
				int x=RIN,y=RIN,w=RIN;
				if(w==0)	continue;
				SLPF::find(x,y,[&](int l,int r)->void{
					foru(i,l,r){
						a[i].add(w);
						// cein<<rid[i]<<' '<<a[i].ls<<endl;
					}
				});
			}else if(ty==2){
				int x=RIN,y=RIN,w=RIN;
				if(w==0)	continue;
				SLPF::find(x,y,[&](int l,int r)->void{
					foru(i,l,r){
						a[i].rmv(w);
						// cein<<rid[i]<<' '<<a[i].ls<<endl;
					}
				});
			}else{
				int x=RIN;
				LL w=RIN;
				auto res=a[id[x]].qry(w);
				int ans=-1;
				if(res.fi!=-1)	ans=calc(res);
				printf("%d\n",ans);
			}
		}
	}
}
void solve(bool SPE){ 
	n=RIN,q=RIN;
	foru(i,1,n-1){
		int u=RIN,v=RIN;
		e[u]+=v;
		e[v]+=u;
	}

	SLPF::dfs1(1,0);
	// return ;
	SLPF::dfs2(1,1);

	if(n<=1000 && q<=1000){
		SUB1::work();
		return ;
	}
	SUB1::work();
	return ;


	
	#ifdef DEBUGING
	if(SPE){
		
	}
	#endif
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
	// #define TESTCASEID
	
	#ifndef ONLINE_JUDGE
	#ifndef CPEDITOR
	if(freopen("c1.in","r",stdin));
	// if(freopen("c.in","r",stdin));
	// if(freopen("c.out","w",stdout));
	#endif
	#endif
	
	#ifdef MULTITEST
	int T=RIN;
	#else
	int T=1;
	#endif
	
	#ifdef TESTCASEID
	ID=RIN;
	#endif
	
	for(int i=1;i<=T;i++) solve(i==0);
	return 0;
}