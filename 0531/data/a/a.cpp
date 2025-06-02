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
#define MAXN 200005
#define eps 1e-10
#define foru(a, b, c) for (int a = (b); (a) <= (c); (a)++)
#define ford(a, b, c) for (int a = (b); (a) >= (c); (a)++)
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
// #define int LL
const int mod=1e9+7;
int n,k;
LL c;
LL qpow(LL x,LL y){
	x%=mod;
	LL ret=1;
	while(y){
		if(y&1)	ret=ret*x%mod;
		x=x*x%mod,y>>=1;
	}
	return ret;
}
namespace SUBK2{
	void work(){
		// cerr<<'?';
		cout<<c*qpow(c-1,n-1)%mod;
	}
}

class DSU{
public:
	int fa[26];
	DSU(){
		memset(fa,0,sizeof fa);
	}
	void init(){
		foru(i,1,k-1){
			fa[i]=i;
		}
	}
	int find(int x){
		return fa[x]==x?x:fa[x]=find(fa[x]);
	}
	void Union(int x,int y){
		x=find(x),y=find(y);
		if(x==y)	return ;
		fa[x]=y;
	}
	void shift(){
		for(int i=k-1;i>=1;i--){
			int f=find(i);
			if(f<i)	fa[f]=i,fa[i]=i;
			assert(find(i)>=i);
		}
	}
	vector<int> hs(){
		shift();
		// static set<vector<int>> ct;
		vector<int> ls;
		// u64 ret=0;
		foru(i,1,k-1){
			// ret=ret*10+417*fa[i];
			ls+=fa[i];
		}
		// if(!ct.count(ls))cerr<<ct.size()<<endl;
		// ct.insert(ls);
		// return ret;
		return ls;
	}
	pair<DSU,int> append(bool hw=0){
		shift();
		int val=fa[1]==1&&hw==0?c:1;
		DSU ret;
		foru(i,1,k-2){
			ret.fa[i]=fa[i+1]-1;
		}
		ret.fa[k-1]=k-1;
		if(hw){
			foru(i,2,k/2){
				ret.Union(i-1,k-i);
			}
			if(fa[1]>1){
				ret.Union(k-1,fa[1]-1);
			}
		}
		return mkp(ret,val);
	}
	void err(){
		cerr<<"{";
		foru(i,1,k-1){
			cerr<<fa[i];
			if(i!=k-1)	cerr<<",";
		}
		cerr<<"}\n";
	}
	int num(){
		int ret=1;
		foru(i,1,k-1){
			if(find(i)!=i)	continue;
			ret=(LL)ret*c%mod;
		}
		return ret;
	}
};

DSU st[100005];
int N;
map<vector<int>,int> id;
void gen(){
	static queue<DSU> q;
	st[1].init();
	id[st[1].hs()]=1;
	q.push(st[1]);
	N=1;
	while(!q.empty()){
		auto tryq=[&](DSU& x)->void{
			// cerr<<"try ";
			// x.err();
			auto h=x.hs();
			// cerr<<h<<endl;
			if(id.find(h)==id.end()){
				N++;
				// cerr<<' '<<N<<endl;
				id[h]=N;
				st[N]=x;
				q.push(x);
			}else{
				// cerr<<id[h]<<"?"<<endl;
			}
		};
		auto u=q.front();
		// u.err();
		q.pop();

		DSU nxt=u.append(false).fi;
		tryq(nxt);

		nxt=u.append(true).fi;
		tryq(nxt);
	}
	cerr<<N<<endl;
}

int f[1024][100000];
void add(int &x,int y){
	x+=y;
	if(x>=mod)	x-=mod;
}
void rmv(int &x,int y){
	x-=y;
	if(x<0)	x+=mod;
}
int mul(int x,int y){
	return (LL)x*y%mod;
}

pair<int,int> to[100000][2];

void solve(bool SPE){ 
	c=RIN,n=RIN,k=RIN;

	if(k>n){
		cout<<qpow(c,n);
		return ;
	}
	if(k<=2){
		SUBK2::work();
		return ;
	}
	
	// k=25;
	gen();
	// exit(0);

	foru(i,1,N){
		auto res=st[i].append(false);
		to[i][0]=mkp(id[res.fi.hs()],res.se);
		res=st[i].append(true);
		to[i][1]=mkp(id[res.fi.hs()],res.se);
	}
	f[k-1][id[st[1].hs()]]=1;
	foru(i,k-1,n-1){
		foru(j,1,N){
			if(f[i][j]==0)	continue;
			add(f[i+1][to[j][0].fi],mul(f[i][j],to[j][0].se));
			rmv(f[i+1][to[j][1].fi],mul(f[i][j],to[j][1].se));
		}
	}
	int ans=0;
	foru(i,1,N){
		// cerr<<f[n][i]<<endl;
		add(ans,mul(f[n][i],st[i].num()));
	}
	cout<<ans;


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
	if(freopen("a0.in","r",stdin));
	// if(freopen("a.in","r",stdin));
	// if(freopen("a.out","w",stdout));
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