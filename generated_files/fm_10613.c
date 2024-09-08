#include "fm_10613.h"

inline int fm_10613(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -16*bmats.A_31_11.data[i][j] + bmats.A_31_12.data[i][j] + bmats.Ax2236.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_15_27.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_31_1.data[i][j]+=1 * m.data[i][j];
        bmats.C_31_2.data[i][j]+=1 * m.data[i][j];
        bmats.C_31_3.data[i][j]+=1 * m.data[i][j];
        bmats.C_31_4.data[i][j]+=1 * m.data[i][j];
        bmats.C_31_5.data[i][j]+=1 * m.data[i][j];
        bmats.C_31_6.data[i][j]+=1 * m.data[i][j];
        bmats.C_31_7.data[i][j]+=1 * m.data[i][j];
        bmats.C_31_8.data[i][j]+=1 * m.data[i][j];
        bmats.C_31_9.data[i][j]+=1 * m.data[i][j];
        bmats.C_31_10.data[i][j]+=1 * m.data[i][j];
        bmats.C_31_11.data[i][j]+=1 * m.data[i][j];
        bmats.C_31_12.data[i][j]+=1 * m.data[i][j];
        bmats.C_31_13.data[i][j]+=1 * m.data[i][j];
        bmats.C_31_14.data[i][j]+=1 * m.data[i][j];
        bmats.C_11_15.data[i][j]+=17 * m.data[i][j];
        bmats.C_31_15.data[i][j]+=1 * m.data[i][j];
        bmats.C_31_16.data[i][j]+=1 * m.data[i][j];
        bmats.C_1_27.data[i][j]+=-1 * m.data[i][j];
        bmats.C_2_27.data[i][j]+=-1 * m.data[i][j];
        bmats.C_3_27.data[i][j]+=-1 * m.data[i][j];
        bmats.C_4_27.data[i][j]+=-1 * m.data[i][j];
        bmats.C_5_27.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_27.data[i][j]+=-1 * m.data[i][j];
        bmats.C_7_27.data[i][j]+=-1 * m.data[i][j];
        bmats.C_8_27.data[i][j]+=-1 * m.data[i][j];
        bmats.C_9_27.data[i][j]+=-1 * m.data[i][j];
        bmats.C_10_27.data[i][j]+=-1 * m.data[i][j];
        bmats.C_11_27.data[i][j]+=-1 * m.data[i][j];
        bmats.C_12_27.data[i][j]+=-1 * m.data[i][j];
        bmats.C_13_27.data[i][j]+=-1 * m.data[i][j];
        bmats.C_14_27.data[i][j]+=-1 * m.data[i][j];
        bmats.C_15_27.data[i][j]+=-1 * m.data[i][j];
        bmats.C_16_27.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
