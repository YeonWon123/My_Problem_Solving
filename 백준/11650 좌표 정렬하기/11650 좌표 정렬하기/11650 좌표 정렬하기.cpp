#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> dot[100000];

int main(void) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> dot[i].first >> dot[i].second;
	}

	sort(dot, dot + N);

	for (int i = 0; i < N; i++) {
		cout << dot[i].first << " " << dot[i].second << "\n";
	}
}