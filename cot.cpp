#include <iostream>
#include "cot.h"
using namespace std; 
#define  PI 3.14159265358979323846
//#define _USE_MATH_DEFINES
//#include <math.h>     // 3，4行保证使用pi，写成M_PI

double cottest(double a)
{	
	int quotient=1;
	// cot函数周期为pi

	//double和fioat型不能用%符号求余 ！！ 所以(a - int(a) + int(a) % 180)是相当与 a%180  
	if ((a - int(a) + int(a) % 180) == 0)
	{
		return INFINITY;
	/*printf("不能输入180的倍数，因为该值在正切函数中是没有意义的！！！\n\a");
	exit(0);*/
	}
	else if (a > 180)    //double转化成int，向下取整
	{
		
		quotient =a/180;      //若a=365.3，则quotient=365/180=2 ，a=365.3-2*180= 5.3 
		a = a - quotient * 180;
	}
	else if(a < -180)     //向上取整，如 -359.7-> 359  ,抹去小数点
	{
		quotient = a / 180;        //若a=-365.3，则quotient=-365/180=-2 ，a=-365.3-（-2）*180 = -5.3 
		a = a - quotient * 180;
	}
	
	//化为主区间 -90<x<90
	if(a>90)   
	{
		a = a - 180;
	}
	else if (a < -90)
	{
		a = a + 180;
	}
	//cout << "最后的a的角度值是：" << a << endl;
	double newa = a * PI / 180.0;
	//cout <<"最后的a的弧度值是："<< newa << endl;
	//根据cot函数的泰勒公式展开，取前面的4项。
	double t = 1.0 / newa - newa / 3.0 - pow(newa, 3) / 45.0 - 2 * pow(newa, 5) / 945.0 - pow(newa, 7) / 4725 - 2.1377806 * pow(10, -5) * pow(newa, 9)-2.16440629*pow(10,-6)*pow(newa,11);
	//double cotx = 0;
	/*for (int i = 0; i < 6; i++)
	{
		cotx = cotx + reFactorial(-1) * pow(2, 2 * i) * reBernoulli(2 * i) * pow(newa, 2 * i - 1) / reFactorial(2 * i);
	}*/
	//if (flag / number == 0)
	//{
	//////////  小数点精确处理   ///////////////////
	int n = 3;//保留n位有效数字。
	double cotx = t - (int)t;  //取小数部分。
	cotx *= pow(10, n);//小数点左移。
	if (cotx - (int)cotx >= 0.5)
	{
		cotx += 1; //四舍五入
	}
	cotx = (int)cotx; //取整数部分。
	cotx /= pow(10, n);//小数点右移。
	cotx += (int)t;//加上原本的整数部分
	//////////////////////////////////////////////
	/*if (abs(cotx) < 0.008)
	{
		cotx = 0;
	}
	*/
	return cotx;
}

