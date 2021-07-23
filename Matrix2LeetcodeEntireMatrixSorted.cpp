#include <bits/stdc++.h>
using namespace std;

class Matrix
{

public:
    vector<vector<int>> inputMatrix(int r, int c);
    bool searchInAMatrix(vector<vector<int>> &matrix, int target);
};

//bettter approach
// bool Matrix::searchInAMatrix(vector<vector<int>> &matrix, int target)
// {

//     // binary_search(matrix.begin(), matrix.end(), target);

//     for (auto itr : matrix)
//     {
//         if (binary_search(itr.begin(), itr.end(), target))
//         {
//             return true;
//         }
//     }

//     return false;
// }



//optimal approach
bool Matrix::searchInAMatrix(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size();
    int m = matrix[0].size();

    int low = 0;
    int high = (n * m) - 1;
    cout << low << " " << high << endl;

    while (low <= high)
    {
        int mid = (high + low) / 2; //that means square matrix
        cout << mid << endl;
        if (matrix[mid / m][mid % m] == target)
        {
            return true;
        }
        if (matrix[mid / m][mid % m] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return false;
}
vector<vector<int>> Matrix ::inputMatrix(int r, int c)
{

    vector<vector<int>> matrix(r); //r is the size of vector<vector<int>>

    for (int i = 0; i < r; i++)
    {
        cout << "Enter the inputs : " << i << endl;
        matrix[i].assign(c, 0);

        for (int j = 0; j < c; j++)
        {
            cin >> matrix[i][j];
        }
    }
    return matrix;
}
int main()
{
    int r = 3;
    int c = 3;
    Matrix ob1;
    vector<vector<int>> matrix = ob1.inputMatrix(r, c);
    bool result = ob1.searchInAMatrix(matrix, 3);
    cout << result << endl;

    // vector<int>::iterator itr;
    // for (itr = vec.begin(); itr < vec.end(); itr++)
    // {
    //     cout << *itr << " ";
    // }

    return 0;
}