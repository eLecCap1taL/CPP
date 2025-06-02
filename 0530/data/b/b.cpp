//%^~
#pragma GCC optimize(3)
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
#define MAXN 500005
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
int type;
int n,q;
int a[MAXN];
// class OPT{
// public:
// 	u32 ty;
// 	u32 l,r,x;
// }qr[MAXN];

constexpr u32 mod=998244353;

// #define u32 LL
// u32 add(const u32 x){return x;}
// template<class ... T>
// u32 add(const u32 x,const T ... xs){
// 	u32 ret=x+add(xs...);
// 	if(ret>=mod)	ret-=mod;
// 	return ret;
// }
// u32 mul(const u32 x){return x;}
// template<class ... T>
// u32 mul(const u32 x,const T ... xs){
// 	return (u64)x*(u64)mul(xs...)%mod;
// }
u32 add(u32 x,const u32 y){
	x+=y;
	if(x>=mod)	x-=mod;
	return x;
}
u32 mul(const u32 x,const u32 y){
	return (u64)x*y%mod;
}

// namespace SUB1{
// 	void work(){
// 		int lst=0;
// 		foru(o,1,q){
// 			auto [ty,l,r,x]=qr[o];
// 			l^=lst*type;
// 			r^=lst*type;
// 			x^=lst*type;
// 			if(ty==1){
// 				foru(i,l,r){
// 					a[i]=add(a[i],x);
// 				}
// 			}else{
// 				LL ans=0;
// 				LL s=0;
// 				foru(i,l,r){
// 					s+=(LL)a[i]%mod*(LL)a[i]%mod;
// 					// ans-=(LL)(i-l+1)*(LL)(r-i+1)%mod*(LL)a[i]%mod*(LL)a[i]%mod;
// 				}
// 				ans-=s%mod*(LL)(r-l+1-mul(l,r))%mod;

// 				s=0;
// 				foru(i,l,r){
// 					s+=(LL)i*(LL)a[i]%mod*(LL)a[i]%mod;
// 				}
// 				ans-=s%mod*(LL)(l+r)%mod;

// 				s=0;
// 				foru(i,l,r){
// 					s+=(LL)i*(LL)i%mod*(LL)a[i]%mod*(LL)a[i]%mod;
// 				}
// 				ans+=s;
				
// 				s=0;
// 				foru(i,l,r){
// 					foru(j,i,r){
// 						s+=(LL)(i+j)*(LL)a[i]%mod*(LL)a[j]%mod;
// 					}
// 				}
// 				ans+=s%mod*(LL)(l+r)%mod;

// 				s=0;
// 				foru(i,l,r){
// 					foru(j,i,r){
// 						s+=(LL)a[i]%mod*(LL)a[j]%mod;
// 					}
// 				}
// 				ans+=s%mod*(LL)(r-l+1-mul(l,r))*2ll%mod;

// 				s=0;
// 				foru(i,l,r){
// 					foru(j,i,r){
// 						s+=(LL)i*(LL)j*(LL)a[i]%mod*(LL)a[j]%mod;
// 					}
// 				}
// 				ans-=s*2ll%mod;
// 				// foru(i,l,r){
// 				// 	foru(j,i,r){
// 				// 		// ans+=((LL)(r-l+2)*(LL)(R-L)%mod+(LL)(L-l+1)*(LL)(r-R+1)%mod*2ll%mod)*(LL)a[L]%mod*(LL)a[R]%mod;
// 				// 		// ans+=(LL)((r-l+2)*(j-i)+2*(i-l+1)*(r-j+1)+2)*(LL)a[i]%mod*(LL)a[j]%mod;
// 				// 		ans+=(LL)((l+r)*(i+j)-2*l*r-2*i*j+2*(r-l)+2)*(LL)a[i]%mod*(LL)a[j]%mod;
// 				// 		// ans+=(LL)((l+r)*(L+R)-2*l*r-2*L*R+2*(r-l))*(LL)a[L]%mod*(LL)a[R]%mod;
// 				// 	}
// 				// }
// 				ans=(ans%mod+mod)%mod;
// 				lst=ans;
// 				printf("%d\n",lst);
// 			}
// 		}
// 	}
// }

