#include <iostream>
#include <cmath>
using namespace std;
bool diagonaldominance(double mas[3][4])
{
    int c = 0; double t=-1000;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == 0&&j == 0)
                if (abs(mas[i][j]) >= abs(mas[i][j + 1]) + abs(mas[i][j + 2]))
                    c++;
            if(i==1&&j==1)
                if (abs(mas[i][j]) >= abs(mas[i][j + 1]) + abs(mas[i][j - 1]))
                    c++;
            if (i ==2&& j == 2)
                if (abs(mas[i][j]) >= abs(mas[i][j - 1]) + abs(mas[i][j - 2]))
                    c++;
        }
    }
    if (c == 3)
        return true;
    else
        return false;
}
void transform(double mas[3][4])
{
    double t = abs(mas[0][0]); int index[3] = { 0,0,0 }; double mas1[3][4] = { {0,0,0,0},{0,0,0,0},{0,0,0,0} }; double str[4] = {0,0,0,0};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (abs(mas[i][j]) >= t)
            {
                t = abs(mas[i][j]);
                index[i] = j;
            }
        }

        for (int j = 0; j < 4; j++)
        {
            if (mas1[index[i]][j] == 0)
                mas1[index[i]][j] = mas[i][j];
            else
                str[j] = mas[i][j];
        }
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (mas1[i][j] == 0)
                mas1[i][j] = str[j];
        }
    }
    t = -1;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (i == 0 && j == 0)
                    if (abs(mas1[i][j]) >= abs(mas1[i][j + 1]) + abs(mas1[i][j + 2]))
                        ;
                    else
                    {
                        for (int k = 0; k < 3; k++)
                        {
                            if (abs(mas1[i][k]) > abs(t))
                            {
                                t = mas1[i][k];
                            }
                        }
                        if (t < 0)
                        {
                            for (int k = 0; k < 4; k++)
                                mas1[i][k] += abs(t);
                        }
                        if (t > 0)
                        {
                            for (int k = 0; k < 4; k++)
                                mas1[i][k] -= t;
                        }
                    }
                if (i == 1&&j == 1)
                    if (abs(mas1[i][j]) >= abs(mas1[i][j + 1]) + abs(mas1[i][j - 1]))
                        ;
                    else
                    {
                        for (int k = 0; k < 3; k++)
                        {
                            if (abs(mas1[i][k]) > abs(t))
                            {
                                t = mas1[i][k];
                            }
                        }
                        if (t < 0)
                        {
                            for (int k = 0; k < 4; k++)
                                mas1[i][k] += abs(t);
                        }
                        if (t > 0)
                        {
                            for (int k = 0; k < 4; k++)
                                mas1[i][k] -= t;
                        }
                    }
                if (i == 2&&j == 2)
                    if (abs(mas1[i][j]) >= abs(mas1[i][j - 1]) + abs(mas1[i][j - 2]))
                        ;
                    else
                    {
                        for (int k = 0; k < 3; k++)
                        {
                            if (abs(mas1[i][k]) > abs(t))
                            {
                                t = mas[i][k];
                            }
                        }
                        if (t < 0)
                        {
                            for (int k = 0; k < 4; k++)
                                mas1[i][k] += abs(t);
                        }
                        if (t > 0)
                        {
                            for (int k = 0; k < 4; k++)
                                mas1[i][k] -= t;
                        }
                    }
            }
        }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            mas[i][j] = mas1[i][j];
            //cout << mas1[i][j] << '\t';
        }
        cout << endl;
    }
}
void solution(double array[3][4])
{
    double x10 = 0, x20 = 0, x30 = 0, dx1 = 1, dx2 = 1, dx3 = 1;
    double t, x1, x2, x3, e = 0.001, vector[3] = { 0,0,0 }; int j=1;
    while ((dx1 >= e) || (dx2 >= e) || (dx3 >= e))
    {
        cout << "Iteration number " << j << endl;
        for (int i = 0; i < 3; i++)
        {
            if (i == 0)
            {
                x10 = vector[i];
                x1 = (array[i][3] - array[i][2] * vector[2] - array[i][1] * vector[1]) / array[i][0];
                cout << "x" << i + 1 << "= " << x1 - remainder(x1, e) << endl;
            }
            if (i == 1)
            {
                x20 = vector[i];
                x2 = (array[i][3] - array[i][2] * vector[2] - array[i][0] * vector[0]) / array[i][1];
                cout << "x" << i + 1 << "= " << x2 - remainder(x2, e) << endl;
            }
            if (i == 2)
            {
                x30 = vector[i];
                x3 = (array[i][3] - array[i][1] * vector[1] - array[i][0] * vector[0]) / array[i][2];
                cout << "x" << i + 1 << "= " << x3 - remainder(x3, e) << endl;
            }
        }
        vector[0] = x1;
        vector[1] = x2;
        vector[2] = x3;
        dx1 = abs(vector[0] - x10);
        dx2 = abs(vector[1] - x20);
        dx3 = abs(vector[2] - x30);
        j++;
    }
}
int main()
{
    double mas[3][4];// = { {1.17, 4.19, -1.77, 4.25},{1.39, -1.45, -4.6, -1.55},{4.06, -5.42, 3.88, -6.01} };
    double t;
    cout << "Enter the matrix" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> mas[i][j];
        }
    }
    if (diagonaldominance(mas) == true)
    {
        solution(mas);
    }
    else
    {
        transform(mas);
        if (diagonaldominance(mas) == true)
            solution(mas);
        else
            cout << "Matrix not solution" << endl;
    }
}