/*#ifndef _m_
#define _m_
#include<iostream>
class Matrix
{
public:
    Matrix(int a, int b); // 构造函数
    ~Matrix(); //析构函数
    friend std::istream &operator>>(std::istream &in, const Matrix &mat); //重载>>
    friend std::ostream &operator<<(std::ostream &out, const Matrix &mat); //重载<<
    Matrix operator+(const Matrix &mat); //重载+实现矩阵相加
    Matrix operator-(const Matrix &mat); //重载-实现矩阵相减
    Matrix operator*(const Matrix &mat); //重载*实现矩阵相乘

    /****            额外                *****/
   /* Matrix(int a, int b, int **matrix); //构造函数重载
    Matrix(const Matrix &mat); //构造函数重载
    bool operator==(const Matrix &mat); //等值运算符的重载
    Matrix operator=(const Matrix &mat); //重载赋值运算符，浅复制
private:
    int rows;
    int cols;
    int **p;
};
#endif
