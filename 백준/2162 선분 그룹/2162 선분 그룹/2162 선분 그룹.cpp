#include <iostream>
using namespace std;

typedef pair<long long, long long> point;
// pair<long long, long long> point;
/*
typedef struct POINT {
	long long x;
	long long y;

	// operator overloading
	bool operator > (const POINT& a) const {
		return ((x > a.x) || ((x == a.x) && (y > a.y)));
	}

	// operator overloading
	bool operator < (const POINT& a) const {
		return ((x < a.x) || ((x == a.x) && (y < a.y)));
	}

	// operator overloading
	bool operator <= (const POINT& a) const {
		return ((*this < a) || ((x == a.x) && (y == a.y)));
	}
} point;
*/

struct line {
	point p1;
	point p2;
};

line input[3000];

// �ﰢ���� ���̸� ���ϴ� �Լ�
int SignArea(point a, point b, point c) {
	long long area = (a.first * b.second - a.second * b.first + b.first * c.second - c.first * b.second
		+ c.first * a.second - a.first * c.second);
	if (area > 0) return 1;
	else if (area == 0) return 0;
	else return -1;
}

// ������ �����ϴ����� Ȯ���ϴ� �Լ�
int T(point a, point b, point c, point d) {
	return (SignArea(a, b, c) * SignArea(a, b, d));
}

// ������ �����ϴ����� Ȯ���ϴ� �Լ�
bool intersect(line l_one, line l_two) {
	point a = l_one.p1;
	point b = l_one.p2;
	point c = l_two.p1;
	point d = l_two.p2;

	int s1 = T(a, b, c, d);
	int s2 = T(c, d, a, b);
	if (s1 == 0 && s2 == 0) {
		if (a > b) swap(a, b);
		if (c > d) swap(c, d);
		return c <= b && a <= d;
	}
	else
		return s1 <= 0 && s2 <= 0;
}

// union-find ������
// �迭 �ϳ������� �ص� �����ϸ� �� ��� root�� ù��°
int union_find[3000]; // �ڽ��� �θ� ���������� ��Ÿ���� up-tree �迭

int find_set(int x) {
	if (union_find[x] == x) return x;
	return find_set(union_find[x]);
}

void Union(int x, int y) {
	int a = find_set(x);
	int b = find_set(y);

	if (a < b) union_find[b] = a;
	else if (a > b) union_find[a] = b;
}

int main(void)
{
	// �Է¹ޱ�
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	// �Է¹����鼭 Union_find group�� �ʱ�ȭ
	for (int i = 0; i < N; i++) {
		cin >> input[i].p1.first >> input[i].p1.second
			>> input[i].p2.first >> input[i].p2.second;

		union_find[i] = i; // parent�� �ڱ� �ڽ�
	}

	// �� ������ ���� �����ϴ��� ����
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (intersect(input[i], input[j])) {
				Union(i, j);
			}
		}
	}

	// Union_find�� �����͸� ä������ ���� ������� ����
	int group_count = 0; // �׷��� ��
	int line_count[3000] = { 0, }; // �׷�鿡 ���� ������ ����
	int max_line = 0; // ���� ũ�Ⱑ ū �׷쿡 ���� ������ ����

	for (int i = 0; i < N; i++) {
		if (union_find[i] == i) {
			group_count++; // ��Ʈ ����� �� == �׷��� ��
		}

		line_count[find_set(i)]++; // ������ ������ 1 ������Ŵ

		// ���� ũ�Ⱑ ū �׷쿡 ���� ������ ���� ����
		if (line_count[find_set(i)] > max_line) {
			max_line = line_count[find_set(i)];
		}
	}

	cout << group_count << "\n" << max_line;
	return 0;
}