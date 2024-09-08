#include "fm_11333.h"

inline int fm_11333(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_24_21.data[i][j] + 16*bmats.A_24_22.data[i][j] - bmats.Ax110.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_8_22.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_24_1.data[i][j]+=-1 * m.data[i][j];
        bmats.C_24_2.data[i][j]+=-1 * m.data[i][j];
        bmats.C_24_3.data[i][j]+=-1 * m.data[i][j];
        bmats.C_24_4.data[i][j]+=-1 * m.data[i][j];
        bmats.C_24_5.data[i][j]+=-1 * m.data[i][j];
        bmats.C_24_6.data[i][j]+=-1 * m.data[i][j];
        bmats.C_24_7.data[i][j]+=-1 * m.data[i][j];
        bmats.C_24_8.data[i][j]+=-1 * m.data[i][j];
        bmats.C_24_9.data[i][j]+=-1 * m.data[i][j];
        bmats.C_24_10.data[i][j]+=-1 * m.data[i][j];
        bmats.C_24_11.data[i][j]+=-1 * m.data[i][j];
        bmats.C_24_12.data[i][j]+=-1 * m.data[i][j];
        bmats.C_24_13.data[i][j]+=-1 * m.data[i][j];
        bmats.C_24_14.data[i][j]+=-1 * m.data[i][j];
        bmats.C_24_15.data[i][j]+=-1 * m.data[i][j];
        bmats.C_24_16.data[i][j]+=-1 * m.data[i][j];
        bmats.C_17_22.data[i][j]+=1 * m.data[i][j];
        bmats.C_18_22.data[i][j]+=1 * m.data[i][j];
        bmats.C_19_22.data[i][j]+=1 * m.data[i][j];
        bmats.C_20_22.data[i][j]+=1 * m.data[i][j];
        bmats.C_21_22.data[i][j]+=1 * m.data[i][j];
        bmats.C_22_22.data[i][j]+=1 * m.data[i][j];
        bmats.C_23_22.data[i][j]+=1 * m.data[i][j];
        bmats.C_24_22.data[i][j]+=1 * m.data[i][j];
        bmats.C_25_22.data[i][j]+=1 * m.data[i][j];
        bmats.C_26_22.data[i][j]+=1 * m.data[i][j];
        bmats.C_27_22.data[i][j]+=1 * m.data[i][j];
        bmats.C_28_22.data[i][j]+=1 * m.data[i][j];
        bmats.C_29_22.data[i][j]+=1 * m.data[i][j];
        bmats.C_30_22.data[i][j]+=1 * m.data[i][j];
        bmats.C_31_22.data[i][j]+=1 * m.data[i][j];
        bmats.C_32_22.data[i][j]+=1 * m.data[i][j];
        bmats.C_6_24.data[i][j]+=17 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
