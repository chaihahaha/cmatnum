#include "fm_3714.h"

inline int fm_3714(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = bmats.Ax1753.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = bmats.B_10_12.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_1_21.data[i][j]+=1 * m.data[i][j];
        bmats.C_2_21.data[i][j]+=1 * m.data[i][j];
        bmats.C_3_21.data[i][j]+=1 * m.data[i][j];
        bmats.C_4_21.data[i][j]+=1 * m.data[i][j];
        bmats.C_5_21.data[i][j]+=1 * m.data[i][j];
        bmats.C_6_21.data[i][j]+=1 * m.data[i][j];
        bmats.C_7_21.data[i][j]+=1 * m.data[i][j];
        bmats.C_8_21.data[i][j]+=1 * m.data[i][j];
        bmats.C_9_21.data[i][j]+=1 * m.data[i][j];
        bmats.C_10_1.data[i][j]+=12 * m.data[i][j];
        bmats.C_10_21.data[i][j]+=1 * m.data[i][j];
        bmats.C_11_21.data[i][j]+=1 * m.data[i][j];
        bmats.C_12_1.data[i][j]+=-1 * m.data[i][j];
        bmats.C_12_2.data[i][j]+=-1 * m.data[i][j];
        bmats.C_12_3.data[i][j]+=-1 * m.data[i][j];
        bmats.C_12_4.data[i][j]+=-1 * m.data[i][j];
        bmats.C_12_5.data[i][j]+=-1 * m.data[i][j];
        bmats.C_12_6.data[i][j]+=-1 * m.data[i][j];
        bmats.C_12_7.data[i][j]+=-1 * m.data[i][j];
        bmats.C_12_8.data[i][j]+=-1 * m.data[i][j];
        bmats.C_12_9.data[i][j]+=-1 * m.data[i][j];
        bmats.C_12_10.data[i][j]+=-1 * m.data[i][j];
        bmats.C_12_11.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
