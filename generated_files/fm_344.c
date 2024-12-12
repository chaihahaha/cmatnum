#include "stdafx.h"
#include "fm_344.h"

inline int fm_344(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.Axx1705, bmats.Axx1714, bmats.Axx3379, };
    double A_coeffs[3] = {1, 1, 1, };
    int n_B_mats = 18;
    double_cmat B_mats[18] = {bmats.B_22_14, bmats.B_30_30, bmats.Bx1968, bmats.Bx2000, bmats.Bx2001, bmats.Bx2002, bmats.Bx2003, bmats.Bx2004, bmats.Bx2005, bmats.Bx2006, bmats.Bx2007, bmats.Bx2008, bmats.Bx2009, bmats.Bx2010, bmats.Bx2011, bmats.Bx2012, bmats.Bx2013, bmats.Bx2014, };
    double B_coeffs[18] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_6_30.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
