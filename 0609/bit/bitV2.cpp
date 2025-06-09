//%^~
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
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
	// #define DEBUGING

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
给定 n 个数，每次查询给定 x 和 c，求 popcount(a_i&x)=c 的 a_i 的数量，怎么做？
*/

#define pc(x) (__builtin_popcount(x))
#define reg register
struct control{
	int ct,val;
	control(int Ct,int Val=-1):ct(Ct),val(Val){}
	inline control operator()(int Val){
		return control(ct,Val);
	}
}_endl(0),_prs(1),_setprecision(2);
struct FastIO{
	#define IOSIZE 1000000
	char in[IOSIZE],*p,*pp,out[IOSIZE],*q,*qq,ch[20],*t,b,K,prs;
	FastIO():p(in),pp(in),q(out),qq(out+IOSIZE),t(ch),b(1),K(6){}
	~FastIO(){fwrite(out,1,q-out,stdout);}
	inline char getch(){
		return p==pp&&(pp=(p=in)+fread(in,1,IOSIZE,stdin),p==pp)?b=0,EOF:*p++;
	}
	inline void putch(char x){
		q==qq&&(fwrite(out,1,q-out,stdout),q=out),*q++=x;
	}
	inline void puts(const char str[]){fwrite(out,1,q-out,stdout),fwrite(str,1,strlen(str),stdout),q=out;}
	inline void getline(string& s){
		s="";
		for(reg char ch;(ch=getch())!='\n'&&b;)s+=ch;
	}
	#define indef(T) inline FastIO& operator>>(T& x){\
		x=0;reg char f=0,ch;\
		while(!isdigit(ch=getch())&&b)f|=ch=='-';\
		while(isdigit(ch))x=(x<<1)+(x<<3)+(ch^48),ch=getch();\
		return x=f?-x:x,*this;\
	}
	indef(int)
	indef(long long)
	inline FastIO& operator>>(char& ch){return ch=getch(),*this;}
	inline FastIO& operator>>(string& s){
		s="";reg char ch;
		while(isspace(ch=getch())&&b);
		while(!isspace(ch)&&b)s+=ch,ch=getch();
		return *this;
	}
	inline FastIO& operator>>(double& x){
		x=0;reg char f=0,ch;
        double d=0.1;
        while(!isdigit(ch=getch())&&b)f|=(ch=='-');
        while(isdigit(ch))x=x*10+(ch^48),ch=getch();
        if(ch=='.')while(isdigit(ch=getch()))x+=d*(ch^48),d*=0.1;
        return x=f?-x:x,*this;
	}
	#define outdef(_T) inline FastIO& operator<<(_T x){\
		!x&&(putch('0'),0),x<0&&(putch('-'),x=-x);\
		while(x)*t++=x%10+48,x/=10;\
		while(t!=ch)*q++=*--t;\
		return *this;\
	}
	outdef(int)
	outdef(long long)
	inline FastIO& operator<<(char ch){return putch(ch),*this;}
	inline FastIO& operator<<(const char str[]){return puts(str),*this;}
	inline FastIO& operator<<(const string& s){return puts(s.c_str()),*this;}
	inline FastIO& operator<<(double x){
		reg int k=0;
		this->operator<<(int(x));
		putch('.');
		x-=int(x);
		prs&&(x+=5*pow(10,-K-1));
		while(k<K)putch(int(x*=10)^48),x-=int(x),++k;
		return *this;
	}
	inline FastIO& operator<<(const control& cl){
		switch(cl.ct){
			case 0:putch('\n');break;
			case 1:prs=cl.val;break;
			case 2:K=cl.val;break;
		}
	}
	inline operator bool(){return b;}
}io;

int n,q;
int a[MAXN];
class QR{
public:
	int A,B,C,k,x;
}qr[70005];


namespace SUB1{
	int b[MAXN];

	#define LB 10
	#define HB 6
	#define LBFULL ((1<<LB)-1)
	#define HBFULL ((1<<HB)-1)
	#define BIT(x,h)	(((x)>>(h))&1)

	u64 cnt[(1<<HB)>>1][1<<LB];
	u64 pre[(1<<HB)>>1][1<<LB];

	int vlb[1<<LB];
	int vhb[1<<HB];
	int t[1<<LB];

