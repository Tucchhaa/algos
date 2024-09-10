#include <iostream>
#include <vector>
#include <map>

using namespace std;

using ll = long long;

vector<int> tree;
vector<int> a;

void build_tree(int i, int tl, int tr) {
    if(tl == tr)
        tree[i] = a[tl];
    else {
        int m = (tl + tr) / 2;
        build_tree(i*2, tl, m);
        build_tree(i*2+1, m+1, tr);
        tree[i] = max(tree[i*2], tree[i*2+1]);
    }
}

void update_tree(int i, int tl, int tr, int pos, int val) {
    if(tl == tr)
        tree[i] = val;
    else {
        int m = (tl + tr) / 2;

        if(pos <= m)
            update_tree(i*2, tl, m, pos, val);
        else
            update_tree(i*2+1, m+1, tr, pos, val);

        tree[i] = max(tree[i*2], tree[i*2+1]);
    }
}

int get_tree_val(int i, int tl, int tr, int l, int r) {
    if(l > r)
        return -1;

    if(tl == l && tr == r)
        return tree[i];

    int m = (tl + tr) / 2;

    return max(
        get_tree_val(i*2, tl, m, l, min(r, m)),
        get_tree_val(i*2+1, m+1, tr, max(l, m+1), r)
    );
}

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);

    for(int i=0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> tree(4*n+1);
    build_tree(1, 0, n-1);

    while(q--) {
        int op;

        cin >> op;

        if(op == 0) {
            int from, to;
            cin >> from >> to;

            cout << get_tree_val(1, 0, n-1, from, to) << endl;
        }
        else if (op == 1) { // update
            int ind, val;
            cin >> ind >> val; 

            update_tree(1, 0, n-1, ind, val);
        }
    }

    return 0;
}

/*
10 10
9 72 55 81 9 48 25 44 36 9
1 2 33
1 10 35
2 10 10
2 5 6
1 4 9
2 8 10
1 8 4
2 4 9
2 5 10
2 5 5
*/
