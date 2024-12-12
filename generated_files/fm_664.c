#include "stdafx.h"
#include "fm_664.h"

inline int fm_664(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.Axx1594, bmats.Axx3366, bmats.Axx466, };
    double A_coeffs[3] = {1, 1, 1, };
    int n_B_mats = 12;
    double_cmat B_mats[12] = {bmats.Bx6015, bmats.Bx6016, bmats.Bx6041, bmats.Bx6042, bmats.Bx6043, bmats.Bx6044, bmats.Bx6045, bmats.Bx6046, bmats.Bx6047, bmats.Bx6048, bmats.Bx6049, bmats.Bx6050, };
    double B_coeffs[12] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_15_27.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
