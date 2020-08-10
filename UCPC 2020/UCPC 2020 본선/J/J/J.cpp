//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <limits>
using namespace std;

int N, M;
int arr[100001];
vector<int> v[100001];	//v[i]는 i번째 모임에 참석한 사람의 번호
//set<int> s;
set<int> s;	//마지막 모임인 감염자

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(arr, 0, sizeof(arr));
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		int k;
		cin >> k;
		for (int j = 0; j < k; j++) {
			int temp;
			cin >> temp;
			v[i].push_back(temp);
		}
	}
	int num_v = 0;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		num_v += arr[i];
		if (arr[i] != 0) { s.insert(i); }
		//int temp;
		//cin >> temp;
		//if (temp == 0) { s.insert(i); }
	}
	//감염자가 한명도 없을 때
	if (num_v == 0) {
		cout << "YES\n";
		for (int i = 0; i < N; i++) {
			cout << "0 ";
		}
		return 0;
	}
	//모두 감염자일 때
	else if (num_v == N) {
		cout << "YES\n";
		for (int i = 0; i < N; i++) {
			cout << "1 ";
		}
		return 0;
	}
	//감염자가 한명이라도 있을 때
	else {
		for (int i = M; i > 0; i--) {
			bool no = false;
			for (int j = 0; j < v[i].size(); j++) {
				int num = v[i][j];
				if (arr[num] == 0) {
					no = true;
					break;
				}
			}
			if (no) {
				for (int j = 0; j < v[i].size(); j++) {
					int num = v[i][j];
					if (s.find(num) != s.end()) {
						cout << "NO";
						return 0;
					}
					arr[num] = 0;
				}
			}
			else if (!no) {
				for (int j = 0; j < v[i].size(); j++) {
					int num = v[i][j];
					if (s.find(num) != s.end()) {
						s.erase(num);
					}
				}
			}
		}



		cout << "YES\n";
		for (int i = 1; i <= N; i++) {
			cout << arr[i] << ' ';
		}
		return 0;
	}
}