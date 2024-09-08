#include "fm_3355.h"

inline int fm_3355(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 11*bmats.A_12_17.data[i][j] - bmats.A_12_18.data[i][j] - bmats.Ax73.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = bmats.B_1_17.data[i][j];
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
        bmats.C_12_6.data[i][j]+=12 * m.data[i][j];
        bmats.C_17_12.data[i][j]+=1 * m.data[i][j];
        bmats.C_17_13.data[i][j]+=1 * m.data[i][j];
        bmats.C_17_14.data[i][j]+=1 * m.data[i][j];
        bmats.C_17_15.data[i][j]+=1 * m.data[i][j];
        bmats.C_17_16.data[i][j]+=1 * m.data[i][j];
        bmats.C_17_17.data[i][j]+=1 * m.data[i][j];
        bmats.C_17_18.data[i][j]+=1 * m.data[i][j];
        bmats.C_17_19.data[i][j]+=1 * m.data[i][j];
        bmats.C_17_20.data[i][j]+=1 * m.data[i][j];
        bmats.C_17_21.data[i][j]+=1 * m.data[i][j];
        bmats.C_17_22.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
