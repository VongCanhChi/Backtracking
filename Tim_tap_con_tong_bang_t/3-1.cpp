#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>

using namespace std;

void sort(vector<int>& W);
void SoS(int k, int sum, int total, vector<int> W, bool* s, int t);

int main()
{
	ifstream fi;
	fi.open("input_3.txt", ios::in);
	int n;
	fi >> n;

	vector<int> W;
	int temp;
	for (int i = 0; i < n; i++)
	{
		fi >> temp;
		W.push_back(temp);
	}
	int t;
	fi >> t;

	bool* s = new bool[n];
	int total = 0;
	for (int i = 0; i < n; i++)
	{
		s[i] = false;
		total += W[i];
	}
	sort(W); // Shaker sort
	if (W[0] <= t && t <= total) {
		SoS(0, 0, total, W, s, t);
	}
	
	W.clear();
	fi.close();
	return 0;
}

void sort(vector<int>& W)
{
	bool flag = true;
	int m = 0;
	while (flag) {
		flag = false;
		m++;
		for (int j = W.size() - 1; j >= m; j--)
		{
			if (W[j - 1] > W[j]) {
				float temp = W[j - 1];
				W[j - 1] = W[j];
				W[j] = temp;
				flag = true;
			}
		}
	}
}

void SoS(int k, int sum, int total, vector<int> W, bool* s, int t)
{
	if (sum == t) {
		for (int i = 0; i < W.size(); i++)
		{
			if (s[i] == true) {
				cout << W[i] << " ";
			}
		}
		cout << endl;
		return;
	}
	else {
		if ((sum + total >= t) && (sum + W[k] <= t)) {
			s[k] = true;
			SoS(k + 1, sum + W[k], total - W[k], W, s, t);
			s[k] = false;
			SoS(k + 1, sum, total - W[k], W, s, t);
		}
	}
}