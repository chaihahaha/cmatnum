#include "fm_12307.h"

inline int fm_12307(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 16*bmats.A_18_15.data[i][j] - bmats.A_18_16.data[i][j] + bmats.A_31_17.data[i][j] + bmats.A_31_18.data[i][j] - 16*bmats.A_31_24.data[i][j] + bmats.A_31_25.data[i][j] + bmats.A_31_31.data[i][j] - bmats.A_8_17.data[i][j] + 16*bmats.A_8_18.data[i][j] - bmats.Ax3723.data[i][j] - bmats.Ax720.data[i][j] - bmats.Ax7893.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_15_24.data[i][j] + bmats.B_18_31.data[i][j] + bmats.B_24_2.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_31_2.data[i][j]+=-1 * m.data[i][j];
        bmats.C_18_24.data[i][j]+=1 * m.data[i][j];
        bmats.C_8_31.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}