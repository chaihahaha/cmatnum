#include "fm_3756.h"

inline int fm_3756(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = bmats.Ax991.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = bmats.B_17_1.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_1_12.data[i][j]+=-1 * m.data[i][j];
        bmats.C_1_13.data[i][j]+=-1 * m.data[i][j];
        bmats.C_1_14.data[i][j]+=-1 * m.data[i][j];
        bmats.C_1_15.data[i][j]+=-1 * m.data[i][j];
        bmats.C_1_16.data[i][j]+=-1 * m.data[i][j];
        bmats.C_1_17.data[i][j]+=-1 * m.data[i][j];
        bmats.C_1_18.data[i][j]+=-1 * m.data[i][j];
        bmats.C_1_19.data[i][j]+=-1 * m.data[i][j];
        bmats.C_1_20.data[i][j]+=-1 * m.data[i][j];
        bmats.C_1_21.data[i][j]+=-1 * m.data[i][j];
        bmats.C_1_22.data[i][j]+=-1 * m.data[i][j];
        bmats.C_12_6.data[i][j]+=1 * m.data[i][j];
        bmats.C_13_6.data[i][j]+=1 * m.data[i][j];
        bmats.C_14_6.data[i][j]+=1 * m.data[i][j];
        bmats.C_15_6.data[i][j]+=1 * m.data[i][j];
        bmats.C_16_6.data[i][j]+=1 * m.data[i][j];
        bmats.C_17_6.data[i][j]+=1 * m.data[i][j];
        bmats.C_17_12.data[i][j]+=12 * m.data[i][j];
        bmats.C_18_6.data[i][j]+=1 * m.data[i][j];
        bmats.C_19_6.data[i][j]+=1 * m.data[i][j];
        bmats.C_20_6.data[i][j]+=1 * m.data[i][j];
        bmats.C_21_6.data[i][j]+=1 * m.data[i][j];
        bmats.C_22_6.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
