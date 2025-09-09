#include <iostream>
#include <stack>
using namespace std;

int evaluatePostfix(string exp) {
    stack<int> st;

    for (char ch : exp) {
        if (isdigit(ch)) {  
            st.push(ch - '0');   
        }
        else {  
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();

            if (ch == '+') st.push(a + b);
            else if (ch == '-') st.push(a - b);
            else if (ch == '*') st.push(a * b);
            else if (ch == '/') st.push(a / b);
        }
    }
    return st.top();
}

int main() {
    string exp;
    cout << "Enter postfix expression: ";
    cin >> exp;

    cout << "Result = " << evaluatePostfix(exp) << endl;
    return 0;
}
