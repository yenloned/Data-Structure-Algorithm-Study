//Question: https://leetcode.com/problems/valid-sudoku/
//n =9x9 = 81 = constant
//Time Complexity: O(n)+O(n)+O(n)=O(1), n = number of cells on the board
//Space Complexity: O(3n) =O(1)
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //Time Complexity: O(n)+O(n)+O(n) = O(3n) = O(n), n = number of cells on the board
        return checkRow(board)&&checkColumn(board)&&checkGrid(board);
    }
    //Time:O(n), n = number of cells on the board
    bool checkRow(vector<vector<char>>& board){
        for(int i=0;i<board.size();i++){
            unordered_set<char> nums;
            for(int u=0;u<board.size();u++){
                //skip cell with '.'
                if(board[i][u] =='.'){
                    continue;
                }
                //return false, if number already exist in row/column/grid
                if(nums.find(board[i][u])!=nums.end()){
                    return false;
                }
                //insert number into hashset to check the occurance of each number
                nums.insert(board[i][u]);
            }
        }
        return true;
    }
    //Time:O(n), n = number of cells on the board
    bool checkColumn(vector<vector<char>>& board){
        for(int i=0;i<board.size();i++){
            unordered_set<char> nums;
            for(int u=0;u<board.size();u++){
                //skip cell with '.'
                if(board[u][i] =='.'){
                    continue;
                }
                //return false, if number already exist in row/column/grid
                if(nums.find(board[u][i])!=nums.end()){
                    return false;
                }
                //insert number into hashset to check the occurance of each number
                nums.insert(board[u][i]);
            }
        }
        return true;
    }
    //Time:O(n), n = number of cells on the board
    bool checkGrid(vector<vector<char>>& board){
        for(int i=0;i<board.size();i++){
            unordered_set<char> nums;
            int temp = i/3;
            //loop each Grid one by one
            /* 
            Gridpos is the coordinate of '1' cell
            check in the following order:
            1 2 3
            4 5 6
            7 8 9
            */
            pair<int,int>Gridpos =make_pair((i%3)*3,(temp*3));
            for(int u=0;u<board.size();u++){
                //skip cell with '.'
                if(board[Gridpos.first+u%3][Gridpos.second+u/3] =='.'){
                    continue;
                }
                //return false, if number already exist in row/column/grid
                if(nums.find(board[Gridpos.first+u%3][Gridpos.second+u/3])!=nums.end()){
                    return false;
                }
                //insert number into hashset to check the occurance of each number
                nums.insert(board[Gridpos.first+u%3][Gridpos.second+u/3]);
            }
        }
        return true;
    }
};