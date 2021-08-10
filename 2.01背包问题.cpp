/*
	N件物品，容量是V的背包，每件物品只能使用一次
	第i件物品的体积是vi，价值是wi
*/
#include<iostream>
using namespace #include <iostream>
using namespace std;
#define N 1001

template<class Type>
void Knapsack(Type* v, int* w, int c, int n, Type(*m)[N]);

int main() {
	int v[N], w[N], n, c, m[N][N];

	// 读入相关数据
	cin >> n >> c;
	for (int i = 1; i <= n; i++)
		cin >> w[i] >> v[i];

	Knapsack<int>(v, w, c, n, m);
    cout << m[1][c];
	return 0;
}

template<class Type>
void Knapsack(Type* v, int* w, int c, int n, Type (*m)[N]) {
	int jMax = min(w[n] - 1, c);		// 表示背包容量放不下第n件物品的上限值（背包容量与物品重量-1的最小值）
	// 第n件物品
	for (int j = 0; j <= jMax; j++)		// 当背包容量j<=jMax时，第n件物品不能放到包中
		m[n][j] = 0;			// 此时包中物品价值为0
	for (int j = w[n]; j <= c; j++)	// 背包容量j>物品n的重量时，物品n可放包中
		m[n][j] = v[n];
	// 第n-1件物品到第2件物品
	for (int i = n - 1; i > 0; i--) {	// i：计算第i件物品放入包的最优值
		jMax = min(w[i] - 1, c);		// Max：包的容量放不下第i件物品上限值
		for (int j = 0; j <= jMax; j++)		// 当背包容量j<=jMax时，第i件物品不能放到包中
			m[i][j] = m[i + 1][j];			// 没有任何效益
		for (int j = w[i]; j <= c; j++)			// 背包容量j>w[i]
			m[i][j] = max(m[i + 1][j], m[i + 1][j - w[i]] + v[i]);		// 效益值增长vi
	}
}



/*
// v1_Knapsack.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。

// 实现0-1背包问题    x取值范围{0,1}（动态规划）
// 输入 W=(2,3,1,2)   V=(15,20,10,12)   C=5
// 输出 背包选择方案以及m(i, j)矩阵
// m(i,j) 背包容量为j，可选择物品为i,i+1,…,n时0-1背包问题的最优值

#include <iostream>
using namespace std;
#define N 101

template<class Type>
void Knapsack(Type* v, int* w, int c, int n, Type(*m)[N]);
template<class Type>
void Traceback(Type(*m)[N], int* w, int c, int n, int* x);

int main() {
	int v[N], w[N], n, c, m[N][N], x[N];
	// 物品价值，物品重量，物品数量，背包容量 
	// m[N][N] 背包问题的子问题的最优值
	// x[N] 背包方案

	// 读入相关数据
	cout << "请输入背包容量：";
	cin >> c;
	cout << "请输入物品数量：";
	cin >> n;
	cout << "请输入物品的重量和价值：" << endl;
	for (int i = 1; i <= n; i++)
		cin >> w[i] >> v[i];

	Knapsack<int>(v, w, c, n, m);
	Traceback(m, w, c, n, x);

	// 打印背包方案
	for (int i = 1; i <= n; i++)
		cout << x[i] << " ";
	cout << "\n";

	// 打印m(i, j)矩阵
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= c; j++)
			cout << m[i][j] << " ";
		cout << endl;
	}

	return 0;
}

template<class Type>
void Knapsack(Type* v, int* w, int c, int n, Type (*m)[N]) {
	int jMax = min(w[n] - 1, c);		// 表示背包容量放不下第n件物品的上限值（背包容量与物品重量-1的最小值）
	// 第n件物品
	for (int j = 0; j <= jMax; j++)		// 当背包容量j<=jMax时，第n件物品不能放到包中
		m[n][j] = 0;			// 此时包中物品价值为0
	for (int j = w[n]; j <= c; j++)	// 背包容量j>物品n的重量时，物品n可放包中
		m[n][j] = v[n];
	// 第n-1件物品到第2件物品
	for (int i = n - 1; i > 0; i--) {	// i：计算第i件物品放入包的最优值
		jMax = min(w[i] - 1, c);		// Max：包的容量放不下第i件物品上限值
		for (int j = 0; j <= jMax; j++)		// 当背包容量j<=jMax时，第i件物品不能放到包中
			m[i][j] = m[i + 1][j];			// 没有任何效益
		for (int j = w[i]; j <= c; j++)			// 背包容量j>w[i]
			m[i][j] = max(m[i + 1][j], m[i + 1][j - w[i]] + v[i]);		// 效益值增长vi
	}
	
	//m[1][c] = m[2][c];		// 第一件物品不放入包中
	//if(c >= w[1])
	//	m[1][c] = max(m[1][c], m[2][c - w[1]] + v[1]);
	
}

template<class Type>
void Traceback(Type (*m)[N], int* w, int c, int n, int* x) {		// 计算最优解
	for (int i = 1; i <= n; i++)
		if (m[i][c] == m[i + 1][c])	// 第i件物品不在包中
			x[i] = 0;
		else {
			x[i] = 1;
			c = c - w[i];
		}
	x[n] == (m[n][c]) ? 1 : 0;	// 计算最后一件物品是否在包中
}
*/
 

