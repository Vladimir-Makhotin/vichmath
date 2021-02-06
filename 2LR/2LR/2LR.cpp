#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    double array[3][4] = { 1.17, 4.19, -1.77, 4.25, 1.39, -1.45, -4.60, -1.55, 4.06, -5.42, 3.88, -6.01 };
    int index[3] = { -1,-1,-1 }, count; double x10 = 0, x20 = 0, x30 = 0, dx1=1, dx2=1, dx3=1;
    double t, x1, x2, x3, e = 0.001, vector[3] = { 0,0,0 };
    /*cout << "Enter matrix" << endl;
    for(int i=0;i<3;i++)
        for (int j = 0; j < 4;j++)
        {
            cin >> array[i][j];
        }*/
    //cout << "Enter quantity iteration: "; cin >> count;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {

            if (j == 0)
                if (abs(array[i][j]) >= abs(array[i][j + 1]) + abs(array[i][j + 2]))
                {
                    index[i] = j;
                    for (int b = 0; b < 4; b++)
                    {
                        t = array[index[i]][b];
                        array[index[i]][b] = array[i][b];
                        array[i][b] = t;
                    }
                } 
            if (j == 1)
                if (abs(array[i][j]) >= abs(array[i][j - 1]) + abs(array[i][j + 1]))
                {
                    index[i] = j;
                    for (int b = 0; b < 4; b++)
                    {
                        t = array[index[i]][b];
                        array[index[i]][b] = array[i][b];
                        array[i][b] = t;
                    }
                }   
            if (j == 2)
                if (abs(array[i][j]) >= abs(array[i][j - 1]) + abs(array[i][j - 2]))
                {
                    index[i] = j;
                    for (int b = 0; b < 4; b++)
                    {
                        t = array[index[i]][b];
                        array[index[i]][b] = array[i][b];
                        array[i][b] = t;
                    }
                }
        }
    }
    for(int i=0;i<3;i++)
        for (int j = 0; j < 4; j++)
        {
            if (i == 0)
                if (j == 0)
                {
                    if (abs(array[i][j]) < abs(array[i][j + 1]) + abs(array[i][j + 2]))
                        for (int c = 0; c < 4; c++)
                            array[i][c] += array[1][c];
                    if (abs(array[i][j]) < abs(array[i][j + 1]) + abs(array[i][j + 2]))
                        for (int c = 0; c < 4; c++)
                            array[i][c] += array[2][c];
                }
            if (i == 1)
                if (j == 1)
                {
                    if (abs(array[i][j]) < abs(array[i][j - 1]) + abs(array[i][j + 1]))
                        for (int c = 0; c < 4; c++)
                            array[i][c] += array[0][c];
                    if (abs(array[i][j]) < abs(array[i][j - 1]) + abs(array[i][j + 1]))
                        for (int c = 0; c < 4; c++)
                            array[i][c] += array[2][c];
                }
            if (i == 2)
                if (j == 2)
                {
                    if (abs(array[i][j]) < abs(array[i][j - 1]) + abs(array[i][j - 2]))
                        for (int c = 0; c < 4; c++)
                            array[i][c] += array[0][c];
                    if (abs(array[i][j]) < abs(array[i][j - 1]) + abs(array[i][j - 2]))
                        for (int c = 0; c < 4; c++)
                            array[i][c] += array[1][c];
                }
        }
    cout << "Transformed matrix" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << array[i][j]<<'\t';
        }
        cout << endl;
    }
    int j = 1;
    while((dx1>=e) || (dx2>=e) || (dx3>=e))
    {
        cout << "Iteration number " << j << endl;
        for (int i = 0; i < 3; i++)
        {
            if (i == 0)
            {
                x10 = vector[i];
                x1 = (array[i][3] - array[i][2]*vector[2] - array[i][1]*vector[1]) / array[i][0];
                cout << "x" << i + 1 << "= " << x1-remainder(x1,e) << endl;
            }
            if (i == 1)
            {
                x20 = vector[i];
                x2 = (array[i][3] - array[i][2]*vector[2] - array[i][0]*vector[0]) / array[i][1];
                cout << "x" << i + 1 << "= " << x2 - remainder(x2, e) << endl;
            }   
            if (i == 2)
            {
                x30 = vector[i];
                x3 = (array[i][3] - array[i][1]*vector[1] - array[i][0]*vector[0]) / array[i][2];
                cout << "x" << i + 1 << "= " << x3 - remainder(x3, e) << endl;
            }    
        }
        vector[0] = x1;
        vector[1] = x2;
        vector[2] = x3;
        dx1 = abs(vector[0]-x10);
        dx2 = abs(vector[1]-x20);
        dx3 = abs(vector[2]-x30);
        j++;
    }
}
