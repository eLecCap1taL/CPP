#include<bits/stdc++.h>

#define pr(...) //printf("#[%d] ",(int)__LINE__);printf(__VA_ARGS__)

struct StackAllocator{
	struct Seg{
		size_t l,r;
		bool operator<(const Seg &x)const{return l<x.l;}
	};
	std::multiset<Seg> mem;
	size_t top=0;
	size_t alloc(size_t size){
		pr("alloc %d,%d\n",(int)top,(int)size);
		size_t ret=top;
		top+=size;
		return ret;
	}
	void free(size_t x,size_t size){
		mem.insert(Seg{x,x+size});
		while(mem.size()){
			auto it=--mem.end();
			if(it->r==top){
				top=it->l;
				mem.erase(it);
			}else break;
		}
		pr("free %d,%d  top=%d\n",(int)x,(int)size,(int)top);
	}
}stack_allocator;

struct Addr{
	enum AddrType{
		NONE=0,STACK=1,MEM=2
	};
	AddrType type=NONE;
	size_t offset=0;
	void stack_alloc(size_t size){
		type=STACK;
		offset=stack_allocator.alloc(size);
	}
	void free(size_t size){
		switch(type){
			case NONE:{
				break;
			}
			case STACK:
			case MEM:{
				stack_allocator.free(offset,size);
				break;
			}
		}
	}
	bool is_stack_top(){
		return type==STACK && offset==stack_allocator.top-1;
	}
	void reset(){
		*this=Addr();
	}
	friend bool operator==(const Addr &a,const Addr &b){
		return a.type!=NONE&&a.type==b.type&&a.offset==b.offset;
	}
	friend std::ostream &operator<<(std::ostream &os,const Addr &x){
		switch(x.type){
			case NONE:{
				assert(0);
				break;
			}
			case STACK:{
				os<<"S["<<x.offset<<"]";
				break;
			}
			case MEM:{
				os<<"M[S["<<x.offset<<"]]";
				break;
			}
		}
		return os;
	}
};

struct Instr{
	enum Type{
		LI, // op1 = x
		UOP, // op1 = op(op2)
		BOP, // op1 = op(op2,op3)
		NCALL, // ncall x op2
		JZ, // if op2 goto label
		JMP, // goto label
		RET, // ret
		CALL, // call label x
		EXIT, // exit
		LABEL, // label:
	}type;
	const char *op;
	Addr op1,op2,op3;
	int64_t x,label;
	static Instr li(Addr c,int64_t a){
		return Instr{LI,NULL,c,Addr(),Addr(),a,0};
	}
	static Instr uop(Addr c,const char *name,Addr a){
		return Instr{UOP,name,c,a,Addr(),0,0};
	}
	static Instr bop(Addr c,const char *name,Addr a,Addr b){
		return Instr{BOP,name,c,a,b,0,0};
	}
	static Instr ncall(int64_t type,Addr a){
		return Instr{NCALL,NULL,Addr(),a,Addr(),type,0};
	}
	static Instr jz(Addr a,int64_t label){
		return Instr{JZ,NULL,Addr(),a,Addr(),0,label};
	}
	static Instr jmp(int64_t label){
		return Instr{JMP,NULL,Addr(),Addr(),Addr(),0,label};
	}
	static Instr ret(){
		return Instr{RET,NULL,Addr(),Addr(),Addr(),0,0};
	}
	static Instr call(int64_t sp,int64_t label){
		return Instr{CALL,NULL,Addr(),Addr(),Addr(),sp,label};
	}
	static Instr exit(){
		return Instr{EXIT,NULL,Addr(),Addr(),Addr(),0,0};
	}
	static Instr put_label(int64_t label){
		return Instr{LABEL,NULL,Addr(),Addr(),Addr(),0,label};
	}
	friend std::ostream &operator<<(std::ostream &os,const Instr &w){
		w.print(os);
		return os;
	}
	void print(std::ostream &os)const{
		switch(type){
			case LI:{
				os<<op1<<'='<<x<<'\n';
				break;
			}
			case UOP:{
				os<<op1<<'='<<op<<op2<<'\n';
				break;
			}
			case BOP:{
				os<<op1<<'='<<op2<<op<<op3<<'\n';
				break;
			}
			case NCALL:{
				os<<"ncall "<<x<<' '<<op2<<'\n';
				break;
			}
			case JZ:{
				os<<"if "<<op2<<" goto "<<label<<'\n';
				break;
			}
			case JMP:{
				os<<"goto "<<label<<'\n';
				break;
			}
			case RET:{
				os<<"ret\n";
				break;
			}
			case CALL:{
				os<<"call "<<label<<' '<<x<<'\n';
				break;
			}
			case EXIT:{
				os<<"exit\n";
				break;
			}
			case LABEL:{
				os<<label<<":\n";
				break;
			}
		}
	}
};

