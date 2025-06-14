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
#define MAXN 2005
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
#include "treasure.h"
#define UP '^'
#define DOWN 'v'
#define RIGHT '>'
#define LEFT '<'

struct ExitForFoundTreasure{};

int X,Y;
char C;

char dat[5005][5005];

int cnt=0;
char Walk(char c){
	C=walk(c);
	cnt++;
	switch(c){
		case UP:
			X--;
			break;
		case DOWN:
			X++;
			break;
		case RIGHT:
			Y++;
			break;
		case LEFT:
			Y--;
			break;
	}
	if(C=='G')	throw ExitForFoundTreasure();
	dat[X][Y]=C;
	return C;
}


class Node{
public:
	int a,b,c,d;
	Node(int a=0,int b=0,int c=0,int d=0):a(a),b(b),c(c),d(d){}
	Node operator + (const Node& x)const{
		return Node(a+x.a,b+x.b,c+x.c,d+x.d);
	}
	Node& operator +=(const Node& x){
		*this=(*this)+x;
		return *this;
	}
	Node& operator +=(const char& x){
		switch(x){
			case UP:
				a++;break;
			case DOWN:
				b++;break;
			case RIGHT:
				c++;break;
			case LEFT:
				d++;break;
			case '.':
				break;
			case 'e':
				break;
			default:
				throw runtime_error("InvalidNodeChar");
		}
		return *this;
	}
	int& operator [] (const char& x){
		switch(x){
			case UP:
				return a;
			case DOWN:
				return b;
			case RIGHT:
				return c;
			case LEFT:
				return d;
		}
		throw runtime_error("InvalidNodeChar");
	}
};

void clear(){
	cnt=0;
}
void out(const string& msg=""){
	cerr<<"[cnt"<<msg<<"] "<<cnt<<endl;
}
int n;

void access_x(int x,int y){
	if(dat[x][y]!='e')	return ;
	while(X<x)	Walk(DOWN);
	while(X>x)	Walk(UP);
	while(Y>y)	Walk(LEFT);
	while(Y<y)	Walk(RIGHT);
}
void access_y(int x,int y){
	if(dat[x][y]!='e')	return ;
	while(Y>y)	Walk(LEFT);
	while(Y<y)	Walk(RIGHT);
	while(X<x)	Walk(DOWN);
	while(X>x)	Walk(UP);
}
// auto access=access_x;


void access_line_x(int x,int l,int r){
	if(abs(Y-l)<abs(Y-r)){
		foru(i,l,r){
			access_x(x,i);
		}
	}else{
		ford(i,r,l){
			access_x(x,i);
		}
	}
}
void smart_access_line_x(int x,int l,int r){
	access_x(x,Y);
	int bg=min(max(Y,l),r);
	access_x(x,l);
	access_x(x-1,r);
	access_x(x,bg);
}
void access_line_y(int y,int l,int r){
	if(abs(X-l)<abs(X-r)){
		foru(i,l,r){
			access_y(i,y);
		}
	}else{
		ford(i,r,l){
			access_y(i,y);
		}
	}
}

Node qry_line_x(int x,int l,int r){
	// cerr<<X<<' '<<Y<<endl;
	access_line_x(x,l,r);
	// out();
	// cerr<<X<<' '<<Y<<endl;
	Node ret;
	foru(i,l,r)	ret+=dat[x][i];
	return ret;
}
Node qry_line_y(int y,int l,int r){
	access_line_y(y,l,r);
	Node ret;
	foru(i,l,r)	ret+=dat[i][y];
	return ret;
}

pair<int,int> borderpair_x(int x,int l,int r){
	// cerr<<" "<<X<<' '<<Y<<endl;
	// access_x(x,l);
	// out();
	// cerr<<" "<<X<<' '<<Y<<endl;
	// cerr<<x<<' '<<l<<' '<<r<<endl;
	return mkp(qry_line_x(x,l,r)[UP],qry_line_x(x-1,l,r)[DOWN]);
}

void border_x(int x,int l,int r,int& down_i,int& down_o,int& up_i,int& up_o){
	//[x,l,r] is the line lower
	if(x<=1 || x>=2*n+2)	return ;

	smart_access_line_x(x,l,r);
	auto res=borderpair_x(x,l,r);
	// out();
	down_o+=res.fi,up_i+=res.fi;
	down_i+=res.se,up_o+=res.se;
}
void border_y(int y,int l,int r,int& left_i,int& left_o,int& right_i,int& right_o){
	//[y,l,r] is the line on the left
	if(y<=0 || y>=2*n+1)	return ;

	Node res;
	res=qry_line_y(y,l,r);
	left_o+=res[RIGHT],right_i+=res[RIGHT];
	res=qry_line_y(y+1,l,r);
	left_i+=res[LEFT],right_o+=res[LEFT];
}


