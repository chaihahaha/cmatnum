#include "fm_3017.h"

inline int fm_3017(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_17_12.data[i][j] - bmats.A_17_13.data[i][j] - bmats.A_17_14.data[i][j] - bmats.A_17_15.data[i][j] - bmats.A_17_16.data[i][j] - bmats.A_17_17.data[i][j] - bmats.A_17_18.data[i][j] - bmats.A_17_19.data[i][j] - bmats.A_17_20.data[i][j] + 11*bmats.A_17_21.data[i][j] - bmats.A_17_22.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = bmats.B_6_21.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_1_17.data[i][j]+=-1 * m.data[i][j];
        bmats.C_2_17.data[i][j]+=-1 * m.data[i][j];
        bmats.C_3_17.data[i][j]+=-1 * m.data[i][j];
        bmats.C_4_17.data[i][j]+=-1 * m.data[i][j];
        bmats.C_5_17.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_17.data[i][j]+=-1 * m.data[i][j];
        bmats.C_7_17.data[i][j]+=-1 * m.data[i][j];
        bmats.C_8_17.data[i][j]+=-1 * m.data[i][j];
        bmats.C_9_17.data[i][j]+=-1 * m.data[i][j];
        bmats.C_10_17.data[i][j]+=-1 * m.data[i][j];
        bmats.C_11_17.data[i][j]+=-1 * m.data[i][j];
        bmats.C_17_10.data[i][j]+=12 * m.data[i][j];
        bmats.C_21_12.data[i][j]+=1 * m.data[i][j];
        bmats.C_21_13.data[i][j]+=1 * m.data[i][j];
        bmats.C_21_14.data[i][j]+=1 * m.data[i][j];
        bmats.C_21_15.data[i][j]+=1 * m.data[i][j];
        bmats.C_21_16.data[i][j]+=1 * m.data[i][j];
        bmats.C_21_17.data[i][j]+=1 * m.data[i][j];
        bmats.C_21_18.data[i][j]+=1 * m.data[i][j];
        bmats.C_21_19.data[i][j]+=1 * m.data[i][j];
        bmats.C_21_20.data[i][j]+=1 * m.data[i][j];
        bmats.C_21_21.data[i][j]+=1 * m.data[i][j];
        bmats.C_21_22.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
