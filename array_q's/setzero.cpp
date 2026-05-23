brute-force approach:
1. Traverse the matrix. Whenever a zero is found, mark its entire row and column to be set to zero later using a special marker value that does not exist in the matrix.
2. After the first traversal, go through the matrix again and set all marked elements to zero.


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int mark= -99999; // assuming this value is not present in the matrix
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    for(int k=0;k<n;k++){
                        if(matrix[i][k]!=0){
                        matrix[i][k]=mark;
                        }
                    }
                    for(int l=0;l<m;l++){
                        if(matrix[l][j]!=0){
                            matrix[l][j]=mark;
                        }
                    }
                    matrix[i][j]=0;
                }
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==mark){
                    matrix[i][j]=0;
                }
            }
        }
        
    }
};
//time complexity: O((m*n)*(m+n)) in worst case
//space complexity: O(1)

better approach:
1. Use two auxiliary arrays to keep track of the rows and columns that need to be set to zero.
2. First, traverse the matrix to identify all the rows and columns that contain a zero and mark them in the auxiliary arrays.
3. Then, traverse the matrix again and set the elements to zero if their corresponding row or column is marked.


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int>m1(m,0);
        vector<int>n1(n,0);

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    m1[i]=1;
                    n1[j]=1;
                }
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(m1[i]==1 || n1[j]==1){
                    matrix[i][j]=0;
                }
            }
        }

    }
};
//time complexity: O(m*n)
//space complexity: O(m+n)  
//intuition:
1. Create two auxiliary arrays to track which rows and columns should be set to zero.   
2. In the first pass, iterate through the matrix to populate these auxiliary arrays whenever a zero is encountered.  
3. In the second pass, use the auxiliary arrays to set the appropriate elements in the matrix to zero.
------------------------------------------------------------------------------

optimal approach:
1. Use the first row and first column of the matrix itself to mark which rows and columns need to be set to zero.
2. Keep a separate variable `col0` to track if the first column needs to be set to zero.
3. Traverse the matrix from (1,1) onwards, and if either the first row or first column is marked, set the current element to zero.
4. Handle the first row and first column separately after processing the rest of the matrix.

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int col0=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    if(j!=0){
                        matrix[0][j]=0;
                    }
                else{
                    col0=0;
                }
                }
            }
        }

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][j]!=0){
                    if(matrix[0][j]==0 || matrix[i][0]==0){
                    matrix[i][j]=0;
                    }
                }
            }
        }

        if(matrix[0][0]==0){
            for(int j=0;j<n;j++){
                matrix[0][j]=0;
            }
        }
        if(col0==0){
            for(int i=0;i<m;i++){
                matrix[i][0]=0;
            }
        }
    }
};
//time complexity: O(m*n)
//space complexity: O(1)
//intuition:
1. Use the first row and first column of the matrix to store markers for which rows and columns should be set to zero.  
2. Use an additional variable to track whether the first column needs to be zeroed out, since it overlaps with the first row marker.  
3. After marking, iterate through the matrix (excluding the first row and column) to set elements to zero based on the markers.
4. Finally, handle the first row and first column based on the markers and the additional variable.
------------------------------------------------------------------------------