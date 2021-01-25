#include <iostream>
using namespace std;
int main()
{
    float mas[3][4], arr[4], res[3]; float t, t1;
    cout << "Enter the matrix:" << endl;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 4; j++)
        {
            cin >> mas[i][j];
        }
    t = mas[0][0];
    for (int i = 0; i < 4; i++)
    {
        mas[0][i] /=t;
        arr[i] = mas[0][i];
    }
    t = mas[1][0]; t1 = mas[2][0];
    for (int i = 1; i < 3; i++)
        for(int j=0;j<4;j++)
        {
            if (i == 1)
            {
                mas[i][j] -= arr[j] * t;
            }
            if (i == 2)
            {
                mas[i][j] -= arr[j] * t1;
            }
        }
    t = mas[1][1]; t1 = mas[2][1];
    for (int i = 0; i < 4; i++)
    {
        mas[1][i] /= t;
        mas[2][i] -= mas[1][i] * t1;
    }
    cout << "Calculated matrix:" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j= 0; j< 4; j++)
        {
            cout << "["<<i+1<<"]["<<j+1<<"]="<<mas[i][j]<<'\t';
        }
        cout << endl;
    }
    res[2] = mas[2][3] / mas[2][2];
    res[1] = (mas[1][3] - mas[1][2]*res[2]) / mas[1][1];
    res[0] = (mas[0][3] - mas[0][2] * res[2] - mas[0][1] * res[1]) / mas[0][0];
    cout << "Root value:" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "[" << i + 1 << "]=" << res[i] << '\t';
    }
    return 0;
}