#include "fm_11587.h"

inline int fm_11587(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 16*bmats.A_3_5.data[i][j] - bmats.A_3_6.data[i][j] - bmats.Ax3923.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_19_5.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_21_3.data[i][j]+=17 * m.data[i][j];
        bmats.C_1_5.data[i][j]+=1 * m.data[i][j];
        bmats.C_2_5.data[i][j]+=1 * m.data[i][j];
        bmats.C_3_5.data[i][j]+=1 * m.data[i][j];
        bmats.C_4_5.data[i][j]+=1 * m.data[i][j];
        bmats.C_5_5.data[i][j]+=1 * m.data[i][j];
        bmats.C_6_5.data[i][j]+=1 * m.data[i][j];
        bmats.C_7_5.data[i][j]+=1 * m.data[i][j];
        bmats.C_8_5.data[i][j]+=1 * m.data[i][j];
        bmats.C_9_5.data[i][j]+=1 * m.data[i][j];
        bmats.C_10_5.data[i][j]+=1 * m.data[i][j];
        bmats.C_11_5.data[i][j]+=1 * m.data[i][j];
        bmats.C_12_5.data[i][j]+=1 * m.data[i][j];
        bmats.C_13_5.data[i][j]+=1 * m.data[i][j];
        bmats.C_14_5.data[i][j]+=1 * m.data[i][j];
        bmats.C_15_5.data[i][j]+=1 * m.data[i][j];
        bmats.C_16_5.data[i][j]+=1 * m.data[i][j];
        bmats.C_3_17.data[i][j]+=-1 * m.data[i][j];
        bmats.C_3_18.data[i][j]+=-1 * m.data[i][j];
        bmats.C_3_19.data[i][j]+=-1 * m.data[i][j];
        bmats.C_3_20.data[i][j]+=-1 * m.data[i][j];
        bmats.C_3_21.data[i][j]+=-1 * m.data[i][j];
        bmats.C_3_22.data[i][j]+=-1 * m.data[i][j];
        bmats.C_3_23.data[i][j]+=-1 * m.data[i][j];
        bmats.C_3_24.data[i][j]+=-1 * m.data[i][j];
        bmats.C_3_25.data[i][j]+=-1 * m.data[i][j];
        bmats.C_3_26.data[i][j]+=-1 * m.data[i][j];
        bmats.C_3_27.data[i][j]+=-1 * m.data[i][j];
        bmats.C_3_28.data[i][j]+=-1 * m.data[i][j];
        bmats.C_3_29.data[i][j]+=-1 * m.data[i][j];
        bmats.C_3_30.data[i][j]+=-1 * m.data[i][j];
        bmats.C_3_31.data[i][j]+=-1 * m.data[i][j];
        bmats.C_3_32.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
