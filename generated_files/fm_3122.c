#include "fm_3122.h"

inline int fm_3122(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = bmats.A_3_19.data[i][j] - 11*bmats.A_3_20.data[i][j] + bmats.Ax1476.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = bmats.B_14_9.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_9_12.data[i][j]+=-1 * m.data[i][j];
        bmats.C_9_13.data[i][j]+=-1 * m.data[i][j];
        bmats.C_9_14.data[i][j]+=-1 * m.data[i][j];
        bmats.C_9_15.data[i][j]+=-1 * m.data[i][j];
        bmats.C_9_16.data[i][j]+=-1 * m.data[i][j];
        bmats.C_9_17.data[i][j]+=-1 * m.data[i][j];
        bmats.C_9_18.data[i][j]+=-1 * m.data[i][j];
        bmats.C_9_19.data[i][j]+=-1 * m.data[i][j];
        bmats.C_9_20.data[i][j]+=-1 * m.data[i][j];
        bmats.C_9_21.data[i][j]+=-1 * m.data[i][j];
        bmats.C_9_22.data[i][j]+=-1 * m.data[i][j];
        bmats.C_12_3.data[i][j]+=1 * m.data[i][j];
        bmats.C_13_3.data[i][j]+=1 * m.data[i][j];
        bmats.C_14_3.data[i][j]+=1 * m.data[i][j];
        bmats.C_14_20.data[i][j]+=12 * m.data[i][j];
        bmats.C_15_3.data[i][j]+=1 * m.data[i][j];
        bmats.C_16_3.data[i][j]+=1 * m.data[i][j];
        bmats.C_17_3.data[i][j]+=1 * m.data[i][j];
        bmats.C_18_3.data[i][j]+=1 * m.data[i][j];
        bmats.C_19_3.data[i][j]+=1 * m.data[i][j];
        bmats.C_20_3.data[i][j]+=1 * m.data[i][j];
        bmats.C_21_3.data[i][j]+=1 * m.data[i][j];
        bmats.C_22_3.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
