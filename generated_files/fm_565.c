#include "stdafx.h"
#include "fm_565.h"

inline int fm_565(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.Axx2540, bmats.Axx3163, bmats.Axx3366, };
    double A_coeffs[3] = {-1, -1, -1, };
    int n_B_mats = 16;
    double_cmat B_mats[16] = {bmats.B_11_28, bmats.Bx4812, bmats.Bx4899, bmats.Bx4900, bmats.Bx4901, bmats.Bx4902, bmats.Bx4903, bmats.Bx4904, bmats.Bx4905, bmats.Bx4906, bmats.Bx4907, bmats.Bx4908, bmats.Bx4909, bmats.Bx4910, bmats.Bx4911, bmats.Bx4912, };
    double B_coeffs[16] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_27_28.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
