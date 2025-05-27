#include"testlib.h"
#include<bits/stdc++.h>
typedef int64_t Int;
typedef uint64_t uInt;

#define Assert(expr) _assert(expr)
bool load_end=0;
void _assert(bool result){
	if(!result){
		if(!load_end)quitf(_wa,"Compile Error");
		else quitf(_wa,"Runtime Error");
	}
}

struct IO{
	static constexpr Int N=5e6;
	Int buf[N];
	Int l=0,r=0;
	Int read(Int L,Int R){
		Int x=read();
		Assert(L<=x&&x<=R);
		return x;
	}
	Int read(){
		Assert(l<r);
		Int x=buf[l++];
		return x;
	}
	void write(Int x){
		Assert(r<N);
		buf[r++]=x;
	}
	void write(const std::vector<Int> &all){
		for(Int x:all)write(x);
	}
	std::vector<Int> readAll(){
		std::vector<Int> ret(buf+l,buf+r);
		l=r=0;
		return ret;
	}
}io;

struct Instr{
	Int opcode,op1,op2,op3;
};
std::vector<Instr> instr;
struct addr_t{
	int32_t type,offset;
	operator uInt(){
		return uint32_t(offset)|(uInt(type)<<32);
	}
};

Int *mem,pc,sp;
Int mem_cost;
uInt TL=1ull<<24,ML=1ull<<24,CL=1ull<<24;
Int &mem_access(uInt x){
	Assert(x<ML);
	return mem[x];
}
Int &get(uInt x){
	addr_t a;
	a.offset=uint32_t(x);
	a.type=uint32_t(x>>32);
	Int &data=mem_access(sp+a.offset);
	if(a.type){
		++mem_cost;
		return mem_access(data);
	}
	return data;
}
Int ncall3_cnt=0;
//FILE *in_file,*out_file;
void solve();
void ncall(Int type,Int &x){
	switch(type){
		case 1:{
			mem_access(x)=io.read();
			break;
		}
		case 2:{
			io.write(x);
			break;
		}
		case 3:{
			Assert(ncall3_cnt>0);
			--ncall3_cnt;
			solve();
			break;
		}
		default:{
			Assert(0);
			break;
		}
	}
}
#define dpr(...) void()//fprintf(stderr,__VA_ARGS__)
void show_mem(int n){
	dpr("pc=%lld\n",(long long)pc);
	dpr("sp=%lld\n",(long long)sp);
	for(int i=0;i<n;i+=10){
		for(int j=0;j<10;++j){
			dpr("%d:%lld  ",i+j,(long long)mem[i+j]);
		}
		dpr("\n");
	}
}
uInt _exec(){
	get(0)=instr.size()-1;
	sp=0;
	pc=0;
	ncall3_cnt=1;
	mem_cost=0;
	const Instr *code=instr.data();
	for(uInt i=0;i<TL;++i){
		dpr("pc: %lld\n",(long long)pc);
		const Instr &cur=code[pc++];
		switch(cur.opcode){
			#define uop(id,op) case id:{get(cur.op1)=op get(cur.op2);break;}
			#define bop(id,op) case id:{get(cur.op1)=get(cur.op2) op get(cur.op3);break;}
			uop(0,+)
			uop(1,-)
			uop(2,!)
			
			bop(3,+)
			bop(4,-)
			bop(5,*)
			bop(6,/)
			bop(7,%)
			
			bop(8,^)
			bop(9,&)
			bop(10,|)
			
			bop(11,<<)
			bop(12,>>)
			
			bop(13,<)
			bop(14,<=)
			bop(15,>)
			bop(16,>=)
			bop(17,==)
			bop(18,!=)
			
			case 19:{
				if(!get(cur.op2))pc=cur.op1;
				break;
			}
			case 20:{
				pc=cur.op1;
				break;
			}
			case 21:{
				show_mem(40);
				dpr("ret %d %d %d %d\n",(int)get(0),(int)get(1),(int)get(2),(int)get(3));
				pc=get(0);
				sp=get(1);
				dpr("ret %d %d\n",(int)pc,(int)sp);
				show_mem(40);
				break;
			}
			case 22:{
				show_mem(40);
				get(cur.op2)=pc;
				get(cur.op2+1)=sp;
				pc=cur.op1;
				sp+=cur.op2;
				dpr("call %d %d\n",(int)pc,(int)sp);
				show_mem(40);
				break;
			}
			case 23:{
				dpr("exit\n");
				return i+1;
			}
			case 24:{
				get(cur.op1)=cur.op2;
				break;
			}
			case 25:{
				get(cur.op1)=sp+cur.op2;
				break;
			}
			case 26:{
				ncall(cur.op2,get(cur.op1));
				break;
			}
			default:{
				Assert(0);
				break;
			}
		}
	}
	return TL+1;
}
std::pair<uInt,uInt> exec(){
	//in_file=fopen("1.in","r");
	//out_file=stdout;
	mem=new Int[ML]();
	auto time=_exec();
	//std::cerr<<"time: "<<time<<'\n';
	//std::cerr<<"M[_]: "<<mem_cost<<'\n';
	delete[]mem;
	return {time,mem_cost};
}
/*
0	uop(+)
1	uop(-)
2	uop(!)
	
3	bop(+)
4	bop(-)
5	bop(*)
6	bop(/)
7	bop(%)
	
8	bop(^)
9	bop(&)
10	bop(|)
	
11	bop(<<)
12	bop(>>)
	
13	bop(<)
14	bop(<=)
15	bop(>)
16	bop(>=)
17	bop(==)
18	bop(!=)

19	jz
20	jmp
21	ret
22	call
23	exit
24	li
25	sp+c
26	ncall

*/
int bop_table[256];
std::unordered_map<Int,Int> label_map;

