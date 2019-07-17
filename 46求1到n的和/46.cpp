//求1 + 2 + 3 + ... + n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A ? B : C）。

#include<iostream>
using namespace std;
//此题出得很好，作者一共提到了四种解法
//第一种是利用构造函数求解，利用构造n个相同的类，使得静态类的静态变量累加至相应的和
//第二种是利用虚函数求解，利用!!n，当n为0时结果为0，不为0 是结果为1这一特性实现递归的结束
//第三种是利用函数指针，跟第二种类似
//第四种是利用模板，在编译期间求解，递归结束点位偏特化模板

//第一种方法

class temp
{
public:
	temp() { N++; Sum += N; }
	static void reset() { N = 0; Sum = 0; }
	static int getSum() { return Sum; }

private:
	static  int N;
	static  int Sum;
};

int temp::N = 0;
int temp::Sum = 0;


//第二种方法
class A;
A* alist[2];
class A
{
public:
	A(){}
	virtual int getsum(int n) { return 0; }

private:

};

class B:public A
{
public:
	B() {}
	virtual int getsum(int n) { return alist[!!n]->getsum(n - 1) + n; }
	

private:
	
};




class Solution {
public:
	int Sum_Solution(int n) {
		A a;
		B b;
		alist[0] = &a;
		alist[1] = &b;
		return alist[1]->getsum(n);
	}
};