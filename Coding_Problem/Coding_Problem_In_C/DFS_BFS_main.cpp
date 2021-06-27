#include <iostream>
#include <string>
using namespace std;

int main() {

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			//입력을 1개씩 숫자로 끊어서 받습니다 -> %1d
			scanf("%1d", &map[i][j]);
	}

	// 전체 지도 탐색
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			// 집이면서 방문하지 않았다면 -> 방문
			if (map[i][j] == 1 && visited[i][j] == false) {

				// 해당 지역에 단지 id를 부여하고
				group_id++;

				// 탐색
				//dfs_recursion(i, j);
				//dfs_stack(i, j);
				//bfs(i, j);
			}
		}
	}

	// 단지마다 집들의 수로 오름차순 정렬
	// ID는 1부터 시작
	// 함수 사용법 : https://twpower.github.io/71-use-sort-and-stable_sort-in-cpp
	sort(groups + 1, groups + group_id + 1);

	printf("%d\n", group_id);
	for (int i = 1; i <= group_id; i++) {
		printf("%d\n", groups[i]);
	}
}