void solve(int xl,int xr,int yl,int yr){
	if(xl==xr)	return access_line_x(xl,yl,yr);
	if(yl==yr)	return access_line_y(yl,xl,xr);
	if(xl>xr)	throw runtime_error("Invalid solve x-region");
	if(yl>yr)	throw runtime_error("Invalid solve y-region");
	if(xr-xl<yr-yl){
		int mid=(yl+yr)>>1;

		int L_i=0;
		int L_o=0;
		int R_i=0;
		int R_o=0;
		int X_i=0;
		int X_o=0;

		clear();
		border_y(mid,xl,xr,L_i,L_o,R_i,R_o);
		out("by");
		// exit(1);
		clear();
		border_y(yl-1,xl,xr,X_i,X_o,L_i,L_o);
		border_y(yr,xl,xr,R_i,R_o,X_i,X_o);

		border_x(xl,yl,mid,L_i,L_o,X_i,X_o);
		border_x(xl,mid+1,yr,R_i,R_o,X_i,X_o);
		border_x(xr+1,yl,mid,X_i,X_o,L_i,L_o);
		border_x(xr+1,mid+1,yr,X_i,X_o,R_i,R_o);
		// out();

		int L=L_o-L_i;
		int R=R_o-R_i;
		int X=X_o-X_i;

		int chk=(L!=0)+(R!=0)+(X!=0);
		
		if(chk!=0 && chk!=2)	throw runtime_error("Invalid Graph degrees (1)");
		
		if(L==0 && R==0 && X==0){
			if(n+1<xl || n+1>xr || n+1<yl || n+1>yr)	throw runtime_error("expect (n+1,n+1) in solve region, but not found");
			if(n+1<=mid)	solve(xl,xr,yl,mid);
			else	solve(xl,xr,mid+1,yr);
			return ;
		}

		if(min({L,R,X})!=-1 || max({L,R,X})!=1)	throw runtime_error("Invalid Graph degrees(2)");
		if(X==-1)	throw runtime_error("-1 should be in the region");

		if(L==-1)	solve(xl,xr,yl,mid);
		else	solve(xl,xr,mid+1,yr);
	}else{
		int mid=(xl+xr)>>1;

		int U_i=0;
		int U_o=0;
		int D_i=0;
		int D_o=0;
		int X_i=0;
		int X_o=0;

		clear();
		border_x(mid+1,yl,yr,D_i,D_o,U_i,U_o);
		out("bx");
		clear();
		border_x(xl,yl,yr,U_i,U_o,X_i,X_o);
		border_x(xr+1,yl,yr,X_i,X_o,D_i,D_o);

		border_y(yl-1,xl,mid,X_i,X_o,U_i,U_o);
		border_y(yl-1,mid+1,xr,X_i,X_o,D_i,D_o);
		border_y(yr,xl,mid,U_i,U_o,X_i,X_o);
		border_y(yr,mid+1,xr,D_i,D_o,X_i,X_o);
		// out();

		int U=U_o-U_i;
		int D=D_o-D_i;
		int X=X_o-X_i;

		int chk=(U!=0)+(D!=0)+(X!=0);
		
		if(chk!=0 && chk!=2)	throw runtime_error("Invalid Graph degrees (1)");
		
		if(U==0 && D==0 && X==0){
			if(n+1<xl || n+1>xr || n+1<yl || n+1>yr)	throw runtime_error("expect (n+1,n+1) in solve region, but not found");
			if(n+1<=mid)	solve(xl,mid,yl,yr);
			else	solve(mid+1,xr,yl,yr);
			return ;
		}

		if(min({U,D,X})!=-1 || max({U,D,X})!=1)	throw runtime_error("Invalid Graph degrees(2)");
		if(X==-1)	throw runtime_error("-1 should be in the region");

		if(U==-1)	solve(xl,mid,yl,yr);
		else	solve(mid+1,xr,yl,yr);
	}
}

void init(){
	const int NL=1;
	const int NMID=n+1;
	const int NR=2*n+1;

	foru(i,NL,NR)	foru(j,NL,NR)	dat[i][j]='e';

	X=NMID,Y=NMID;
	dat[X][Y]=UP;
	
	int U_i=0;
	int U_o=0;
	int D_i=0;
	int D_o=0;

	smart_access_line_x(NMID+1,NL,NR);
	border_x(NMID+1,NL,NR,D_i,D_o,U_i,U_o);
	out();
	// exit(1);

	if(U_o==D_o){
		solve(NL,NMID,NL,NR);
	}else if(U_o==D_o+1){
		solve(NMID+1,NR,NL,NR);
	}else{
		throw runtime_error("Unexpect Init Status");
	}

	throw runtime_error("init didn't find treasure");
}
void find_treasure(int _n){
	n=_n;
	try{
		init();
	}catch(ExitForFoundTreasure){
		return ;
	}catch(const runtime_error& e){
		cerr<<"Error: "<<e.what()<<endl;
		exit(1);
		return ;
	}
}