#include <iostream>
#include <vector>


template <typename T>


class MatrixBase {
public:
    std::vector<std::vector<T>> data; 
    size_t rows;
    size_t cols;

public:

    MatrixBase() : rows(0), cols(0) {}
    
    MatrixBase(size_t r, size_t c) : rows(r), cols(c), data(r, std::vector<T>(c, T())) {}

    virtual ~MatrixBase() = default;

    void addElement(size_t r, size_t c, T val) {
        if (r < rows && c < cols) {
            data[r][c] = val;
        }
    }

    T getElement(size_t r, size_t c) const {
        return data[r][c];
    }

    // 4. Fonctions getRows et getCols
    size_t getRows() const {
        return rows;
    }

    size_t getCols() const {
        return cols;
    }


    void Display() const {
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                std::cout << data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};


template <typename T>
class MatrixNumerical;


template <typename T>
MatrixNumerical<T> getCoFactor(const MatrixNumerical<T>& mat, size_t p, size_t q, size_t n) {
    MatrixNumerical<T> temp(n - 1, n - 1);
    size_t i = 0, j = 0;
    for (size_t row = 0; row < n; row++) {
        for (size_t col = 0; col < n; col++) {
            if (row != p && col != q) {
                temp.addElement(i, j, mat.getElement(row, col));
                j++;
                if (j == n - 1) {
                    j = 0;
                    i++;
                }
            }
        }
    }
    return temp;
}


template <typename T>
class MatrixNumerical : public MatrixBase<T> {
public:
    // 8. Constructeurs
    MatrixNumerical() : MatrixBase<T>() {}
    MatrixNumerical(size_t r, size_t c) : MatrixBase<T>(r, c) {}


    T getDeterminant(size_t n) const {
        T det = 0;
        if (n == 1) {
            return this->data[0][0];
        }
        if (n == 2) {
            return (this->data[0][0] * this->data[1][1] - this->data[0][1] * this->data[1][0]);
        }

        int sign = 1;
        for (size_t f = 0; f < n; f++) {
            MatrixNumerical<T> cof = getCoFactor(*this, 0, f, n);
            det += sign * this->data[0][f] * cof.getDeterminant(n - 1);
            sign = -sign;
        }
        return det;
    }


    MatrixNumerical<T> operator+(const MatrixNumerical<T>& other) const {
        MatrixNumerical<T> res(this->rows, this->cols);
        for (size_t i = 0; i < this->rows; ++i) {
            for (size_t j = 0; j < this->cols; ++j) {
                res.addElement(i, j, this->data[i][j] + other.getElement(i, j));
            }
        }
        return res;
    }

    MatrixNumerical<T> operator-(const MatrixNumerical<T>& other) const {
        MatrixNumerical<T> res(this->rows, this->cols);
        for (size_t i = 0; i < this->rows; ++i) {
            for (size_t j = 0; j < this->cols; ++j) {
                res.addElement(i, j, this->data[i][j] - other.getElement(i, j));
            }
        }
        return res;
    }

    MatrixNumerical<T> operator*(const MatrixNumerical<T>& other) const {
        MatrixNumerical<T> res(this->rows, other.getCols());
        for (size_t i = 0; i < this->rows; ++i) {
            for (size_t j = 0; j < other.getCols(); ++j) {
                T sum = 0;
                for (size_t k = 0; k < this->cols; ++k) {
                    sum += this->data[i][k] * other.getElement(k, j);
                }
                res.addElement(i, j, sum);
            }
        }
        return res;
    }


    MatrixNumerical<double> getInverse() const {
        size_t n = this->rows;
        MatrixNumerical<double> inverse(n, n);
        double det = static_cast<double>(getDeterminant(n));
        
        if (det == 0) return inverse;

        MatrixNumerical<double> matDouble(n, n);
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < n; ++j) {
                matDouble.addElement(i, j, static_cast<double>(this->data[i][j]));
            }
        }

        int sign = 1;
        for (size_t i = 0; i < n; i++) {
            for (size_t j = 0; j < n; j++) {
                MatrixNumerical<double> cof = getCoFactor(matDouble, i, j, n);
                sign = ((i + j) % 2 == 0) ? 1 : -1;
                inverse.addElement(j, i, (sign * cof.getDeterminant(n - 1)) / det);
            }
        }
        return inverse;
    }


    MatrixNumerical<double> operator/(const MatrixNumerical<T>& other) const {
        MatrixNumerical<double> otherInv = other.getInverse();
        MatrixNumerical<double> currentDouble(this->rows, this->cols);
        for (size_t i = 0; i < this->rows; ++i) {
            for (size_t j = 0; j < this->cols; ++j) {
                currentDouble.addElement(i, j, static_cast<double>(this->data[i][j]));
            }
        }
        return currentDouble * otherInv;
    }


    static MatrixNumerical<T> getIdentity(int size) {
        MatrixNumerical<T> id(size, size);
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (i == j) {
                    id.addElement(i, j, 1);
                } else {
                    id.addElement(i, j, 0);
                }
            }
        }
        return id;
    }
};


int main() {
    std::cout << "--- Test Matrice Identite (Taille 3) ---" << std::endl;
    MatrixNumerical<int> id = MatrixNumerical<int>::getIdentity(3);
    id.Display();

    std::cout << "\n--- Test Addition ---" << std::endl;
    MatrixNumerical<int> m1(2, 2);
    m1.addElement(0, 0, 1); m1.addElement(0, 1, 2);
    m1.addElement(1, 0, 3); m1.addElement(1, 1, 4);

    MatrixNumerical<int> m2(2, 2);
    m2.addElement(0, 0, 5); m2.addElement(0, 1, 6);
    m2.addElement(1, 0, 7); m2.addElement(1, 1, 8);

    MatrixNumerical<int> m3 = m1 + m2;
    m3.Display();

    std::cout << "\n--- Test Determinant ---" << std::endl;
    std::cout << "Determinant de m1 : " << m1.getDeterminant(2) << std::endl;

    return 0;
}