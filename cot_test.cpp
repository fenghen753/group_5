#include <iostream>
#include <ctime>
#include <cmath>
#include <random>
#include "cot.h"
#define  PI 3.14159265358979323846
using namespace std;
int main()
{
	
	int flag = 0;
	int number = 1000;
	default_random_engine e(time(0));
	uniform_real_distribution<double> u(-100, 100);
	for (int num = 0; num < number; num++)
	{
		double result = u(e);
		cout << cottest(result) << endl;
		cout << 1 / tan(result * PI / 180.0) << endl;
		if (fabs(cottest(result) - 1 / tan(result * PI / 180.0)) >= 0.001)
		{
			flag = flag + 1;
		}
	}
	cout << flag << endl;
	double rate = flag / 1000.0;
	cout << "Îó²îÂÊÎª£º" << rate << endl;

	return 0;
}
