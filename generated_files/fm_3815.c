#include "fm_3815.h"

inline int fm_3815(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.Ax1393.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = bmats.B_4_12.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_1_15.data[i][j]+=-1 * m.data[i][j];
        bmats.C_2_15.data[i][j]+=-1 * m.data[i][j];
        bmats.C_3_15.data[i][j]+=-1 * m.data[i][j];
        bmats.C_4_15.data[i][j]+=-1 * m.data[i][j];
        bmats.C_5_15.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_15.data[i][j]+=-1 * m.data[i][j];
        bmats.C_7_15.data[i][j]+=-1 * m.data[i][j];
        bmats.C_8_15.data[i][j]+=-1 * m.data[i][j];
        bmats.C_9_15.data[i][j]+=-1 * m.data[i][j];
        bmats.C_10_15.data[i][j]+=-1 * m.data[i][j];
        bmats.C_11_15.data[i][j]+=-1 * m.data[i][j];
        bmats.C_12_12.data[i][j]+=1 * m.data[i][j];
        bmats.C_12_13.data[i][j]+=1 * m.data[i][j];
        bmats.C_12_14.data[i][j]+=1 * m.data[i][j];
        bmats.C_12_15.data[i][j]+=1 * m.data[i][j];
        bmats.C_12_16.data[i][j]+=1 * m.data[i][j];
        bmats.C_12_17.data[i][j]+=1 * m.data[i][j];
        bmats.C_12_18.data[i][j]+=1 * m.data[i][j];
        bmats.C_12_19.data[i][j]+=1 * m.data[i][j];
        bmats.C_12_20.data[i][j]+=1 * m.data[i][j];
        bmats.C_12_21.data[i][j]+=1 * m.data[i][j];
        bmats.C_12_22.data[i][j]+=1 * m.data[i][j];
        bmats.C_15_1.data[i][j]+=12 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
