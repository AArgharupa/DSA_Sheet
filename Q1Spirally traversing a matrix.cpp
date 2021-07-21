#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Matrix
{

public:
    vector<vector<int>> inputMatrix(int r, int c);
    vector<int> spirallyMatrix(int r, int c, vector<vector<int>> matrix);
};

vector<int> Matrix ::spirallyMatrix(int r, int c, vector<vector<int>> matrix)
{
    int direction = 0;
    vector<int> vec;
    int k, l;
    int top = 0, left = 0;
    while (top <= r - 1 && left <= c - 1)
    {
        if (direction == 0)
        {
            for (k = left; k < c; k++)
                vec.push_back(matrix[top][k]);
            top++;
        }

        else if (direction == 1)
        {
            for (l = top; l < r; l++)
                vec.push_back(matrix[l][c - 1]);
            c--;
        }

        else if (direction == 2)
        {
            for (k = c - 1; k >= left && top != r; k--)
                vec.push_back(matrix[r - 1][k]);
            r--;
        }

        else if (direction == 3)
        {
            for (k = r - 1; k >= top; k--)
                vec.push_back(matrix[k][left]);
            left++;
        }
        direction = (direction + 1) % 4;
    }
    return vec;
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
    int c = 5;
    Matrix ob1; //3 5
                //6 6 2 28 2 12 26 3 28 7 22 25 3 4 23
    vector<vector<int>> matrix = ob1.inputMatrix(r, c);
    // cout << "The matrix is: " << endl;
    // for (int i = 0; i < r; i++)
    // {

    //     for (int j = 0; j < c; j++)
    //     {

    //         cout << matrix[i][j] << " ";
    //     }

    //     cout << endl;
    // }

    vector<int> vec = ob1.spirallyMatrix(r, c, matrix);
    cout << "The spiral matrix is: " << endl;
    vector<int>::iterator itr;
    for (itr = vec.begin(); itr < vec.end(); itr++)
    {
        cout << *itr << " ";
    }

    return 0;
}