std::list<Instr> instrs;

struct Var{
	Addr addr;
	friend std::ostream &operator<<(std::ostream &os,const Var &x){
		return os<<x.addr;
	}
};

void li_instr(Addr c,int64_t a){
	instrs.emplace_back(Instr::li(c,a));
	//std::cout<<c<<'='<<a<<'\n';
}
void uop_instr(Addr c,const char *name,Addr a){
	if(!strcmp(name,"+"))name="";
	instrs.emplace_back(Instr::uop(c,name,a));
	//std::cout<<c<<'='<<name<<a<<'\n';
}
void bop_instr(Addr c,const char *name,Addr a,Addr b){
	instrs.emplace_back(Instr::bop(c,name,a,b));
	//std::cout<<c<<'='<<a<<name<<b<<'\n';
}
void native_call_instr(int64_t type,Addr a){
	instrs.emplace_back(Instr::ncall(type,a));
	//std::cout<<"ncall "<<type<<' '<<a<<'\n';
}

#define default_alloc(A) \
	A(){\
		pr("%s: ",#A);\
		addr.stack_alloc(A::size);\
	}\
	~A(){\
		pr("%s: ",#A);\
		addr.free(A::size);\
	}\
	A(Addr a,int):A(){\
		assert(addr.type==Addr::STACK);\
		uop_instr(addr,"+",a);\
		addr.type=Addr::MEM;\
	}\
	A(A &&a){\
		assert(a.addr.is_stack_top());\
		addr=a.addr;\
		a.addr.reset();\
	}
	
#define default_value_copy(A) \
	A(const A &a):A(){*this=a;}\
	A(const Addr &a):A(){\
		uop_instr(addr,"+",a);\
	}\
	A(Addr &&a):A(){\
		addr=a;\
		a.type=Addr::NONE;\
	}\
	const A &operator=(const A &a)const{\
		uop_instr(addr,"+",a.addr);\
		return *this;\
	}\
	const A &operator=(A &&a)const{\
		if(!instrs.empty()){\
			auto &w=instrs.back();\
			if(w.op1==a.addr){\
				w.op1=addr;\
				return *this;\
			}\
		}\
		uop_instr(addr,"+",a.addr);\
		return *this;\
	}\
	static constexpr size_t size=1;

#define op_eq(T,T2,op,op_eq) \
	const T &operator op_eq(const T2 &a)const{\
		*this=*this op a;\
		return *this;\
	}

/*template<class T>
struct Ref:Var{
	default_alloc(Ref)
	//default_value_copy(Ref)
	
	T value(){
		T c;
		
		return c;
	}
};*/

struct Int:Var{
	default_alloc(Int)
	default_value_copy(Int)
	
	Int(int64_t a):Int(){*this=a;}
	const Int &operator=(int64_t a){
		li_instr(addr,a);
		return *this;
	}
/*	Int &operator=(const Ref<Int> &a){
		Addr x=a.addr;
		x.type=Addr::MEM;
		uop_instr(addr,"+",x);
	}*/
	
	#define uop(op) \
	friend Int operator op(const Int &a){\
		Int c;\
		uop_instr(c.addr,#op,a.addr);\
		return c;\
	}
	uop(+)
	uop(-)
	uop(!)
	
	#undef uop
	
	
	#define bop(op) \
	friend Int operator op(const Int &a,const Int &b){\
		Int c;\
		bop_instr(c.addr,#op,a.addr,b.addr);\
		return c;\
	}
	bop(+)
	bop(-)
	bop(*)
	bop(/)
	bop(%)
	
	bop(^)
	bop(&)
	bop(|)
	
	bop(<<)
	bop(>>)
	
	bop(<)
	bop(<=)
	bop(>)
	bop(>=)
	bop(==)
	bop(!=)
	
	#undef bop
	
	#define bopeq(op,opeq) \
	friend const Int &operator opeq(const Int &a,const Int &b){\
		bop_instr(a.addr,#op,a.addr,b.addr);\
		return a;\
	}
	bopeq(+,+=)
	bopeq(-,-=)
	bopeq(*,*=)
	bopeq(/,/=)
	bopeq(%,%=)
	
	bopeq(^,^=)
	bopeq(&,&=)
	bopeq(|,|=)
	
	bopeq(<<,<<=)
	bopeq(>>,>>=)
	#undef bopeq
};

template<class T>
struct Ptr:Var{
	default_alloc(Ptr)
	default_value_copy(Ptr)

	Ptr(const T &a):Ptr(){
		*this=a;
	}
	Ptr &operator=(const T &a){
		set_addr(a.addr);
		return *this;
	}
	T operator*()const{
		return T(addr,0);
	}
	/*Ref<T> operator*(){
		return Ref<T>(addr);
	}*/
	void set_addr(Addr a){
		switch(a.type){
			case Addr::NONE:{
				assert(0);
				break;
			}
			case Addr::STACK:{
				uop_instr(addr,"&",a);
				break;
			}
			case Addr::MEM:{
				a.type=Addr::STACK;
				uop_instr(addr,"+",a);
				break;
			}
		}
	}
	
	T operator[](const Int &a)const{
		return *(*this+a);
	}
	
	friend Ptr operator+(const Ptr &a,const Int &b){
		if(T::size==1){
			Ptr c;
			bop_instr(c.addr,"+",a.addr,b.addr);
			return c;
		}
		return Ptr((Int(a.addr)+b*T::size).addr);
	}
	friend Ptr operator+(const Int &b,const Ptr &a){
		return a+b;
	}
	friend const Ptr &operator+=(const Ptr &a,const Int &b){
		if(T::size==1){
			bop_instr(a.addr,"+",a.addr,b.addr);
			return a;
		}
		a=a+b;
		return a;
	}
	friend Ptr operator-(const Ptr &a,const Int &b){
		if(T::size==1){
			Ptr c;
			bop_instr(c.addr,"-",a.addr,b.addr);
			return c;
		}
		return Ptr((Int(a.addr)-b*T::size).addr);
	}
	friend Int operator-(const Ptr &a,const Ptr &b){
		if(T::size==1){
			Int c;
			bop_instr(c.addr,"-",a.addr,b.addr);
			return c;
		}
		return (Int(a.addr)-Int(b.addr))/T::size;
	}
	
	#define bop(op) \
	friend Int operator op(const Ptr &a,const Ptr &b){\
		Int c;\
		bop_instr(c.addr,#op,a.addr,b.addr);\
		return c;\
	}
	
	bop(<)
	bop(<=)
	bop(>)
	bop(>=)
	bop(==)
	bop(!=)
	
	#undef bop
	
	op_eq(Ptr,Int,-,-=)
};

template<class T,size_t n>
struct Array:Var{
	default_alloc(Array)
	
	Array(const Array &a)=delete;
	
	static constexpr size_t size=n*T::size;
	
	operator Ptr<T>()const{
		Ptr<T> c;
		c.set_addr(addr);
		return c;
	}
	
	T operator[](const Int &a)const{
		return *(*this+a);
	}
	
	friend Ptr<T> operator+(const Array &a,const Int &b){
		if(T::size==1){
			Ptr<T> c;
			c.set_addr(a.addr);
			bop_instr(c.addr,"+",c.addr,b.addr);
			return c;
		}
		return Ptr<T>((Int(((Ptr<T>)a).addr)+b*T::size).addr);
	}
	friend Ptr<T> operator+(const Int &b,const Array &a){
		return a+b;
	}
	friend Ptr<T> operator-(const Array &a,const Int &b){
		return Ptr<T>((Int(((Ptr<T>)a).addr)-b*T::size).addr);
	}
};

#undef op_eq


#define If(x) ctrl_if(x); {{
#define Elif(x) }}ctrl_elif(x);{{
#define Else }}ctrl_else();{{
#define End }}ctrl_end();
#define While(x) {\
	int _continue=ctx.label++;\
	put_label(_continue);\
	ctrl_while(_continue,x); {
#define For(A,B,C) {\
	int _continue=ctx.label++;\
	int _begin=ctx.label++;\
	A;\
	jmp(_begin);\
	put_label(_continue);\
	C;\
	put_label(_begin);\
	ctrl_while(_continue,B); {
#define Break ctrl_break();
#define Continue ctrl_continue();
#define Func(name,...) {Int __ra;Int __old_sp;ctrl_func(#name);__VA_ARGS__;{
#define Call(name,...) ctrl_call(#name,__VA_ARGS__)
#define Return ctrl_return()
#define Exit ctrl_exit()

struct Ctrl{
	enum State{
		IF,WHILE
	}state;
	int label1,label2;
};

struct Context{
	const char *func=NULL;
	std::vector<Ctrl> ctrl,loop;
	int label=1;
	std::map<std::string,int> func_label;
	int get_label(const char *fn){
		int &w=func_label[fn];
		if(!w)w=label++;
		return w;
	}
	~Context(){
		assert(!func);
	}
}ctx;

void jz(const Int &a,int64_t label){
	instrs.emplace_back(Instr::jz(a.addr,label));
	//std::cout<<"if "<<a<<" goto "<<label<<'\n';
}
void jmp(int64_t label){
	instrs.emplace_back(Instr::jmp(label));
	//std::cout<<"goto "<<label<<'\n';
}
void ret_instr(){
	instrs.emplace_back(Instr::ret());
	//std::cout<<"ret"<<'\n';
}
void call_instr(int64_t sp,int64_t label){
	//Int ra;
	//Int old_sp;
	instrs.emplace_back(Instr::call(sp,label));
	//std::cout<<"call "<<label<<' '<<sp<<'\n';
}
void exit_instr(){
	instrs.emplace_back(Instr::exit());
	//std::cout<<"exit"<<'\n';
}
void put_label(int64_t label){
	instrs.emplace_back(Instr::put_label(label));
	//std::cout<<label<<":\n";
}

void ctrl_if(const Int &a){
	pr("if\n");
	int _else=ctx.label++;
	int _endif=ctx.label++;
	jz(a,_else);
	ctx.ctrl.push_back(Ctrl{Ctrl::IF,_else,_endif});
}
void ctrl_elif(const Int &a){
	pr("else if\n");
	assert(ctx.ctrl.size());
	auto &w=ctx.ctrl.back();
	switch(w.state){
		case Ctrl::IF:
			jmp(w.label2);
			put_label(w.label1);
			w.label1=ctx.label++;
			jz(a,w.label1);
			break;
		default:
			assert(0);
	}
}
void ctrl_else(){
	pr("else\n");
	assert(ctx.ctrl.size());
	auto &w=ctx.ctrl.back();
	switch(w.state){
		case Ctrl::IF:
			jmp(w.label2);
			put_label(w.label1);
			w.label1=0;
			break;
		default:
			assert(0);
	}
}
void ctrl_end(){
	if(ctx.ctrl.empty()){
		pr("end func\n");
		assert(ctx.func);
		ret_instr();
		ctx.func=NULL;
		
		for(const Instr &x:instrs){
			std::cout<<x;
		}
		instrs.clear();
		return;
	}
	auto &w=ctx.ctrl.back();
	switch(w.state){
		case Ctrl::IF:
			pr("end if\n");
			if(w.label1)put_label(w.label1);
			put_label(w.label2);
			ctx.ctrl.pop_back();
			break;
		case Ctrl::WHILE:
			pr("end while\n");
			jmp(w.label1);
			put_label(w.label2);
			ctx.ctrl.pop_back();
			ctx.loop.pop_back();
			break;
		default:
			assert(0);
	}
}
void ctrl_while(int _continue,const Int &a){
	pr("while\n");
	int _break=ctx.label++;
	jz(a,_break);
	ctx.ctrl.push_back(Ctrl{Ctrl::WHILE,_continue,_break});
	ctx.loop.push_back(Ctrl{Ctrl::WHILE,_continue,_break});
}
void ctrl_break(){
	pr("break\n");
	assert(ctx.loop.size());
	jmp(ctx.loop.back().label2);
}
void ctrl_continue(){
	pr("continue\n");
	assert(ctx.loop.size());
	jmp(ctx.loop.back().label1);
}
void ctrl_func(const char *name){
	pr("func %s\n",name);
	assert(!ctx.func);
	ctx.func=name;
	put_label(ctx.get_label(name));
}
int arg_pos=0;
void ctrl_call_args(const char *name){
}
template<class T>
void ctrl_call_args(const char *name,const T &x){
	pr("arg %d\n",++arg_pos);
	T arg=x;
	ctrl_call_args(name);
}
template<class T,class ... Ts>
void ctrl_call_args(const char *name,const T &x,const Ts &... xs){
	pr("arg %d\n",++arg_pos);
	T arg=x;
	ctrl_call_args(name,xs...);
}
template<class ... Ts>
void ctrl_call(const char *name,const Ts & ... xs){
	pr("call %s\n",name);
	size_t sp=stack_allocator.top;
	Int ra;
	Int old_sp;
	arg_pos=0;
	ctrl_call_args(name,xs...);
	call_instr(sp,ctx.get_label(name));
}
void ctrl_return(){
	pr("return\n");
	assert(ctx.func);
	ret_instr();
}
void ctrl_exit(){
	pr("exit\n");
	assert(ctx.func);
	exit_instr();
}

void Read(const Ptr<Int> &x){
	pr("read\n");
	native_call_instr(1,x.addr);
}
void Write(const Int &x){
	pr("write\n");
	native_call_instr(2,x.addr);
}
void Solve(){
	pr("solve\n");
	Int x;
	native_call_instr(3,x.addr);
}



#define Fe(i,l,r) For(Int i=l,i<=r,i+=_1)

void W(){}
template<class ... T>
void W(const Int &x,const T & ... xs){
	Write(x);
	W(xs...);
}

int main(){
	freopen("tungtungtungsahur.in","r",stdin);
	freopen("tungtungtungsahur.out","w",stdout);
const int N=207;
Func(main,)
	Array<Array<Int,N>,N> a;
	Array<Array<Int,N>,N> b;
	Int in,jn,kn;
	Int _1=1;
	
	Read(in);
	Read(jn);
	Read(kn);
	
	Fe(i,1,in)
		// Ptr<Int> ai=a[i];
		Fe(j,1,jn)
			Read(a[i][j]);
		End
	End
	Fe(j,1,jn)
		// Ptr<Int> bj=b[j];
		Fe(k,1,kn)
			Read(b[k][j]);
		End
	End

	constexpr int B=5;
	Int jn_B=jn/B;

	//work A
	Fe(i,1,in)
		Fe(j,0,jn_B-1)
			Int x=0;
			Fe(k,1,B)
				x=(x<<11)+a[i][j*B+k];
			End
			a[i][j+1]=x;
		End
	End

	//work B
	Fe(i,1,kn)
		Fe(j,0,jn_B-1)
			Int x=0;
			Fe(k,1,B)
				x=(x<<11)+b[i][j*B+k];
			End
			b[i][j+1]=x;
		End
	End
	
	// an example of Solve()
	// W(5,1);
	// W(1,3,-2,4,-5);
	// W(2,2,5);
	// Solve();
	// Int c_;
	// Read(c_);
	// If(c_!=5)
	// 	Return;
	// End
	
	Int c=0;
	Fe(i,1,in)
		Ptr<Int> ai=a[i];
		Fe(k,1,kn)
			Ptr<Int> bk=b[k];
			c=0;
			Fe(j,1,jn_B)
				Int v=ai[j]+bk[j];
				Fe(bit,1,B)
					If((v&((1<<11)-1))>c)
						c=(v&((1<<11)-1));
					End
					v>>=11;
				End
			End
			Write(c);
		End
	End
End

	return 0;
}