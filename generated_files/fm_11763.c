#include "fm_11763.h"

inline int fm_11763(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 16*bmats.A_13_3.data[i][j] - bmats.A_13_4.data[i][j] - bmats.Ax2152.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_29_3.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_1_3.data[i][j]+=1 * m.data[i][j];
        bmats.C_2_3.data[i][j]+=1 * m.data[i][j];
        bmats.C_3_3.data[i][j]+=1 * m.data[i][j];
        bmats.C_4_3.data[i][j]+=1 * m.data[i][j];
        bmats.C_5_3.data[i][j]+=1 * m.data[i][j];
        bmats.C_6_3.data[i][j]+=1 * m.data[i][j];
        bmats.C_7_3.data[i][j]+=1 * m.data[i][j];
        bmats.C_8_3.data[i][j]+=1 * m.data[i][j];
        bmats.C_9_3.data[i][j]+=1 * m.data[i][j];
        bmats.C_10_3.data[i][j]+=1 * m.data[i][j];
        bmats.C_11_3.data[i][j]+=1 * m.data[i][j];
        bmats.C_12_3.data[i][j]+=1 * m.data[i][j];
        bmats.C_13_3.data[i][j]+=1 * m.data[i][j];
        bmats.C_14_3.data[i][j]+=1 * m.data[i][j];
        bmats.C_15_3.data[i][j]+=1 * m.data[i][j];
        bmats.C_16_3.data[i][j]+=1 * m.data[i][j];
        bmats.C_19_13.data[i][j]+=17 * m.data[i][j];
        bmats.C_13_17.data[i][j]+=-1 * m.data[i][j];
        bmats.C_13_18.data[i][j]+=-1 * m.data[i][j];
        bmats.C_13_19.data[i][j]+=-1 * m.data[i][j];
        bmats.C_13_20.data[i][j]+=-1 * m.data[i][j];
        bmats.C_13_21.data[i][j]+=-1 * m.data[i][j];
        bmats.C_13_22.data[i][j]+=-1 * m.data[i][j];
        bmats.C_13_23.data[i][j]+=-1 * m.data[i][j];
        bmats.C_13_24.data[i][j]+=-1 * m.data[i][j];
        bmats.C_13_25.data[i][j]+=-1 * m.data[i][j];
        bmats.C_13_26.data[i][j]+=-1 * m.data[i][j];
        bmats.C_13_27.data[i][j]+=-1 * m.data[i][j];
        bmats.C_13_28.data[i][j]+=-1 * m.data[i][j];
        bmats.C_13_29.data[i][j]+=-1 * m.data[i][j];
        bmats.C_13_30.data[i][j]+=-1 * m.data[i][j];
        bmats.C_13_31.data[i][j]+=-1 * m.data[i][j];
        bmats.C_13_32.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
