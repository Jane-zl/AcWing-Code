/*
	N����Ʒ��������V�ı�����ÿ����Ʒֻ��ʹ��һ��
	��i����Ʒ�������vi����ֵ��wi
*/
#include<iostream>
using namespace #include <iostream>
using namespace std;
#define N 1001

template<class Type>
void Knapsack(Type* v, int* w, int c, int n, Type(*m)[N]);

int main() {
	int v[N], w[N], n, c, m[N][N];

	// �����������
	cin >> n >> c;
	for (int i = 1; i <= n; i++)
		cin >> w[i] >> v[i];

	Knapsack<int>(v, w, c, n, m);
    cout << m[1][c];
	return 0;
}

template<class Type>
void Knapsack(Type* v, int* w, int c, int n, Type (*m)[N]) {
	int jMax = min(w[n] - 1, c);		// ��ʾ���������Ų��µ�n����Ʒ������ֵ��������������Ʒ����-1����Сֵ��
	// ��n����Ʒ
	for (int j = 0; j <= jMax; j++)		// ����������j<=jMaxʱ����n����Ʒ���ܷŵ�����
		m[n][j] = 0;			// ��ʱ������Ʒ��ֵΪ0
	for (int j = w[n]; j <= c; j++)	// ��������j>��Ʒn������ʱ����Ʒn�ɷŰ���
		m[n][j] = v[n];
	// ��n-1����Ʒ����2����Ʒ
	for (int i = n - 1; i > 0; i--) {	// i�������i����Ʒ�����������ֵ
		jMax = min(w[i] - 1, c);		// Max�����������Ų��µ�i����Ʒ����ֵ
		for (int j = 0; j <= jMax; j++)		// ����������j<=jMaxʱ����i����Ʒ���ܷŵ�����
			m[i][j] = m[i + 1][j];			// û���κ�Ч��
		for (int j = w[i]; j <= c; j++)			// ��������j>w[i]
			m[i][j] = max(m[i + 1][j], m[i + 1][j - w[i]] + v[i]);		// Ч��ֵ����vi
	}
}



/*
// v1_Knapsack.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������

// ʵ��0-1��������    xȡֵ��Χ{0,1}����̬�滮��
// ���� W=(2,3,1,2)   V=(15,20,10,12)   C=5
// ��� ����ѡ�񷽰��Լ�m(i, j)����
// m(i,j) ��������Ϊj����ѡ����ƷΪi,i+1,��,nʱ0-1�������������ֵ

#include <iostream>
using namespace std;
#define N 101

template<class Type>
void Knapsack(Type* v, int* w, int c, int n, Type(*m)[N]);
template<class Type>
void Traceback(Type(*m)[N], int* w, int c, int n, int* x);

int main() {
	int v[N], w[N], n, c, m[N][N], x[N];
	// ��Ʒ��ֵ����Ʒ��������Ʒ�������������� 
	// m[N][N] ��������������������ֵ
	// x[N] ��������

	// �����������
	cout << "�����뱳��������";
	cin >> c;
	cout << "��������Ʒ������";
	cin >> n;
	cout << "��������Ʒ�������ͼ�ֵ��" << endl;
	for (int i = 1; i <= n; i++)
		cin >> w[i] >> v[i];

	Knapsack<int>(v, w, c, n, m);
	Traceback(m, w, c, n, x);

	// ��ӡ��������
	for (int i = 1; i <= n; i++)
		cout << x[i] << " ";
	cout << "\n";

	// ��ӡm(i, j)����
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= c; j++)
			cout << m[i][j] << " ";
		cout << endl;
	}

	return 0;
}

template<class Type>
void Knapsack(Type* v, int* w, int c, int n, Type (*m)[N]) {
	int jMax = min(w[n] - 1, c);		// ��ʾ���������Ų��µ�n����Ʒ������ֵ��������������Ʒ����-1����Сֵ��
	// ��n����Ʒ
	for (int j = 0; j <= jMax; j++)		// ����������j<=jMaxʱ����n����Ʒ���ܷŵ�����
		m[n][j] = 0;			// ��ʱ������Ʒ��ֵΪ0
	for (int j = w[n]; j <= c; j++)	// ��������j>��Ʒn������ʱ����Ʒn�ɷŰ���
		m[n][j] = v[n];
	// ��n-1����Ʒ����2����Ʒ
	for (int i = n - 1; i > 0; i--) {	// i�������i����Ʒ�����������ֵ
		jMax = min(w[i] - 1, c);		// Max�����������Ų��µ�i����Ʒ����ֵ
		for (int j = 0; j <= jMax; j++)		// ����������j<=jMaxʱ����i����Ʒ���ܷŵ�����
			m[i][j] = m[i + 1][j];			// û���κ�Ч��
		for (int j = w[i]; j <= c; j++)			// ��������j>w[i]
			m[i][j] = max(m[i + 1][j], m[i + 1][j - w[i]] + v[i]);		// Ч��ֵ����vi
	}
	
	//m[1][c] = m[2][c];		// ��һ����Ʒ���������
	//if(c >= w[1])
	//	m[1][c] = max(m[1][c], m[2][c - w[1]] + v[1]);
	
}

template<class Type>
void Traceback(Type (*m)[N], int* w, int c, int n, int* x) {		// �������Ž�
	for (int i = 1; i <= n; i++)
		if (m[i][c] == m[i + 1][c])	// ��i����Ʒ���ڰ���
			x[i] = 0;
		else {
			x[i] = 1;
			c = c - w[i];
		}
	x[n] == (m[n][c]) ? 1 : 0;	// �������һ����Ʒ�Ƿ��ڰ���
}
*/
 

