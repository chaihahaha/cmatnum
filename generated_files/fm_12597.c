#include "fm_12597.h"

inline int fm_12597(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 16*bmats.A_14_31.data[i][j] - bmats.A_14_32.data[i][j] + bmats.A_29_17.data[i][j] + bmats.A_29_18.data[i][j] + bmats.A_29_19.data[i][j] + bmats.A_29_20.data[i][j] + bmats.A_29_28.data[i][j] + bmats.A_29_29.data[i][j] - 16*bmats.A_29_30.data[i][j] + 16*bmats.A_31_13.data[i][j] - bmats.A_31_14.data[i][j] - bmats.Ax482.data[i][j] - bmats.Ax745.data[i][j] - bmats.Ax7538.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_13_30.data[i][j] + bmats.B_30_15.data[i][j] + bmats.B_31_29.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_29_15.data[i][j]+=-1 * m.data[i][j];
        bmats.C_14_29.data[i][j]+=1 * m.data[i][j];
        bmats.C_31_30.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}