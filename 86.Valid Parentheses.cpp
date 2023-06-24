//https://www.codingninjas.com/studio/problems/valid-parentheses_8230714?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include<bits/stdc++.h>
bool isValidParenthesis(string expression)
{
    // Write your code here.
    stack<char>lola;
    for(auto ch:expression){
        if(ch=='('||ch=='[' ||ch=='{')lola.push(ch);
        else {
          if (lola.empty())
            return false;
          char op = lola.top();
          lola.pop();
          if (ch == ')' and op != '(')
            return false;
          else if (ch == '}' and op!='{')return false;
          else if(ch==']' and op!='[')return false;
        }
    }
    return lola.empty();
}
