
#include<bits/stdc++.h>
using namespace std;
// BM字符串搜索算法

class BoyerMoore {
private:
	int R;
	int right[128];
	string pat;

public:
	BoyerMoore(string& pat) {//计算跳跃表,对字符串的每个字符按其建立索引
		this->R = 128;//128位足以存储txt中包含的字符
		this->pat = pat;
		for (int c = 0; c < R; c++)
			right[c] = -1;  //不包含在模式字符串中的字符的值为-1
		for (int j = 0; j < pat.length(); j++)
			right[pat[j]] = j;   //包含在模式字符串中的字符的值为它在其中出现的最右位置
	}
	void search(string& txt, int *number) {//进行字符串查找
		int m = pat.length();
		int n = txt.length();
		int skip;
		number[0] = -1;
		number[1] = 0; //返回数组,第一个记录首次找到位置,第二个记录次数
		for (int i = 0; i <= n - m; i += skip) {//模式字符串和文本位置在位置i匹配吗?
			skip = 0;
			for (int j = m - 1; j >= 0; j--) {//从右向左移动
				if (pat[j] != txt[i + j]) {
					skip = j - right[txt[i + j]];  //通过right数组将模式串和文本对齐
					if (skip < 1)skip = 1;//至少移动一个位置
					break;
				}
			}
			if (skip == 0) {
				if (number[0] == -1)  //首次找到
					number[0] = i;
				number[1]++;
				skip = m;//跳过此找到的串
				//return ;// 找到了，则返回第一个字符的位置
			}
		}
		// 没找到,不改变 返回-1
		//return number; // 没找到 返回-1
	}
	int searchPosition(string& txt, int n) { //计算某个字符串之前的单词数目
		int count = 0;
		for (int i = 1; i < n; i++) {
			if (txt[i] == ' ' && txt[i - 1] != ' ') //对于间隔的判断
				count++;
		}
		return count;
	}
};

int main() {
	ifstream inCorpus, inQuery;
	inCorpus.open("D://Codes/C/algs4/4corpus.txt", ios::in);
	inQuery.open("D://Codes/C/algs4/4Query.txt", ios::in);
	string  line;
    string *corpus = new string;
	while (getline(inCorpus, line))
	{
		line += " ";
		*corpus += line;
	}
	while (getline(inQuery, line))
	{
		BoyerMoore* boyermoore = new BoyerMoore(line);
		int* offset = new int[2];
		boyermoore->search(*corpus,offset);
		if (offset[0] == -1)
			cout << "-- " << line << endl;// 没找到
		else {
			int pos = boyermoore->searchPosition(*corpus, offset[0]);
			cout << pos + 1;
			cout << "\t " << line << "\ttimes: " << offset[1] << endl;
		}
		delete  []offset,boyermoore;
	}
    delete corpus;
	return 0;
}