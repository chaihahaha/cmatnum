#include "fm_11740.h"

inline int fm_11740(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_17_19.data[i][j] + 16*bmats.A_17_20.data[i][j] - bmats.Ax4357.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_1_20.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_17_1.data[i][j]+=-1 * m.data[i][j];
        bmats.C_17_2.data[i][j]+=-1 * m.data[i][j];
        bmats.C_17_3.data[i][j]+=-1 * m.data[i][j];
        bmats.C_17_4.data[i][j]+=-1 * m.data[i][j];
        bmats.C_17_5.data[i][j]+=-1 * m.data[i][j];
        bmats.C_17_6.data[i][j]+=-1 * m.data[i][j];
        bmats.C_17_7.data[i][j]+=-1 * m.data[i][j];
        bmats.C_17_8.data[i][j]+=-1 * m.data[i][j];
        bmats.C_17_9.data[i][j]+=-1 * m.data[i][j];
        bmats.C_17_10.data[i][j]+=-1 * m.data[i][j];
        bmats.C_17_11.data[i][j]+=-1 * m.data[i][j];
        bmats.C_17_12.data[i][j]+=-1 * m.data[i][j];
        bmats.C_17_13.data[i][j]+=-1 * m.data[i][j];
        bmats.C_17_14.data[i][j]+=-1 * m.data[i][j];
        bmats.C_17_15.data[i][j]+=-1 * m.data[i][j];
        bmats.C_17_16.data[i][j]+=-1 * m.data[i][j];
        bmats.C_4_17.data[i][j]+=17 * m.data[i][j];
        bmats.C_17_20.data[i][j]+=1 * m.data[i][j];
        bmats.C_18_20.data[i][j]+=1 * m.data[i][j];
        bmats.C_19_20.data[i][j]+=1 * m.data[i][j];
        bmats.C_20_20.data[i][j]+=1 * m.data[i][j];
        bmats.C_21_20.data[i][j]+=1 * m.data[i][j];
        bmats.C_22_20.data[i][j]+=1 * m.data[i][j];
        bmats.C_23_20.data[i][j]+=1 * m.data[i][j];
        bmats.C_24_20.data[i][j]+=1 * m.data[i][j];
        bmats.C_25_20.data[i][j]+=1 * m.data[i][j];
        bmats.C_26_20.data[i][j]+=1 * m.data[i][j];
        bmats.C_27_20.data[i][j]+=1 * m.data[i][j];
        bmats.C_28_20.data[i][j]+=1 * m.data[i][j];
        bmats.C_29_20.data[i][j]+=1 * m.data[i][j];
        bmats.C_30_20.data[i][j]+=1 * m.data[i][j];
        bmats.C_31_20.data[i][j]+=1 * m.data[i][j];
        bmats.C_32_20.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
