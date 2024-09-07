#include "fm_3697.h"

inline int fm_3697(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = bmats.A_17_1.data[i][j] + bmats.A_17_10.data[i][j] + bmats.A_17_11.data[i][j] - 11*bmats.A_17_2.data[i][j] + bmats.A_17_3.data[i][j] + bmats.A_17_4.data[i][j] + bmats.A_17_5.data[i][j] + bmats.A_17_6.data[i][j] + bmats.A_17_7.data[i][j] + bmats.A_17_8.data[i][j] + bmats.A_17_9.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = bmats.B_6_13.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_1_17.data[i][j]+=1 * m.data[i][j];
        bmats.C_2_17.data[i][j]+=1 * m.data[i][j];
        bmats.C_3_17.data[i][j]+=1 * m.data[i][j];
        bmats.C_4_17.data[i][j]+=1 * m.data[i][j];
        bmats.C_5_17.data[i][j]+=1 * m.data[i][j];
        bmats.C_6_2.data[i][j]+=12 * m.data[i][j];
        bmats.C_6_17.data[i][j]+=1 * m.data[i][j];
        bmats.C_7_17.data[i][j]+=1 * m.data[i][j];
        bmats.C_8_17.data[i][j]+=1 * m.data[i][j];
        bmats.C_9_17.data[i][j]+=1 * m.data[i][j];
        bmats.C_10_17.data[i][j]+=1 * m.data[i][j];
        bmats.C_11_17.data[i][j]+=1 * m.data[i][j];
        bmats.C_13_1.data[i][j]+=-1 * m.data[i][j];
        bmats.C_13_2.data[i][j]+=-1 * m.data[i][j];
        bmats.C_13_3.data[i][j]+=-1 * m.data[i][j];
        bmats.C_13_4.data[i][j]+=-1 * m.data[i][j];
        bmats.C_13_5.data[i][j]+=-1 * m.data[i][j];
        bmats.C_13_6.data[i][j]+=-1 * m.data[i][j];
        bmats.C_13_7.data[i][j]+=-1 * m.data[i][j];
        bmats.C_13_8.data[i][j]+=-1 * m.data[i][j];
        bmats.C_13_9.data[i][j]+=-1 * m.data[i][j];
        bmats.C_13_10.data[i][j]+=-1 * m.data[i][j];
        bmats.C_13_11.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
