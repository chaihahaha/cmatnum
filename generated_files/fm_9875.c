#include "fm_9875.h"

inline int fm_9875(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_21_31.data[i][j] + 16*bmats.A_21_32.data[i][j] - bmats.Ax636.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_5_32.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_21_1.data[i][j]+=-1 * m.data[i][j];
        bmats.C_21_2.data[i][j]+=-1 * m.data[i][j];
        bmats.C_21_3.data[i][j]+=-1 * m.data[i][j];
        bmats.C_21_4.data[i][j]+=-1 * m.data[i][j];
        bmats.C_21_5.data[i][j]+=-1 * m.data[i][j];
        bmats.C_21_6.data[i][j]+=-1 * m.data[i][j];
        bmats.C_21_7.data[i][j]+=-1 * m.data[i][j];
        bmats.C_21_8.data[i][j]+=-1 * m.data[i][j];
        bmats.C_21_9.data[i][j]+=-1 * m.data[i][j];
        bmats.C_21_10.data[i][j]+=-1 * m.data[i][j];
        bmats.C_21_11.data[i][j]+=-1 * m.data[i][j];
        bmats.C_21_12.data[i][j]+=-1 * m.data[i][j];
        bmats.C_21_13.data[i][j]+=-1 * m.data[i][j];
        bmats.C_21_14.data[i][j]+=-1 * m.data[i][j];
        bmats.C_21_15.data[i][j]+=-1 * m.data[i][j];
        bmats.C_21_16.data[i][j]+=-1 * m.data[i][j];
        bmats.C_16_21.data[i][j]+=17 * m.data[i][j];
        bmats.C_17_32.data[i][j]+=1 * m.data[i][j];
        bmats.C_18_32.data[i][j]+=1 * m.data[i][j];
        bmats.C_19_32.data[i][j]+=1 * m.data[i][j];
        bmats.C_20_32.data[i][j]+=1 * m.data[i][j];
        bmats.C_21_32.data[i][j]+=1 * m.data[i][j];
        bmats.C_22_32.data[i][j]+=1 * m.data[i][j];
        bmats.C_23_32.data[i][j]+=1 * m.data[i][j];
        bmats.C_24_32.data[i][j]+=1 * m.data[i][j];
        bmats.C_25_32.data[i][j]+=1 * m.data[i][j];
        bmats.C_26_32.data[i][j]+=1 * m.data[i][j];
        bmats.C_27_32.data[i][j]+=1 * m.data[i][j];
        bmats.C_28_32.data[i][j]+=1 * m.data[i][j];
        bmats.C_29_32.data[i][j]+=1 * m.data[i][j];
        bmats.C_30_32.data[i][j]+=1 * m.data[i][j];
        bmats.C_31_32.data[i][j]+=1 * m.data[i][j];
        bmats.C_32_32.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
