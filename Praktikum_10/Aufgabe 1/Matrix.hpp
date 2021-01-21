//
// Created by ch-ni on 20.01.2021.
//

#ifndef PRAKTIKUMS_PROJEKT_MATRIX_H
#define PRAKTIKUMS_PROJEKT_MATRIX_H
#include <iostream>

template <class T> class Matrix {
    private:
        T **m;
        int dim;
    public:
        Matrix(int n)
        {
            this->dim = n;

            //Der Pointer m wird auf ein neues Array vom Pointer auf Datentyp T der Größe Dim gelegt, der die Zeilen aufnimmt  darstellt
            m = new T*[dim];
            //Jeder Pointer des erstellten Arrays wird nun auf ein neues Array von Datentyp T der Größe dim gelegt welches dann die i-te Zeile repräsenteirt
            for(int il=0; il < dim; il++)
            {
                m[il] = new T[dim];

                //Nullen der Werte jeder Zeile
                for(int il2=0; il2< dim; il2++)
                {
                    m[il][il2] = 0;
                }
            }
        }

        Matrix(const Matrix<T>& matrix)
        {
            this->dim= matrix.getDim();
            //Der Pointer m wird auf ein neues Array vom Pointer auf Datentyp T der Größe Dim gelegt, der die Zeilen aufnimmt  darstellt
            m = new T*[dim];

            //Befüllen der Matrix mit werten aus der Übergebenen
            for(int il=0;il<this->dim;il++)
            {
                m[il] = new T[dim];
                for(int il2=0;il2<this->dim;il2++)
                {
                    this->set(il,il2,matrix.get(il,il2));
                }
            }
        }

        ~Matrix()
        {
            for(int il=0; il< this->dim; il++)
            {
                delete[] m[il];
            }
            delete[] m;
        }

        Matrix<T> operator*(const Matrix<T> &mat)
        {
            Matrix<T> matrix(this->getDim());
            for(int il=0; il<this->dim; il++)
            {
                for(int il2=0;il2< this->dim; il2++)
                {
                    matrix.set(il,il2,berechneStelle(this,mat,il,il2));
                }
            }
            return matrix;
        }

        T berechneStelle(Matrix<T> *m1,const Matrix<T> &m2,int x, int y)
        {
            T v=0;
            for(int il=0; il<m1->dim;il++)
            {
                v+= m1->get(x,il) * m2.get(il,y);
            }
            return v;
        }

        void set(int x,int y, int value)
        {
            m[x][y] = value;
        }

        T get (int x,int y) const{return m[x][y];}

        int getDim() const {return this->dim;};
};




std::ostream& operator<<(std::ostream& ausgabe,const Matrix<int>& matrix)
{
    for(int il=0; il< matrix.getDim();il++)
    {
        for(int il2=0; il2<matrix.getDim();il2++)
        {
            ausgabe << matrix.get(il,il2) << "  " ;
        }
        ausgabe << "\n" << std::endl;
    }
    return ausgabe;
}


#endif //PRAKTIKUMS_PROJEKT_MATRIX_H
