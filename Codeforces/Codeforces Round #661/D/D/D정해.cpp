#include<iostream>
#include<vector>
using namespace std;
int main()
{
	long max, i, j, n, t, last[200005];
	vector<int> v[2];
	string str, s;
	cin >> t;
	while (t--)
	{
		s = "";
		max = 0;
		cin >> n;
		cin >> str;
		v[0].clear();
		v[1].clear();
		for (i = 0; i < n; i++)
		{
			// ascii code로 49는 1을 의미
			if (v[abs(str[i] - 49)].size() > 0)
			{
				j = v[abs(str[i] - 49)].back();
				v[str[i] - 48].push_back(j);
				v[abs(str[i] - 49)].pop_back();
			}
			else
			{
				j = max;
				max++;
				v[str[i] - 48].push_back(j);
			}
			s += to_string(j + 1) + " ";
		}
		cout << max << endl << s << endl;
	}
}
