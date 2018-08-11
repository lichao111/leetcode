#include "../base.h"


/*
'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

通配符，说白了一般只用于文件名匹配， 它是由shell解析的。通配符的英文 名是wildcard，就是万用牌的意思，它相当简单，一般来说，*nix系统上面的shell大多将三个特殊符号当作通配符，它们是 * ? [...]， 其中 * 表示匹配任意长度的任意字符； ? 表示匹配一个任意字符， 而[...]则表示匹配括号中列出的字符中的任意一个。

*/
class Solution {
public:
    bool isMatch(string s,string p)//只要在p中有了第二*，第一个*就可以一笔勾销。 不会再有改变第一个星匹配得需要
    {
        int t_nLen1 = s.size();
        int t_nLen2 = p.size();
        int t_nSpostion=0;
        int t_nMathPostion = 0;
        int t_nStarPositonOfP = -1;
        bool has_start = false;
        for(int i = 0;i<t_nLen2-1;) // erase the duplicate '*' 
        {
            if((p[i]=='*')&&(p[i+1]=='*'))
            p.erase(i,1);
            else i++;
        }
        t_nLen2 = p.size();
        int j = 0;
        int i = 0;
        for(;i<t_nLen1&&j<t_nLen2||has_start;)
        {
            cout<<"s[i] "<<s[i]<<endl;
            cout<<"         p[j] "<<p[j]<<endl;
            if(i == t_nLen1) break;
            if(t_nLen2 == j&&!has_start) return false;
            if(j==t_nLen2&&has_start)
            {
                     t_nSpostion = p[t_nStarPositonOfP+1]=='?'?t_nSpostion+1:s.find_first_of(p[t_nStarPositonOfP+1],t_nSpostion+1);
                    if(t_nSpostion==string::npos)
                    {
                        return false;
                    }
                    i = t_nSpostion;
                    j = t_nStarPositonOfP +1;
                    continue;
            }
            if(s[i]==p[j]||p[j]=='?')
            {
                i++;
                j++;
                continue;
            }
            else if(p[j]=='*')
            {
                has_start = true;
                t_nStarPositonOfP = j;
                t_nSpostion = i;
                if(j==t_nLen2-1)
                {
                    return true;
                }
                else{
                    t_nSpostion = p[t_nStarPositonOfP+1]=='?'?i:s.find_first_of(p[t_nStarPositonOfP+1],t_nSpostion);
                    if(t_nSpostion==string::npos) return false;
                    i = t_nSpostion;
                    j ++;
                    continue;
                }
            }
            else 
            {
                if(has_start)
                {
                    t_nSpostion = p[t_nStarPositonOfP+1]=='?'?t_nSpostion+1:s.find_first_of(p[t_nStarPositonOfP+1],t_nSpostion+1);
                    if(t_nSpostion==string::npos) return false;
                    i = t_nSpostion;
                    j = t_nStarPositonOfP +1;
                }
                else
                {
                    return false;
                }
            }
        }
        if(i!=t_nLen1) return false;
        while(j<t_nLen2)
        {
            if(p[j++]!='*')
            {
                return false;
            }
        }
        return true;
    }
};