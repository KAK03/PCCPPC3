#include <iostream>
#include <ctime>

using namespace std;

class MASSIV
{
	int height, weight;
	int** arr;
	int** arr1;
public:

	void SetValue()
	{
		cout << "¬ведите высоту: ";
		cin >> height;
		cout << "¬ведите ширину: ";
		cin >> weight;
		arr = new int* [height];
		for (int i = 0; i < height; i++)
		{
			arr[i] = new int[weight];
		}
		
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < weight; j++)
			{
				arr[i][j] = rand() % 10;
				cout << arr[i][j] << "\t";
			}
			cout << endl;
		}		
	}

	void GetValue()
	{
		arr1 = new int* [weight];
		for (int i = 0; i < weight; i++)
		{
			arr1[i] = new int[height];
		}

		for (int i = 0; i < weight; i++)
		{
			for (int j = 0; j < height; j++)
			{
				arr1[i][j] = arr[j][i];
				cout << arr1[i][j]<<"\t";
			}
			cout << endl;
		}
	}

	~MASSIV()
	{
		for (int i = 0; i < height; i++)
		{
			delete[]arr[i];
		}
		delete[]arr;
		arr = nullptr;

		for (int i = 0; i < height; i++)
		{
			delete[]arr1[i];
		}
		delete[]arr1;
		arr1 = nullptr;
	}

};

int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	MASSIV mas;
	mas.SetValue();
	cout << endl;
	mas.GetValue();
}