#include <bits/stdc++.h>

using namespace std;
// function to get the precedence of the operator
int getPrec(char a)
{
    if (a == '!')
       return 30;
    else if (a == '&')
       return 20;
    else if (a == '|')
        return 10;
    else
        return -1;
}
/////////////////////////////////////// ToPostFix Fuction IMPLEMENTATION /////////////////////////////////////

stack<char> st;

int len = infixString.length();

string result = "";
for (int i = 0; i < len; i++)
{
    if(infixString[i] == ' ')
    continue;
    else if ((infixString[i] >= 'a' && infixString[i] <= 'z') || (infixString[i] >= 'A' && infixString[i] <= 'Z'))
{
    result += infixString[i];
    result += " ";
}
else if (infixString[i] == '(')
    st.push('(');
       
else if(infixString[i] == ')'){
    while(!st.empty() && st.top() != '('){
        char temp = st.top();
        st.pop();
        result += temp;
        result += " ";
    }
        if(st.empty()){
            return "";
    }
            
        if(st.top() == '('){
            st.pop();
    }
    else{
    return "";
 }
}
else{
    while (!st.empty() && getPrec(infixString[i]) <= getPrec(st.top()))
    {
        char temp = st.top();
        st.pop();
        result += temp;
        result += " ";
    }
st.push(infixString[i]);
        }
    }
}
while (!st.empty()){
    char temp = st.top();
    st.pop();
    result += temp;
    result += " ";
}
return result;
}

////////////////// EvaluateCircuit ///////////////////

int len = postfix.length();
stack<char> st;
bool result;
for (int i = 0; i < len; i++)
{
    if (postfix[i] == ' ')
        continue;
    else if (postfix[i] >= 'a' && postfix[i] <= 'z'){
        st.push(postfix[i]);
    }
    else if (postfix[i] == '!'){
        st.push(postfix[i]);
    }
    else if (postfix[i] == '!'){
        if (st.empty()){
            return false;
        }
        if (st.top() == 'r')
        result = !(result);
    else{
        result = !(value[st.top() - 97]);
        st.pop();
        st.push('r');
        }
    }
    else if (postfix[i] == '&'){
        char ch1, ch2;
        if (st.empty()){
            return false;
        }
    else {
        ch1 = st.top();
        st.poop();
    }
    if(st.empty()){
        return false;
        else{
            ch2 = st.top();
            st.pop();
    }
               if (ch1 == 'r')
    {
    result = result & value[ch2 - 97];
        st.push('r');
    }
        else if (ch2 == 'r')
    {
        result = (value[ch1 - 97] & result);
      st.push('r');
    }
      else
    {
    result = (value[ch1 - 97] & value[ch2 - 97]);
    st.push('r');
    
    }

    }
           else if (postfix[i] == '|')
    {
    char ch1, ch2;
        if (st.empty()){
    return false;
    }
    else{

    ch1 = st.top();
    st.pop();
    }
    if (st.empty())
    {
        return false;
    
    }
    else{
        ch2 = st.top();
        st.pop();
    }
    if (ch1 == 'r')
    {
        result = result & value[ch2 - 97];
            st.push('r');
    }
    else if (ch2 == 'r')
    {
        result = (value[ch1 - 97] & result);
        st.push('r');
    }
    else
    {
        result = (value[ch1 - 97] & value[ch2 - 97]);
        st.push('r');
            }
    }
}
       return result;
}
