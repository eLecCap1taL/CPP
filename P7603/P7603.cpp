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
#define MAXN 100005
#define eps 1e-10
#define foru(a, b, c) for (int a = (b); (a) <= (c); (a)++)
#define ford(a, b, c) for (int a = (b); (a) >= (c); (a)--)
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

int n,m;

vector<int> pls[MAXN];
void gen(){
	static bitset<MAXN> vis;
	static vector<int> prim;
	static int lowp[MAXN];
	foru(i,2,n){
		if(!vis[i]){
			lowp[i]=i;
			prim+=i;
		}
		for(int j=0;j<sz(prim) && i*prim[j]<=n;j++){
			vis[i*prim[j]]=1;
			lowp[i*prim[j]]=prim[j];
			if(i%prim[j]==0)	break;
		}
	}
	foru(i,2,n){
		int x=i;
		while(x>1){
			int p=lowp[x];
			pls[i]+=p;
			while(x%p==0)	x/=p;
		}
	}
}

constexpr int M=35;

class Monitor{
public:
	static vector<int> dead;
	static int cnt;
	int h;
	int id;
	LL r;
	LL tar;
	vector<int> ls;
	Monitor(const vector<int>& pos,int idx,LL y);
	void build();
};
vector<int> Monitor::dead;
int Monitor::cnt;

class Node{
public:
	u64 hv;
	LL v;
	vector<Monitor*> ls[M+5];
	void add_buzzer(Monitor* mn,int h);
	void increse(LL k);
}a[MAXN];

namespace utils{
	LL pow2(int h){return 1ull<<h;}
	LL nxt_pow2(LL v,int h){
		return (v&(~(pow2(h)-1)))+pow2(h);
	}
	LL dis_to_nxt_pow2(LL v,int h){
		return nxt_pow2(v,h)-v;
	}
	u64 cross_mask(u64 v,u64 w){
		const int diff=63-__builtin_clzll(v^(v+w));
		return pow2(diff+1)-1;
	}
	u64 lowbit(u64 v){
		return __builtin_ffsll(v)-1;
	}
}

void Node::add_buzzer(Monitor* mn,int h){
	hv|=utils::pow2(h);
	ls[h]+=mn;
}
void Node::increse(LL k){
	if(k==0)	return ;

	static queue<Monitor*> q;
	while(!q.empty())	q.pop();

	v+=k;

	u64 mask=utils::cross_mask(v-k,k)&hv;
	while(mask!=0){
		int t=utils::lowbit(mask);
		for(auto mn:ls[t]){
			if(t!=mn->h)	continue;
			q.push(mn);
		}
		ls[t].clear();
		mask^=utils::pow2(t);
	}

	while(!q.empty()){
		auto mn=q.front();
		q.pop();

		mn->r-=v-utils::nxt_pow2(v-k,mn->h)+1;
		auto res=utils::dis_to_nxt_pow2(v,mn->h)-1;
		if(mn->r>res){
			mn->r-=res;
			ls[mn->h]+=mn;
		}else{
			mn->build();
		}
	}
}
void Monitor::build(){
	r=tar;
	for(auto p:ls)	r-=a[p].v;
	if(r<=0){
		Monitor::dead+=id;
		h=-1;
		delete this;
		return ;
	}
	while(r<=(utils::pow2(h)-1)*sz(ls))	h--;
	//register
	for(auto p:ls){
		a[p].add_buzzer(this,h);
		r-=utils::dis_to_nxt_pow2(a[p].v,h)-1;
	}
}
Monitor::Monitor(const vector<int>& pos,int idx,LL y){
	h=M;
	id=idx;
	tar=y;
	ls=pos;
	for(auto p:pos)	tar+=a[p].v;
	build();
}

void solve(bool SPE){ 
	n=RIN,m=RIN;

	gen();

	int lst=0;
	while(m--){
		LL op=RIN,x=RIN,y=RIN^lst;
		if(op==0){
			for(auto p:pls[x])	a[p].increse(y);
			sort(All(Monitor::dead));
			lst=sz(Monitor::dead);
			printf("%d ",lst);
			for(auto c:Monitor::dead){
				printf("%d ",c);
			}
			printf("\n");
			Monitor::dead.clear();
		}else{
			new Monitor(pls[x],++Monitor::cnt,y);
		}
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
	// if(freopen("P76032.in","r",stdin));
	#ifdef ONLINE_JUDGE
	// if(freopen("P7603.in","r",stdin));
	// if(freopen("P7603.out","w",stdout));
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