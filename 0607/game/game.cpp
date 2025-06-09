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
#define ast(x) if(!(x))	{cein<<endl<<"err at"<<__LINE__<<endl;exit(1);}
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
// Cap1taLDebug cein(cout);
Cap1taLDebug cein(cerr);
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
	LL mi[40];
	inline LL pow2(int h){return 1ull<<h;}
	inline LL nxt_pow2(LL v,int h){
		return (v&(~(pow2(h)-1)))+pow2(h);
	}
	inline LL dis_to_nxt_pow2(LL v,int h){
		return nxt_pow2(v,h)-v;
	}
	inline u64 cross_mask(LL v,LL k){
		int t=63-__builtin_clzll(v^(v+k));
		return pow2(t+1)-1;
	}
	inline int lowbit(u64 x){
		return __builtin_ffsll(x)-1;
	}
	void init(){
		foru(i,0,39)	mi[i]=1ll<<i;
	}
}

constexpr int M=30;

namespace Alert{
	class Monitor;
	class Manager;

	class Manager{
		int hv;
		vector<int> ls[M+1];
		LL v;

	public:

		// int hook_L;
		// int hook_R;

		LL get_lim()const;
		LL get_value()const;
		void increse(LL k);
		void add_buzzer(int i,int h);
	};

	class Monitor{
		inline static pair<int,int> rebuild_queue[10001];
		inline static int rebuild_queue_top;
		// inline static stack<pair<int,int>,vector<pair<int,int>>> rebuild_queue;

		int id;
		int h;
		LL tar;
		LL r;
		int L,R;
		vector<Manager*> ls;

	public:
		inline static vector<int> dead;

		void add_rebuild();
		LL get_r()const;
		int get_h()const;
		LL get_target()const;
		pair<int,int> get_range()const;
		int get_id()const;
		void reduce_r(const LL& k);
		void init(const vector<Manager*>& pos,int _L,int _R,LL t,int idx);

		static void rebuild(const function<void(int l,int r)>& prefetch,const function<void(int l,int r)>& callback);
	};

	Monitor tsk[MAXN];

	LL Manager::get_lim()const{
		if(hv==0)	return 1e18;
		const LL lb=hv&(-hv);
		return (v&(~(lb-1)))+lb-v-1;
	}
	LL Manager::get_value()const{
		return this->v;
	}

	void Manager::increse(LL k){
		if(k==0)	return ;
		static int q[5000],qtop=0;
		// while(!q.empty())	q.pop();
		qtop=0;		

		v+=k;
		if(hv==0)	return ;
		// cein<<hook_L<<' '<<hook_R<<" do add "<<k<<endl;
		u32 mask=((1<<(32-__builtin_clz(v^(v-k))))-1)&hv;
		// cein<<"	mask="<<bitset<10>(mask)<<endl;
		while(mask){
			int t=utils::lowbit(mask);
			for(auto i:ls[t]){
				// cein<<"	find monitor "<<mn->get_id()<<"'s buzzer"<<endl;
				if(t!=tsk[i].get_h()){
					// cein<<"	ignoreing..."<<endl;
					continue;
				}
				q[qtop++]=i;
				// q.push(i);
			}
			ls[t].clear();
			mask^=1<<t;
		}
		
		while(qtop){
			// auto i=q.top();
			// q.pop();
			auto i=q[--qtop];

			// cein<<"	"<<"trigger monitor "<<tsk[i].get_id()<<endl;
			tsk[i].reduce_r(v-utils::nxt_pow2(v-k,tsk[i].get_h())+1);
			LL res=utils::dis_to_nxt_pow2(v,tsk[i].get_h())-1;
			if(tsk[i].get_r()>res){
				// cein<<"	replace with r="<<tsk[i].get_r()<<endl;
				ls[tsk[i].get_h()]+=i;
				tsk[i].reduce_r(res);
			}else{
				// cein<<"	ask "<<tsk[i].get_id()<<" to rebuild."<<endl;
				tsk[i].add_rebuild();
			}
		}
	}

	void Manager::add_buzzer(int i,int h){
		ls[h]+=i;
		hv|=utils::pow2(h);
		// cein<<"yes ("<<hook_L<<' '<<hook_R<<")receive buzzer("<<h<<") from monitor "<<mn->get_id()<<endl;;
	}


