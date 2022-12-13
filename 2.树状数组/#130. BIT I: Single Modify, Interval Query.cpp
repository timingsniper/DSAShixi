//https://loj.ac/p/130
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
const int maxn=1e6+1;
#define LowBit(i) (i&(-i))
#define mem(a) memset(a, 0, sizeof(a))
int n,m;
long long p[maxn];
int a[maxn];

using namespace std;

int lowbit(int x){
    return x&(-x);
}

void update(int x, long long add){
    for(int i=x; i<=n; i+=lowbit(i)){
        p[i] += add;
    }
}

long long query(int x){
    long long answer = 0;
    for(int i=x; i>=1; i-=lowbit(i)){
        answer+=p[i];
    }
    return answer;
}

int main(){
    cin >> n >> m;
    for(int i = 1; i<=n; i++){
        cin >> a[i];
        update(i, a[i]);
    }

    int op, a, b;
    while(m--){
        cin >> op >> a >> b;
        if(op == 1){
            update(a,b);
        }
        else if(op == 2){
            long long ans = query(b)-query(a-1);
            cout << ans << endl;
        }
    }

}
