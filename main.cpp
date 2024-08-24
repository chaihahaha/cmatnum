#include "stdafx.h"

int main() {
    MatrixXd A = MatrixXd::Random(22*22, 22*22);
    MatrixXd B = MatrixXd::Random(22*22, 22*22);
    MatrixXd C = fmm_22x22(A,B);
    MatrixXd TC = A*B;
    std::cout << "C" << std::endl;
    std::cout << C << std::endl;
    std::cout << "TC" << std::endl;
    std::cout << TC << std::endl;
    return 0;
}
