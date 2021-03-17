#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>
#include <ctime>

using namespace std;

void sort(vector<double>& mas)
{
	for (int i = 0; i < mas.size(); i++)
	{
		for (int j = 0; j < mas.size(); j++)
		{
			if (mas[i] > mas[j])
			{
				double t = mas[i];
				mas[i] = mas[j];
				mas[j] = t;
			}
		}
	}
}

vector<double> generate(int n)
{
	srand(time(0));
	vector<double> res;
	for (int i = 0; i < n; i++)res.push_back(-1 + rand() % 1);
	return res;
}

int main()
{
	ofstream out("out.txt");
	int mas[8]{ 1000, 2000, 4000, 8000, 16000, 32000, 64000, 128000 };
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			system("cls");
			cout << "Now N = " << mas[i] << ", Test " << j + 1 << endl;
			vector<double>test = generate(mas[i]);
			chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();
			sort(test);
			chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();
			chrono::duration<double, nano>nano_dif = end - start;
			chrono::duration<double, micro>micro_dif = end - start;
			chrono::duration<double, milli>milli_dif = end - start;
			chrono::duration<double>sec_dif = end - start;
			out << "N = " << mas[i] << ", Test " << j + 1<<endl;
			out << "Time: " << nano_dif.count() << " nano sec." << endl;
			out << "Time: " << micro_dif.count() << " micro sec." << endl;
			out << "Time: " << milli_dif.count() << " milli sec." << endl;
			out << "Time: " << sec_dif.count() << " sec." << endl;
		}
		out << endl << endl;
	}
	return 0;
}