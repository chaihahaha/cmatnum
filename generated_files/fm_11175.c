#include "fm_11175.h"

inline int fm_11175(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 16*bmats.A_27_23.data[i][j] - bmats.A_27_24.data[i][j] - bmats.Ax79.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_11_23.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_27_1.data[i][j]+=-1 * m.data[i][j];
        bmats.C_27_2.data[i][j]+=-1 * m.data[i][j];
        bmats.C_27_3.data[i][j]+=-1 * m.data[i][j];
        bmats.C_27_4.data[i][j]+=-1 * m.data[i][j];
        bmats.C_27_5.data[i][j]+=-1 * m.data[i][j];
        bmats.C_27_6.data[i][j]+=-1 * m.data[i][j];
        bmats.C_27_7.data[i][j]+=-1 * m.data[i][j];
        bmats.C_27_8.data[i][j]+=-1 * m.data[i][j];
        bmats.C_27_9.data[i][j]+=-1 * m.data[i][j];
        bmats.C_27_10.data[i][j]+=-1 * m.data[i][j];
        bmats.C_27_11.data[i][j]+=-1 * m.data[i][j];
        bmats.C_27_12.data[i][j]+=-1 * m.data[i][j];
        bmats.C_27_13.data[i][j]+=-1 * m.data[i][j];
        bmats.C_27_14.data[i][j]+=-1 * m.data[i][j];
        bmats.C_27_15.data[i][j]+=-1 * m.data[i][j];
        bmats.C_27_16.data[i][j]+=-1 * m.data[i][j];
        bmats.C_17_23.data[i][j]+=1 * m.data[i][j];
        bmats.C_18_23.data[i][j]+=1 * m.data[i][j];
        bmats.C_19_23.data[i][j]+=1 * m.data[i][j];
        bmats.C_20_23.data[i][j]+=1 * m.data[i][j];
        bmats.C_21_23.data[i][j]+=1 * m.data[i][j];
        bmats.C_22_23.data[i][j]+=1 * m.data[i][j];
        bmats.C_23_23.data[i][j]+=1 * m.data[i][j];
        bmats.C_24_23.data[i][j]+=1 * m.data[i][j];
        bmats.C_25_23.data[i][j]+=1 * m.data[i][j];
        bmats.C_26_23.data[i][j]+=1 * m.data[i][j];
        bmats.C_27_23.data[i][j]+=1 * m.data[i][j];
        bmats.C_28_23.data[i][j]+=1 * m.data[i][j];
        bmats.C_29_23.data[i][j]+=1 * m.data[i][j];
        bmats.C_30_23.data[i][j]+=1 * m.data[i][j];
        bmats.C_31_23.data[i][j]+=1 * m.data[i][j];
        bmats.C_32_23.data[i][j]+=1 * m.data[i][j];
        bmats.C_7_27.data[i][j]+=17 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}