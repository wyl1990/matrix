#ifdef _DLLMAIN_H
#define _DLLMAIN __declspec(dllexport)
#else
#define _DLLMAIN __declspec(dllimport)
#endif

class Matrix
{
private:
	double **ppMatrix;
	int nLength;
	int nWide;
public:
	_DLLMAIN Matrix();
	_DLLMAIN Matrix(double p[], int w, int l);
	_DLLMAIN Matrix(const Matrix& s);
	_DLLMAIN double** GetMatrix();
	_DLLMAIN int GetLength();
	_DLLMAIN int GetWide();
	_DLLMAIN  int Sum(Matrix s);
	_DLLMAIN  Matrix Add(Matrix s1, Matrix s2);
	_DLLMAIN void Transpose();
	_DLLMAIN ~Matrix();
};