struct Init{
	Init(){
		for(int i=0;i<256;++i)bop_table[i]=-1;
		bop_table['+']=3;
		bop_table['-']=4;
		bop_table['*']=5;
		bop_table['/']=6;
		bop_table['%']=7;
		
		bop_table['^']=8;
		bop_table['&']=9;
		bop_table['|']=10;
		
		bop_table['<']=-2;
		bop_table['>']=-2;
		bop_table['=']=-2;
		bop_table['!']=-2;
	}
}__;

void check_addr(addr_t a){
	Assert(a.type==0||a.type==1);
}
void add_instr(Int opcode,Int op1,Int op2,Int op3){
	instr.push_back(Instr{opcode,op1,op2,op3});
}

void li_instr(addr_t c,Int a){
	check_addr(c);
	add_instr(24,c,a,0);
}
void uop_instr(addr_t c,int uop,addr_t a){
	check_addr(c);
	Assert(uop>=0&&uop<=2);
	check_addr(a);
	add_instr(uop,c,a,0);
}
void bop_instr(addr_t c,int bop,addr_t a,addr_t b){
	check_addr(c);
	Assert(bop>=3&&bop<=18);
	check_addr(a);
	check_addr(b);
	add_instr(bop,c,a,b);
}

void jz(addr_t a,Int label){
	check_addr(a);
	add_instr(19,label,a,0);
}
void jmp(Int label){
	add_instr(20,label,0,0);
}
void ret_instr(){
	add_instr(21,0,0,0);
}
void call_instr(Int sp,Int label){
	add_instr(22,label,sp,0);
}
void native_call_instr(Int type,addr_t op1){
	add_instr(26,op1,type,0);
}
void put_label(Int label){
	if(label_map.count(label)){
		Assert(0);
	}
	label_map[label]=instr.size();
}
void exit_instr(){
	add_instr(23,0,0,0);
}

