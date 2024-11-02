#include "fm_531.h"

inline int fm_531(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.A_12_11, bmats.A_12_12, bmats.A_13_31, bmats.A_13_32, bmats.A_28_13, bmats.A_28_14, bmats.A_2_11, bmats.A_2_12, bmats.Ax2175, bmats.Ax2178, bmats.Ax2216, bmats.Ax491, bmats.Ax760, };
    double A_coeffs[13] = {-1, 16, -1, -1, 16, -1, -1, 16, -1, -1, -1, -1, -1, };
    int n_B_mats = 10;
    double_cmat B_mats[10] = {bmats.B_12_29, bmats.B_13_11, bmats.B_13_12, bmats.B_13_14, bmats.B_13_15, bmats.B_13_16, bmats.B_13_2, bmats.B_13_5, bmats.Bx4615, bmats.Bx4633, };
    double B_coeffs[10] = {1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    fmm_32x32(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_13_12.data[0][0], 1);    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
