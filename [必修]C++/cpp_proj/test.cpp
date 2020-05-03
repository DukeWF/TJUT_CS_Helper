#include "test.h"

//矩阵相乘算法(*)
Matrix operator*(const Matrix &lhs,const Matrix &rhs){
    //检验前置条件
    assert(lhs.COLS == rhs.ROWS);
    //乘积矩阵
    Matrix ret(lhs.ROWS,rhs.COLS);
    //乘积操作
    for(int i=0;i<lhs.ROWS;i++)
    {
        for(int j=0;j<rhs.COLS;j++)
        {
        	ret.m_matrix[i][j] = 0;
            for(int k =0; k<lhs.COLS;k++)
            {
                ret.m_matrix[i][j] += lhs.m_matrix[i][k]*rhs.m_matrix[k][j]; 
            }
        }
    }
    //返回乘积(注意局部对象的返回构造方式)
    return ret;
}

//矩阵构造函数，进行了动态内存分配
Matrix::Matrix(int rows, int cols):ROWS(rows),COLS(cols){
	if(rows==0 || cols == 0){
		m_matrix = NULL;
		return;
	}
    m_matrix = new int*[ROWS];
    for(int i=0;i<ROWS;i++)
    {
        m_matrix[i] = new int[COLS];
        for(int j=0;j<COLS;j++)
        {
            m_matrix[i][j] = rand() % 100;
        }
    }
}
//矩阵析构函数，释放动态分配的内存
Matrix::~Matrix()
{
	if(m_matrix){
    	for(int i=0;i<ROWS;i++){   
        	delete[] m_matrix[i];
    	}
    	delete[] m_matrix;
	}
}

Matrix& Matrix::operator = (const Matrix& t){
	if(this->m_matrix){
		for(int i=0;i<ROWS;i++){   
        	delete[] m_matrix[i];
    	}
    	delete[] m_matrix;
	}
	
	ROWS = t.ROWS;
	COLS = t.COLS;
	m_matrix = new int*[t.ROWS];
    for(int i=0;i<ROWS;i++)
    {
        m_matrix[i] = new int[t.COLS];
        for(int j=0;j<COLS;j++)
        {
            m_matrix[i][j] = t.m_matrix[i][j];
        }
    }
	return *this;
}

//矩阵打印函数，打印出矩阵的内容
void Matrix::Output() const
{
    for(int i=0;i<ROWS;i++)
    {
        for(int j=0;j<COLS;j++)
        {
            cout << m_matrix[i][j] << "\t";
        }
        cout << endl;
    }
}
