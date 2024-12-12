#include "stdafx.h"
#include "fm_1028.h"

inline int fm_1028(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 18;
    double_cmat A_mats[18] = {bmats.Axx1005, bmats.Axx1594, bmats.Axx1643, bmats.Axx1653, bmats.Axx1737, bmats.Axx1759, bmats.Axx1802, bmats.Axx1938, bmats.Axx2067, bmats.Axx2854, bmats.Axx3250, bmats.Axx3336, bmats.Axx3400, bmats.Axx368, bmats.Axx475, bmats.Axx667, bmats.Axx726, bmats.Axx727, };
    double A_coeffs[18] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    int n_B_mats = 13;
    double_cmat B_mats[13] = {bmats.Bx8613, bmats.Bx9339, bmats.Bx9393, bmats.Bx9405, bmats.Bx9406, bmats.Bx9407, bmats.Bx9408, bmats.Bx9409, bmats.Bx9410, bmats.Bx9411, bmats.Bx9412, bmats.Bx9413, bmats.Bx9414, };
    double B_coeffs[13] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_1_25.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
