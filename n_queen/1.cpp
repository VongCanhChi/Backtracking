#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>

using namespace std;

int main()
{
	ifstream fi;
	fi.open("input_1.txt", ios::in);
	int n;
	fi >> n;

	bool promising(int i);
	void n_queen(int i, int n, int* col, vector<vector<int>> &kq);

	int* col = new int[n];
	vector<vector<int>> kq;
	n_queen(1, n, col, kq);

	cout << kq.size() << endl;
	for (int i = 0; i < kq.size(); i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			cout << kq[i][j] << ",";
		}
		cout << kq[i][n - 1] << endl;
	}
	
	kq.clear();
	return 0;
}

bool promising(int i, int* col)
{
	int j = 1;
	bool flag = true;
	while (j < i && flag) {
		if (col[i - 1] == col[j - 1] || abs(col[i - 1] - col[j - 1]) == i - j) {
			flag = false;
		}
		j++;
	}
	return flag;
}

void n_queen(int i, int n, int* col, vector<vector<int>> &kq)
{
	for (int j = 1; j <= n; j++)
	{
		col[i - 1] = j;
		if (promising(i, col)) {
			if (i == n) {
				vector<int> temp;
				for (int k = 0; k < n; k++)
				{
					temp.push_back(col[k]);
				}
				kq.push_back(temp);
			}
			else {
				n_queen(i + 1, n, col, kq);
			}
		}
	}
}