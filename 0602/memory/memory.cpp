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
template<typename T>\
pb<T>& operator += (pb<T>& x,const T& y){x.push_back(y);return x;}

#define OPERATOR_FOR_PUSH(p)\
template<typename T>\
p<T>& operator += (p<T>& x,const T& y){x.push(y);return x;}

#define OPERATOR_FOR_INSERT(i)\
template<typename T>\
i<T>& operator += (i<T>& x,const T& y){x.insert(y);return x;}

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
LL b[MAXN];
LL a[MAXN];
bool uni;

class Info{
public:
	LL mx;
	int num;
	int L;
	Info(LL x=0){
		mx=x;
		num=0;
		L=1;
	}
	Info operator + (const Info& x)const{
		Info ret;
		ret.mx=max(mx,x.mx);
		int lf=__lg(mx);
		int rf=__lg(x.mx);
		if(lf==max(lf,rf)){
			ret.num+=num;
		}else{
			ret.num+=L;
		}
		if(rf==max(lf,rf)){
			ret.num+=x.num;
		}else{
			ret.num+=x.L;
		}
		ret.L=L+x.L;
		return ret;
	}
};
class Node{
public:
	int l,r;
	Info v;
}tr[MAXN<<2];
inline int lc(int x){return x<<1;}
inline int rc(int x){return x<<1|1;}
void push_up(int p){
	tr[p].v=tr[lc(p)].v+tr[rc(p)].v;
}
void build(int p,int l,int r){
	tr[p].l=l,tr[p].r=r;
	if(l==r){
		tr[p].v=Info(a[l]);
		return ;
	}
	int mid=(l+r)>>1;
	build(lc(p),l,mid);
	build(rc(p),mid+1,r);
}
Info query(int p,int l,int r){
	if(l<=tr[p].l && tr[p].r<=r){
		return tr[p].v;
	}
	int mid=(tr[p].l+tr[p].r)>>1;
	if(r<=mid)	return query(lc(p),l,r);
	if(l>mid)	return query(rc(p),l,r);
	return query(lc(p),l,r)+query(rc(p),l,r);
}

void init(int _n, const vector<long long> &_a){
	n=_n;
	foru(i,1,n){
		a[i]=_a[i-1];
		b[i]=a[i];
	}
	sort(b+1,b+1+n);
	uni=1;
	foru(i,2,n){
		if(b[i]==b[i-1]){
			uni=0;
		}
	}
	build(1,1,n);
}

long long ask(int l, int r){
    return 0;
}

vector<long long> askAll(int q, const vector<int> &l, const vector<int> &r){
    vector<long long> ans(q);

	static int s[MAXN];
	foru(i,1,n){
		if(a[i]-(1ll<<__lg(a[i])))	s[i]=1;
		s[i]+=s[i-1];
	}

	bool sub1=1;
	foru(i,2,n){
		if(a[i]!=a[i-1]){
			sub1=0;
			break;
		}
	}
	if(sub1){
		foru(i,0,q-1){
			ans[i]=r[i]-l[i]+1+(1ll<<__lg(a[1]));
			ans[i]+=s[r[i]]-s[l[i]-1];
			chkmin(ans[i],r[i]-l[i]+1+a[1]);
		}
		return ans;
	}

	if(n<=1000 && q<=1000){
		foru(o,0,q-1){
			int L=l[o];
			int R=r[o];

			int hb=0;
			foru(i,L,R){
				chkmax(hb,__lg(a[i]));
			}

			vector<LL> ls;

			ans[o]=(1ll<<hb);
			int len=0;
			foru(i,L,R){
				if(a[i]<=(1ll<<hb))	ans[o]++;
				else{
					len++;
					ls+=a[i];
				}
			}

			sort(All(ls));
			LL mn=0;
			for(size_t i=0;i<ls.size();i++){
				if(i+1<ls.size() && ls[i]==ls[i+1]){
					continue;
				}
				chkmin(mn,ls[i]-(1ll<<hb)-(i+1));
				// cerr<<ls[i]-(1ll<<hb)<<' '<<pre<<endl;
			}
			
			ans[o]+=2ll*len+mn;
		}

		return ans;
	}

	if(uni){
		foru(o,0,q-1){
			int L=l[o];
			int R=r[o];

			auto res=query(1,L,R);
			int hb=__lg(res.mx);
			int L=res.L;
			int x=res.num;
			ans[o]=1ll<<hb;
			ans[o]+=x;
			ans[o]+=2*(L-x);
		}
		return ans;
	}
	
	int sub3=__lg(a[1]);
	foru(i,2,n){
		if(__lg(a[i])!=sub3){
			sub3=-1;
			break;
		}
	}
	if(sub3!=-1){
		foru(i,0,q-1){
			ans[i]=r[i]-l[i]+1+(1ll<<sub3);
			ans[i]+=s[r[i]]-s[l[i]-1];
		}
		return ans;
	}

	// exit(0);
    return ans;
}