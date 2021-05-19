#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>

using namespace std;
int row[] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int col[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
void KnightTour(int i, int r, int c, int n, int** h, vector<vector<int>>& kq);

int main()
{
	ifstream fi;
	fi.open("input_2.txt", ios::in);
	int n;
	fi >> n;

	int r0, c0;
	fi >> r0;
	fi >> c0;

	int** h = new int*[n];
	for (int i = 0; i < n; i++) {
		h[i] = new int[n];
	}
	// Khởi tạo mảng h = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			h[i][j] = 0;
		}
	}
	
	vector<vector<int>> kq;

	h[r0][c0] = 1;
	KnightTour(2, r0, c0, n, h, kq);
	
	cout << kq.size() << endl;
	for (int i = 0; i < kq.size(); i++) {
		for (int j = 0; j < n * n - 1; j++) {
			//if (j % n == 0)cout << endl;
			cout << kq[i][j] << ",";
		}
		cout << kq[i][n * n - 1] << endl;
	}
	
	fi.close();
	return 0;
}

void KnightTour(int i, int r, int c, int n, int** h, vector<vector<int>>& kq)
{
	int u, v;
	for (int k = 0; k < 8; k++) {
		u = r + row[k];
		v = c + col[k];
		if (u >= 0 && v >= 0 && u < n && v < n && h[u][v] == 0) {
			h[u][v] = i;
			if (i == n * n) {
				vector<int> temp;
				for (int a = 0; a < n; a++) {
					for (int b = 0; b < n; b++) {
						temp.push_back(h[a][b]);
					}
				}
				kq.push_back(temp);
			}
			else {
				KnightTour(i + 1, u, v, n, h, kq);
			}
			h[u][v] = 0;
		}
	}
}
