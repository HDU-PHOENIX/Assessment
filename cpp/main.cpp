/**
 * 完善 Matrix 类，使得下面的代码可以正常运行:
 * class Matrix {
 * public:
 * TODO: Someting
 * private:
 *     int rows;
 *     int cols;
 *     int **matrix;
 * };
 *
 * 评分标准：
 * 1. 代码能够正常的运行就有 100 分，若代码不能正常运行，则按以下标准进行评分：
 * Matrix::Matrix(int rows, int cols):                              20 points
 * Matrix::~Matrix():                                               20 points
 * std::istream& operator>>(std::istream& in, Matrix& matrix)       20 points
 * std::ostream& operator<<(std::ostream& os, const Matrix& matrix) 20 points
 * Matrix Matrix::operator*(Matrix &other)                          20 points
 * 2. 在正常运行的基础上，若还有其他的功能，则按以下标准进行评分：
 * Matrix::Matrix(int rows, int cols, int** matrix)                 10 points
 * template <...> Matrix::Matrix(int (&matrix)[rows][cols])         10 points
 * Matrix::Matrix(const Matrix& other)                              10 points
 * Matrix::Matrix(Matrix&& other)                                   10 points
 * Matrix& Matrix::operator=(const Matrix& other)                   10 points
 * Matrix& Matrix::operator=(Matrix &&other)                        10 points
 * Matrix Matrix::operator+(const Matrix& other)                    10 points
 * Matrix Matrix::operator-(const Matrix& other)                    10 points
 * Matrix Matrix::operator/(const Matrix& other)                    10 points
 * bool Matrix::operator==(const Matrix& other)                     10 points
 */
#include <iostream>
class Matrix
{
public:
    Matrix(int a, int b) // 构造函数
    {
        rows = a;
        cols = b;
        p = new int *[rows];
        for (int i = 0; i < rows; i++)
        {
            p[i] = new int[cols];
        }
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                p[i][j] = 0;
            }
        }
    }

    ~Matrix() //析构函数
    {
        for (int i = 0; i < rows; i++)
        {
            delete[] p[i];
        }
        delete[] p;
    }

    friend std::istream &operator>>(std::istream &in, const Matrix &mat) //重载>>
    {
        for (int i = 0; i < mat.rows; i++)
        {
            for (int j = 0; j < mat.cols; j++)
            {
                in >> mat.p[i][j];
            }
        }
        return in;
    }

    friend std::ostream &operator<<(std::ostream &out, const Matrix &mat) //重载<<
    {
        out << "[";
        for (int i = 0; i < mat.rows; i++)
        {
            for (int j = 0; j < mat.cols; j++)
            {
                out << mat.p[i][j] << " ";
            }
            if (i != mat.rows - 1)
            {
                out << std::endl;
            }
        }
        out << "]" << std::endl;
        return out;
    }
    Matrix operator+(const Matrix &mat) //重载+实现矩阵相加
    {
        int rows = mat.rows;
        int cols = mat.cols;
        Matrix M(rows, cols);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                M.p[i][j] = this->p[i][j] + mat.p[i][j];
            }
        }
        return M;
    }
    Matrix operator-(const Matrix &mat) //重载-实现矩阵相减
    {
        int rows = mat.rows;
        int cols = mat.cols;
        Matrix M(rows, cols);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                M.p[i][j] = this->p[i][j] - mat.p[i][j];
            }
        }
        return M;
    }
    Matrix operator*(const Matrix &mat) //重载*实现矩阵相乘
    {
        int trows = this->rows;
        int mcols = mat.cols;
        int same = this->cols;
        Matrix M(trows, mcols);
        if (this->cols != mat.rows)
        {
            std::cout << "请输入 n*m与m*l 的矩阵" << std::endl;
            return M;
        }
        std::cout << "row =" << trows << "\n cols = " << mcols << "\n same = " << same << std::endl;
        for (int i = 0; i < trows; i++)
        {
            for (int j = 0; j < mcols; j++)
            {
                int sum = 0;
                for (int z = 0; z < same; z++)
                {
                    sum += this->p[i][z] * mat.p[z][j];
                }
                M.p[i][j] = sum;
            }
        }
        return M;
    }
    /****            额外                *****/
    Matrix(int a, int b, int **matrix) //构造函数重载
    {
        rows = a;
        cols = b;
        p = new int *[rows];
        for (int i = 0; i < rows; i++)
        {
            p[i] = new int[cols];
        }
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                p[i][j] = matrix[i][j];
            }
        }
    }
    Matrix(const Matrix &mat)//构造函数重载
    {
        rows = mat.rows;
        cols = mat.cols;
        p = new int *[rows];
        for (int i = 0; i < rows; i++)
        {
            p[i] = new int[cols];
        }
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                p[i][j] = mat.p[i][j];
            }
        }
    }
    bool operator==(const Matrix &mat)//等值运算符的重载
    {
        bool flag = 0;
        if (this->rows == mat.rows && this->cols == mat.cols)
        {
            int rows = mat.rows;
            int cols = mat.cols;
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    if (this->p[i][j] != mat.p[i][j])
                    {
                        return flag;
                    }
                }
            }
            flag = 1;
        }
        else
        {
            return flag;
        }
        return flag;
    }
    Matrix operator = (const Matrix &mat){//重载赋值运算符，浅复制
        rows = this->rows;
        cols = this->cols;
        for(int i = 0;i<rows;i++){
            delete [] this->p[i];
        }
        delete [] this->p;
        this->p = mat.p;
        this->rows = mat.rows;
        this->cols = mat.cols;
        return mat;
    }
private:
    int rows;
    int cols;
    int **p;
};
int main()
{
    int rows, cols;

    std::cin >> rows >> cols;
    Matrix A(rows, cols);
    std::cin >> A;

    std::cin >> rows >> cols;
    Matrix B(rows, cols);
    std::cin >> B;
    std::cout<<A*B<<std::endl;

    return 0;
};
