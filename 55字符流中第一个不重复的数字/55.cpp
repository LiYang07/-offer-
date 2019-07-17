#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

class Solution//此题一开始没有明白是什么意思，主要要求就是实时更新第一次出现的字符
{
public:
	//Insert one char from stringstream
	Solution(): index(0){
		for (int i = 0; i < 256; i++)
			Ocurrence[i] = -1;
	}

	void Insert(char ch)
	{
		if (Ocurrence[ch] == -1) {
			Ocurrence[ch] = index;//存放第一次的位置
		}
		else
			Ocurrence[ch] = -2;
		index++;
	}
	//return the first appearence once char in current stringstream
	char FirstAppearingOnce()
	{
		char c = '\0';
		int minIndex = numeric_limits<int>::max();
		for (int i = 0; i < 256; i++) {
			if (Ocurrence[i] >= 0 && Ocurrence[i] < minIndex){
				minIndex = Ocurrence[i];
				c = (char)i;
			}
			return c;
		}
	}
private:
	int Ocurrence[256];
	int index;//存放当前插入的字符数
};

int main() {

	return 0;
}