#include "fm_3689.h"

inline int fm_3689(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = bmats.A_16_1.data[i][j] + bmats.A_16_10.data[i][j] + bmats.A_16_11.data[i][j] - 11*bmats.A_16_2.data[i][j] + bmats.A_16_3.data[i][j] + bmats.A_16_4.data[i][j] + bmats.A_16_5.data[i][j] + bmats.A_16_6.data[i][j] + bmats.A_16_7.data[i][j] + bmats.A_16_8.data[i][j] + bmats.A_16_9.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = bmats.B_5_13.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_1_16.data[i][j]+=1 * m.data[i][j];
        bmats.C_2_16.data[i][j]+=1 * m.data[i][j];
        bmats.C_3_16.data[i][j]+=1 * m.data[i][j];
        bmats.C_4_16.data[i][j]+=1 * m.data[i][j];
        bmats.C_5_2.data[i][j]+=12 * m.data[i][j];
        bmats.C_5_16.data[i][j]+=1 * m.data[i][j];
        bmats.C_6_16.data[i][j]+=1 * m.data[i][j];
        bmats.C_7_16.data[i][j]+=1 * m.data[i][j];
        bmats.C_8_16.data[i][j]+=1 * m.data[i][j];
        bmats.C_9_16.data[i][j]+=1 * m.data[i][j];
        bmats.C_10_16.data[i][j]+=1 * m.data[i][j];
        bmats.C_11_16.data[i][j]+=1 * m.data[i][j];
        bmats.C_13_1.data[i][j]+=-1 * m.data[i][j];
        bmats.C_13_2.data[i][j]+=-1 * m.data[i][j];
        bmats.C_13_3.data[i][j]+=-1 * m.data[i][j];
        bmats.C_13_4.data[i][j]+=-1 * m.data[i][j];
        bmats.C_13_5.data[i][j]+=-1 * m.data[i][j];
        bmats.C_13_6.data[i][j]+=-1 * m.data[i][j];
        bmats.C_13_7.data[i][j]+=-1 * m.data[i][j];
        bmats.C_13_8.data[i][j]+=-1 * m.data[i][j];
        bmats.C_13_9.data[i][j]+=-1 * m.data[i][j];
        bmats.C_13_10.data[i][j]+=-1 * m.data[i][j];
        bmats.C_13_11.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
