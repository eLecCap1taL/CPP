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
#define MAXN 10005
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
inline bool chkmax(T1& x,const T2& y){return (T1)x<y?x=(T1)y,true:false;}
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
int n,m,q,T,K;
class Task{
public:
	int l,r,c;
}b[10005];
int a[MAXN];

class OPT{
public:
	int l,r,v;
}op[200005];

namespace SUBM100{
	int f[MAXN];
	int s[MAXN];
	void work(){
		int lst=0;
		foru(o,1,q){
			auto [l,r,v]=op[o];
			if(T){
				l^=lst;
				r^=lst;
				v^=lst;
			}
			foru(i,1,m){
				if(f[i])	continue;
				auto [L,R,c]=b[i];
				s[i]+=max(0,min(R,r)-max(L,l)+1)*v;
				if(s[i]>=c){
					f[i]=o;
					lst^=L^R^c;
				}
			}
		}
		foru(i,1,m){
			if(f[i]==0)	f[i]=-1;
			printf("%d ",f[i]);
		}
	}
}

namespace SUBT0{
	class Node{
	public:
		int lc,rc;
		LL s;
		LL tg;
	}tr[200005*40];
	inline int& lc(int p){return tr[p].lc;}
	inline int& rc(int p){return tr[p].rc;}
	int pcnt;
	void push_up(int p,int l,int r){
		tr[p].s=tr[lc(p)].s+tr[rc(p)].s+tr[p].tg*(r-l+1);
	}
	int rt[200005];
	void build(int& p,int l,int r){
		if(!p)	p=++pcnt;
		if(l==r){
			return ;
		}
		int mid=(l+r)>>1;
		build(lc(p),l,mid);
		build(rc(p),mid+1,r);
	}
	void modify(int& p,int l,int r,int nl,int nr,int k){
		tr[++pcnt]=tr[p];
		// cerr<<"vis "<<pcnt<<"("<<p<<") "<<l<<' '<<r<<' '<<nl<<' '<<nr<<' '<<k<<endl; 
		p=pcnt;
		if(nl<=l && r<=nr){
			tr[p].s+=(LL)(r-l+1)*k;
			tr[p].tg+=k;
			return ;
		}
		int mid=(l+r)>>1;
		if(nl<=mid)	modify(lc(p),l,mid,nl,nr,k);
		if(nr>mid)	modify(rc(p),mid+1,r,nl,nr,k);
		push_up(p,l,r);
	}
	// void Modify(int& p,int l,int r,int nl,int nr,int k){
	// 	// tr[++pcnt]=tr[p];
	// 	// cerr<<"vis "<<pcnt<<"("<<p<<") "<<l<<' '<<r<<' '<<nl<<' '<<nr<<' '<<k<<endl; 
	// 	// p=pcnt;
	// 	if(nl<=l && r<=nr){
	// 		// cerr<<"upd"<<endl;
	// 		// tr[p].s+=(LL)(r-l+1)*k;
	// 		// tr[p].tg+=k;
	// 		return ;
	// 	}
	// 	int mid=(l+r)>>1;
	// 	if(nl<=mid)	Modify(lc(p),l,mid,nl,nr,k);
	// 	if(nr>mid)	Modify(rc(p),mid+1,r,nl,nr,k);
	// 	push_up(p);
	// }
	LL query(int p,int l,int r,int nl,int nr,LL tg){
		if(nl<=l && r<=nr){
			return tr[p].s+tg*(r-l+1);
		}
		tg+=tr[p].tg;
		int mid=(l+r)>>1;
		LL ret=0;
		if(nl<=mid)	ret+=query(lc(p),l,mid,nl,nr,tg);
		if(nr>mid)	ret+=query(rc(p),mid+1,r,nl,nr,tg);
		return ret;
	}
	void work(){
		build(rt[0],1,n);
		foru(o,1,q){
			auto [l,r,v]=op[o];
			rt[o]=rt[o-1];
			modify(rt[o],1,n,l,r,v);
		}
		// cerr<<pcnt<<' '<<200005*32<<endl;
		foru(i,1,m){
			auto [L,R,c]=b[i];
			// if(query(rt[q],1,n,L,R,0)>=c){
			// 	// t=q;
			// }else{
			// 	LL s=0;
			// 	foru(o,1,q){
			// 		auto [l,r,v]=op[o];
			// 		if(r<L || l>R)	continue;
			// 		cerr<<' '<<l<<' '<<r<<' '<<v<<endl;
			// 		s+=max(0,min(R,r)-max(L,l)+1)*(LL)v;
					
			// 		LL cur=query(rt[o],1,n,L,R,0);
			// 		cerr<<cur<<' '<<s<<endl;
			// 		if(cur!=s){
			// 			cerr<<query(rt[o-1],1,n,L,R,0)<<endl;
			// 			cerr<<L<<' '<<R<<endl;
			// 			int RT=rt[o-1];
			// 			Modify(RT,1,n,1247,1422,2);
			// 			cerr<<query(RT,1,n,L,R,0)<<endl;
			// 			exit(0);
			// 		}
			// 	}

			// 	exit(0);
			// }
			int l=1,r=q,t=-1;
			while(l<=r){
				int mid=(l+r)>>1;
				if(query(rt[mid],1,n,L,R,0)>=c){
					t=mid;
					r=mid-1;
				}else{
					l=mid+1;
				}
			}
			printf("%d ",t);
		}
	}
}

void solve(bool SPE){ 
	n=RIN,m=RIN,q=RIN,T=RIN,K=RIN;
	foru(i,1,m){
		b[i]={RIN,RIN,RIN};
	}
	foru(i,1,q){
		op[i]={RIN,RIN,RIN};
	}
	if(T==0){
		SUBT0::work();
		return ;
	}
	if(m<=100){
		SUBM100::work();
		return ;
	}

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
	if(freopen("game3.in","r",stdin));
	#ifdef ONLINE_JUDGE
	if(freopen("game.in","r",stdin));
	if(freopen("game.out","w",stdout));
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