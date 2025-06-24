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
OPERATOR_FOR_PUSHBACK(deque)
OPERATOR_FOR_PUSH(stack)
OPERATOR_FOR_PUSH(queue)
OPERATOR_FOR_PUSH(priority_queue)
OPERATOR_FOR_INSERT(set)
OPERATOR_FOR_INSERT(unordered_set)
OPERATOR_FOR_INSERT(multiset)
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

// constexpr int mod=998244353;
constexpr int mod=1e9+7;

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
int n;
int lc[MAXN],rc[MAXN];



int sz[MAXN];

int pre[MAXN];

void dfs(int u){
	if(!u)	return ;
	sz[u]=1;
	dfs(lc[u]);
	dfs(rc[u]);
	sz[u]+=sz[lc[u]];
	sz[u]+=sz[rc[u]];
}

int fac[MAXN<<2];
int ifac[MAXN<<2];
int C(int n,int m){
	if(m<0)	return 0;
	if(n<m)	return 0;
	return mul(fac[n],ifac[m],ifac[n-m]);
}

namespace SUBRC10{
	void work(){
		int lm=1;
		foru(u,2,n){
			int lf=sz[lc[u]];
			int rf=sz[rc[u]];
			// cerr<<lf<<' '<<rf<<" "<<C(lf+rf,lf)<<endl;
			mll(lm,C(lf+rf,lf));
		}
		// cout<<lm<<' '<<mul(lm,n-2)<<endl;
		cout<<add(mul(n-2,lm),mul(n-3,lm,n-2));
	}
}

// int f[505][505];

// int pathto(int x,int y){
// 	assert((x+y)%2==0);
// 	int up=(x+y)/2;
// 	int dn=x-up;
// 	return C(up,dn);
// }

int pathto_in(int up,int dn,int s){
	if(abs(up-dn)>=s)	return 0;
	// y=x+s
	// y=x-s
	
	int ret=0;
	for(int i=-(dn/(2*s));i<=up/(2*s);i++){
		mdd(ret,C(up+dn,up-2*i*s));
	}
	for(int i=-((dn+s)/(2*s));i<=(up+s)/(2*s);i++){
		mmv(ret,C(up+dn,up-(2*i-1)*s));
	}
	// cout<<up<<' '<<dn<<' '<<s<<' '<<ret<<endl;
	return ret;
}
int pathto_in_spe(int up,int dn,int s){
	if(abs(up-dn)>=s)	return 0;
	return rmv(C(up+dn,up),C(up+dn,dn-s));
}

int md[MAXN];

void solve(bool SPE){ 
	n=RIN;
	foru(i,1,n){
		lc[i]=RIN,rc[i]=RIN;
	}

	fac[0]=1;
	foru(i,1,n*2){
		fac[i]=mul(fac[i-1],i);
	}
	ifac[n*2]=qpow(fac[2*n],mod-2);
	ford(i,n*2-1,0){
		ifac[i]=mul(ifac[i+1],i+1);
	}

	// cout<<C(2,1)<<endl

	dfs(1);

	if(rc[1]!=0 && lc[rc[1]]==0 && rc[rc[1]]==0){
		SUBRC10::work();
		return ;
	}

	foru(s,1,n){
		pre[s]=1;
		md[s]=1;
	}
	foru(u,1,n){
		int lf=sz[lc[u]];
		int rf=sz[rc[u]];

		if(lf>rf)	swap(lf,rf);
		
		int x=pathto_in(lf,rf,rf+1);

		mll(md[rf],x);
	}

	int sum=0;
	int zr=0;
	foru(u,1,n){
		int lf=sz[lc[u]];
		int rf=sz[rc[u]];

		if(lf>rf)	swap(lf,rf);
		chkmax(zr,rf-lf-1);

		sum+=lf;

		foru(s,1,lf-1){
			mll(pre[s],pathto_in(lf,rf,s+1));
		}
	}


	foru(u,1,n){
		int lf=sz[lc[u]];
		int rf=sz[rc[u]];

		if(lf>rf)	swap(lf,rf);

		int l=max(lf,rf-lf);

		foru(s,l,rf-1){
			mll(pre[s],pathto_in_spe(lf,rf,s+1));
			// mll(pre[s],rmv(C(lf+rf,lf),C(lf+rf,rf-s-1)));
		}
	}

	cerr<<sum<<endl;
	// exit(0);

	int mdl=1;
	foru(i,1,n){
		mll(mdl,md[i]);
		mll(pre[i],mdl);
		if(i<=zr)	pre[i]=0;
	}

	int ans=0;
	foru(i,1,n){
		// cout<<i<<' '<<rmv(pre[i],pre[i-1])<<endl;
		mdd(ans,mul(i,rmv(pre[i],pre[i-1])));
		// cout<<pre[i]<<' ';
	}
	cout<<ans;

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
	#ifndef ONLINE_JUDGE
	// if(freopen("rainbow3.in","r",stdin));
	if(freopen("rainbow.in","r",stdin));
	if(freopen("rainbow.out","w",stdout));
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