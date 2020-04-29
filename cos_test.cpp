
#include <iostream>
#include <math.h>
#include <cstdlib>
using namespace std;
#include <ctime>
int main()
{
    double f_cos(double x);
    int cos_test();
    int cnt = cos_test();
    //double cnt = cos(-705);
    std::cout << cnt;

   
}
double f_cos(double x)
{
    double result;
    double temp = 0;
    int symbol = 1;
    if (x < -1048576 || x>1048576)
    {
        result = INFINITY;
        return result;
    }
    const double pi = 3.1415926535897932384;
    x = (x / 180) * pi;
    
    for (; 1;)
    {
        if (x > pi)
        {
            x = x - 2 * pi;
        }
        if (x < -pi)
        {
            x = x + 2 * pi;
        }
        if (-pi <= x && x <= pi)
        {
            break;
        }
    }

    

    for (int i = 2; i < 21; i = i + 2)
    {
        symbol = symbol * (-1);
        double mi_x = 1;
        double jicheng = 1;
        for (int j = 1; j <= i; j = j + 1)
        {
            mi_x = mi_x * x;
            jicheng = jicheng * j;
        }
        temp = temp + symbol * mi_x / jicheng;
    }
    result = 1 + temp;
    if (result < 0) symbol = -1;
    else  symbol = 1;
    result = 1000 * result + symbol * 0.5;
    result = (int)result;
    result = result * 0.001;
    // double TT = 12;
    return result;
}
int cos_test()
{
    double f_cos(double x);
    const double Pi = 3.141592653589793238462;
    srand((int)time(0));  // 产生随机种子  把0换成NULL也行
   double t;
    int cnt=0;
    for (int i = 0; i < 1000; i++)
    {
        t = rand() % 1048576 - 2 * rand() % 1048576;
        
        double temp=f_cos(t);
        t = t / 180 * Pi;
        double real = cos(t);
        if (abs(temp - real) >= 0.001)
            cnt++;
        
       

    }
    return cnt;
}