#include <iostream>
#include <cstdlib>
#include <cassert>
using namespace std;

//¾ØÕóÀàµÄÉùÃ÷
class Matrix
{
private: 
    int ROWS,COLS;
    int **m_matrix;
public:
    void Output() const;
    Matrix(int rows = 0,int cols = 0);
    
    Matrix& operator = (const Matrix& t);
    ~Matrix();

    friend Matrix operator*(const Matrix &lhs,const Matrix &rhs);
};

Matrix operator*(const Matrix &lhs,const Matrix &rhs);

