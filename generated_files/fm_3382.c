#include "fm_3382.h"

inline int fm_3382(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = bmats.A_5_1.data[i][j] + bmats.A_5_10.data[i][j] + bmats.A_5_11.data[i][j] + bmats.A_5_2.data[i][j] + bmats.A_5_3.data[i][j] + bmats.A_5_4.data[i][j] + bmats.A_5_5.data[i][j] - 11*bmats.A_5_6.data[i][j] + bmats.A_5_7.data[i][j] + bmats.A_5_8.data[i][j] + bmats.A_5_9.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = bmats.B_5_6.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_1_5.data[i][j]+=1 * m.data[i][j];
        bmats.C_2_5.data[i][j]+=1 * m.data[i][j];
        bmats.C_3_5.data[i][j]+=1 * m.data[i][j];
        bmats.C_4_5.data[i][j]+=1 * m.data[i][j];
        bmats.C_5_5.data[i][j]+=1 * m.data[i][j];
        bmats.C_5_6.data[i][j]+=12 * m.data[i][j];
        bmats.C_6_1.data[i][j]+=1 * m.data[i][j];
        bmats.C_6_2.data[i][j]+=1 * m.data[i][j];
        bmats.C_6_3.data[i][j]+=1 * m.data[i][j];
        bmats.C_6_4.data[i][j]+=1 * m.data[i][j];
        bmats.C_6_5.data[i][j]+=2 * m.data[i][j];
        bmats.C_6_6.data[i][j]+=1 * m.data[i][j];
        bmats.C_6_7.data[i][j]+=1 * m.data[i][j];
        bmats.C_6_8.data[i][j]+=1 * m.data[i][j];
        bmats.C_6_9.data[i][j]+=1 * m.data[i][j];
        bmats.C_6_10.data[i][j]+=1 * m.data[i][j];
        bmats.C_6_11.data[i][j]+=1 * m.data[i][j];
        bmats.C_7_5.data[i][j]+=1 * m.data[i][j];
        bmats.C_8_5.data[i][j]+=1 * m.data[i][j];
        bmats.C_9_5.data[i][j]+=1 * m.data[i][j];
        bmats.C_10_5.data[i][j]+=1 * m.data[i][j];
        bmats.C_11_5.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
