#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

// order_of_key(k): returns the number of elements in the set strictly less than k
// find_by_order(k): returns an iterator to the k-th element (zero-based) in the set
