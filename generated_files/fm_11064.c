#include "fm_11064.h"

inline int fm_11064(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = bmats.A_27_7.data[i][j] - 16*bmats.A_27_8.data[i][j] + bmats.Ax2726.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_11_24.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_27_1.data[i][j]+=1 * m.data[i][j];
        bmats.C_27_2.data[i][j]+=1 * m.data[i][j];
        bmats.C_27_3.data[i][j]+=1 * m.data[i][j];
        bmats.C_27_4.data[i][j]+=1 * m.data[i][j];
        bmats.C_27_5.data[i][j]+=1 * m.data[i][j];
        bmats.C_27_6.data[i][j]+=1 * m.data[i][j];
        bmats.C_27_7.data[i][j]+=1 * m.data[i][j];
        bmats.C_27_8.data[i][j]+=1 * m.data[i][j];
        bmats.C_27_9.data[i][j]+=1 * m.data[i][j];
        bmats.C_27_10.data[i][j]+=1 * m.data[i][j];
        bmats.C_8_11.data[i][j]+=17 * m.data[i][j];
        bmats.C_27_11.data[i][j]+=1 * m.data[i][j];
        bmats.C_27_12.data[i][j]+=1 * m.data[i][j];
        bmats.C_27_13.data[i][j]+=1 * m.data[i][j];
        bmats.C_27_14.data[i][j]+=1 * m.data[i][j];
        bmats.C_27_15.data[i][j]+=1 * m.data[i][j];
        bmats.C_27_16.data[i][j]+=1 * m.data[i][j];
        bmats.C_1_24.data[i][j]+=-1 * m.data[i][j];
        bmats.C_2_24.data[i][j]+=-1 * m.data[i][j];
        bmats.C_3_24.data[i][j]+=-1 * m.data[i][j];
        bmats.C_4_24.data[i][j]+=-1 * m.data[i][j];
        bmats.C_5_24.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_24.data[i][j]+=-1 * m.data[i][j];
        bmats.C_7_24.data[i][j]+=-1 * m.data[i][j];
        bmats.C_8_24.data[i][j]+=-1 * m.data[i][j];
        bmats.C_9_24.data[i][j]+=-1 * m.data[i][j];
        bmats.C_10_24.data[i][j]+=-1 * m.data[i][j];
        bmats.C_11_24.data[i][j]+=-1 * m.data[i][j];
        bmats.C_12_24.data[i][j]+=-1 * m.data[i][j];
        bmats.C_13_24.data[i][j]+=-1 * m.data[i][j];
        bmats.C_14_24.data[i][j]+=-1 * m.data[i][j];
        bmats.C_15_24.data[i][j]+=-1 * m.data[i][j];
        bmats.C_16_24.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}