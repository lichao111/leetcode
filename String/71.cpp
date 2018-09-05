#include "../base.h"
/*Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"

Corner Cases:

Did you consider the case where path = "/../"?
In this case, you should return "/".
Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
In this case, you should ignore redundant slashes and return "/home/foo".
*/

class Solution {
public:
    string simplifyPath(string path) {
        int t_nLen = path.size();
        if(t_nLen==0) return "";
        else path += "/";
        vector<string> native;
        vector<string> t_vecBox;
        string tmp="";
        size_t pos= path.find("/")+1;
        size_t pos1 = 0;
        while(1)
        {
            pos1 = path.find("/",pos);
            if(pos1==string::npos) break;
            if(pos1-pos!=0)
            native.push_back(path.substr(pos,pos1-pos));
            pos =  pos1+1;
        }
        for(int i = 0,len = native.size();i<len;i++){
            if(native[i]==".") continue;
            else if(native[i]==".."){
                if(t_vecBox.empty()){
                   continue; 
                }
                else{
                    t_vecBox.pop_back();
                }
            }
            else{
                t_vecBox.push_back(native[i]);
            }
        }
        string t_strRet="";
        if(t_vecBox.empty()) return "/";
        for(int i = 0;i<t_vecBox.size();i++){
            t_strRet += ("/"+t_vecBox[i]);
        }
        
        return t_strRet;
    }
};