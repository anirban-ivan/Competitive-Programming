#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>ordered_set;

main()
{
    ordered_set os;
    //os.order_of_key(x)=the number of elements strictly less than x in the os
    //os.find_by_order(k)=iterator to kth largest element(indexing from 0)
}
