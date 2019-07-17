#include<iostream>
#include<vector>
using namespace std;

//任意给定色子的数量，求任丢一次色子出现某点数之和的概率

//可以递归求解，但是递归次数较多，效率低下
//迭代求解更好，用一个数组表示色子和为n出现的次数
//新增加一个色子后，那么和为n出现的次数是上个数组中元素 n-1,n-2,n-3,n-4,n-5,n-6出现的次数之和

int g_maxValue = 6;//色子面数
void PrintProbality(int number) {
	if (number < 1)
		return;
	vector<vector<int>> times = { vector<int>(number * g_maxValue + 1,0) ,vector<int>(number * g_maxValue + 1,0) };
	for (int i = 1; i <= g_maxValue; i++)
		times[0][i] = 1;//初始化第一个色子
	int flag = 1; //当前应该累加数组
	for (int i = 2; i <= number; i++) {//迭代求解
		for(int j=i;j<=i*g_maxValue;j++)//目前可能出现的所有点数{
			for (int k = 1; k <= g_maxValue; k++) {
				int pos = j - k;//在上一个数组的坐标
				if (pos >= i - 1 && pos <= g_maxValue * (i - 1))//在上一组中存在
					times[flag][j] += times[!flag][pos];
			}
		flag = !flag;
	}
	//打印所有点数可能出现的次数
	flag = !flag;
	for (int i = number; i <= number * g_maxValue; i++) {
		cout <<i<<"出现"<<times[flag][i] <<"次数  ";
	}
	cout << endl;
}

int main() {

	PrintProbality(10);
	system("pause");
	return 0;
}