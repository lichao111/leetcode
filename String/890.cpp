#include "../base.h"
/*
Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
Output: ["mee","aqq"]
Explanation: "mee" matches the pattern because there is a permutation {a -> m, b -> e, ...}. 
"ccc" does not match the pattern because {a -> c, b -> c, ...} is not a permutation,
since a and b map to the same letter.
*/

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> t_nRet;
        map<char,char> t_nTmp1;
        map<char,char> t_nTmp2;
        bool ok = true;
        std::map<char,char>::iterator it;
        for(int i = 0;i<words.size();i++)  {
            if(words[i].size()!=pattern.size()){
                continue;
            }
            for(int j =0;j<words[i].size();j++){
                it = t_nTmp1.find(pattern[j]);
                if(it!=t_nTmp1.end()){//Find
                    if(t_nTmp1[pattern[j]]==words[i][j])
                    {
                        continue;
                    }
                    else{
                        ok = false;
                    }
                }
                else{
                    t_nTmp1[pattern[j]]=words[i][j];
                }
                                it = t_nTmp2.find(words[i][j]);
                if(it!=t_nTmp2.end()){//Find
                    if(t_nTmp2[words[i][j]]==pattern[j])
                    {
                        continue;
                    }
                    else{
                        ok = false;
                    }
                }
                else{
                    t_nTmp2[words[i][j]]=pattern[j];
                }
            }
            if(ok)
            {
                t_nRet.push_back(words[i]);
                
            }
            t_nTmp1.clear();
            t_nTmp2.clear();
            ok = true;

        }
        return t_nRet;
    }
};
