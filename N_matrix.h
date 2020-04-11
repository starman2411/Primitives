#ifndef N_MATRIX_H_INCLUDED
#define N_MATRIX_H_INCLUDED
#include <iostream>
using namespace std;
class N_matrix
{
private:
    float** matrix;
    long int height;
    long int width;

public:
    N_matrix(){   //конструктор без параметров
    height=0;
    width=0;
    }

    N_matrix(long int m,long int n){   //стандартный конструктор принимает высоту и ширину
        height=m;
        width=n;
        matrix = (float**) new float*[m];
        for (int i = 0; i < m; i++){
            matrix[i] = (float*)new float[n];
        }
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                matrix[i][j] = 0;
            }
        }
    }

    N_matrix(const N_matrix& a)      //конструктор копирования
  {
    height = a.height;
    width = a.width;

    matrix = (float**) new float*[height];

    for (int i = 0; i < height; i++)
      matrix[i] = (float*) new float[width];

    for (int i = 0; i < height; i++)
      for (int j = 0; j < width; j++)
        matrix[i][j] = a.matrix[i][j];
  }
    ~N_matrix(){
    if (width>0){
        for(int i=0;i<height;i++){
            delete[] matrix[i];
        }
    }
    if (height>0){
        delete[] matrix;
    }

    }

    N_matrix& rotate_matrix(int k){        //поворот матрицы на угол k*Пи/2
        switch (k){
            case 1:{
                float a[width][height];
                for (int i = 0; i < height; i++){
                    for (int j = 0; j < width; j++){
                        a[j][height-1-i] = matrix[i][j];
                    }
                }
                N_matrix* new_m=new N_matrix(width,height);
                for (int i = 0; i < width; i++){
                    for (int j = 0; j < height; j++){
                        new_m->matrix[i][j]=a[i][j];
                    }
                }
                return(*new_m);}
            case 2:{
                float a[height][width];
                for (int i = 0; i < height; i++){
                    for (int j = 0; j < width; j++){
                        a[height-1-i][width-1-j] = matrix[i][j] ;
                    }
                }
                N_matrix* new_m=new N_matrix(height,width);
                for (int i = 0; i < height; i++){
                    for (int j = 0; j < width; j++){
                        new_m->matrix[i][j]=a[i][j];
                    }
                }
                return(*new_m);}
            case 3:{
            float a[width][height];
                for (int i = 0; i < height; i++){
                    for (int j = 0; j < width; j++){
                        a[width-1-j][i] = matrix[i][j] ;
                    }
                }
                N_matrix* new_m=new N_matrix(width,height);
                for (int i = 0; i < height; i++){
                    for (int j = 0; j < width; j++){
                        new_m->matrix[i][j]=a[i][j];
                    }
                }
                return(*new_m);}
    };

                float a[height][width];
                for (int i = 0; i < height; i++){
                    for (int j = 0; j < width; j++){
                        a[i][j] = matrix[i][j] ;
                    }
                }
                N_matrix* new_m=new N_matrix(height,width);
                for (int i = 0; i < height; i++){
                    for (int j = 0; j < width; j++){
                        new_m->matrix[i][j]=a[i][j];
                    }
                }
                return(*new_m);
    }

    N_matrix& operator =(const N_matrix& a){     //оператор присваивания

        if (width > 0)
    {
      for (int i = 0; i < height; i++)
        delete[] matrix[i];
    }

    if (height > 0)
    {
      delete[] matrix;
    }

    height = a.height;
    width = a.width;

    matrix = (float**) new float*[height];
    for (int i = 0; i < height; i++)
      matrix[i] = (float*) new float[width];

    for (int i = 0; i < height; i++)
      for (int j = 0; j < width; j++)
        matrix[i][j] = a.get_value(i,j);
    return(*this);
    };

    long int get_height()const{  //получить высоты
        return(height);
    }
    long int get_width()const{   //получить ширину
        return(width);
    }


    void set_value(int i,int j,float a){   //задать значение по индексам
        if ((i<0)||(i>height)) return;
        if ((j<0)||(j>width)) return;
        matrix[i][j]=a;
    }
    float get_value(int i,int j) const{   //получить значение по индексам
        if ((i<0)||(i>height)) return(0);
        if ((j<0)||(j>width)) return(0);
        return(matrix[i][j]);

    }
    void set_from_array(float* a){
    unsigned int k=0;
    for (int i = 0; i < height; i++){
      for (int j = 0; j < width; j++){
        matrix[i][j]=a[k];
        k++;}
    }
    }

};



ostream& operator<<(std::ostream& os,const N_matrix& m){
    os<<"{ ";
    for (int i = 0; i < m.get_height(); i++){
    os<<"{ ";
      for (int j = 0; j < m.get_width(); j++){
        os<<m.get_value(i,j)<<" ";}
    os<<"}";}
    os<<"}";
    return(os);
};


#endif // N_MATRIX_H_INCLUDED
