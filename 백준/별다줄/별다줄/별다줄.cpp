#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int GO_MAX = 26; // Ʈ���� ��帶�� ������ ����

long long answer = 0;

struct Trie {
    Trie* go[GO_MAX]; // ���� ��带 ����Ű�� ������ �迭
    bool output; // �� ��忡�� ������ ��ȭ��ȣ�� �ִ°�?
    bool goexist; // �� ����� �ڽ��� �ִ°�?

    // ������
    Trie() {
        fill(go, go + GO_MAX, nullptr);
        output = goexist = false;
    }
    // �Ҹ���
    ~Trie() {
        for (int i = 0; i < GO_MAX; i++)
            if (go[i]) delete go[i];
    }
    // ���ڿ� key�� ���� ������ ����
    void insert(const char* key) {
        // ���ڿ��� ����
        if (*key == '\0') output = true;
        // �ƴ� ���
        else {
            int next = *key - '0';
            // �ش� ��尡 ������ ���� ���� �Ҵ��ؼ� ����
            if (!go[next]) go[next] = new Trie;
            goexist = true;
            // �ڽ� ��忡�� �̾ ����
            go[next]->insert(key + 1);
        }
    }
    // �� ��尡 �ϰ����� �ִ°�?
    bool consistent() {
        // �ڽĵ� �����鼭 ���⼭ ������ ��ȭ��ȣ�� �ִٸ� �ϰ��� ����
        if (goexist && output) return false;
        // �ڽĵ� �� �ϳ��� �ϰ����� ������ �� ��嵵 �ϰ����� ����
        for (int i = 0; i < GO_MAX; i++)
            if (go[i] && !go[i]->consistent()) {
                answer = (answer + 1) % 1000000007;
                return true;
            }
        // �ϰ����� ����
        answer = (answer + 1) % 1000000007;
        return true;
    }
};

int main() {
    int N;
    scanf("%d", &N);
    Trie* root = new Trie; // ��Ʈ ��� �����
    for (int i = 0; i < N; i++) {
        char tel[301];
        scanf("%s", tel);
        root->insert(tel);
    }

    char sss[200001];
    scanf("%s", sss);
    root->consistent();
    printf("%ld", answer);
}