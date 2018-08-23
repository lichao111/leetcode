#include "../base.h"

class Solution
{
  public:
    void solveSudoku(vector<vector<char> > &board)
    {
        vector<pair<int,int> > t_nLocate;
        t_nLocate.clear();
        for(int i = 0;i<9;i++) //the coordinate need to fill
        {
            for(int j = 0;j<9;j++)
            {
                if(board[i][j]=='.'){
                    t_nLocate.push_back(make_pair(i,j));
                }
            }
        }
        backtrack(board,t_nLocate,0);

    }

  private:
    bool  backtrack(vector<vector<char> >&board,const vector<pair<int,int> > &t_nLocate,int index)
    {
        if(!iscorrect(board)){
            return false;
        }
        if(!hasPoint(board)){
            return true;
        }
        //DisplayVecofVec(board);
        int i =( t_nLocate[index]).first;
        int j =( t_nLocate[index]).second;
        for(int k = 1;k<=9;k++){
            board[i][j]=(k+'0');
            //cout<<"i "<<i<<endl;
            //cout<<"j "<<j<<endl;
            if(backtrack(board,t_nLocate,index+1)){
                return true;
            }else{
                board[i][j]='.';
            }
        }
        return false;

    }
    bool hasPoint(vector<vector<char> >&board){
        for(int i=0;i<9;i++)
        {
            for(int j =0;j<9;j++){
                if(board[i][j]=='.')
                    return true;
            }
        }
        return false;
    }
    bool iscorrect(vector<vector<char> > &board)
    {
        vector<char> tmp;
        map<char, int> t_mapCount;
        t_mapCount.clear();
        //row
        for (int i = 0; i < 9; i++)
        {
            tmp = board[i];
            for (int j = 0; j < 9; j++)
            {
                t_mapCount[tmp[j]] += 1;
            }
            for (map<char, int>::iterator iter = t_mapCount.begin(); iter != t_mapCount.end(); iter++)
            {
                if ((iter->second) > 1 && ((iter->first) != '.'))
                {
                    return false;
                }
            }
            t_mapCount.clear();
        }
        //column
        for (int i = 0; i < 9; i++)
        {

            for (int j = 0; j < 9; j++)
            {
                t_mapCount[board[j][i]]++;
            }
            for (map<char, int>::iterator iter = t_mapCount.begin(); iter != t_mapCount.end(); iter++)
            {
                if ((iter->second) > 1 && ((iter->first) != '.'))
                {
                    return false;
                }
            }
            t_mapCount.clear();
        }

        //3*3
        int k = 0;
        int l = 0;
        while (l < 9)
        {
            while (k < 9)
            {
                for (int i = l; i < l + 3; i++)
                {
                    for (int j = k; j < k + 3; j++)
                    {
                        t_mapCount[board[i][j]]++;
                    }
                }
                for (map<char, int>::iterator iter = t_mapCount.begin(); iter != t_mapCount.end(); iter++)
                {
                    if ((iter->second) > 1 && ((iter->first) != '.'))
                    {
                        return false;
                    }
                }
                t_mapCount.clear();
                k += 3;
            }
            l += 3;
            k = 0;
        }
        return true;
    }
};