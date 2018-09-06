#include "../base.h"
/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.*/
class Solution
{
  public:
    bool exist(vector<vector<char> > &board, string word)
    {
        int row = board.size();
        if (row == 0)
            return false;
        int column = board[0].size();
        if (column == 0)
            return false;
        vector<vector<int> > foots(row, vector<int> (column,-1));
        DisplayVecofVec(foots);
        DisplayVecofVec(board);
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                if (board[i][j] == word[0])
                {
                    foots[i][j]=0;
                    if (this->find(board, word, 0, i, j, foots))
                        return true;
                    foots[i][j]=-1;
                }
            }
        }
        return false;
    }

  private:
    bool find(vector<vector<char> > &board, string word, int index, int &i, int &j, vector<vector<int> > foots)
    {
        if (index == (word.size() - 1))
        {
            return true;
        }
        else
        {
            index++;
            int t_nTmpi = 0;
            int t_nTmpj = 0;
            t_nTmpi = i;
            t_nTmpj = j - 1;
            if (t_nTmpj >= 0 && (foots[t_nTmpi][t_nTmpj]==-1)&&(board[t_nTmpi][t_nTmpj]==word[index]))
            {
                foots[t_nTmpi][t_nTmpj]=0;
                if (find(board, word, index, t_nTmpi, t_nTmpj,foots))
                    return true;
                foots[t_nTmpi][t_nTmpj]=-1;
                
            }
            t_nTmpi = i - 1;
            t_nTmpj = j;
            if (t_nTmpi >= 0 && (foots[t_nTmpi][t_nTmpj]==-1)&&(board[t_nTmpi][t_nTmpj]==word[index]))
            {
                foots[t_nTmpi][t_nTmpj]=0;
                if (find(board, word, index, t_nTmpi, t_nTmpj, foots))
                    return true;
                foots[t_nTmpi][t_nTmpj]=-1;

            }
            t_nTmpi = i + 1;
            t_nTmpj = j;
            if (t_nTmpi < board.size() && ((foots[t_nTmpi][t_nTmpj]==-1))&&(board[t_nTmpi][t_nTmpj]==word[index]))
            {
                foots[t_nTmpi][t_nTmpj]=0;
                if (find(board, word, index, t_nTmpi, t_nTmpj, foots))
                    return true;
                foots[t_nTmpi][t_nTmpj]=-1;
            }
            t_nTmpi = i;
            t_nTmpj = j + 1;
            if (t_nTmpj < board[0].size()&& ((foots[t_nTmpi][t_nTmpj]==-1))&&(board[t_nTmpi][t_nTmpj]==word[index]))
            {
                foots[t_nTmpi][t_nTmpj]=0;
                if (find(board, word, index, t_nTmpi, t_nTmpj, foots))
                    return true;
                foots[t_nTmpi][t_nTmpj]=-1;
            }
        }
        return false;
    }
};