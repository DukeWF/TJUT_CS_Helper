#include "test.h"

//��������㷨(*)
Matrix operator*(const Matrix &lhs,const Matrix &rhs){
    //����ǰ������
    assert(lhs.COLS == rhs.ROWS);
    //�˻�����
    Matrix ret(lhs.ROWS,rhs.COLS);
    //�˻�����
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
    //���س˻�(ע��ֲ�����ķ��ع��췽ʽ)
    return ret;
}

//�����캯���������˶�̬�ڴ����
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
//���������������ͷŶ�̬������ڴ�
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

//�����ӡ��������ӡ�����������
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
