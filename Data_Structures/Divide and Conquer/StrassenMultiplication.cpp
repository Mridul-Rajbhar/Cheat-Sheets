#include<iostream>
using namespace std;


void 

int** sub(int** matrix1, int** matrix2, int size)
{
    int** resultMatrix;
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            resultMatrix[i][j] = matrix1[i][j] - matrix2[i][j]; 
        }
    }
    return resultMatrix;
}

int** add(int** matrix1, int** matrix2, int size)
{
    int** resultMatrix;
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            resultMatrix[i][j] = matrix1[i][j] + matrix2[i][j]; 
        }
    }
    return resultMatrix;
}

void split(int** parent,int** child, int iB, int jB, int size)
{
    for(int child_row=0, parent_row=iB; child_row<size;child_row++,parent_row++)
    {
        for(int child_coloumn=0, parent_coloumn = jB; child_coloumn<size;child_coloumn++,parent_coloumn++)
        {
            child[child_row][child_coloumn]=parent[parent_row][parent_coloumn];
        }
    }
}
int** StrassenMultiply(int size,int** A,int** B)
{
    int** C = new int*[size];
    if(size == 1)
    {
        C[0][0]=A[0][0]*B[0][0];
    }
    else
    {
        int** A11=new int*[size/2];
        int** A12 = new int*[size/2];
        int** A21 = new int*[size/2];
        int** A22 = new int*[size/2];
        int** B11 = new int*[size/2];
        int** B12 = new int*[size/2];
        int** B21 = new int*[size/2];
        int** B22 = new int*[size/2];

        split(A, A11, 0,0,size/2);
        split(A, A12, 0, size/2, size/2);
        split(A, A21, size/2, 0, size/2);
        split(A, A22, size/2, size/2, size/2);

        split(B, B11, 0, 0, size/2);
        split(B, B12, 0, size/2, size/2);
        split(B, B21, size/2, 0, size/2);
        split(B, B22, size/2, size/2, size/2);


        //Multiplication

        int** M0 = StrassenMultiply(size/2,add(A11,A22,size/2),add(B11,B22,size/2));
        int** M6 = StrassenMultiply(size/2,add(A21,A22,size/2),B11);
        int** M4 = StrassenMultiply(size/2,A11,sub(B12,B22,size/2));
        int** M5 = StrassenMultiply(size/2,A22,sub(B21,B11,size/2));
        int** M3 = StrassenMultiply(size/2,add(A11,A12,size/2),B22);
        int** M2 = StrassenMultiply(size/2, sub(A21,A11,size/2),add(B11,B12,size/2));
        int** M1 = StrassenMultiply(size/2, sub(A12,A22,size/2),add(B21,B22,size/2));

        int** C1 = sub(add(M0,M1,size/2),add(M3,M5,size/2),size/2);
        int** C2 = add(M3,M4,size/2);
        int** C3 = add(M5, M6, size/2);
        int** C4 = add(sub(M0,M2,size/2),sub(M4,M6,size/2),size/2);
    }

    join()

}
int main()
{   
    int num=1;
    int **A = new int*[4];
    int **B = new int*[4];
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            A[i][j]=num;
            num++;
        }
    }
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            B[i][j]=num;
            num++;
        }
    }

    int N=4;
    StrassenMultiply(N,A,B);
}