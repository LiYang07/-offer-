  
#include<iostream>

using namespace std;
struct tagDate
{
	int year;
	int month;
	int day;
};

//得到date.month的最大天数  
int GetLastDay(tagDate date)
{
	int num;
	switch (date.month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		num = 31;
		break;
	case 2:
		num = 28 + ((date.year % 4 == 0) && (date.year % 100 != 0) || date.year % 400 == 0);
		break;
	default:
		num = 30;
	}
	return num;
}

//date+1  
void AddDay(tagDate *date)
{
	date->day++;
	if (date->day > GetLastDay(*date))
	{
		date->day = 1;
		date->month++;
		if (date->month > 12)
		{
			date->month = 1;
			date->year++;
		}
	}
}

//date1比date2小返回值为1，否则为0  
int Compare(tagDate date1, tagDate date2)
{
	if (date1.year < date2.year)
		return 1;
	if (date1.year <= date2.year && date1.month < date2.month)
		return 1;
	if (date1.year <= date2.year && date1.month <= date2.month && date1.day < date2.day)
		return 1;

	return 0;
}
//计算两个日期的间隔天数  
long DateDiff(tagDate date1, tagDate date2)
{
	long delta = 0;
	tagDate date3;
	//date1比date2少时，date1日期加1  
	while (Compare(date1, date2))
	{
		AddDay(&date1);
		delta++;
	}
	return delta;
}

int  main()
{
	tagDate date1, date2;
	date1.year = 2012;
	date1.month = 3;
	date1.day = 12;
	int N;//n组数据
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> date2.year >> date2.month >> date2.day;
		cout << DateDiff(date1, date2) << endl;
	
	}
	system("pause");
	return 0;
}
