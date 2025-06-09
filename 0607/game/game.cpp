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
#define sz(x) ((int)(x.size()))
/*

*/

namespace utils{
	inline LL pow2(int h){return 1ull<<h;}
	inline LL nxt_pow2(LL v,int h){
		return (v&(~(pow2(h)-1)))+pow2(h);
	}
	inline LL dis_to_nxt_pow2(LL v,int h){
		return nxt_pow2(v,h)-v;
	}
	// inline LL ceil_to_pow2(LL v,int h){
	// 	return ((v-1)/pow2(h)+1)*pow2(h);
	// }
	inline u64 cross_mask(LL v,LL k){
		int t=63-__builtin_clzll(v^(v+k));
		return pow2(t+1)-1;
	}
	inline u64 lowbit(u64 x){
		return __builtin_ffsll(x)-1;
	}
}

class Monitor;
class Manager;
class SegmentTree;

constexpr int M=30;

class Manager{
	u64 hv;
	vector<Monitor*> ls[M+1];
public:
	static SegmentTree* faT;
	int treeid;
	LL v;

	void increse(LL k);
	void add_buzzer(Monitor* mn,int h);
	LL getlim()const;
};

class Monitor{
public:
	inline static vector<int> dead;
	inline static int mcnt;
	int id;
	LL tar;
	LL r;
	int h;
	vector<Manager*> ls;

	void init(const vector<Manager*>& pos,LL tar,int idx);
	void build();
};

LL Manager::getlim()const{
	if(hv==0)	return 1e18;
	return utils::dis_to_nxt_pow2(v,utils::lowbit(hv))-1;
}

void Manager::increse(LL k){
	if(k==0)	return ;
	
	static queue<Monitor*> q;
	while(!q.empty())	q.pop();

	v+=k;
	u64 mask=utils::cross_mask(v-k,k)&hv;
	while(mask){
		int t=utils::lowbit(mask);
		for(auto mn:ls[t]){
			if(mn->h!=t)	continue;
			q.push(mn);
		}
		mask^=utils::pow2(t);
	}

	while(!q.empty()){
		auto mn=q.front();
		q.pop();

		mn->r-=v-utils::nxt_pow2(v-k,mn->h)+1;
		LL res=utils::dis_to_nxt_pow2(v,mn->h)-1;
		if(mn->r>res){
			mn->r-=res;
			ls[mn->h]+=mn;
		}else{
			mn->build();
		}
	}
	faT->updlim(treeid);
}

void Manager::add_buzzer(Monitor* mn,int h){
	ls[h]+=mn;
	hv|=utils::pow2(h);
	faT->updlim(treeid);
}

void Monitor::build(){
	r=tar;
	for(auto nd:ls)	r-=nd->v;
	if(r<=0){
		Monitor::dead+=id;
		h=-1;
		return ;
	}
	while((utils::pow2(h)-1)*sz(ls)>=r)	h--;
	for(auto nd:ls){
		r-=utils::dis_to_nxt_pow2(nd->v,h)-1;
		nd->add_buzzer(this,h);
	}
}

void Monitor::init(const vector<Manager*>& pos,LL s,int idx){
	this->id=idx;
	this->ls=pos;
	this->tar=s;
	this->h=M;
	this->build();
}

// Monitor


class SegmentTree{
public:
	class Node{
	public:
		int l,r;
		Manager node;
		LL add;
		LL lim;
		inline LL calc_add(int L,int R,LL k)const{
			return (min(R,r)-max(L,l)-1)*k;
		}
	}tr[MAXN<<2];
	inline int lc(int x){return x<<1;}
	inline int rc(int x){return x<<1|1;}
	void push_up(int p){
		tr[p].lim=min({tr[lc(p)].lim,tr[rc(p)].lim,tr[p].node.getlim()});
	}
	void build(int p,int l,int r){
		tr[p].l=l,tr[p].r=r;
		tr[p].node.treeid=p;
		if(l==r){
			tr[p].lim=tr[p].node.getlim();
			return ;
		}
		int mid=(l+r)>>1;
		build(lc(p),l,mid);
		build(rc(p),mid+1,r);
		push_up(p);
	}
	void access(int p,int l,int r,vector<Manager*>& ls){
		if(l<=tr[p].l && tr[p].r<=r){
			ls+=&tr[p].node;
			return ;
		}
		int mid=(tr[p].l+tr[p].r)>>1;
		if(l<=mid)	access(lc(p),l,r,ls);
		if(r>mid)	access(rc(p),l,r,ls);
	}

	void push_down(int p);
	void upd(int p,LL k){
		if(k<=tr[p].lim){
			tr[p].add+=k;
			tr[p].lim-=k;
			tr[p].node.increse(k);
			return ;
		}
		tr[p].node.increse(k);
		if(tr[p].l==tr[p].r){
			tr[p].lim=tr[p].node.getlim();
			return ;
		}
		push_down(p);
		push_up(p);
	}
	void push_down(int p){
		if(tr[p].add==0)	return ;
		LL tg=tr[p].add;
		tr[p].add=0;
		upd(lc(p),tg);
		upd(rc(p),tg);
	}

	void updlim(int t){
		static stack<int> st;
		
		int x=t>>1;
		while(x){
			st.push(x);
			x>>=1;
		}
		while(!st.empty()){
			int p=st.top();
			st.pop();
			push_down(p);
		}
		if(tr[t].l==tr[t].r)	tr[t].lim=tr[t].node.getlim();
		else	push_up(t);
		t>>=1;
		while(t){
			push_up(t);
			t>>=1;
		}
	}
}tr;

Monitor mo[MAXN];

int n,m,q,T,K;
class Task{
public:
	int l,r,c;
}tsk[MAXN];
void solve(bool SPE){ 
	n=RIN,m=RIN,q=RIN,T=RIN,K=RIN;
	
	Manager::faT=&tr;
	tr.build(1,1,n);
	
	foru(i,1,m){
		int l=RIN,r=RIN,c=RIN;
		tsk[i]={l,r,c};
		vector<Manager*> ls;
		tr.access(1,l,r,ls);
		mo[i].init(ls,c,i);
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
	if(freopen("game1.in","r",stdin));
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
