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
#define MAXN 1000005
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

int fac[5000001];
int inv[5000001];
int C(int n,int m){
	if(n<m)	return 0;
	return mul(fac[n],inv[m],inv[n-m]);
}
int g[MAXN];
int f[MAXN];
int G(int n,int k){
	return C(2*n,k);
}
int F(int n,int k,int L){
	return rmv(G(n,k),G(n,2*(L-1)-(k-n)+n));
}
int S(int n,int k,int L){
	return rmv(F(n,k,L),F(n,k,L+1));
}

int n,q;
int a[MAXN];
void gen(){
	static int c[5000005];
	static int s[5000005];
	foru(i,0,2*n){
		c[i]=C(2*n,i);
	}
	s[0]=c[0],s[1]=c[1];
	foru(i,2,5*n){
		s[i]=add(s[i-2],c[i]);
	}
	auto qry=[](int l,int n)->int {
		int ret=s[l+2*(n-1)];
		if(l>=2)	mmv(ret,s[l-2]);
		return ret;
	};
	foru(k,1,n){
		mdd(g[k],mul(n,C(2*n,2*n-k)));
		mmv(g[k],mul(n,C(2*n,2*n+k+2)));
		mmv(g[k],mul(n-k,C(2*n,2*(n-k)+k)));
		mdd(g[k],mul(n+1,C(2*n,2*(n+1)+k)));
		mmv(g[k],qry(k+2*(n-k+1),(n+1)-(n-k+1)+1));
		// foru(L,n-k+1,n+1){
		// 	mmv(g[k],c[2*L+k]);
		// }
		mll(g[k],fac[k],fac[2*n-k]);
	}
	foru(k,n+1,2*n){
		mdd(g[k],mul(n,C(2*n,k)));
		mmv(g[k],mul(n,C(2*n,2*n+k+2)));
		mmv(g[k],mul(0,C(2*n,2*(0)+k)));
		mdd(g[k],mul(n+1,C(2*n,2*(n+1)+k)));
		mmv(g[k],qry(2+k,n));
		// foru(L,1,n+1){
		// 	mmv(g[k],c[2*L+k]);
		// }
		mll(g[k],fac[k],fac[2*n-k]);
	}
	foru(i,1,2*n){
		f[i]=rmv(g[i],g[i-1]);
	}
}

void solve(bool SPE){ 
	n=RIN/2,q=RIN;
	foru(i,1,2*n){
		a[i]=RIN;
	}

	fac[0]=1;
	foru(i,1,5000000){
		fac[i]=mul(fac[i-1],i);
	}
	inv[5000000]=qpow(fac[5000000],mod-2);
	ford(i,5000000-1,0){
		inv[i]=mul(inv[i+1],i+1);
	}
	
	gen();
	
	int ans=0;
	static int b[MAXN];
	foru(i,1,2*n){
		b[i]=a[i];
	}
	sort(b+1,b+1+2*n,[](int x,int y)->bool {
		return x>y;
	});
	foru(i,1,2*n){
		// cerr<<b[i]<<end
		mdd(ans,mul(f[i],b[i]));
	}

	static pair<int,int> rg[1000005];
	foru(i,1,1000000){
		rg[i]={INT_MAX,INT_MIN};
	}
	foru(l,1,2*n){
		int r=l;
		while(r+1<=2*n && b[r+1]==b[l]){
			r++;
		}
		// cerr<<b[l]<<' '<<l<<' '<<r<<endl;
		rg[b[l]]={l,r};
		l=r;
	}

	auto PUSH=[&ans](int x,int rk)->void {
		assert(rg[x].fi==INT_MAX || rg[x].fi-1==rk || rg[x].se+1==rk);
		mdd(ans,mul(f[rk],x));
		chkmax(rg[x].se,rk);
		chkmin(rg[x].fi,rk);
	};
	auto POP=[&ans](int x,bool L)->void {
		assert(rg[x].fi!=INT_MAX);
		if(L){
			mmv(ans,mul(f[rg[x].fi],x));
			rg[x].fi++;
		}else{
			mmv(ans,mul(f[rg[x].se],x));
			rg[x].se--;
		}
		if(rg[x].fi>rg[x].se)	rg[x]={INT_MAX,INT_MIN};
	};
	auto ADD=[&](int x)->void {
		// cerr<<"ADD "<<rg[x].fi<<' '<<rg[x].se<<endl;
		assert(rg[x+1].se==INT_MIN || rg[x+1].se+1==rg[x].fi);
		assert(rg[x].fi!=INT_MAX);
		PUSH(x+1,rg[x].fi);
		POP(x,true);
	};
	auto RMV=[&](int x)->void {
		// cerr<<"RMV "<<rg[x].fi<<' '<<rg[x].se<<endl;
		PUSH(x-1,rg[x].se);
		POP(x,false);
	};

	auto out=[]()->void {
		cerr<<"OP"<<endl;
		foru(i,1,1000000){
			if(rg[i].fi==INT_MAX)	continue;
			cerr<<i<<' '<<rg[i].fi<<' '<<rg[i].se<<endl;
		}
	};
	// out();
	
	while(q--){
		int x=RIN,y=RIN;
		if(y>0){
			foru(i,a[x],a[x]+y-1){
				// cerr<<i<<endl;
				// assert(1<=i && i<=999999);
				ADD(i);
			}
		}
		if(y<0){
			ford(i,a[x],a[x]+y+1){
				// cerr<<i<<endl;
				// assert(2<=i && i<=1000000);
				RMV(i);
			}
			// exit(1);
		}
		a[x]+=y;
		printf("%d\n",ans);
		// out();
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
	if(freopen("permutation0.in","r",stdin));
	#ifdef ONLINE_JUDGE
	if(freopen("permutation.in","r",stdin));
	if(freopen("permutation.out","w",stdout));
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