#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
 
#define ordered_set                              \
    tree<int, null_type, less<int>, rb_tree_tag, \
         tree_order_statistics_node_update>
 
void josephusOrder(int n, int k) {
    ordered_set circle;

    for (int i = 1; i <= n; ++i) {
        circle.insert(i);
    }
 
    int position = 0;
 
    while (circle.size() > 1) {
        position = (position + k) % (int)circle.size();

        cout << *(circle.find_by_order(position)) << " ";

        circle.erase(*(circle.find_by_order(position)));
 
        position %= (int)circle.size();
    }

    cout << *(circle.find_by_order(0));
}
 
int main() {
    int n;
    long long k;

    cin >> n >> k;
 
    josephusOrder(n, k);

    cout << endl;
 
    return 0;
}