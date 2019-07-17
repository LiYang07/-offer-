#include<iostream>

using namespace std;

class Solution {
public:
	void replaceSpace(char *str, int length) {
		if (str == NULL || length <= 0)
			return;
		int spaceCnt = 0,oldLen=0;
		for (; str[oldLen] != '\0'; oldLen++)
			if (str[oldLen] == ' ')spaceCnt++;
		if (oldLen == 0)
			return;
		int newLen = oldLen + spaceCnt * 2;
		if (newLen > length)
			return;
		int indexOld = oldLen, indexNew = newLen;
		while (indexOld >= 0 && indexNew > indexOld) {
			if (str[indexOld] == ' ') {
				str[indexNew--] = '0';
				str[indexNew--] = '2';
				str[indexNew--] = '%';
			}
			else
				str[indexNew--] = str[indexOld];
		}
		--indexOld;
	}
};