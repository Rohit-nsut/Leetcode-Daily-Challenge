#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/parsing-a-boolean-expression/
// 1106

// T.C -> O(n);
// S.C -> O(n);

class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char>st;

        int n = expression.size();
        vector<char>v;

        for(int i=0;i<n;i++){

            while(expression[i] != ')'){

                if(expression[i] == ','){
                    i++;
                    continue;
                }

                if(expression[i] == '&' || expression[i] == '!' || expression[i] == '|'){
                    v.push_back(expression[i]);
                    i++;
                    continue;
                }

                st.push(expression[i]);
                i++;
            }

            char ch = v.back();
            v.pop_back();

            while(true){
                
                char a = st.top();
                st.pop();

                if(ch == '!'){
                    st.pop();
                    if(a == 't'){
                        st.push('f');
                    }
                    else
                    st.push('t');

                    break;
                }
                
                if(!st.empty() && st.top() != 'f' && st.top() != 't'){
                    st.pop();
                    st.push(a);
                    break;
                }

                char b = st.top();
                st.pop();

                if(ch == '&'){
                    if(a == 'f' || b == 'f'){
                        st.push('f');
                    }
                    else
                    st.push('t');
                }
                else {
                    if(a == 'f' && b == 'f'){
                        st.push('f');
                    }
                    else
                    st.push('t');
                }

            }

        }

        if(st.top() == 'f')
        return false;

        return true;
        
    }
};