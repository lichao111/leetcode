#include "../base.h"

/*
Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"*/
class Solution {
public:
    string addBinary(string a, string b) {
        string t_strRet="";
        char t_ctmp ='0';
        int i=a.size()-1,j=b.size()-1;
        for(;i>=0&&j>=0;--i,--j){
            if(t_ctmp=='0'){
                if(a[i]=='1'&&b[j]=='1'){
                    t_strRet = '0'+t_strRet;
                    t_ctmp = '1';
                }
                else if(a[i]=='0'&&b[j]=='0'){
                    t_strRet = '0'+t_strRet;
                    t_ctmp = '0';
                }
                else{
                    t_strRet = '1'+t_strRet;
                    t_ctmp = '0';
                }
            }
            else{
                if(a[i]=='1'&&b[j]=='1'){
                    t_strRet = '1'+t_strRet;
                    t_ctmp = '1';
                }
                else if(a[i]=='0'&&b[j]=='0'){
                    t_strRet ='1'+ t_strRet;
                    t_ctmp = '0';
                }
                else{
                    t_strRet = '0'+t_strRet;
                    t_ctmp = '1';
                }
            }
        }
        if(i<0){
            for(;j>=0;j--){
                if(b[j]=='1'&&t_ctmp=='1'){
                    t_strRet = '0'+t_strRet;
                    t_ctmp='1';
                }
                else if(b[j]=='0'&&t_ctmp=='0'){
                    t_strRet = '0'+t_strRet;
                    t_ctmp = '0';
                }
                else{
                    t_strRet = '1'+t_strRet;
                    t_ctmp = '0';
                }
            }
        }
        if(j<0){
                for(;i>=0;i--){
                if(a[i]=='1'&&t_ctmp=='1'){
                    t_strRet = '0'+t_strRet;
                    t_ctmp='1';
                }
                else if(a[i]=='0'&&t_ctmp=='0'){
                    t_strRet = '0'+t_strRet;
                    t_ctmp = '0';
                }
                else{
                    t_strRet = '1'+t_strRet;
                    t_ctmp = '0';
                }
            }
        }
        if(t_ctmp=='1'){
            t_strRet = '1'+t_strRet ;
        }
        return t_strRet;
    }

};