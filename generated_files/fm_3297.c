#include "fm_3297.h"

inline int fm_3297(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_12_17.data[i][j] + 11*bmats.A_12_18.data[i][j] - bmats.Ax73.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = bmats.B_1_18.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_1_12.data[i][j]+=-1 * m.data[i][j];
        bmats.C_2_12.data[i][j]+=-1 * m.data[i][j];
        bmats.C_3_12.data[i][j]+=-1 * m.data[i][j];
        bmats.C_4_12.data[i][j]+=-1 * m.data[i][j];
        bmats.C_5_12.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_12.data[i][j]+=-1 * m.data[i][j];
        bmats.C_7_12.data[i][j]+=-1 * m.data[i][j];
        bmats.C_8_12.data[i][j]+=-1 * m.data[i][j];
        bmats.C_9_12.data[i][j]+=-1 * m.data[i][j];
        bmats.C_10_12.data[i][j]+=-1 * m.data[i][j];
        bmats.C_11_12.data[i][j]+=-1 * m.data[i][j];
        bmats.C_12_7.data[i][j]+=12 * m.data[i][j];
        bmats.C_18_12.data[i][j]+=1 * m.data[i][j];
        bmats.C_18_13.data[i][j]+=1 * m.data[i][j];
        bmats.C_18_14.data[i][j]+=1 * m.data[i][j];
        bmats.C_18_15.data[i][j]+=1 * m.data[i][j];
        bmats.C_18_16.data[i][j]+=1 * m.data[i][j];
        bmats.C_18_17.data[i][j]+=1 * m.data[i][j];
        bmats.C_18_18.data[i][j]+=1 * m.data[i][j];
        bmats.C_18_19.data[i][j]+=1 * m.data[i][j];
        bmats.C_18_20.data[i][j]+=1 * m.data[i][j];
        bmats.C_18_21.data[i][j]+=1 * m.data[i][j];
        bmats.C_18_22.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
