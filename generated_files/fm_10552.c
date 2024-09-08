#include "fm_10552.h"

inline int fm_10552(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = bmats.A_24_11.data[i][j] - 16*bmats.A_24_12.data[i][j] + bmats.Ax2263.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_8_28.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_24_1.data[i][j]+=1 * m.data[i][j];
        bmats.C_24_2.data[i][j]+=1 * m.data[i][j];
        bmats.C_24_3.data[i][j]+=1 * m.data[i][j];
        bmats.C_24_4.data[i][j]+=1 * m.data[i][j];
        bmats.C_24_5.data[i][j]+=1 * m.data[i][j];
        bmats.C_24_6.data[i][j]+=1 * m.data[i][j];
        bmats.C_24_7.data[i][j]+=1 * m.data[i][j];
        bmats.C_12_8.data[i][j]+=17 * m.data[i][j];
        bmats.C_24_8.data[i][j]+=1 * m.data[i][j];
        bmats.C_24_9.data[i][j]+=1 * m.data[i][j];
        bmats.C_24_10.data[i][j]+=1 * m.data[i][j];
        bmats.C_24_11.data[i][j]+=1 * m.data[i][j];
        bmats.C_24_12.data[i][j]+=1 * m.data[i][j];
        bmats.C_24_13.data[i][j]+=1 * m.data[i][j];
        bmats.C_24_14.data[i][j]+=1 * m.data[i][j];
        bmats.C_24_15.data[i][j]+=1 * m.data[i][j];
        bmats.C_24_16.data[i][j]+=1 * m.data[i][j];
        bmats.C_1_28.data[i][j]+=-1 * m.data[i][j];
        bmats.C_2_28.data[i][j]+=-1 * m.data[i][j];
        bmats.C_3_28.data[i][j]+=-1 * m.data[i][j];
        bmats.C_4_28.data[i][j]+=-1 * m.data[i][j];
        bmats.C_5_28.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_28.data[i][j]+=-1 * m.data[i][j];
        bmats.C_7_28.data[i][j]+=-1 * m.data[i][j];
        bmats.C_8_28.data[i][j]+=-1 * m.data[i][j];
        bmats.C_9_28.data[i][j]+=-1 * m.data[i][j];
        bmats.C_10_28.data[i][j]+=-1 * m.data[i][j];
        bmats.C_11_28.data[i][j]+=-1 * m.data[i][j];
        bmats.C_12_28.data[i][j]+=-1 * m.data[i][j];
        bmats.C_13_28.data[i][j]+=-1 * m.data[i][j];
        bmats.C_14_28.data[i][j]+=-1 * m.data[i][j];
        bmats.C_15_28.data[i][j]+=-1 * m.data[i][j];
        bmats.C_16_28.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
