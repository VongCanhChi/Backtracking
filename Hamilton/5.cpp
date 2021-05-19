#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

constexpr auto MIN = 10000;
bool promising(int pos, int v, int* path, float** maTranKe, int n);
void Hamilton(float** maTranKe, int* path, int pos, int n, int* minPath, int& dmin);
int main()
{
	ifstream fi;
	fi.open("input_5.txt", ios::in);
	int n;
	fi >> n;
	float** maTranKe = new float* [n];
	for (int i = 0; i < n; i++)
		maTranKe[i] = new float[n];
	for (int i = 0; i < n; i++) {// Khởi tạo trọng số cho ma trận ban đầu bằng 0;
		for (int j = 0; j < n; j++) {
			maTranKe[i][j] = 0;
		}
	}
	int a, b;
	float d;
	while (true)
	{
		fi >> a;
		if (a == -1)
			break;
		fi >> b;
		fi >> d;
		maTranKe[a - 1][b - 1] = d;
		maTranKe[b - 1][a - 1] = d;
	}

	// Giải thuật
	int* path = new int[n];
	int* minPath = new int[n];
	for (int i = 0; i < n; i++)
	{
		path[i] = -1;
		minPath[i] = -1;
	}
	path[0] = 1;
	int dmin = MIN;
	Hamilton(maTranKe, path, 1, n, minPath, dmin);
	if (minPath[0] == -1) return 0;

	for (int i = 0; i < n; i++)
	{
		cout << minPath[i] << " ";
	}
	cout << endl << dmin;

	delete[] maTranKe;
	return 0;
}

bool promising(int pos, int v, int* path, float** maTranKe, int n)
{
	if (maTranKe[path[pos-1] - 1][v - 1] == 0) {
		return false;
	}
	else {
		for (int i = 0; i < pos; i++)
		{
			if (path[i] == v) return false;
		}
		if (pos == n && maTranKe[v - 1][path[0] - 1] == 0) {
			return false;
		}
	}
	return true;
}

void Hamilton(float** maTranKe, int* path, int pos, int n, int* minPath, int &dmin)
{
	if (pos == n) {
		float s = 0;
		for (int i = 0; i < n - 1; i++) {
			s += maTranKe[path[i] - 1][path[i + 1] - 1];
		}
		s += maTranKe[0][path[n - 1] - 1];
		if (s < dmin) {
			dmin = s;
			for (int j = 0; j < n; j++) {
				minPath[j] = path[j];
			}
		}
	}
	else {
		for (int v = 1; v <= n; v++)
		{
			if (promising(pos, v, path, maTranKe, n)) {
				path[pos] = v;
				Hamilton(maTranKe, path, pos + 1, n, minPath, dmin);
			}
		}
	}
}