struct Parse{
	const char *s;
	int getBop(){
		if(!*s||isspace(*s))return -1;
		int w=bop_table[unsigned(*s++)];
		if(w==-2)
		switch(s[-1]){
			case '<':{
				if(*s=='<'){++s;return 11;}
				if(*s=='='){++s;return 14;}
				return 13;
			}
			case '>':{
				if(*s=='>'){++s;return 12;}
				if(*s=='='){++s;return 16;}
				return 15;
			}
			case '=':{
				expect('=');
				return 17;
			}
			case '!':{
				expect('=');
				return 18;
			}
			default:Assert(0);
		}
		return w;
	}
	Parse(const char *s0){
		s=s0;
		if(isEnd())return;
		if(isAddr()){
			auto op1=expectAddr();
			expect('=');
			if(isAddr()){
				auto op2=expectAddr();
				int bop=getBop();
				if(bop!=-1){
					auto op3=expectAddr();
					expectEnd();
					bop_instr(op1,bop,op2,op3);
				}else{
					expectEnd();
					uop_instr(op1,0,op2);
				}
			}else if(isInt()){
				auto x=expectInt();
				expectEnd();
				li_instr(op1,x);
			}else if(*s=='&'){
				++s;
				auto op2=expectAddr();
				expectEnd();
				Assert(!op2.type);
				add_instr(25,op1,op2.offset,0);
			}else if(*s=='-'||*s=='!'){
				char c=*s;
				++s;
				auto op2=expectAddr();
				expectEnd();
				uop_instr(op1,c=='-'?1:2,op2);
			}else Assert(0);
		}else if(isInt()){
			auto x=expectInt();
			expect(':');
			expectEnd();
			put_label(x);
		}else if(*s=='i'){
			expect("if ");
			auto op1=expectAddr();
			expect(" goto ");
			auto x=expectInt();
			expectEnd();
			jz(op1,x);
		}else if(*s=='g'){
			expect("goto ");
			auto x=expectInt();
			expectEnd();
			jmp(x);
		}else if(*s=='r'){
			expect("ret");
			expectEnd();
			ret_instr();
		}else if(*s=='c'){
			expect("call ");
			auto label=expectInt();
			expect(' ');
			auto sp=expectInt();
			expectEnd();
			call_instr(sp,label);
		}else if(*s=='e'){
			expect("exit");
			expectEnd();
			exit_instr();
		}else if(*s=='n'){
			expect("ncall ");
			auto type=expectInt();
			expect(' ');
			auto op1=expectAddr();
			expectEnd();
			native_call_instr(type,op1);
		}else Assert(0);
	}
	bool isEnd(){
		while(*s&&isspace(*s))++s;
		return *s=='#'||!*s;
	}
	void expectEnd(){
		Assert(isEnd());
	}
	void expect(const char *c){
		while(*c)expect(*c++);
	}
	void expect(char c){
		Assert(*s++==c);
	}
	bool isInt(){
		return *s=='-'&&isdigit(s[1])||isdigit(*s);
	}
	Int expectInt(){
		Int x=0;
		bool neg=0;
		if(*s=='-'){
			++s;
			neg=1;
		}
		Assert(isdigit(*s));
		while(isdigit(*s)){
			x=x*10+*s++-'0';
		}
		if(neg)x=-x;
		return x;
	}
	bool isAddr(){
		return *s=='S'||*s=='M';
	}
	addr_t expectAddr(){
		if(*s=='S'){
			expect("S[");
			auto x=expectInt();
			Assert(x==int32_t(x));
			expect(']');
			return {0,int32_t(x)};
		}
		expect("M[S[");
		auto x=expectInt();
		Assert(x==int32_t(x));
		expect("]]");
		return {1,int32_t(x)};
	}
};

void load(){
	Int ln_cnt=0;
	while(!ouf.seekEof()){
		std::string ln=ouf.readLine();
		Assert(ln.size()<=1024);
		Assert(++ln_cnt<=1024);
		Parse(ln.data());
		Assert(instr.size()<=CL);
	}
	add_instr(23,0,0,0);
	for(Instr &x:instr){
		if(x.opcode==19||x.opcode==20||x.opcode==22){
			if(!label_map.count(x.op1)){
				//printf("unknown label: %lld\n",(long long)x.op1);
				Assert(0);
			}
			x.op1=label_map[x.op1];
			Assert(x.op1>=0&&x.op1<instr.size());
		}
	}
}