	void work(){
		foru(i,1,n){
			int x=a[i]>>LB;
			if(x&1){
				cnt[x>>1][a[i]&LBFULL]+=1ull<<32;
			}else{
				cnt[x>>1][a[i]&LBFULL]++;
			}
		}
		for(int i=0;i<=LBFULL;i++){
			t[i]=i;
		}


		// int lstx=INT_MIN;
		// int lste=INT_MIN;
		int lstE=0;
		foru(o,1,q){
			auto [A,B,C,k,x]=qr[o];

			auto D=A-B-2*C;
			auto E=B+C;
			auto CONST=(B+C)*pc(x);

			// foru(i,1,n){
			// 	b[i]=D*pc(a[i]&x)+E*pc(a[i]);
			// }

			for(int i=0;i<=LBFULL;i++){
				vlb[i]=0;
				for(int j=0;j<LB;j++){
					vlb[i]+=BIT(i,j)*(E+D*BIT(x,j));
				}
			}
			for(int i=0;i<=HBFULL;i++){
				vhb[i]=0;
				for(int j=0;j<HB;j++){
					vhb[i]+=BIT(i,j)*(E+D*BIT(x,LB+j));
				}
			}

			sort(t,t+LBFULL+1,[](const int& x,const int& y)->bool {
				return vlb[x]<vlb[y];
			});
			// sort(VLB,VLB+LBFULL+1);

			// continue;
			for(int i=0;i<=(HBFULL>>1);i++){
				pre[i][0]=cnt[i][t[0]];
				for(int j=1;j<=LBFULL;j++){
					pre[i][j]=pre[i][j-1]+cnt[i][t[j]];
				}
				// assert(pre[i][LBFULL]>=1);
			}

			// continue;
			int l=-7e6,r=7e6,ans=0;
			int L=0,R=LBFULL,N=-1;
			while(l<=r){
				int mid=(l+r)>>1;
				u32 num=0;
				// __builtin_prefetch(vlb, 0, 1);
				// __builtin_prefetch(vhb, 0, 1);

				for(u16 i=0;i<=HBFULL;i++){
					L=0,R=LBFULL,N=-1;
					while(L<=R){
						int Mid=(L+R)>>1;
						if(vlb[t[Mid]]+vhb[i]<=mid){
							N=Mid;
							L=Mid+1;
						}else{
							R=Mid-1;
							// if(Mid==0)	break;
						}
					}
					num+=N>=0?((i&1)?(pre[i>>1][N]>>32):(pre[i>>1][N]&((1ull<<32)-1))):0;
					if(num>=k)	break;
				}
				if(num>=k){
					ans=mid;
					r=mid-1;
				}else{
					l=mid+1;
				}
			}

			// cout<<' '<<ans<<endl;
			// foru(i,1,n){
			// 	b[i]=vlb[a[i]&LBFULL]+vhb[a[i]>>LB];
			// }
			// nth_element(b+1,b+k,b+1+n);
			// cout<<' '<<b[k]<<endl;

			// cout<<ans+CONST<<'\n';
			io<<ans+CONST<<'\n';
			// printf("%d\n",ans+CONST);
		}
	}
}

namespace SUBA{

	void work(){

	}
}

void solve(bool SPE){
	// ios::sync_with_stdio(0);
	// cin.tie(0),cout.tie(0); 
	// n=RIN,q=RIN;
	io>>n>>q;
	foru(i,1,n){
		io>>a[i];
		// a[i]=RIN;
	}

	bool fA=1;
	bool fB=1;
	bool fC=1;
	foru(i,1,q){
		io>>qr[i].A;
		io>>qr[i].B;
		io>>qr[i].C;
		io>>qr[i].k;
		io>>qr[i].x;
		// qr[i]={RIN,RIN,RIN,RIN,RIN};
		fA&=qr[i].A==0;
		fB&=qr[i].B==0;
		fC&=qr[i].C==0;
	}

	// if(fB && fC){
	// 	SUBA::work();
	// 	return ;
	// }
	// if(n<=10000){
		SUB1::work();
		return ;
	// }

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
	if(freopen("bit1.in","r",stdin));
	if(freopen("a.in","r",stdin));
	if(freopen("bit.out","w",stdout));
	#ifdef ONLINE_JUDGE
	if(freopen("bit.in","r",stdin));
	if(freopen("bit.out","w",stdout));
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