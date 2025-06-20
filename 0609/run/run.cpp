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
int a[MAXN];

class OPT{
public:
	int ty,l,r;
}op[MAXN];

inline int getval(int n){
	return add(mul(n+2,qpow(2,n+1)),1);
}

int g[MAXN];

int mi[MAXN];

int calc(int L,int R);
int calc(int n){
	if(n==0)	return 1;
	if(n==1)	return 6;
	if(g[n])	return g[n];
	return g[n]=add(calc(n-2,n-1),mul(getval(0),mi[n-2]));
}

constexpr int _2=qpow(2,mod-2);

int calc(int L,int R){
	if(L==0){
		return add(calc(R),getval(R));
	}else{
		int ans=rmv(0,mul(1+L,L,_2));
		mdd(ans,mul(L,R+2));
		mll(ans,mi[R]);
		mdd(ans,calc(0,R),rmv(mi[L],1));
		return ans;
	}
}

class DS{
	struct Node{
		int l,r;
		int sum;
		int cv;
		int rv;
		int val;
	}tr[MAXN<<2];
	inline int lc(int x){return x<<1;}
	inline int rc(int x){return x<<1|1;}
	void push_up(int p){
		tr[p].sum=tr[lc(p)].sum+tr[rc(p)].sum;
		
		int mid=(tr[p].r+tr[p].l)>>1;
		tr[p].val=add(tr[lc(p)].val,mul(tr[rc(p)].val,mi[mid-tr[p].l+1]));
	}
	void COV(int p,int k){
		tr[p].sum=(tr[p].r-tr[p].l+1)*k;
		tr[p].cv=k;
		tr[p].rv=0;
		tr[p].val=rmv(mi[tr[p].r-tr[p].l+1],1)*k;
	}
	void REV(int p){
		tr[p].sum=(tr[p].r-tr[p].l+1)-tr[p].sum;
		tr[p].rv^=1;
		tr[p].val=rmv(rmv(mi[tr[p].r-tr[p].l+1],1),tr[p].val);
	}
	void push_down(int p){
		if(tr[p].cv!=-1){
			COV(lc(p),tr[p].cv);
			COV(rc(p),tr[p].cv);
			tr[p].cv=-1;
		}
		if(tr[p].rv){
			REV(lc(p));
			REV(rc(p));
			tr[p].rv=0;
		}
	}
	void build(int p,int l,int r){
		tr[p].l=l,tr[p].r=r;
		tr[p].cv=-1;
		tr[p].rv=0;
		tr[p].sum=tr[p].val=0;
		if(l==r){
			tr[p].sum=a[l];
			tr[p].val=a[l];
			return ;
		}
		int mid=(l+r)>>1;
		build(lc(p),l,mid);
		build(rc(p),mid+1,r);
		push_up(p);
	}
	void modify(int p,int l,int r,int k){
		if(l<=tr[p].l && tr[p].r<=r){
			COV(p,k);
			return ;
		}
		push_down(p);
		int mid=(tr[p].l+tr[p].r)>>1;
		if(l<=mid)	modify(lc(p),l,r,k);
		if(r>mid)	modify(rc(p),l,r,k);
		push_up(p);
	}
	void modify(int p,int l,int r){
		if(l<=tr[p].l && tr[p].r<=r){
			REV(p);
			return ;
		}
		push_down(p);
		int mid=(tr[p].l+tr[p].r)>>1;
		if(l<=mid)	modify(lc(p),l,r);
		if(r>mid)	modify(rc(p),l,r);
		push_up(p);
	}
	int query(int p,int l,int r){
		if(l<=tr[p].l && tr[p].r<=r)	return tr[p].val;
		push_down(p);
		int mid=(tr[p].l+tr[p].r)>>1;
		if(r<=mid)	return query(lc(p),l,r);
		if(l>mid)	return query(rc(p),l,r);
		return add(query(lc(p),l,r),mul(query(rc(p),l,r),mi[mid-max(tr[p].l,l)+1]));
	}
	int find(int p,int l,int r){
		if(l<=tr[p].l && tr[p].r<=r){
			if(tr[p].sum==0)	return l-1;
			if(tr[p].l==tr[p].r)	return tr[p].l;
			push_down(p);
			if(tr[rc(p)].sum)	return find(rc(p),l,r);
			else	return find(lc(p),l,r);
		}
		push_down(p);
		int mid=(tr[p].l+tr[p].r)>>1;
		if(r<=mid)	return find(lc(p),l,r);
		if(l>mid)	return find(rc(p),l,r);
		int res=find(rc(p),l,r);
		if(res!=l-1)	return res;
		return find(lc(p),l,r);
	}
public:
	void init(){
		build(1,1,n);
	}
	void set(int l,int r,int k){
		modify(1,l,r,k);
		// foru(i,l,r){
		// 	a[i]=k;
		// }
	}
	void rev(int l,int r){
		modify(1,l,r);
		// foru(i,l,r){
		// 	a[i]^=1;
		// }
	}
	int findR(int l,int r){
		if(l>r)	return l-1;
		return find(1,l,r);
		// ford(i,r,l){
		// 	if(a[i]==1)	return i;
		// }

		// return l-1;
	}
	int qryVal(int l,int r){
		if(l>r)	return 0;
		return query(1,l,r);
		// int ret=0;
		// ford(i,r,l){
		// 	mll(ret,2);
		// 	mdd(ret,a[i]);
		// }
		// return ret;
	}
}ds;


void solve(bool SPE){ 
	n=RIN,m=RIN;

	mi[0]=1;
	foru(i,1,n){
		mi[i]=mul(mi[i-1],2);
	}
	foru(i,1,n){
		a[i]=RCIN=='1';
	}
	foru(i,1,m){
		op[i]={RIN,RIN,RIN};
	}

	ds.init();

	foru(o,1,m){
		auto [ty,l,r]=op[o];
		switch(ty){
		case 1:
			ds.rev(l,r);
			break;
		case 2:
			ds.set(l,r,0);
			break;
		case 3:
			ds.set(l,r,1);
			break;
		case 4:
			int R1=l-1;
			int R2=l-1;

			R1=ds.findR(l,r);
			R2=ds.findR(l,R1-1);

			// foru(i,l,r){
			// 	cout<<a[i];
			// }
			// cout<<endl;
			// cout<<' '<<getval(1)<<endl;
			if(R1==l-1){
				printf("0\n");
				break;
			}
			if(R2==l-1){
				printf("%d\n",calc(R1-l));
				break;
			}
			
			int ans=0;

			int base=ds.qryVal(l,R2-1);

			// cerr<<' '<<calc(0,2)<<endl;
			ans=mul(base,getval(R1-R2-1));
			mdd(ans,calc(R2-l,R1-l));

			printf("%d\n",ans);

			break;
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
	if(freopen("run0.in","r",stdin));
	#ifdef ONLINE_JUDGE
	if(freopen("run.in","r",stdin));
	if(freopen("run.out","w",stdout));
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