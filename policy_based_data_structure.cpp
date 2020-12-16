#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
#include <ext/rope>

using namespace std;

using namespace __gnu_pbds;

using prefix_trie =
    __gnu_pbds::trie<string, null_type, trie_string_access_traits<>,
                     pat_trie_tag, trie_prefix_search_node_update>;

template <typename T>
using indexed_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag,
                                     tree_order_statistics_node_update>;

template <typename T>
using binomial_heap = __gnu_pbds::priority_queue<T, less<T>, binomial_heap_tag>;

template <typename T>
using binary_heap = __gnu_pbds::priority_queue<T, less<T>, binary_heap_tag>;

template <typename T>
using rc_binomial_heap =
    __gnu_pbds::priority_queue<T, less<T>, rc_binomial_heap_tag>;

template <typename T>
using pairing_heap = __gnu_pbds::priority_queue<T, less<T>, pairing_heap_tag>;

template <typename T>
using thin_heap = __gnu_pbds::priority_queue<T, less<T>, thin_heap_tag>;

int main() {
  prefix_trie pt;
  pt.insert("hello");
  for (auto [b, e] = pt.prefix_range("hel"); b != e; ++b) {
    cout << *b << '\n';
  }
  return 0;
}

/*
 * Associative container
 * =====================
 * ## Policy
 * 1. Hash policy
 * 2. Resize policy
 *
 * Erase methods
 * -------------
 * -> Range erase is not supported in both (order preserving and non-order
 * preserving) pb_ds
 * -> Ordering preserving pb_ds have erase method
 * -> Hash based pb_ds do not have erase method
 * -> All pb_ds have erase_if
 * -> For range erase in tree based pb_ds go for split method of tree based
 * pb_ds
 *
 * Insert methods
 * --------------
 * -> For range insert in tree based pb_ds go for join method of tree based
 * pb_ds
 * -> Range insert is not supported by any other pb_ds
 *
 * Comparison methods
 * ------------------
 * -> Comparison of two pb_ds via operator== is not supported
 *
 * Multiple keys
 * -------------
 * -> Multiple keys are not allowed in pb_ds
 *
 * Tree based container
 * ====================
 * -> TREE = KEY + VALUE + META-DATA
 * ## Policy
 * 1.node invariant
 *
 * Under lying data structures for pb_ds associative containers
 * ------------------------------------------------------------
 * 1. Collision chaining hash table
 * 2. Probing hash table
 * 3. RB-tree
 * 4. Splay tree
 * 5. Cartesian tree
 * 6. PATRICIA tree
 * 7. List with node update policy
 *
 * Priority queue
 * ==============
 * -> Change of priority (supported)
 * -> Joining two priority queue (supported)
 * -> Remove arbitrary key (supported)
 * -> STL priority queue do not support iterator
 * -> pb_ds supports iterators
 *
 */

/*
 * Hash based containers
 * =====================
 * 1. basic_hash_table (abstract class)
 * 2. cc_hash_table (collision chaining)
 * 3. gp_hash_table (general probing)
 *
 * Tree based containers
 * ====================
 * 1. basic_tree (abstract class)
 * 2. tree
 * 3. trie
 *
 * List based container
 * ====================
 * 1. list_update (singly list with update policy)
 *
 * Priority queue
 * ==============
 * 1. priority_queue
 *
 *
 * Container tags
 * ==============
 * associaive_container_tag (base class)
 *    |- basic_hash_tag (base class)
 *    |   |- cc_hash_tag
 *    |   `- gp_hash_tag
 *    |
 *    |- basic_tree_tag (base class)
 *    |   |- tree_tag (base)
 *    |   |    |- rb_tree_tag
 *    |   |    |- splay_tree_tag
 *    |   |    `- ov_tree_tag (cartesian tree)
 *    |   |
 *    |   `- trie_tag
 *    |        `- pat_trie_tag
 *    |
 *    `- list_update_tag
 *
 * priority_queue_tag
 *    |- pairing_heap_tag
 *    |- binomial_heap_tag
 *    |- rc_binomial_heap_tag
 *    |- binary_heap_tag
 *    `- thin_heap_tag
 *
 * Useful policies
 * ====================
 * 1. Trie node-update policy
 *    1. trie_prefix_search_node_update
 *    2. trie_order_statics_node_update
 *    3. null_trie_node_update
 *
 * 2. Trie element access trait
 *    1. string_trie_e_access_traits
 *
 * 3. Tree node-update policy
 *    1. tree_order_statistics_node_update
 *
 * 4. List update policy
 *    1. move_to_front_lu_policy
 *    2. counter_lu_policy
 *
 * https://gcc.gnu.org/onlinedocs/libstdc++/ext/pb_ds/interface.html
 * https://gcc.gnu.org/onlinedocs/libstdc++/manual/policy_data_structures_design.html
 *
 */
