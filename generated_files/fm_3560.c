#include "fm_3560.h"

inline int fm_3560(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 11*bmats.A_14_15.data[i][j] - bmats.A_14_16.data[i][j] - bmats.Ax864.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = bmats.B_3_15.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_1_14.data[i][j]+=-1 * m.data[i][j];
        bmats.C_2_14.data[i][j]+=-1 * m.data[i][j];
        bmats.C_3_14.data[i][j]+=-1 * m.data[i][j];
        bmats.C_4_14.data[i][j]+=-1 * m.data[i][j];
        bmats.C_5_14.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_14.data[i][j]+=-1 * m.data[i][j];
        bmats.C_7_14.data[i][j]+=-1 * m.data[i][j];
        bmats.C_8_14.data[i][j]+=-1 * m.data[i][j];
        bmats.C_9_14.data[i][j]+=-1 * m.data[i][j];
        bmats.C_10_14.data[i][j]+=-1 * m.data[i][j];
        bmats.C_11_14.data[i][j]+=-1 * m.data[i][j];
        bmats.C_14_4.data[i][j]+=12 * m.data[i][j];
        bmats.C_15_12.data[i][j]+=1 * m.data[i][j];
        bmats.C_15_13.data[i][j]+=1 * m.data[i][j];
        bmats.C_15_14.data[i][j]+=1 * m.data[i][j];
        bmats.C_15_15.data[i][j]+=1 * m.data[i][j];
        bmats.C_15_16.data[i][j]+=1 * m.data[i][j];
        bmats.C_15_17.data[i][j]+=1 * m.data[i][j];
        bmats.C_15_18.data[i][j]+=1 * m.data[i][j];
        bmats.C_15_19.data[i][j]+=1 * m.data[i][j];
        bmats.C_15_20.data[i][j]+=1 * m.data[i][j];
        bmats.C_15_21.data[i][j]+=1 * m.data[i][j];
        bmats.C_15_22.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