namespace IO{
	char buf[1<<21],*p1=buf,*p2=buf;
	template<typename T>inline void redi(T& ret){
		ret=0;char ch;
		do
			ch=(p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++);
		while(ch<'0'||ch>'9');
		while(ch>='0'&&ch<='9')
			ret=(ret<<1)+(ret<<3)+ch-48,ch=(p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++);
	}
	template<typename T,typename...Args>inline void redi(T& t, Args&...args){redi(t),redi(args...);}
	char buffer[1<<21];int p3=-1;const int p4=(1<<21)-1;
	template<typename T>inline void wrtn(T x){
		static char buf[15];
		static int len=-1;
		do
			buf[++len]=x%10+48,x/=10;
		while(x);
		while(len>=0)
			buffer[++p3]=buf[len],--len;
		buffer[++p3]='\n';
		if(p3>p4)
			fwrite(buffer,1,p3+1,stdout),p3=-1;
	}
	template<typename T,typename... Args>inline void wrtn(T t,Args ... args){wrtn(t),wrtn(args...);}
	inline void flush(){fwrite(buffer,1,p3+1,stdout),p3=-1;}
}
using namespace IO;

#undef RIN

constexpr int qpow(LL x,int y){
	LL ret=1;
	while(y){
		if(y&1)	ret=ret*x%mod;
		x=x*x%mod,y>>=1;
	}
	return ret;
}

// constexpr int _6=qpow(6,mod-2);
constexpr u64 _2=qpow(2,mod-2);

namespace SUBNLOG{ 


	inline u32 mi1(const u32 r){
		return (u64)(1+r)*(u64)(r)*_2%mod;
	}
	// inline int mi1(int l,int r){
	// 	return rmv(mi1(r),mi1(l-1));
	// }
	// inline int mi2(int r){
	// 	return mul(r,r+1,2*r+1,_6);
	// }
	// inline int mi2(int l,int r){
	// 	return rmv(mi2(r),mi2(l-1));
	// }

	// inline int rg(int l,int r){
	// 	return mi1(r-l+1);
	// }

	inline void fdd(u32 &x,u32 y){
		x+=y;
		if(x>=mod)	x-=mod;
	}

