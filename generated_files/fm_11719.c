#include "fm_11719.h"

inline int fm_11719(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -16*bmats.A_15_3.data[i][j] + bmats.A_15_4.data[i][j] + bmats.Ax944.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_15_3.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_15_1.data[i][j]+=1 * m.data[i][j];
        bmats.C_15_2.data[i][j]+=1 * m.data[i][j];
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
        bmats.C_15_3.data[i][j]+=2 * m.data[i][j];
        bmats.C_16_3.data[i][j]+=1 * m.data[i][j];
        bmats.C_15_4.data[i][j]+=1 * m.data[i][j];
        bmats.C_15_5.data[i][j]+=1 * m.data[i][j];
        bmats.C_15_6.data[i][j]+=1 * m.data[i][j];
        bmats.C_15_7.data[i][j]+=1 * m.data[i][j];
        bmats.C_15_8.data[i][j]+=1 * m.data[i][j];
        bmats.C_15_9.data[i][j]+=1 * m.data[i][j];
        bmats.C_15_10.data[i][j]+=1 * m.data[i][j];
        bmats.C_15_11.data[i][j]+=1 * m.data[i][j];
        bmats.C_15_12.data[i][j]+=1 * m.data[i][j];
        bmats.C_15_13.data[i][j]+=1 * m.data[i][j];
        bmats.C_15_14.data[i][j]+=1 * m.data[i][j];
        bmats.C_3_15.data[i][j]+=17 * m.data[i][j];
        bmats.C_15_15.data[i][j]+=1 * m.data[i][j];
        bmats.C_15_16.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
