#include "fm_3204.h"

inline int fm_3204(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = bmats.A_19_6.data[i][j] - 11*bmats.A_19_7.data[i][j] + bmats.Ax83.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = bmats.B_8_18.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_1_19.data[i][j]+=1 * m.data[i][j];
        bmats.C_2_19.data[i][j]+=1 * m.data[i][j];
        bmats.C_3_19.data[i][j]+=1 * m.data[i][j];
        bmats.C_4_19.data[i][j]+=1 * m.data[i][j];
        bmats.C_5_19.data[i][j]+=1 * m.data[i][j];
        bmats.C_6_19.data[i][j]+=1 * m.data[i][j];
        bmats.C_7_19.data[i][j]+=1 * m.data[i][j];
        bmats.C_8_7.data[i][j]+=12 * m.data[i][j];
        bmats.C_8_19.data[i][j]+=1 * m.data[i][j];
        bmats.C_9_19.data[i][j]+=1 * m.data[i][j];
        bmats.C_10_19.data[i][j]+=1 * m.data[i][j];
        bmats.C_11_19.data[i][j]+=1 * m.data[i][j];
        bmats.C_18_1.data[i][j]+=-1 * m.data[i][j];
        bmats.C_18_2.data[i][j]+=-1 * m.data[i][j];
        bmats.C_18_3.data[i][j]+=-1 * m.data[i][j];
        bmats.C_18_4.data[i][j]+=-1 * m.data[i][j];
        bmats.C_18_5.data[i][j]+=-1 * m.data[i][j];
        bmats.C_18_6.data[i][j]+=-1 * m.data[i][j];
        bmats.C_18_7.data[i][j]+=-1 * m.data[i][j];
        bmats.C_18_8.data[i][j]+=-1 * m.data[i][j];
        bmats.C_18_9.data[i][j]+=-1 * m.data[i][j];
        bmats.C_18_10.data[i][j]+=-1 * m.data[i][j];
        bmats.C_18_11.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