	void Monitor::add_rebuild(){
		// cein<<"yes I put "<<this->id<<endl; 
		Monitor::rebuild_queue[Monitor::rebuild_queue_top++]={id,this->h};
	}
	LL Monitor::get_r()const{
		return r;
	}
	int Monitor::get_h()const{
		return h;
	}
	pair<int,int> Monitor::get_range()const{
		return mkp(L,R);
	}
	LL Monitor::get_target()const{
		return tar;
	}
	int Monitor::get_id()const{
		return id;
	}
	void Monitor::reduce_r(const LL& k){
		r-=k;
	}
	void Monitor::init(const vector<Manager*>& pos,int _L,int _R,LL t,int idx){
		id=idx;
		h=M;
		tar=t;
		// id=0;
		ls=pos;
		L=_L,R=_R;
		// cein<<"i called rebuild for "<<idx<<endl;
		// cein<<"i called rebuild for "<<id<<endl;
		// exit(0);
		this->add_rebuild();
	}
	void Monitor::rebuild(const function<void(int l,int r)>& prefetch,const function<void(int l,int r)>& callback){
		while(rebuild_queue_top){
			auto [i,H]=rebuild_queue[--rebuild_queue_top];

			if(tsk[i].h!=H)	continue;

			// cein<<"rebuild monitor "<<tsk[i].id<<endl;
			// exit(0);

			prefetch(tsk[i].L,tsk[i].R);
			
			tsk[i].r=tsk[i].tar;
			for(auto p:tsk[i].ls){
				tsk[i].r-=p->get_value();
			}

			if(tsk[i].r<=0){
				// cein<<"monitor "<<tsk[i].id<<" dead"<<endl;
				Monitor::dead+=tsk[i].id;
				tsk[i].h=-1;
				continue;
			}
			// cein<<"monitor "<<tsk[i].id<<": "<<tsk[i].tar-tsk[i].r<<"/"<<tsk[i].tar<<endl;

			while((utils::pow2(tsk[i].h)-1)*sz(tsk[i].ls)>=tsk[i].r)	tsk[i].h--;

			for(auto p:tsk[i].ls){
				p->add_buzzer(tsk[i].id,tsk[i].h);
				tsk[i].r-=utils::dis_to_nxt_pow2(p->get_value(),tsk[i].h)-1;
			}

			callback(tsk[i].L,tsk[i].R);
		}
	}
}

using namespace Alert;

class SegmentTree{
	class Node{
	public:
		int l,r;
		LL add;
		LL lim;
		Manager node;
	}tr[MAXN<<2];

	int N;

	inline int lc(int x){return x<<1;}
	inline int rc(int x){return x<<1|1;}

