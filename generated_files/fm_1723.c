#include "stdafx.h"
#include "fm_1723.h"

inline int fm_1723(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx1268, bmats.Axx1292, bmats.Axx1520, bmats.Axx2347, };
    double A_coeffs[4] = {1, -1, 1, 1, };
    int n_B_mats = 12;
    double_cmat B_mats[12] = {bmats.B_24_19, bmats.B_24_27, bmats.B_30_19, bmats.Bx10228, bmats.Bx10439, bmats.Bx12489, bmats.Bx12506, bmats.Bx12507, bmats.Bx12508, bmats.Bx12510, bmats.Bx3132, bmats.Bx4527, };
    double B_coeffs[12] = {-2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_24_19.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
