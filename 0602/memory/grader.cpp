#include <bits/stdc++.h>
using namespace std;

void init(int n, const vector<long long> &a);
long long ask(int l, int r);
vector<long long> askAll(int q, const vector<int> &l, const vector<int> &r);

namespace fastio {

const int buf_size = 1 << 14, small = 30;
char buf_read[buf_size + small];
char buf_write[buf_size + small];
char *ptr_read = buf_read + buf_size;
char *ptr_write = buf_write;

char getChar() {
    if (ptr_read == buf_read + buf_size){
        buf_read[fread(buf_read, 1, buf_size, stdin)] = 0;
        ptr_read = buf_read;
    }
    return *ptr_read++;
};

inline bool is_whitespace(char c) {
    return c == ' ' || c == '\r' || c == '\n';
}

char read_char() {
    char c = getChar();
    while (is_whitespace(c)) {
        c = getChar();
    }
    return c;
}

string read_string() {
    string res;
    char c = read_char();
    do {
        res += c;
        c = getChar();
    } while (c && !is_whitespace(c));
    return res;
}

long long read_int() {
    char c = getChar();
    while (c && (c < '0' || c > '9') && c != '-') {
        c = getChar();
    }
    long long z = 1;
    if (c == '-') {
        z = -1;
        c = getChar();
    }
    long long res = 0;
    while (c >= '0' && c <= '9'){
        res = res * 10 + (c - '0');
        c = getChar();
    }
    return z * res;
}

void write_flush() {
    fwrite(buf_write, 1, ptr_write - buf_write, stdout);
    ptr_write = buf_write;
}

void write_int(long long x) {
    if (x < 0) {
        *ptr_write++ = '-';
        x = -x;
    }
    char *start = ptr_write;
    if (!x) {
        *ptr_write++ = '0';
    }
    while (x) {
        *ptr_write++ = x % 10 + '0';
        x /= 10;
    }
    reverse(start, ptr_write);
    if (ptr_write >= buf_write + buf_size) {
        write_flush();
    }
}

void write_char(char c) {
    *ptr_write++ = c;
    if (ptr_write >= buf_write + buf_size) {
        write_flush();
    }
}

void write_string(const string &s) {
    for (char c : s) {
        write_char(c);
    }
}

}

int main(){
	// #ifndef ONLINE_JUDGE
	// #ifndef CPEDITOR
	if(freopen("memory2.in","r",stdin));
	// if(freopen("memory.in","r",stdin));
	if(freopen("memory.out","w",stdout));
	// #endif
	// #endif
    int n, q, t;
    n = fastio::read_int();
    q = fastio::read_int();
    t = fastio::read_int();
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = fastio::read_int();
    }
    vector<int> l(q), r(q);
    for (int i = 0; i < q; i++) {
        l[i] = fastio::read_int();
        r[i] = fastio::read_int();
    }
    init(n, a);
    if (t == 1) {
        vector<long long> result = askAll(q, l, r);
        for (long long a : result) {
            fastio::write_int(a);
            fastio::write_char('\n');
        }
    } else {
        for (int i = 0; i < q; i++) {
            fastio::write_int(ask(l[i], r[i]));
            fastio::write_char('\n');
        }
    }
    fastio::write_flush();
}