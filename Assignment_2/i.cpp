#include <iostream>
#include <vector>
#include <algorithm> // for std::find

using namespace std;

// Function to swap two rows in a matrix
void swapRows(vector<vector<int>>& matrix, int row1, int row2) {
    if (row1 != row2) {
        swap(matrix[row1], matrix[row2]);
    }
}

// Function to swap two columns in a matrix
void swapColumns(vector<vector<int>>& matrix, int col1, int col2, int n) {
    for (int i = 0; i < n; ++i) {
        swap(matrix[i][col1], matrix[i][col2]);
    }
}

// Function to extract a submatrix from a matrix
vector<vector<int>> extractSubmatrix(const vector<vector<int>>& matrix, int startRow, int startCol, int numRows, int numCols) {
    vector<vector<int>> submatrix;
    for (int i = 0; i < numRows; ++i) {
        vector<int> row;
        for (int j = 0; j < numCols; ++j) {
            row.push_back(matrix[startRow + i][startCol + j]);
        }
        submatrix.push_back(row);
    }
    return submatrix;
}

// Function to search for an element in a matrix and return its indices
vector<int> searchMatrix(const vector<vector<int>>& matrix, int target, int& rowIndex, int& colIndex) {
    int rows = matrix.size();
    vector<int> rc(2);

    for (int i = 0; i < rows; ++i) {
        auto it = std::find(matrix[i].begin(), matrix[i].end(), target);
        if (it != matrix[i].end()) {
            rowIndex = i; // Save row index
            colIndex = std::distance(matrix[i].begin(), it); // Calculate column index
            rc[0] = rowIndex;
            rc[1] = colIndex;
            return rc; // Element found, return indices
        }
    }

    return {-1, -1}; // Element not found, return some default or error indices
}

// Function to make the first element of matrix2 equal to 'first'
void make_element_equal(vector<vector<int>>& matrix1, vector<vector<int>>& matrix2, int n, int m) {
    int rowIndex, colIndex;
    searchMatrix(matrix2, first, rowIndex, colIndex);
    swapColumns(matrix2, 0, colIndex, n);
    swapRows(matrix2, 0, rowIndex);
}

// Function to recursively check if matrix1 is a permutation of matrix2
bool check_permutation(vector<vector<int>>& matrix1, vector<vector<int>>& matrix2, int n, int m) {
    if (n == 1 || m == 1) {
        return true;
    }
    if (matrix1 == matrix2) {
        return true;
    }

    int first = matrix1[0][0];
    if (matrix2[0][0] == first) {
        for (int j = 1; j < m; j++) {
            if (matrix1[0][j] != matrix2[0][j]) {
                return false;
            }
        }
        for (int i = 1; i < n; i++) {
            if (matrix1[i][0] != matrix2[i][0]) {
                return false;
            }
        }
        auto submatrix1 = extractSubmatrix(matrix1, 1, 1, n - 1, m - 1);
        auto submatrix2 = extractSubmatrix(matrix2, 1, 1, n - 1, m - 1);
        return check_permutation(submatrix1, submatrix2, n - 1, m - 1);
    } else {
        
        make_element_equal(matrix1, matrix2, n, m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<matrix2[i][j]<<" ";
            }
            cout<<endl;
        }
        return check_permutation(matrix1, matrix2, n, m);
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        // Input matrix1
        vector<vector<int>> matrix1(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> matrix1[i][j];
            }
        }

        // Input matrix2
        vector<vector<int>> matrix2(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> matrix2[i][j];
            }
        }

        // Check if matrix1 is a permutation of matrix2
        if (check_permutation(matrix1, matrix2, n, m)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
