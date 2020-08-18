#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <memory.h>
using namespace std;

int n, m, tmp;
vector<int> a;
vector<int> b;
vector<set<int>> pairs;
int ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        a.push_back(tmp);
        set<int> s;
        pairs.push_back(s);
        for (int j = 0; j < m; j++)
        {
            pairs.at(i).insert(j);
        }
    }
    for (int i = 0; i < m; i++)
    {
        cin >> tmp;
        b.push_back(tmp);
    }
    for (int digit = 256; digit >= 1; digit /= 2)
    {
        bool pass = true;
        vector<int> notPassIdx_a;

        for (int i = 0; i < n; i++)
        {
            if (a.at(i) & digit)
            {
                pass = false;
                notPassIdx_a.push_back(i);
            }
        }

        if (!pass)
        {
            bool contain = false;
            for (int i = 0; !contain && i < n; i++)
            {
                for (auto itr = pairs.at(i).begin(); itr != pairs.at(i).end(); itr++)
                {
                    if (!(a.at(i) & b.at(*itr) & digit))
                    {
                        contain = false;
                        break;
                    }
                    contain = true;
                }

            }
            if (!contain)
            {
                for (int i = 0; i < n; i++)
                {
                    for (auto itr = pairs.at(i).begin(); itr != pairs.at(i).end(); )
                    {
                        if (a.at(i) & b.at(*itr) & digit)
                        {
                            itr = pairs.at(i).erase(itr);
                        }
                        else itr++;
                    }
                }
            }
            else
            {
                ans |= digit;
            }

        }

    }
    cout << ans;


    return 0;
}