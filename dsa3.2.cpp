#include <iostream>
#include <stack>
using namespace std;

int main() {
    string a;
    cout << "Enter a string: ";
    cin >> a;

    stack<char> st;
    for (int i = 0; i < a.length(); i++) {
        st.push(a[i]);
    }
    for (int i = 0; i < a.length(); i++) {
        a[i] = st.top();
        st.pop();
    }
    cout << "Reversed string: " << a << endl;

    return 0;
}