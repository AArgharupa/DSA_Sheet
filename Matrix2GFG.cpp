#include <bits/stdc++.h>
using namespace std;

class Matrix
{

public:
    vector<vector<int>> inputMatrix(int r, int c);
    bool searchInAMatrix(vector<vector<int>> &matrix, int n, int m, int x);
};


bool Matrix:: searchInAMatrix(vector<vector<int>> &matrix, int n, int m, int x) 
    {
        // code here 
        int i = 0, j =  m - 1;
        while(i<n && j>=0){
            if(matrix[i][j] == x){
                return true;
            }
            if(matrix[i][j] < x){
                i++;
            }else{
                j--;
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