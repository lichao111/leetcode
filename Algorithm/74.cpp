#include "../base.h"

/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 13
Output: false*/

class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        int row = matrix.size();
        if(row==0) return false;
        int column = matrix[0].size();
        if(column==0) return false;
        int t_nrowLocation = -1;
        if(target<matrix[0][0]||target>matrix[row-1][column-1]) return false;
        for(int i=0;i<row;i++){
            if(target==matrix[i][0]||target==matrix[i][column-1]) return true;
            if(target>matrix[i][0]&&target<matrix[i][column-1]){
                t_nrowLocation = i;
            }
        }
        if(t_nrowLocation == -1) return false;
        cout<<"t_nrowLocation"<<t_nrowLocation<<endl;
        int start = 0;
        int end = column-1;
        int half = -1;
        if(target==matrix[t_nrowLocation][start]||target==matrix[t_nrowLocation][end]) return true;
        while(start!=(end-1)){
            
            half = start + (end-start)/2;
            if(matrix[t_nrowLocation][half]==target) return true;
            if(target>matrix[t_nrowLocation][half]){
                start = half;
            }
            else{
                end = half;
            }
            cout<<"start"<<start<<endl;
            cout<<"end"<<end<<endl;
            //getchar();
            
        }
        return false;
    }
};
