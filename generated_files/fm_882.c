#include "stdafx.h"
#include "fm_882.h"

inline int fm_882(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx1927, bmats.Axx522, bmats.Axx551, bmats.Axx858, };
    double A_coeffs[4] = {1, -1, 1, 1, };
    int n_B_mats = 12;
    double_cmat B_mats[12] = {bmats.B_4_10, bmats.Bx7726, bmats.Bx8026, bmats.Bx8197, bmats.Bx8198, bmats.Bx8199, bmats.Bx8200, bmats.Bx8201, bmats.Bx8202, bmats.Bx8203, bmats.Bx8204, bmats.Bx8206, };
    double B_coeffs[12] = {-2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_4_10.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
