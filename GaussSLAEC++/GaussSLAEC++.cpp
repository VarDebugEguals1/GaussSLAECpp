#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(int argc, char const* argv[])
{
    typedef vector<double> matrix;
    vector<matrix> A;

    cout << "Enter num of cols and rows in matrix A (we assume that matrix B has equal number of rows) : ";
    int cols, rows;
    cin >> cols >> rows;
    if (cols < rows)
    {
        cout << "Matrix is not fully defined" << endl;
        return 0;
    }
    matrix B;

    cout << "Enter all rows of matrix A :" << endl;
    for (int i = 0; i < rows; i++)
    {
        matrix temp;
        for (int j = 0; j < cols; j++)
        {
            double input;
            cin >> input;
            temp.push_back(input);
        }
        A.push_back(temp);
    }

    cout << "Enter all numbers from matrix B:" << endl;
    for (int i = 0; i < rows; i++)
    {
        double input;
        cin >> input;
        B.push_back(input);
    }

    for (int k = 0; k < rows; k++)
    {
        for (int i = k + 1; i < rows; i++)
        {
            double koef = A[i][k] / A[k][k];
            B[i] -= B[k] * koef;
            for (int j = 0; j < cols; j++)
            {
                A[i][j] -= A[k][j] * koef;

            }
        }
    }

    vector<double> result;
    for (int i = 0; i < rows; i++)
    {
        double temp = B[rows - i - 1];
        for (int k = 0; k < i; k++)
        {
            temp -= A[rows - i - 1][rows - k - 1] * result[k];
        }
        temp /= A[rows - i - 1][rows - i - 1];
        result.push_back(temp);
    }


    reverse(result.begin(), result.end());


    cout << "Values of X matrix :" << endl;
    for (double& r : result)
        cout << r << endl;
    cout << endl;

    return 0;
}
