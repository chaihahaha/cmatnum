#include "fm_9999.h"

inline int fm_9999(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 16*bmats.A_26_31.data[i][j] - bmats.A_26_32.data[i][j] - bmats.Ax627.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_10_31.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_26_1.data[i][j]+=-1 * m.data[i][j];
        bmats.C_26_2.data[i][j]+=-1 * m.data[i][j];
        bmats.C_26_3.data[i][j]+=-1 * m.data[i][j];
        bmats.C_26_4.data[i][j]+=-1 * m.data[i][j];
        bmats.C_26_5.data[i][j]+=-1 * m.data[i][j];
        bmats.C_26_6.data[i][j]+=-1 * m.data[i][j];
        bmats.C_26_7.data[i][j]+=-1 * m.data[i][j];
        bmats.C_26_8.data[i][j]+=-1 * m.data[i][j];
        bmats.C_26_9.data[i][j]+=-1 * m.data[i][j];
        bmats.C_26_10.data[i][j]+=-1 * m.data[i][j];
        bmats.C_26_11.data[i][j]+=-1 * m.data[i][j];
        bmats.C_26_12.data[i][j]+=-1 * m.data[i][j];
        bmats.C_26_13.data[i][j]+=-1 * m.data[i][j];
        bmats.C_26_14.data[i][j]+=-1 * m.data[i][j];
        bmats.C_26_15.data[i][j]+=-1 * m.data[i][j];
        bmats.C_26_16.data[i][j]+=-1 * m.data[i][j];
        bmats.C_15_26.data[i][j]+=17 * m.data[i][j];
        bmats.C_17_31.data[i][j]+=1 * m.data[i][j];
        bmats.C_18_31.data[i][j]+=1 * m.data[i][j];
        bmats.C_19_31.data[i][j]+=1 * m.data[i][j];
        bmats.C_20_31.data[i][j]+=1 * m.data[i][j];
        bmats.C_21_31.data[i][j]+=1 * m.data[i][j];
        bmats.C_22_31.data[i][j]+=1 * m.data[i][j];
        bmats.C_23_31.data[i][j]+=1 * m.data[i][j];
        bmats.C_24_31.data[i][j]+=1 * m.data[i][j];
        bmats.C_25_31.data[i][j]+=1 * m.data[i][j];
        bmats.C_26_31.data[i][j]+=1 * m.data[i][j];
        bmats.C_27_31.data[i][j]+=1 * m.data[i][j];
        bmats.C_28_31.data[i][j]+=1 * m.data[i][j];
        bmats.C_29_31.data[i][j]+=1 * m.data[i][j];
        bmats.C_30_31.data[i][j]+=1 * m.data[i][j];
        bmats.C_31_31.data[i][j]+=1 * m.data[i][j];
        bmats.C_32_31.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}