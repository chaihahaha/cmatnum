#include "fm_3353.h"

inline int fm_3353(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -11*bmats.A_1_17.data[i][j] + bmats.A_1_18.data[i][j] + bmats.Ax159.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = bmats.B_12_6.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_6_12.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_13.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_14.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_15.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_16.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_17.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_18.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_19.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_20.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_21.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_22.data[i][j]+=-1 * m.data[i][j];
        bmats.C_12_1.data[i][j]+=1 * m.data[i][j];
        bmats.C_12_17.data[i][j]+=12 * m.data[i][j];
        bmats.C_13_1.data[i][j]+=1 * m.data[i][j];
        bmats.C_14_1.data[i][j]+=1 * m.data[i][j];
        bmats.C_15_1.data[i][j]+=1 * m.data[i][j];
        bmats.C_16_1.data[i][j]+=1 * m.data[i][j];
        bmats.C_17_1.data[i][j]+=1 * m.data[i][j];
        bmats.C_18_1.data[i][j]+=1 * m.data[i][j];
        bmats.C_19_1.data[i][j]+=1 * m.data[i][j];
        bmats.C_20_1.data[i][j]+=1 * m.data[i][j];
        bmats.C_21_1.data[i][j]+=1 * m.data[i][j];
        bmats.C_22_1.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
