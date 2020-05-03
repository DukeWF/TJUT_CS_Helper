//#include <QCoreApplication>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double eps;

vector<double> relaxation(vector<vector<double> > &A,
                          vector<double> b,
                          int unsigned &time)
{
    time = 0;
    double w = 1.49;

    vector<double> x(A.size());
    vector<double> tmpX(A.size());

    for (int unsigned i=0; i<A.size(); i++){
        x[i] = 0;
        tmpX[i] = 0;
    }



    while(1){
        bool returnFlag = 1;
        time ++;

        //�ɳڷ�
        for (int unsigned i=0; i<x.size(); i++){
            tmpX[i] = 0;
            for (int unsigned j=0; j<A[i].size(); j++){

                if( i== j)
                    continue;
                tmpX[i] -= A[i][j]*tmpX[j];

            }
            tmpX[i] = (double)(tmpX[i]+b[i])/A[i][i];
            tmpX[i] = (1-w)*x[i] + w*tmpX[i];
            cout<<"X"<<i<<" = "<<tmpX[i]<<'\t';

        }
        cout<<endl;

        //���ȿ���
        for(int unsigned i=0; i<x.size(); i++){

            if(fabs(tmpX[i]-x[i]) >= eps){
                returnFlag = 0;
            }
        }
        for(int unsigned i=0; i<x.size(); i++)
            x[i] = tmpX[i];
        if(returnFlag)
            return x;


    }
}

vector<double> gaussSeidel(vector<vector<double> > &A,
                           vector<double> b,
                           int unsigned &time)
{
    time = 0;

    vector<double> x(A.size());
    vector<double> tmpX(A.size());

    for (int unsigned i=0; i<A.size(); i++){
        x[i] = 0;
    }



    while(1){
        bool returnFlag = 1;
        time ++;

        //��˹���¶�
        for (int unsigned i=0; i<x.size(); i++){
            tmpX[i] = 0;
            for (int unsigned j=0; j<A[i].size(); j++){

                if( i== j)
                    continue;
                tmpX[i] -= A[i][j]*tmpX[j];

            }
            tmpX[i] = (tmpX[i]+b[i])/A[i][i];
            cout<<"X"<<i<<" = "<<tmpX[i]<<'\t';

        }
        cout<<endl;

        //���ȿ���
        for(int unsigned i=0; i<x.size(); i++){

            if(fabs(tmpX[i]-x[i]) >= eps){
                returnFlag = 0;
            }
        }
        for(int unsigned i=0; i<x.size(); i++)
            x[i] = tmpX[i];
        if(returnFlag)
            return x;


    }
}

vector<double> jacobi(vector<vector<double> > &A,
                      vector<double> b,
                      int unsigned &time)
{
    time = 0;

    vector<double> x(A.size());
    vector<double> tmpX(A.size());

    for (int unsigned i=0; i<A.size(); i++){
        x[i] = 0;
    }


    while(1){
        time++;
        bool returnFlag = 1;

        //�ſɱ�
        for (int unsigned i=0; i<x.size(); i++){
            tmpX[i] = 0;
            for (int unsigned j=0; j<A[i].size(); j++){

                if( i== j)
                    continue;
                tmpX[i] -= A[i][j]*x[j];

            }
            tmpX[i] = (tmpX[i]+b[i])/A[i][i];
            cout<<"X"<<i<<" = "<<tmpX[i]<<'\t';

        }
        cout<<endl;

        //���ȿ���
        for(int unsigned i=0; i<x.size(); i++){

            if(fabs(tmpX[i]-x[i]) >= eps){
                returnFlag = 0;
            }
        }
        for(int unsigned i=0; i<x.size(); i++)
            x[i] = tmpX[i];
        if(returnFlag)
            return x;


    }

}

vector<vector<double> > getData(vector<double> &b){
    int n;
    cout<<"������ά�� n:";		cin>>n;

    vector<vector<double> > A(n);

    // for(int i=0; i<n; i++){
    // 	A[i].resize(n);
    // }
    for(int  i=0; i<n; i++){
        cout<<"�� "<<i+1<<" ��: ";
        for(int  j=0; j<n; j++){
            double tmp;
            cin>>tmp;
            A[i].push_back(tmp);
        }
    }

    cout<<"Ϊ<b>���� "<<n<<" ��ֵ: ";
    for(int  i=0; i<n; i++){
        double tmp;
        cin>>tmp;
        b.push_back(tmp);
    }

    cout<<"���뾫�ȣ�"; cin>>eps;
    return A;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int unsigned time;
    vector<double> b;
    vector<vector<double> > A(getData(b));

    cout<<"====================�ſɱ�=====================\n";
    vector<double> result(jacobi(A, b, time)) ;
    cout<<"�����"<<endl ;
    for(int unsigned i=0; i<result.size(); i++){
        cout<<"X"<<i+1<<" = "<<result[i]<<'\t';
    }
    cout<<endl;
    cout<<"����������"<<time<<endl;


    cout<<"====================��˹���¶�=====================\n";
    vector<double> resultOfGaussSeidel(gaussSeidel(A, b, time)) ;
    cout<<"�����"<<endl ;
    for(int unsigned i=0; i<resultOfGaussSeidel.size(); i++){
        cout<<"X"<<i+1<<" = "<<resultOfGaussSeidel[i]<<'\t';
    }
    cout<<endl;
    cout<<"����������"<<time<<endl;

    cout<<"====================���ɳڷ�=====================\n";
    vector<double> resultOfRelaxation(relaxation(A,b,time));
    cout<<"�����"<<endl ;
    for(int unsigned i=0; i<resultOfRelaxation.size(); i++){
        cout<<"X"<<i+1<<" = "<<resultOfRelaxation[i]<<'\t';
    }
    cout<<endl;
    cout<<"����������"<<time<<endl;

    //return a.exec();
}
