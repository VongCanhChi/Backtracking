#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>

using namespace std;

void sort(vector<int>& W);
void SoS2(int* s2, int size, int sum, int start, int t, vector<int> W);

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

	// Cách 2: Quay lui vét cạn
	int* s2 = new int[n];
	int total = 0;
	for (int i = 0; i < n; i++)
	{
		s2[i] = 0;
		total += W[i];
	}

	if (W[0] <= t && t <= total) {
		SoS2(s2, 0, 0, 0, t, W);
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

void SoS2(int* s2, int size, int sum, int start, int t, vector<int> W)
{
	if (sum == t) {
		for (int i = 0; i < size; i++)
		{
			cout << s2[i] << " ";
		}
		cout << endl;
	}
	else {
		for (int i = start; i < W.size(); i++)
		{
			s2[size] = W[i];
			SoS2(s2, size + 1, sum + W[i], i + 1, t, W);
		}
	}
}