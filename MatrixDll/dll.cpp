#include "stdafx.h"
#include "dll.h"



_DLLMAIN Matrix::Matrix()
{
	ppMatrix = NULL;
	nLength = 0;
	nWide = 0;
}

_DLLMAIN Matrix::Matrix(double p[], int w, int l)
{
	int i,j;
	ppMatrix = NULL;
	ppMatrix = new double*[w];
	for (i = 0; i < w; i++)
	{
		ppMatrix[i] = new double[l];
	}
	nLength = l;
	nWide = w;
	for (i = 0; i < w; i++)
	{
		for (j = 0; j < l; j++)
		{
			ppMatrix[i][j] = p[i * l + j];
			std::wcout << ppMatrix[i][j] << ' ';
		}
		std::wcout << std::endl;
	}
}

_DLLMAIN Matrix::Matrix(const Matrix& s)
{
	ppMatrix = s.ppMatrix;
	nLength = s.nLength;
	nWide = s.nWide;
}

_DLLMAIN double** Matrix::GetMatrix()
{
	return  ppMatrix;
}

_DLLMAIN int Matrix::GetLength()
{
	return nLength;
}

_DLLMAIN int Matrix::GetWide()
{
	return nWide;
}

_DLLMAIN int Matrix::Sum(Matrix s)
{
	int sum = 0, i, j;
	for (i = 0; i < s.nWide; i++)
	{
		for (j = 0; j < s.nLength; j++)
		{
			sum += ppMatrix[i][j];
		}	
	}
	std::wcout << sum << std::endl;
	return sum;
}

_DLLMAIN  Matrix Matrix::Add(Matrix s1, Matrix s2)
{
	int i,j;
	if (s1.nLength != s2.nLength || s1.nWide != s2.nWide)
	{
		std::wcout << "not match, error" << std::endl;
		Matrix m;
		return m;
	}
	else
	{
		for (i = 0; i < s1.nWide; i++)
		{
			for (j = 0; j < s1.nLength; j++)
			{
				s1.ppMatrix[i][j] = s1.ppMatrix[i][j]+s2.ppMatrix[i][j];
				std::wcout << s1.ppMatrix[i][j] << ' ';
			}	
			std::wcout << std::endl;
		}
		Matrix m(s1);
		return m;
	}
}

_DLLMAIN  void Matrix::Transpose()
{
	int temp, i, j;
	temp = nLength;
	nLength = nWide;
	nWide = temp;
	double **p = NULL;
	p = new double*[nWide];
	for (i = 0; i < nWide; i++)
	{
		p[i] = new double[nLength];
	}
	for (i = 0; i < nWide; i++)
	{
		for (j = 0; j < nLength; j++)
		{
			p[i][j] = ppMatrix[j][i];
			std::wcout << p[i][j] << ' ';
		}	
		std::wcout << std::endl;
	}
	for(i = 0; i < nLength; ++i) 
	{
		delete[] ppMatrix[i]; 
	}
	delete[] ppMatrix; 
	ppMatrix = p;
}

_DLLMAIN Matrix::~Matrix()
{
	/*if (ppMatrix != NULL)
	{
		delete[] ppMatrix;
	}*/
}

