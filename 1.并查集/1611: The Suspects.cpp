#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

const int MAX = 30000;
int parent[MAX+10];
int total[MAX+10];

int getRoot(int a){
    if(parent[a] == a){
        return a;
    }
    return parent[a] = getRoot(parent[a]);
}

void merge(int a, int b){
    int p1 = getRoot(a);
    int p2 = getRoot(b);
    if(p1 == p2){
        return;
    }
    total[p1] += total[p2];
    parent[p2] = p1;
}

int main(){
    int n, m, k;
    while(1){
        cin >> n >> m;
        if(n == 0 && m == 0){
            break;
        }
        for(int i = 0; i < n; i++){
            parent[i] = i; total[i] = 1; //초기화
        }

        for(int i = 0; i<m; i++){
            cin >> k;
            int head;
            cin >> head;
            
            for(int j = 1; j<k; j++){
                int stu;
                cin >> stu;
                merge(head, stu);
            }
        }

        cout << total[getRoot(0)] << endl;
    }
    

}
