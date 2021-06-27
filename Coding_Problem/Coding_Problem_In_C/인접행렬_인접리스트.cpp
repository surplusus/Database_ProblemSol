#include <iostream>
#include <string>
using namespace std;
const int n = 10; // 크기
void 인접행렬()
{
	int[][] a = new int[n + 1][n + 1]; 
	
	for (int i = 0; i < m; i++) 
	{ 
		int v1 = sc.nextInt(); 
		int v2 = sc.nextInt(); 
		a[v1][v2] = 1; 
		a[v2][v1] = 1; 
	}

}

void 인접리스트() {

	ArrayList<Integer>[] a = (ArrayList<Integer>[]) new ArrayList[n + 1]; 
	
	for (int i = 0; i <= n; i++) {
		a[i] = new ArrayList<>(); 
	} 
	for (int i = 0; i < m; i++) {
		int v1 = sc.nextInt();
		int v2 = sc.nextInt();
		a[v1].add(v2);
		a[v2].add(v1);
	}
}