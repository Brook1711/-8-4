#include<iostream>
using namespace std;

int Find_Pos(int RMB[],int n, int key)
{
	for (int i = 0; i < n; i++)
	{
		if (RMB[i] > key)
		{
			return i-1;
			break;
		}
	}
	return n - 1;
}
int Num_RMB(int RMB[], int n, int key)
{
	if (key == 0)
		return 0;
	else
	{
		int Pos = Find_Pos(RMB, n, key);
		int Num_Now = key / RMB[Pos];
		int Next_key = key % RMB[Pos];
		return Num_Now + Num_RMB(RMB, n, Next_key);
	}

	
}
int main()
{
	int n_case;
	while (cin >> n_case)
	{
		int Num = 0;
		if (n_case == 0)
			break;
		int*p = new int[n_case];
		for (int i = 0; i < n_case; i++)
			cin >> p[i];
		int RMB[6] = { 1,2,5,10,50,100 };
		for (int i = 0; i < n_case; i++)
		{
			Num += Num_RMB(RMB, 6, p[i]);
		}
		cout << Num << endl;
		delete[] p;
	}

//	system("pause");
	return 0;
}