#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

const int MAX = 31000;
int parent[MAX]; 
//int total[MAX];
//int under[MAX]; //큐브 i 밑에 있는 큐브 개수 표시
int cnt;



int getRoot(int a) {
	if (parent[a] == a) {
	  return a;
  }
  return parent[a] = getRoot(parent[a]);
}

void find(int l, int r){
    int ll = getRoot(l), rr = getRoot(r);
    if(ll == rr){
        cout << "Yes" << endl;
    }
    else{
        parent[rr] = ll;
        cnt--;
        cout << "No" << endl;
    }
}

/*
void merge(int a, int b){
    int p1 = getRoot(a);
    int p2 = getRoot(b);
    if(p1 == p2){
        return;
    }
	parent[getRoot(b)] = getRoot(a);
}*/


int main(){
    while(1){
        int n,m;
        cin >> n >> m;
        for(int i = 1; i<=n; i++){
            parent[i] = i;
        }
        cnt = n;
        for(int i = 1; i<=m; i++){
            int x, y;
            cin >> x >> y;
            find(x,y);
        }
        cout << cnt << endl;
        for(int i = 1; i<=n; i++){
            if(parent[i] == i){
                cout << i << " ";
            }
            
        }
        cout << endl;
    }
    

    
}
