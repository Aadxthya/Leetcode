// Last updated: 9/16/2025, 9:48:13 AM
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <unordered_set>
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <set>
#include <stack>
#include <fstream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bitset>
#include <sstream>
#include <ext/rope>
#include <ctime>
#include <random>
#include <cstdlib>
#include <complex>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

/* clang-format off */

/* TYPES  */
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define vpii vector<pair<int, int>>
#define vpii vector<pair<int, int>>
#define vvpii vector<vector<pair<int, int>>>
#define vpll vector<pair<long long, long long>>
#define vvpll vector<vector<pair<long long, long long>>>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
#define mii map<int, int>
#define si set<int>
#define sc set<char>



/* FUNCTIONS */
#define feach(el, v) for(auto &el: v)
#define rep(i, n) for(int i=0;i<n;i++)
#define reprv(i, n) for(int i=n-1;i>=0;i--)
#define reps(i, s, e) for(int i=s;i<e;i++)
#define reprve(i, e, s) for(int i=e;i>=s;i--)
#define repe(x, y) for (auto &x: y)
#define repe2(x, a, y) for (auto &[x,a]: y)

typedef tree<int, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update> oSet;

const ll MOD = 1e9 + 7;

struct nd {
    ll lr, lplus1r, lrminus1, lplus1rminus1;
};

nd combine (nd a, nd b) {
    ll lr = max(a.lrminus1 + b.lplus1r, a.lr + b.lplus1r);
    lr = max(lr, a.lrminus1 + b.lr);

    ll lplus1r = max(a.lplus1rminus1 + b.lplus1r, a.lplus1r + b.lplus1r);
    lplus1r = max(lplus1r, a.lplus1rminus1 + b.lr);

    ll lrminus1 = max(a.lrminus1 + b.lplus1rminus1, a.lr + b.lplus1rminus1);
    lrminus1 = max(lrminus1, a.lrminus1 + b.lrminus1);

    ll lplus1rminus1 = max(a.lplus1rminus1 + b.lplus1rminus1, a.lplus1r + b.lplus1rminus1);
    lplus1rminus1 = max(lplus1rminus1, a.lplus1rminus1 + b.lrminus1);

    return {
        lr % MOD, lplus1r % MOD, lrminus1 % MOD, lplus1rminus1 % MOD
    };
}

class Solution {
public:
    void build(vector<nd> &stree, vi &vec, int v, int tl, int tr) {
        if (tl == tr) {
            stree[v] = {
                    max(0, vec[tl]), 0, 0, 0
            };
            return;
        }
        int tm = (tl + tr) >> 1;
        build(stree, vec, v << 1, tl, tm);
        build(stree, vec, v << 1 | 1, tm + 1, tr);

        stree[v] = combine(stree[v << 1], stree[v << 1 | 1]);
    }

    void update(vector<nd> &stree, int pos, int val, int v, int tl, int tr) {
        if (tl == tr) {
            stree[v] = {
                    max(0, val), 0, 0, 0
            };
            return;
        }

        int tm = (tl + tr) >> 1;
        if (pos <= tm) update(stree, pos, val, v << 1, tl, tm);
        else update(stree, pos, val, v << 1 | 1, tm + 1, tr);

        stree[v] = combine(stree[v << 1], stree[v << 1 | 1]);
    }

    ll query(vector<nd> &stree) {
        ll ans = max(stree[1].lr, stree[1].lplus1r);
        ans = max(ans, stree[1].lrminus1);
        ans = max(ans, stree[1].lplus1rminus1);
        return ans;
    }

    int maximumSumSubsequence(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<nd> segtree(4 * n);
        build(segtree, nums, 1, 0, n - 1);

        ll ans = 0;
        int q = queries.size();
        rep(i, q) {
            ll pos = queries[i][0], x = queries[i][1];
            update(segtree, pos, x, 1, 0, n - 1);
            ans += query(segtree);
            ans %= MOD;
        }
        return ans;
    }
};