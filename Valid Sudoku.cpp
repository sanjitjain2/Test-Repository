int Solution::isValidSudoku(const vector<string> &a) {
    vector<vector<bool>> check_row(9, vector<bool>(9, false));
    vector<vector<bool>> check_col(9, vector<bool>(9, false));
    vector<vector<bool>> check_box(9, vector<bool>(9, false));
    
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            if (a[i][j] == '.'){
                continue;
            }
            
            int digit = (int)a[i][j] - (int)'0';
            
            if (check_row[i][digit - 1]){
                return false;
            }
            
            check_row[i][digit - 1] = true;
            
            if (check_col[j][digit - 1]){
                return false;
            }
            
            check_col[j][digit - 1] = true;
            
            if (check_box[(i/3)*3 + (j/3)][digit - 1]){
                return false;
            }
            
            check_box[(i/3)*3 + (j/3)][digit - 1] = true;
        }
    }
    return true;
}
