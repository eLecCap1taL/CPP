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
int n;
int a[MAXN];

constexpr int LEN[10]={0,1,1,2,1,3,2,2,2,2};
constexpr int HGT[10]={0,1,2,1,3,1,2,2,2,2};
class Space{
	u128 d;
public:
	Space(const u128 x=0):d(x){}
	bool operator ()(int x,int y)const{
		return (d>>(x*9+y))&1;
	}
	void set(int x,int y,bool v=1){
		int pos=x*9+y;
		if(v)	d|=u128(1)<<pos;
		else	d=d&(~(u128(1)<<pos));
	}
	int chk(int l,int r)const{
		int ret=-1;
		foru(i,l,r){
			ford(j,8,0){
				if((*this)(i,j)){
					chkmax(ret,j);
					break;
				}
			}
		}
		return ret;
	}

	void down(int i,int h){
		ford(j,7,h)	set(i,j,(*this)(i,j+1));
		set(i,8,0);
	}
	bool chkdown(int h){
		bool full=1;
		foru(i,0,8){
			if((*this)(i,h)==0){
				full=0;
				break;
			}
		}
		if(!full)	return 0;
		foru(i,0,8){
			down(i,h);
		}
		return 1;
	}
	
	int push(int ty,int p){
		// if(p+LEN[ty]-1>=9)	return -1;

		int h;
		if(ty==8){
			h=max(this->chk(p,p)+1,this->chk(p+1,p+1));
		}else if(ty==9){
			h=max(this->chk(p,p)+1,this->chk(p+1,p+1)+2);
		}else{
			h=this->chk(p,p+LEN[ty]-1)+1;
		}
		
		if(h+HGT[ty]-1>=9)	return -1;

		int w=0;
		bool con=1;

		switch(ty){
			case 1:{
				this->set(p,h);
				if(con && chkdown(h))	w++;else	con=0;
				break;
			}
			case 2:{
				this->set(p,h);
				this->set(p,h+1);
				if(con && chkdown(h))	w++;else	con=0;
				if(con && chkdown(h))	w++;else	con=0;
				break;
			}
			case 3:{
				this->set(p,h);
				this->set(p+1,h);
				if(con && chkdown(h))	w++;else	con=0;
				break;
			}
			case 4:{
				this->set(p,h);
				this->set(p,h+1);
				this->set(p,h+2);
				if(con && chkdown(h))	w++;else	con=0;
				if(con && chkdown(h))	w++;else	con=0;
				if(con && chkdown(h))	w++;else	con=0;
				break;
			}
			case 5:{
				this->set(p,h);
				this->set(p+1,h);
				this->set(p+2,h);
				if(con && chkdown(h))	w++;else	con=0;
				break;
			}
			case 6:{
				this->set(p,h);
				this->set(p+1,h);
				this->set(p,h+1);
				if(con && chkdown(h))	w++;else	con=0;
				if(con && chkdown(h))	w++;else	con=0;
				break;
			}
			case 7:{
				this->set(p,h);
				this->set(p+1,h);
				this->set(p+1,h+1);
				if(con && chkdown(h))	w++;else	con=0;
				if(con && chkdown(h))	w++;else	con=0;
				break;
			}
			case 8:{
				this->set(p,h);
				this->set(p,h+1);
				this->set(p+1,h+1);
				if(con && chkdown(h))	w++;else	con=0;
				if(con && chkdown(h))	w++;else	con=0;
				break;
			}
			case 9:{
				this->set(p,h);
				this->set(p+1,h);
				this->set(p+1,h-1);
				if(con && chkdown(h-1))	w++;else	con=0;
				if(con && chkdown(h-1))	w++;else	con=0;
				break;
			}
		}
		return w;
	}
	int chkcv(){
		int ret=0;
		foru(i,0,8){
			bool hv=0;
			ford(j,8,0){
				if((*this)(i,j))	hv=1;
				else	ret+=hv;
			}
		}
		return ret;
	}
};

ostream& operator << (ostream& os,const Space& s){
	ford(j,8,0){
		foru(i,0,8){
			os<<s(i,j);
		}
		os<<endl;
	}
	return os;
}


class State{
public:
	Space d;
	int r;
	int k;

	float score;

	void calc(){
		int mxh=d.chk(0,8)+1;
		int cv=d.chkcv();

		float r_score=1.0*r*r/n/n;
		float mxh_score=1.0*(8-mxh)/8;
		float cv_score=1.0*(81-cv)/81;
		float k_score=1.0*k/n;

		score=1*r_score+0.1*mxh_score+100*cv_score+500*k_score;
	}
	State(const Space& x,const int& rd,const int& wk){
		d=x,r=rd,k=wk;
		calc();
	}
	bool operator < (const State& x)const{
		return score<x.score;
	}
};


void solve(bool SPE){ 
	n=RIN;
	foru(i,1,n){
		a[i]=RIN;
	}

	static priority_queue<State> q;
	q.push(State(Space(),1,0));

	int step=100000;
	int mx=-1;
	while(!q.empty()){
		const State u=q.top();
		q.pop();

		chkmax(mx,u.r);

		step--;
		if(step==0){

			break;
		}

		if(u.r==n){

			break;
		}

		int t=a[u.r];

		foru(i,0,8-LEN[t]+1){
			State nxt=u;
			int x=nxt.d.push(t,i);	
			if(x==-1)	continue;
			nxt.k+=x;
			nxt.r++;
			nxt.calc();
			q.push(nxt);
			// if(u.r==480){
			// 	cout<<nxt.score<<' '<<q.top().score<<endl;
			// 	cout<<nxt.d<<endl<<q.top().d<<endl;
			// 	return ;
			// }
		}
	}

	cout<<mx;
	
	// Space s;

	// s.push(5,0);
	// s.push(5,3);
	// cout<<s.push(5,6)<<endl;

	// cout<<s.chkcv()<<endl;
	// cout<<s;

	// s.set(0,2);
	// s.set(1,1);

	// cout<<s.chk(1,1);

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
	if(freopen("block1.in","r",stdin));
	// if(freopen("block.out","w",stdout));
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