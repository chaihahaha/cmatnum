#include "fm_12675.h"

inline int fm_12675(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 16*bmats.A_14_27.data[i][j] - bmats.A_14_28.data[i][j] + 16*bmats.A_27_13.data[i][j] - bmats.A_27_14.data[i][j] + bmats.A_29_17.data[i][j] + bmats.A_29_18.data[i][j] + bmats.A_29_19.data[i][j] + bmats.A_29_20.data[i][j] + bmats.A_29_28.data[i][j] + bmats.A_29_29.data[i][j] - 16*bmats.A_29_30.data[i][j] - bmats.Ax1229.data[i][j] - bmats.Ax488.data[i][j] - bmats.Ax7538.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_13_30.data[i][j] + bmats.B_27_29.data[i][j] + bmats.B_30_11.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_29_11.data[i][j]+=-1 * m.data[i][j];
        bmats.C_14_29.data[i][j]+=1 * m.data[i][j];
        bmats.C_27_30.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}