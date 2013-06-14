#include <iostream>
#include <tchar.h>
#include <dll.h>

int main(int nArgc, char **ppArgs)
{
	double p[2][3] = {{1,2,3},{4,5,6}};
	double px[6] = {1,2,3,4,5,6};
	Matrix m(px,2,3);
	m.Transpose();
	Matrix m1(m);
	double s=m1.Sum(m1);
	m1.Add(m1,m1);
	system("pause");
	return 0;
}

