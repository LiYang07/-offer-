//牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它的意思。
//例如，“student.a am I”。后来才意识到，这家伙原来把句子单词的顺序翻转了，
//正确的句子应该是“I am a student.”。Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？
#include<iostream>
#include<string>
using namespace std;

//此题和上一题是一样的，只是需要在将空格之间的单词先翻转一次，然后再整体翻转
class Solution {
public:
	string ReverseSentence(string str) {
		if (str.empty())
			return str;
		int wordBegin = 0;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == ' '&&i>0) {//此写法未考虑开始为空格以及句子中有多个空格的情况
				_reverse(str, wordBegin, i - 1);
				wordBegin = i+1;
			}
		}
		_reverse(str, wordBegin, str.size() - 1);
		_reverse(str, 0,str.size() - 1);
		return str;
	}
private:
	void _reverse(string&s, int start, int end) {
		while (start < end)
		{
			char temp = s[start];
			s[start] = s[end];
			s[end] = temp;
			start++;
			end--;
		}
	}
};
int main() {
	Solution s;
	cout << s.ReverseSentence("student. a am I");
	system("pause");

}