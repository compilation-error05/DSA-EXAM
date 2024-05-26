#include<iostream>
#include<stack>
using namespace std;
bool isoperand(char c){
    if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9' )){
        return true;
    }
    return false;
}
int precedence(char c){
    if (c == '^') {
        return 3;
    }
    else if (c == '/' || c == '*') {
        return 2;
    }
    else if (c == '+' || c == '-') {
        return 1;
    }
    else {
        return 0;
    }
}
string inTOpre(string s){
    stack<char> st;
    string post;
    for(int i=0;i<s.length();i++){
        if(isoperand(s[i])){
            post=post+s[i];
        }
        else if(s[i]=='('){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            while(st.top() != '('){
            char a=st.top();
            post =post+a;
            st.pop();
            }
            st.pop();//to remove the opening bracket
        }
        else{
            while(!st.empty() && precedence(s[i])<=precedence(st.top())){
            post+= st.top();//aggey jjar precedence boro taake add korlam then
            st.pop();
            }
        }
        st.push(s[i]);//then current taa add korlam stack aa   
    }
    while (!st.empty()) {
        post+= st.top();
        st.pop();
    }
    return post;
}
int main(){
    string emp="a+b*(c^d-e)^(f+g*h)-i";
    cout<<inTOpre(emp);
}