# include <iostream>
# include <algorithm>
# include <vector>
# define maxn 300010
using namespace std;
int n, x;
int minx = maxn;
vector<int>book;
int visit[35] = { 0 };
void DFS(int sum, int t)
{
	if (sum >= x) {
		minx = min(minx, sum);
		return;
	}
	for (int i = t; i < book.size(); i++) {
		if (visit[i] == 0) {   //如果这本书没被取
			visit[i] = 1;   //取这本书
			DFS(sum + book[i], i); //进入递归
			visit[i] = 0; //出递归后恢复没被取的状态
		}
	}
}
int main()
{
	cin >> n >> x;
	int y;
	for (int i = 0; i < n; i++) {
		cin >> y;
		book.push_back(y);
	}
	DFS(0,0);
	cout << minx << endl;
	book.push_back()
	return 0;
}