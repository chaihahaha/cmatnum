#include "fm_11600.h"

inline int fm_11600(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = bmats.A_29_3.data[i][j] - 16*bmats.A_29_4.data[i][j] + bmats.Ax2143.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_13_20.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_29_1.data[i][j]+=1 * m.data[i][j];
        bmats.C_29_2.data[i][j]+=1 * m.data[i][j];
        bmats.C_29_3.data[i][j]+=1 * m.data[i][j];
        bmats.C_29_4.data[i][j]+=1 * m.data[i][j];
        bmats.C_29_5.data[i][j]+=1 * m.data[i][j];
        bmats.C_29_6.data[i][j]+=1 * m.data[i][j];
        bmats.C_29_7.data[i][j]+=1 * m.data[i][j];
        bmats.C_29_8.data[i][j]+=1 * m.data[i][j];
        bmats.C_29_9.data[i][j]+=1 * m.data[i][j];
        bmats.C_29_10.data[i][j]+=1 * m.data[i][j];
        bmats.C_29_11.data[i][j]+=1 * m.data[i][j];
        bmats.C_29_12.data[i][j]+=1 * m.data[i][j];
        bmats.C_4_13.data[i][j]+=17 * m.data[i][j];
        bmats.C_29_13.data[i][j]+=1 * m.data[i][j];
        bmats.C_29_14.data[i][j]+=1 * m.data[i][j];
        bmats.C_29_15.data[i][j]+=1 * m.data[i][j];
        bmats.C_29_16.data[i][j]+=1 * m.data[i][j];
        bmats.C_1_20.data[i][j]+=-1 * m.data[i][j];
        bmats.C_2_20.data[i][j]+=-1 * m.data[i][j];
        bmats.C_3_20.data[i][j]+=-1 * m.data[i][j];
        bmats.C_4_20.data[i][j]+=-1 * m.data[i][j];
        bmats.C_5_20.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_20.data[i][j]+=-1 * m.data[i][j];
        bmats.C_7_20.data[i][j]+=-1 * m.data[i][j];
        bmats.C_8_20.data[i][j]+=-1 * m.data[i][j];
        bmats.C_9_20.data[i][j]+=-1 * m.data[i][j];
        bmats.C_10_20.data[i][j]+=-1 * m.data[i][j];
        bmats.C_11_20.data[i][j]+=-1 * m.data[i][j];
        bmats.C_12_20.data[i][j]+=-1 * m.data[i][j];
        bmats.C_13_20.data[i][j]+=-1 * m.data[i][j];
        bmats.C_14_20.data[i][j]+=-1 * m.data[i][j];
        bmats.C_15_20.data[i][j]+=-1 * m.data[i][j];
        bmats.C_16_20.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
