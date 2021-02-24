#include <iostream>
#include <cmath>
using namespace std;
bool del(double arr[3][4])
{
	double del = 0;
	del = arr[0][0] * arr[1][1] * arr[2][2] + arr[0][1] * arr[1][2] * arr[2][0] + arr[1][0] * arr[2][1] * arr[0][2] - arr[0][2] * arr[1][1] * arr[2][0] - arr[0][1] * arr[1][0] * arr[2][2] - arr[0][0] * arr[1][2] * arr[2][1];
	//cout << del << endl;
	if (del == 0)
		return false;
	else
		return true;
}
int main()
{
	//double mas[3][4] = { {2,-1,0,3},{0,5,2,7},{1,-1,3,4} }; 
	double vec[3] = { 0,0,0 };
	double mas[3][4]; 
	cout << "Enter the member matrix" << endl;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 4; j++)
			cin >> mas[i][j];
	double t = mas[0][0]; 
	if (del(mas) == true)
	{
		if (mas[0][0] != 1 && mas[0][0] != 0)
		{
			for (int i = 0; i < 4; i++)
			{
				mas[0][i] /= t;
			}
		}
		if (mas[1][0]!=0)
		{
			t = mas[1][0];
			for (int i = 0; i < 4; i++)
			{
				mas[1][i] /= t;
				mas[1][i] -= mas[0][i];
			}
		}
		if (mas[2][0] != 0)
		{
			t = mas[2][0];
			for (int i = 0; i < 4; i++)
			{
				mas[2][i] /= t;
				mas[2][i] -= mas[0][i];
			}
		}
		if (mas[1][1] != 0)
		{
			t = mas[1][1];
			for (int i = 0; i < 4; i++)
			{
				mas[1][i] /= t;
			}
		}
		if (mas[2][1] != 0)
		{
			t = mas[2][1];
			for (int i = 0; i < 4; i++)
			{
				mas[2][i] /= t;
				mas[2][i] -= mas[1][i];
			}
		}
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				cout << mas[i][j] << '\t';
			}
			cout << endl;
		}
		vec[0] = mas[2][3] / mas[2][2];
		vec[1] = (mas[1][3]-mas[1][2]*vec[0])/mas[1][1];
		vec[2] = (mas[0][3] - mas[0][2] * vec[0] - mas[0][1] * vec[1]) / mas[0][0];
		for (int i = 0; i < 3; i++)
		{
			cout << vec[i] << '\t' << endl;
		}
	}
	else
	{
		cout << "System have not solution" << endl;
	}


}