/*
三角函数tan模块

主要功能与说明：
	f_tan()实现了tan函数的计算
	test_tan()对tan函数进行测试

主要算法：
	在tan函数实现中用麦克劳林展开近似三角函数计算

接口说明：
	调用形式：C函数直接调用立即执行
	f_tan()要求输入double类型的待求角度值，返回double类型结果
	test_tan()中调用f_tan()函数进行测试,随机生成1000个数测试；返回值：int型，返回1000组测试中误差大于0.001的次数。

作者：
	彭浩琦

	修改：
	2020.4.16
		测试发现精度不够，对f_tan函数进行修改，依然使用麦克劳林展开实现，尝试增加了阶数。1000次测试中平均有350次误差大于0.001。

*/
#include "tan_function.h"

#include <stdio.h>

//定义误差值
#define accuracy 0.001

//求绝对值
double absolute(double x)
{
	if (x < 0)x = -x;
	return x;
}

//求阶乘
double Factorial(int x)
{
	if (x == 1 || x == 0)return 1;
	else
		return 1.0 * x * Factorial(x - 1);
}

//求n次方
double nth(double x, int n)
{
	if (n > 0)
	{
		return x * nth(x, n - 1);
	}
	if (n == 0)
	{
		return 1;
	}
	if (n < 0)
	{
		return (1 / x) * nth(x, n + 1);
	}
}


//求伯努利数
double Bernoulli(int x)
{
	int k = x;
	double B = 0;
	if (x == 0)
		return 1;
	else
		if (x > 1 && x % 2 == 1)
		{
			return 0;
		}
		else
		{
			while (k)
			{
				k--;
				B += -1.0 * (Factorial(x) * Bernoulli(k)) / (Factorial(x - k) * Factorial(k) * (x - k + 1));
			}
			return B;
		}
}

double tanx(double x)//tan(x)  精度保持0.000001 计算速度太慢
{
	int i = 1;
	double e = 1, sum = 0;
	while ( i <= 10)//考虑计算速度，控制Bernoulli()
	{
		e = 1.0 * (nth(-1, i - 1) * nth(2, 2 * i) * (nth(2, 2 * i) - 1.0) * Bernoulli(2 * i) * nth(x, 2 * i - 1)) / (Factorial(2 * i));
		sum += e;
		i++;
	}
	return sum;
}



/*tan函数*/
double f_tan(double input)
{
	//使用麦克劳林展开近似tan函数，默认阶数为10
	double o;
	double x, y;

	if (input > 1048576.0)//输入大于2^20
		return INFINITY;


	//不存在则返回INFINITY，输出显示inf
	//if ((fmod(input, 180) == 90) || (fmod(input, 180) == -90))
	//{
	//	return INFINITY;
	//}

	//对输入进行处理：使得输入在-90到+90范围内
	//x = fmod(input, 180);//将数轴上的点全部映射到-180到180上,此时x的取值范围为-180到180,需要再将其压缩为-90到90
	//if (x > 90)
	//{
	//	x = x - 180;//将90-180上的点映射为-90-0
	//}
	//else if (x < -90)
	//{
	//	x = x + 180;//将-180--90的点映射为0-90
	//}
	while (input < -90) input += 180;
	while (input > 90)  input -= 180;

	if(absolute(input) == 90)
		return INFINITY;

	//常用特殊值
	if (input == 45)
		return 1;
	if (input == -45)
		return -1;

	y = input / 180 * pi;	//将角度输入转化为弧度输入
//	o = y + (double(1.0 / 3.0)) * pow(y, 3) + double(2.0 / 15.0) * pow(y, 5) + double(17.0 / 315.0) * pow(y, 7) + double(62.0 / 2835.0) * pow(y, 9);
	o = tanx(y);
	//保留小数点后三位
	o = int(o * 1000) / 1000.0;

	return o;
}





int tan_test(void)
{
	//TUDO 随机生成1000个数测试；返回值：int型，返回1000组测试中误差大于0.001的次数。
	double n;
	double x, y;
	int cnt = 0;
	srand((unsigned)time(NULL));
	for (int i = 0; i < 1000; i++)
	{
		n = (rand() % 180) - 90.0;
		
		if (absolute(n) != 90)
		{
			x = tan(n/180.0 * pi);
			y = f_tan(n);
			if (absolute(x - y) >= accuracy)
				cnt++;
		}
	}
	return cnt;
}