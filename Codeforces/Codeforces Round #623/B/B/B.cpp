#include <iostream>
using namespace std;

char save_char[105];
int save_int[105];
int save_count = 0;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;

	int bus, tram, p;
	for (int i = 0; i < t; i++) {
		save_count = 0;
		memset(save_char, 0, sizeof(save_char));
		memset(save_int, 0, sizeof(save_int));

		cin >> bus >> tram >> p;
		string s;
		cin >> s;

		char last_char = s[s.size() - 1];
		for (int j = s.size() - 1; j > 0; j--) {
			if (last_char != s[j]) {
				save_char[save_count] = last_char;
				save_int[save_count] = j + 1;
				save_count++;
				last_char = s[j];
			}
		}

		save_char[save_count] = s[0];
		save_int[save_count] = 1;
		save_count++;
		
		cout << save_count << endl;
		int total = 0;
		int sum_part = 0;
		int sum_part_count = 0;
		while (1) {
			if (save_char[sum_part_count] == 'A') {
				sum_part = bus;
			}
			else {
				sum_part = tram;
			}

			if (total + sum_part > p) {
				if (sum_part_count != 0)
					cout << save_int[sum_part_count - 1] << "\n";
				else
					cout << s.size() << "\n";

				break;
			}
			else if (total + sum_part == p) {
				cout << save_int[sum_part_count] << "\n";
				break;
			}
			else if (sum_part_count == save_count) {
				cout << 100 << "\n";
				break;
			}

			sum_part_count++;
		}

	}

	return 0;
}