#include <iostream>
#include <set>

using namespace std;

void permute(string str, int left, int right, set<string> &unique)  
{  
    if (left == right) {
        unique.insert(str);
    } else {  
        for (int i = left; i <= right; i++) {  
            swap(str[left], str[i]);  
  
            permute(str, left+1, right, unique);  
  
            swap(str[left], str[i]);  
        }  
    }  
}  

int main() {
    string input;
    cin >> input;

    set<string> unique;
    int n = input.size();  

    permute(input, 0, n-1, unique); 

    cout << unique.size() << "\n";

    for(const auto &str : unique) {
        cout << str << endl;
    }

    return 0;
}
