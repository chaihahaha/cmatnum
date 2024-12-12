#include "stdafx.h"
#include "fm_713.h"

inline int fm_713(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.Axx1634, bmats.Axx2716, bmats.Axx759, };
    double A_coeffs[3] = {-1, -1, -1, };
    int n_B_mats = 15;
    double_cmat B_mats[15] = {bmats.B_9_27, bmats.Bx6393, bmats.Bx6529, bmats.Bx6530, bmats.Bx6531, bmats.Bx6532, bmats.Bx6533, bmats.Bx6534, bmats.Bx6535, bmats.Bx6536, bmats.Bx6537, bmats.Bx6538, bmats.Bx6539, bmats.Bx6540, bmats.Bx6541, };
    double B_coeffs[15] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_25_27.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
