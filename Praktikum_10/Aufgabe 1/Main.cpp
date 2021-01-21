//
// Created by ch-ni on 20.01.2021.
//
#include "Matrix.hpp"



int main()
{
    Matrix<int> *m = new Matrix<int>(3);
    m-> set(0,0,7);
    m-> set(0,1,18);
    m-> set(0,2,9);
    m-> set(1,0,0);
    m-> set(1,1,2);
    m-> set(1,2,12);
    m-> set(2,0,32);
    m-> set(2,1,9);
    m-> set(2,2,0);

    Matrix<int> *m2 = new Matrix<int>(3);
    m2-> set(0,0,1);
    m2-> set(0,1,2);
    m2-> set(0,2,3);
    m2-> set(1,0,12);
    m2-> set(1,1,4);
    m2-> set(1,2,8);
    m2-> set(2,0,9);
    m2-> set(2,1,9);
    m2-> set(2,2,2);


    Matrix<int> m3 = *m;
    m3.set(0,0,-3);

    std::cout << *m <<" \n\n" << m3<< std::endl;

    //std::cout << *m << "\n*\n\n"  << *m2 << "\n=\n\n" << (*m)*(*m2) << std::endl;
    delete m;
    delete m2;

}