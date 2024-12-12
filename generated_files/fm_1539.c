#include "stdafx.h"
#include "fm_1539.h"

inline int fm_1539(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 18;
    double_cmat A_mats[18] = {bmats.Axx2309, bmats.Axx2312, bmats.Axx2313, bmats.Axx2316, bmats.Axx2318, bmats.Axx2319, bmats.Axx2322, bmats.Axx2323, bmats.Axx2326, bmats.Axx2327, bmats.Axx2330, bmats.Axx2331, bmats.Axx2334, bmats.Axx2335, bmats.Axx2340, bmats.Axx3380, bmats.Axx78, bmats.Axx957, };
    double A_coeffs[18] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    int n_B_mats = 9;
    double_cmat B_mats[9] = {bmats.Bx11833, bmats.Bx11984, bmats.Bx12018, bmats.Bx12025, bmats.Bx12026, bmats.Bx12027, bmats.Bx12028, bmats.Bx12029, bmats.Bx12030, };
    double B_coeffs[9] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_17_5.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