	inline void push_up(const int& p){
		tr[p].lim=min({tr[lc(p)].lim,tr[rc(p)].lim,tr[p].node.get_lim()/(tr[p].r-tr[p].l+1)});
	}
	inline void push_up_leaf(const int& p){
		tr[p].lim=tr[p].node.get_lim();
	}
	inline void add_single(const int& p,const LL& k,const LL& rangek){
		// if(tr[p].node.get_lim()>=rangek){
			tr[p].node.increse(rangek);
		// }else{
		// 	SegmentTree::increseQueue.push(mkp(&tr[p].node,rangek));
		// }
	}
	inline void add_sub(const int& p,const LL& k){
		tr[p].add+=k;
		tr[p].lim-=k;
		add_single(p,k,k*(tr[p].r-tr[p].l+1));
	}
	void push_down(int p){
		if(tr[p].add!=0){
			add_sub(lc(p),tr[p].add);
			add_sub(rc(p),tr[p].add);
			tr[p].add=0;
		}
	}
	void build(int p,int l,int r){
		tr[p].l=l,tr[p].r=r;
		// tr[p].node.hook_L=l;
		// tr[p].node.hook_R=r;
		if(l==r){
			push_up_leaf(p);
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
	void pushdown_range(int p,int l,int r){
		if(l<=tr[p].l && tr[p].r<=r)	return ;
		push_down(p);
		int mid=(tr[p].l+tr[p].r)>>1;
		if(l<=mid)	pushdown_range(lc(p),l,r);
		if(r>mid)	pushdown_range(rc(p),l,r);
	}
	void pushup_range(int p,int l,int r){
		if(tr[p].l==tr[p].r){
			push_up_leaf(p);
			return ;
		}
		if(l<=tr[p].l && tr[p].r<=r){
			push_down(p);
			push_up(p);
			// cein<<"pushup range access "<<tr[p].l<<' '<<tr[p].r<<' '<<tr[p].lim<<endl;
			return ;
		}
		push_down(p);
		int mid=(tr[p].l+tr[p].r)>>1;
		if(l<=mid)	pushup_range(lc(p),l,r);
		if(r>mid)	pushup_range(rc(p),l,r);
		push_up(p);
	}
	void modify(int p,int l,int r,int k){
		// cein<<"vis modify "<<tr[p].l<<' '<<tr[p].r<<' '<<tr[p].lim<<endl;
		if(l<=tr[p].l && tr[p].r<=r){
			if(tr[p].l==tr[p].r){
				add_sub(p,k);
				return ;
			}
			if(tr[p].lim>=k){
				add_sub(p,k);
				return ;
			}
			add_single(p,k,(tr[p].r-tr[p].l+1)*(LL)k);
			push_down(p);
			// increseNode.push(p);
			modify(lc(p),l,r,k);
			modify(rc(p),l,r,k);
			push_up(p);
			// cerr<<"exit moidfy "<<tr[p].l<<' '<<tr[p].r<<' '<<tr[p].lim<<endl;
			return ;
		}
		// cein<<tr[p].l<<' '<<tr[p].r<<' '<<(min(r,tr[p].r)-max(l,tr[p].l)+1)*(LL)k<<endl;
		add_single(p,k,(min(r,tr[p].r)-max(l,tr[p].l)+1)*(LL)k);
		push_down(p);
		int mid=(tr[p].l+tr[p].r)>>1;
		// increseNode.push(p);
		if(l<=mid)	modify(lc(p),l,r,k);
		if(r>mid)	modify(rc(p),l,r,k);
		push_up(p);
		// cerr<<"exit moidfy "<<tr[p].l<<' '<<tr[p].r<<' '<<tr[p].lim<<endl;
	}
public:
	void init(int n){
		N=n;
		build(1,1,N);
	}
	void get_manager_list(int l,int r,vector<Manager*>& ls){
		access(1,l,r,ls);
	}
	void pushdown_range(int l,int r){
		pushdown_range(1,l,r);
	}
	void pushup_range(int l,int r){
		pushup_range(1,l,r);
	}
	void increse(int l,int r,int k){
		modify(1,l,r,k);
		Monitor::rebuild([this](const int& l,const int& r)->void {
			this->pushdown_range(l,r);
		},[this](const int& l,const int& r)->void {
			this->pushup_range(l,r);
		});
	}
};

SegmentTree tr;

int n,m,q,T,K;

void solve(bool SPE){ 
	n=RIN,m=RIN,q=RIN,T=RIN,K=RIN;
	
	tr.init(n);
	utils::init();

	foru(i,1,m){
		int l=RIN,r=RIN,c=RIN;
		// if(i!=25)	continue;
		// cein<<"Monitor "<<i<<": "<<l<<' '<<r<<' '<<c<<endl;
		vector<Manager*> mls;
		tr.get_manager_list(l,r,mls);
		tsk[i].init(mls,l,r,c,i);
	}
	Monitor::rebuild([](int l,int r)->void {
		// prefetch do nothing;	
	},[](int l,int r)->void {
		tr.pushup_range(l,r);
	});
	
	static int ans[MAXN];
	foru(i,1,m){
		ans[i]=-1;
	}
	int lst=0;
	foru(o,1,q){
		// cein<<endl;
		// cein<<o<<" OPT~~~~~~~~~~~~~~~~~~~~~"<<endl;
		int l=RIN,r=RIN,v=RIN;
		// cein<<l<<' '<<r<<' '<<v<<endl;
		if(T){
			l^=lst;
			r^=lst;
			v^=lst;
		}
		tr.increse(l,r,v);
		// tr.pushup_range(l,r);
		
		for(auto id:Monitor::dead){
			// printf("%d get dead monitor %d\n",o,id);
			ans[id]=o;
			lst^=tsk[id].get_range().fi;
			lst^=tsk[id].get_range().se;
			lst^=tsk[id].get_target();
		}
		Monitor::dead.clear();
	}

	foru(i,1,m){
		// if(i!=25)	continue;
		// printf("(%d)",i);
		printf("%d ",ans[i]);
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
	if(freopen("game.out","w",stdout));
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
