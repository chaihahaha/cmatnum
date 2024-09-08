#include "fm_10126.h"

inline int fm_10126(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = bmats.A_26_13.data[i][j] - 16*bmats.A_26_14.data[i][j] + bmats.Ax509.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_10_30.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_26_1.data[i][j]+=1 * m.data[i][j];
        bmats.C_26_2.data[i][j]+=1 * m.data[i][j];
        bmats.C_26_3.data[i][j]+=1 * m.data[i][j];
        bmats.C_26_4.data[i][j]+=1 * m.data[i][j];
        bmats.C_26_5.data[i][j]+=1 * m.data[i][j];
        bmats.C_26_6.data[i][j]+=1 * m.data[i][j];
        bmats.C_26_7.data[i][j]+=1 * m.data[i][j];
        bmats.C_26_8.data[i][j]+=1 * m.data[i][j];
        bmats.C_26_9.data[i][j]+=1 * m.data[i][j];
        bmats.C_14_10.data[i][j]+=17 * m.data[i][j];
        bmats.C_26_10.data[i][j]+=1 * m.data[i][j];
        bmats.C_26_11.data[i][j]+=1 * m.data[i][j];
        bmats.C_26_12.data[i][j]+=1 * m.data[i][j];
        bmats.C_26_13.data[i][j]+=1 * m.data[i][j];
        bmats.C_26_14.data[i][j]+=1 * m.data[i][j];
        bmats.C_26_15.data[i][j]+=1 * m.data[i][j];
        bmats.C_26_16.data[i][j]+=1 * m.data[i][j];
        bmats.C_1_30.data[i][j]+=-1 * m.data[i][j];
        bmats.C_2_30.data[i][j]+=-1 * m.data[i][j];
        bmats.C_3_30.data[i][j]+=-1 * m.data[i][j];
        bmats.C_4_30.data[i][j]+=-1 * m.data[i][j];
        bmats.C_5_30.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_30.data[i][j]+=-1 * m.data[i][j];
        bmats.C_7_30.data[i][j]+=-1 * m.data[i][j];
        bmats.C_8_30.data[i][j]+=-1 * m.data[i][j];
        bmats.C_9_30.data[i][j]+=-1 * m.data[i][j];
        bmats.C_10_30.data[i][j]+=-1 * m.data[i][j];
        bmats.C_11_30.data[i][j]+=-1 * m.data[i][j];
        bmats.C_12_30.data[i][j]+=-1 * m.data[i][j];
        bmats.C_13_30.data[i][j]+=-1 * m.data[i][j];
        bmats.C_14_30.data[i][j]+=-1 * m.data[i][j];
        bmats.C_15_30.data[i][j]+=-1 * m.data[i][j];
        bmats.C_16_30.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