#define Fe(i,l,r) for(Int i=l;i<=r;++i)
#define Fer(i,l,r) for(Int i=l;i>=r;--i)
	
#define pr(...) //fprintf(stderr,__VA_ARGS__)
	
typedef int64_t Int;

Int read(Int L,Int R){
	return io.read(L,R);
}
void write(Int x){
	io.write(x);
}

namespace TB6{
const Int maxn=1e5,maxm=2e5;
const Int N=maxn+7;
typedef long long i64;
Int a[N];
void solve(){
	Int n=read(1,maxn);
	Int m=read(1,maxm);
	pr("%d %d\n",(int)n,(int)m);
	Fe(i,1,n){
		a[i]=read(-1e12,1e12);
		pr("%ld\n",a[i]);
	}
	Fe(_,1,m){
		Int o=read(1,2),l=read(1,n),r=read(l,n);
		if(o==1){
			Int x=read(-1e6,1e6);
			pr("1 %ld %ld %ld\n",l,r,x);
			Fe(i,l,r)a[i]+=x;
		}else{
			Int ans=0,s=0;
			Fe(i,l,r){
				s=std::max(Int(0),s+a[i]);
				ans=std::max(ans,s);
			}
			write(ans);
			pr("2 %ld %ld ans=%ld\n",l,r,ans);
		}
	}
}
}

std::mt19937 mt(1234);

namespace MM{
const Int maxn=1e3,maxv=1e3;
const Int N=maxn+7;
Int a[N][N],b[N][N],c[N][N];
void solve(){
	Int in=read(1,maxn);
	Int jn=read(1,maxn);
	Int kn=read(1,maxn);
	Fe(i,1,in)Fe(j,1,jn)a[i][j]=read(0,maxv);
	Fe(j,1,jn)Fe(k,1,kn)b[j][k]=read(0,maxv);
	
	Fe(i,1,in)Fe(k,1,kn)c[i][k]=0;
	Fe(i,1,in)Fe(j,1,jn)Fe(k,1,kn)c[i][k]=std::max(c[i][k],a[i][j]+b[j][k]);
	
	Fe(i,1,in)Fe(k,1,kn){
		write(c[i][k]);
		pr("%d %d: %d\n",(int)i,(int)k,(int)c[i][k]);
	}
}
void gen(Int in,Int jn,Int kn){
	write(in);
	write(jn);
	write(kn);
	Fe(i,1,in)Fe(j,1,jn)write(mt()%(1+maxv));
	Fe(j,1,jn)Fe(k,1,kn)write(mt()%(1+maxv));
}
}

void solve(){
	TB6::solve();
}

const uInt T0=1145141919810;
const uInt M0=150000;
int main(int argc,char **argv){
	registerTestlibCmd(argc,argv);
	inf.readEof();
	ans.readEof();
	TL=T0*2;
	load();
	load_end=1;
	double score=0,scores[16];
	int T=0;
	for(int N:{50,100,150,200}){
		int n1=N,n2=N,n3=N;
		MM::gen(n1,n2,n3);
		auto in=io.readAll();
		io.write(in);
		MM::solve();
		auto ans=io.readAll();
		io.write(in);
		auto res=exec();
		auto out=io.readAll();
		double ac=1;
		if(ans!=out)ac=0;
		double v=ac*std::max(0.,std::min(1.,2-res.first*1./3000000))*std::max(0.,std::min(1.,2-res.second*1./M0));
		printf("%d  %g  %d/%d  %d/%d\n",N,ac,(int)res.first,(int)3000000,(int)res.second,(int)M0);
		printf("%.3lf %.3lf %.3lf\n",std::max(0.,std::min(1.,2-res.first*1./3000000)),std::max(0.,std::min(1.,2-res.second*1./M0)),v);
		score+=v;
		scores[T++]=v*25;
	}
	score/=4;
	quitp(score*100,"%g + %g + %g + %g = %g",scores[0],scores[1],scores[2],scores[3],score*100);
}
