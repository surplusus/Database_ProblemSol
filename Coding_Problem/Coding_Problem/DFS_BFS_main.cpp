#include <iostream>
#include <string>
using namespace std;

int main() {

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			//�Է��� 1���� ���ڷ� ��� �޽��ϴ� -> %1d
			scanf("%1d", &map[i][j]);
	}

	// ��ü ���� Ž��
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			// ���̸鼭 �湮���� �ʾҴٸ� -> �湮
			if (map[i][j] == 1 && visited[i][j] == false) {

				// �ش� ������ ���� id�� �ο��ϰ�
				group_id++;

				// Ž��
				//dfs_recursion(i, j);
				//dfs_stack(i, j);
				//bfs(i, j);
			}
		}
	}

	// �������� ������ ���� �������� ����
	// ID�� 1���� ����
	// �Լ� ���� : https://twpower.github.io/71-use-sort-and-stable_sort-in-cpp
	sort(groups + 1, groups + group_id + 1);

	printf("%d\n", group_id);
	for (int i = 1; i <= group_id; i++) {
		printf("%d\n", groups[i]);
	}
}