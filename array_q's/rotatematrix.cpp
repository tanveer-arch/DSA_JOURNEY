brute force solution for rotating a matrix by 90 degrees clockwise
#include <iostream>
using namespace std;
void rotateMatrix(int matrix[][100], int n) {
    int rotated[100][100];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            rotated[j][n - 1 - i] = matrix[i][j];
        }
    }

    // Copy rotated matrix back to original matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = rotated[i][j];
        }
    }
}

time complexity: O(n^2)
space complexity: O(n^2)

optimized solution for rotating a matrix by 90 degrees clockwise
In this approach, we first transpose the matrix and then reverse each row to achieve the 90-degree rotation.


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<m;j++){
                swap(matrix[i][j],matrix[j][i]);
                    
                }
            }
        
        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }

    }
};

time complexity: O(n^2)
space complexity: O(1)
intuition:
To rotate a matrix by 90 degrees clockwise, we can first transpose the matrix (swap rows with columns) and then reverse each row. This method is efficient and operates in-place, requiring no additional space for another matrix.#include <iostream>