	class Node{
	public:
		u32 tg;
		u32 v;
		u32 iv;
	}tr[MAXN<<2];
	u32 len[MAXN<<2];
	u32 mi2[MAXN<<2];
	inline u32 lc(u32 x){return x<<1;}
	inline u32 rc(u32 x){return x<<1|1;}
	inline void push_up(const u32 p){
		tr[p].v=add(tr[lc(p)].v,tr[rc(p)].v);
		tr[p].iv=add(tr[lc(p)].iv,tr[rc(p)].iv);
	}
	inline void upd(const u32 p,const u32 k){
		fdd(tr[p].v,mul(len[p],k));
		// if(mi2[p]!=)
		fdd(tr[p].iv,mul(mi2[p],k));
		fdd(tr[p].tg,k);
	}
	inline void push_down(const u32 p){
		if(tr[p].tg==0)	return ;
		upd(lc(p),tr[p].tg);
		upd(rc(p),tr[p].tg);
		tr[p].tg=0;
	}
	void build(u32 p,u32 l,u32 r){
		if(l==r){
			tr[p].v=a[l];
			tr[p].iv=mul(l,a[l]);
			mi2[p]=l;
			len[p]=1;
			return ;
		}
		u32 mid=(l+r)>>1;
		build(lc(p),l,mid);
		build(rc(p),mid+1,r);
		push_up(p);
		mi2[p]=add(mi2[lc(p)],mi2[rc(p)]);
		len[p]=add(len[lc(p)],len[rc(p)]);
		// if(mi2[p])
		// assert(mi2[p]==mi1(tr))
		// cerr<<l<<' '<<r<<' '<<mi2[p]<<endl;
	}
	void modify(const u32 p,const u32 tl,const u32 tr,const u32 l,const u32 r,const u32 k){
		// cerr<<"modi "<<l<<' '<<r<<' '<<k<<' '<<"at "<<tr[p].l<<' '<<tr[p].r<<endl;
		if(l<=tl && tr<=r){
		// if(tr[p].l==tr[p].r){
			// tr[p].v.apply(k);
			// cerr<<"upd "<<tr[p].l<<' '<<tr[p].r<<" v="<<tr[p].v.v<<endl;
			// fdd(tr[p].tg,k);
			upd(p,k);
			return ;
		}
		push_down(p);
		u32 mid=(tl+tr)>>1;
		if(l<=mid)	modify(lc(p),tl,mid,l,r,k);
		if(r>mid)	modify(rc(p),mid+1,tr,l,r,k);
		// tr[p].v.v=add(tr[lc(p)].v.v,tr[rc(p)].v.v);
		// tr[p].v.iv=add(tr[lc(p)].v.iv,tr[rc(p)].v.iv);
		push_up(p);
		// cerr<<"psup "<<tr[p].l<<' '<<tr[p].r<<" v="<<tr[p].v.v<<endl;
	}
	void query(const u32 p,const u32 trl,const u32 trr,const u32 l,const u32 r,u32& V,u32& IV){
		if(l<=trl && trr<=r){
			fdd(V,tr[p].v);
			fdd(IV,tr[p].iv);
			return ;
		}
		push_down(p);
		u32 mid=(trl+trr)>>1;
		if(l<=mid)	query(lc(p),trl,mid,l,r,V,IV);
		if(r>mid)	query(rc(p),mid+1,trr,l,r,V,IV);
	}
	void work(){
		build(1,1,n);
		// cerr<<' '<<tr[1].v.vij<<endl;
		// cerr<<' '<<tr[1].v.ijvi<<endl;
		// cerr<<' '<<tr[1].v.ijvij<<endl;
		// cerr<<' '<<tr[1].v.ij<<endl;
		// tr[1].v.apply(1);
		// cerr<<' '<<tr[1].v.vij<<endl;
		// exit(0);
		int lst=0;
		foru(o,1,q){
			int ty=0,l=0,r=0;
			redi(ty),redi(l),redi(r);
			l^=lst*type;
			r^=lst*type;
			if(ty==1){
				// foru(i,l,r){
				// 	a[i]=add(a[i],x);
				// }
				int x=0;
				redi(x);
				x^=lst*type;
				// cerr<<l<<' '<<r<<' '<<x<<endl;
				modify(1,1,n,l,r,x);
			}else{
				// cerr<<l<<' '<<r<<endl;
				// continue;
				u32 V=0,IV=0;
				query(1,1,n,l,r,V,IV);
				// cerr<<res.s<<' '<<res.L<<' '<<res.v<<' '<<res.iv<<endl;
				
				
				// int x=0,y=0;
				// x=res.iv;
				// y=res.v;
				// foru(i,l,r){
				// 	x=add(x,mul(i,a[i]));
				// 	y=add(y,a[i]);
				// }

				lst=mul(add(IV,mul(mod-l+1,V)),add(mod-IV,mul(r+1,V)));
				// printf("%d\n",lst);
				wrtn(lst);
			}
		}
		flush();
	}
}

void solve(bool SPE){ 
	redi(type);
	redi(n);
	redi(q);
	foru(i,1,n){
		redi(a[i]);
	}

	// foru(i,1,q){
	// 	auto& [ty,l,r,x]=qr[i];
	// 	ty=RIN;
	// 	if(ty==1){
	// 		l=RIN,r=RIN,x=RIN;
	// 	}else{
	// 		l=RIN,r=RIN;
	// 	}
	// }

	// if(n<=600 && q<=600){
	// 	SUB1::work();
	// 	return ;
	// }
	// if(n<=5000 && q<=5000){
		// SUB1::work();
		// return ;
	// }
	SUBNLOG::work();
	
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
	if(freopen("b1.in","r",stdin));
	// if(freopen("b.in","r",stdin));
	// if(freopen("b.out","w",stdout));
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