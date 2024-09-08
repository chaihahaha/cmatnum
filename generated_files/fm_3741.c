#include "fm_3741.h"

inline int fm_3741(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 11*bmats.A_13_13.data[i][j] - bmats.A_13_14.data[i][j] - bmats.Ax1458.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = bmats.B_2_13.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_1_13.data[i][j]+=-1 * m.data[i][j];
        bmats.C_2_13.data[i][j]+=-1 * m.data[i][j];
        bmats.C_3_13.data[i][j]+=-1 * m.data[i][j];
        bmats.C_4_13.data[i][j]+=-1 * m.data[i][j];
        bmats.C_5_13.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_13.data[i][j]+=-1 * m.data[i][j];
        bmats.C_7_13.data[i][j]+=-1 * m.data[i][j];
        bmats.C_8_13.data[i][j]+=-1 * m.data[i][j];
        bmats.C_9_13.data[i][j]+=-1 * m.data[i][j];
        bmats.C_10_13.data[i][j]+=-1 * m.data[i][j];
        bmats.C_11_13.data[i][j]+=-1 * m.data[i][j];
        bmats.C_13_2.data[i][j]+=12 * m.data[i][j];
        bmats.C_13_12.data[i][j]+=1 * m.data[i][j];
        bmats.C_13_13.data[i][j]+=1 * m.data[i][j];
        bmats.C_13_14.data[i][j]+=1 * m.data[i][j];
        bmats.C_13_15.data[i][j]+=1 * m.data[i][j];
        bmats.C_13_16.data[i][j]+=1 * m.data[i][j];
        bmats.C_13_17.data[i][j]+=1 * m.data[i][j];
        bmats.C_13_18.data[i][j]+=1 * m.data[i][j];
        bmats.C_13_19.data[i][j]+=1 * m.data[i][j];
        bmats.C_13_20.data[i][j]+=1 * m.data[i][j];
        bmats.C_13_21.data[i][j]+=1 * m.data[i][j];
        bmats.C_13_22.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
