#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>
using namespace std;

struct ITEM {
	int w;
	int cost;
};

int main()
{
	ifstream fi;
	fi.open("input_4.txt", ios::in);
	int W;
	fi >> W;
	int n;
	fi >> n;
	vector <ITEM> lItem;
	ITEM temp;
	for (int i = 0; i < n; i++)
	{
		fi >> temp.w;
		fi >> temp.cost;
		lItem.push_back(temp);
	}
	



	return 0;
}

//void findmaxcost(int k, int cost, int cantren, vector <item> litem, vector<int>& litemselected, int w)
//{
//	if (sum == t) {
//		for (int i = 0; i < w.size(); i++)
//		{
//			if (s[i] == true) {
//				cout << w[i] << " ";
//			}
//		}
//		cout << endl;
//		return;
//	}
//	else {
//		if ((cost + total >= t) && (sum + w[k] <= t)) {
//			s[k] = true;
//			findmaxcost(k + 1, cost + litem[k].cost, cantren + , w, s, t);
//			s[k] = false;
//			findmaxcost(k + 1, sum, total - w[k], w, s, t);
//		}
//	}
//}
//https://www.youtube.com/watch?v=gnvnnoqz5n0&ab_channel=c%e1%ba%a5utr%c3%bacd%e1%bb%afli%e1%bb%87uv%c3%a0gi%e1%ba%a3ithu%e1%ba%adt-nguy%e1%bb%85nv%c4%83nlinh