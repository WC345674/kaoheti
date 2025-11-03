#include<iostream>
#include<string>
using namespace std;
string s1;
int word_len = 0;
int main()
{
	getline(cin, s1);
	int zongshu = s1.size();
	int in_word = 0, count = 0;
	string word_list[90];
	int num_list[90];
	for (int i = 0; i < zongshu; i++)
	{
		if (s1[i] == ' ')
		{
			if (word_len > 0) {
				num_list[count] = word_len;
				in_word = 0;
				word_len = 0;
				count++;
			}
		}
		else if (s1[i] == '.')
		{
			if (word_len > 0) {
				num_list[count] = word_len;
				count++;
			}
			break;
		}
		else
		{
			if (in_word == 0)
			{
				in_word = 1;
			}
			word_len++;
			word_list[count] += s1[i];
		}
	}
	for (int k = 0; k < count - 1; k++) {
		for (int j = 0; j < count - k - 1; j++)
		{
			if (num_list[j + 1] < num_list[j])
			{
				int temp = num_list[j];
				num_list[j] = num_list[j + 1];
				num_list[j + 1] = temp;
				string tem = word_list[j];
				word_list[j] = word_list[j + 1];
				word_list[j + 1] = tem;
			}
		}
	}

	cout << "单词个数" << count << endl;
	if (count > 0) {
		cout << "最长的单词" << word_list[count - 1] << " 长度是" << num_list[count - 1] << endl;
	}
	for (int m = 0; m < count; m++) {
		cout << "单词:" << word_list[m] << "  长度：" << num_list[m] << endl;
	}
	system("pause");
	return 0;
}