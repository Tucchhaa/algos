#include <iostream>
#include <memory>
#include <vector>

using namespace std;

vector<int> a;
vector<int> fenwick;

int get_range(int l, int r) {
    int from = r & (r + 1);

    if(l == from)
        return fenwick[r];

    if(l > from)
        return fenwick[r] - get_range(from, l-1);

    return fenwick[r] + get_range(l, from-1);
}

void update(int index, int old_val, int val) {
    for(; index < fenwick.size(); index = index | (index + 1))
        fenwick[index] = fenwick[index] - old_val + val;
}

int main() {
    int n;
    cin >> n;

    a.resize(n);
    fenwick.resize(n);

    for(int i=0; i < n; i++) {
        cin >> a[i];

        fenwick[i] = a[i];

        int l = i & (i + 1);
        int r = i - 1;

        if(l <= r) {
            fenwick[i] += get_range(l, r);
        }
    }

    for(int i=0; i < 5; i++) {
        int op;
        cin >> op;

        if(op == 0) { // get
            int from, to;
            cin >> from >> to;

            cout << get_range(from, to);
        }
        else if(op == 1) { // update
            int ind, val;
            cin >> ind >> val;

            update(ind, a[ind], val);
        }

    }

    return 0;
}
/*
10
0 1 2 3 4 5 6 7 8 9
*/
