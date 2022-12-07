#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>

using namespace std;

const int INF = 1 << 30;
int minV = INF;
int maxV = -INF;

struct Node {
    int l, r;
    int minV, maxV; //구간에서의 최소, 최댓값
    int mid() {
        return (l + r) / 2;
    }
};
Node tree[200010];

void BuildTree(int root, int l, int r) {
    tree[root].l = l;
    tree[root].r = r;
    tree[root].minV = INF;
    tree[root].maxV = -INF;
    if (l != r) { //잎 노드가 아니라면
        int mid = (l + r) / 2;
        BuildTree(2 * root + 1, l, mid);
        BuildTree(2 * root + 2, mid + 1, r);
    }
}

//i번째 숫자에 v 삽입
void insert(int root, int i, int v) {
    if (tree[root].l == tree[root].r) { //leaf node
        tree[root].minV = tree[root].maxV = v;
        return;
    }
    tree[root].minV = min(tree[root].minV, v);
    tree[root].maxV = max(tree[root].maxV, v);
    if (i <= tree[root].mid()) {
        insert(2 * root + 1, i, v);
    }
    else {
        insert(2 * root + 2, i, v);
    }
}

void query(int root, int s, int e) { // 구간 [s, e]에서 최소 값 및 최대 값을 찾는다
    if (tree[root].minV >= minV && tree[root].maxV <= maxV) // 기존에 저장된 최소 및 최대 값이 만족할 경우
        return;
    if (tree[root].l == s && tree[root].r == e) { // 구간이랑 같은 범위일 때
        minV = min(minV, tree[root].minV);
        maxV = max(maxV, tree[root].maxV);
        return;
    }
    if (e <= tree[root].mid())
        query(2 * root + 1, s, e);
    else if (s > tree[root].mid())
        query(2 * root + 2, s, e);
    else {
        query(2 * root + 1, s, tree[root].mid());
        query(2 * root + 2, tree[root].mid() + 1, e);
    }
}

int main() {
    int n, q, h;
    int i, j, k;
    cin >> n >> q;
    BuildTree(0, 1, n);
    for (i = 1; i <= n; i++) {
        cin >> h;
        insert(0, i, h);
    }
    for (i = 0; i < q; i++) {
        int s, e;
        cin >> s >> e;
        minV = INF;
        maxV = -INF;
        query(0, s, e);
        cout << maxV - minV << endl;
    }
    return 0;

}
