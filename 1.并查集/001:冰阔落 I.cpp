#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>

using namespace std;

int parent[50005];
int cnt;

int getRoot(int a) {
    if (parent[a] == a) {
        return a;
    }
    //return parent[a] = getRoot(parent[a]);
    return getRoot(parent[a]);
}

void check(int x, int y) {
    int rootOne = getRoot(x);
    int rootTwo = getRoot(y);
    if (rootOne==rootTwo) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
        parent[rootTwo] = rootOne;
        cnt--;
    }
}

int main() {
    int n, m;
    int x, y;
    while (scanf("%d %d", &n, &m) != EOF) {
        //cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
        cnt = n;
        for (int i = 1; i <= m; i++) {
            
            cin >> x >> y;
            check(x, y);
        }
        cout << cnt << endl;
        for (int i = 1; i <= n; i++) {
            if (parent[i] == i) {
                cout << i << " ";
            }
        }
        cout << endl;
    }
}
