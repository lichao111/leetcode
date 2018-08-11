#include "../base.h"

class Solution {
public:
    vector<vector<string> > groupAnagrams3(vector<string>& strs) {//O
     map<string, vector<string> > mp;
        vector<vector<string> > result;
        for(int i = 0;i<strs.size();i++)
        {
            string tem = strs[i];
            sort(tem.begin(), tem.end());
            mp[tem].push_back(strs[i]);
        }
        for(map<string,vector<string> >::iterator val=mp.begin();val !=mp.end();val++)
        {
            
            sort((*val).second.begin(), (*val).second.end());
            result.push_back((*val).second);
        }
        return result;
    }
    vector<vector<string> > groupAnagrams2(vector<string>& strs) {//Time limit exceeded
        vector<vector<string> > t_vecRet;
        if(strs.empty()) return t_vecRet;
        vector<string> t_vecTuple;
        bool isMath = false;
        for(int i = 0;i<strs.size();i++)
        {
            isMath = false;
            t_vecTuple.clear();
            for(int j  = 0;j<t_vecRet.size();j++)
            {
                if(isequal(strs[i],t_vecRet[j][0]))
                {
                    t_vecRet[j].push_back(strs[i]);
                    isMath = true;
                    break;
                }
            }
            if(!isMath)
            {
                t_vecTuple.push_back(strs[i]);
                //Display(t_vecTuple);
                t_vecRet.push_back(t_vecTuple);
                
            }
        }
        return t_vecRet;
    }

    vector<vector<string> > groupAnagrams1(vector<string>& strs) {//Time limit exceeded
        
        vector<vector<string> > t_vecRet; 
        if(strs.empty()) return t_vecRet;
        vector<string> t_vecTumple;
        //t_vecTumple.push_back(str[0]);
        for(int i = 0;i<strs.size();)
        {
            //cout<<i<<"-"<<strs.size()<<endl;
            t_vecTumple.clear();
            t_vecTumple.push_back(strs[i]);
            strs.erase(strs.begin());
           // Display(strs);
            for(int j=i;j<strs.size();)
            {
                if(isequal(t_vecTumple[0],strs[j]))
                {
                    t_vecTumple.push_back(strs[j]);
                    strs.erase(strs.begin()+j);
                }
                else{
                    j++;
                }
                //strs.erase(i);
            }
            t_vecRet.push_back(t_vecTumple);
        }
        return t_vecRet;
    }
    bool isequal(string str1,string str2)
    {
        sort(str1.begin(),str1.end());
        sort(str2.begin(),str2.end());
        return str1==str2;
    }
};