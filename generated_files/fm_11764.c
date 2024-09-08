#include "fm_11764.h"

inline int fm_11764(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 16*bmats.A_29_19.data[i][j] - bmats.A_29_20.data[i][j] - bmats.Ax2149.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_13_19.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_29_1.data[i][j]+=-1 * m.data[i][j];
        bmats.C_29_2.data[i][j]+=-1 * m.data[i][j];
        bmats.C_29_3.data[i][j]+=-1 * m.data[i][j];
        bmats.C_29_4.data[i][j]+=-1 * m.data[i][j];
        bmats.C_29_5.data[i][j]+=-1 * m.data[i][j];
        bmats.C_29_6.data[i][j]+=-1 * m.data[i][j];
        bmats.C_29_7.data[i][j]+=-1 * m.data[i][j];
        bmats.C_29_8.data[i][j]+=-1 * m.data[i][j];
        bmats.C_29_9.data[i][j]+=-1 * m.data[i][j];
        bmats.C_29_10.data[i][j]+=-1 * m.data[i][j];
        bmats.C_29_11.data[i][j]+=-1 * m.data[i][j];
        bmats.C_29_12.data[i][j]+=-1 * m.data[i][j];
        bmats.C_29_13.data[i][j]+=-1 * m.data[i][j];
        bmats.C_29_14.data[i][j]+=-1 * m.data[i][j];
        bmats.C_29_15.data[i][j]+=-1 * m.data[i][j];
        bmats.C_29_16.data[i][j]+=-1 * m.data[i][j];
        bmats.C_17_19.data[i][j]+=1 * m.data[i][j];
        bmats.C_18_19.data[i][j]+=1 * m.data[i][j];
        bmats.C_19_19.data[i][j]+=1 * m.data[i][j];
        bmats.C_20_19.data[i][j]+=1 * m.data[i][j];
        bmats.C_21_19.data[i][j]+=1 * m.data[i][j];
        bmats.C_22_19.data[i][j]+=1 * m.data[i][j];
        bmats.C_23_19.data[i][j]+=1 * m.data[i][j];
        bmats.C_24_19.data[i][j]+=1 * m.data[i][j];
        bmats.C_25_19.data[i][j]+=1 * m.data[i][j];
        bmats.C_26_19.data[i][j]+=1 * m.data[i][j];
        bmats.C_27_19.data[i][j]+=1 * m.data[i][j];
        bmats.C_28_19.data[i][j]+=1 * m.data[i][j];
        bmats.C_29_19.data[i][j]+=1 * m.data[i][j];
        bmats.C_30_19.data[i][j]+=1 * m.data[i][j];
        bmats.C_31_19.data[i][j]+=1 * m.data[i][j];
        bmats.C_32_19.data[i][j]+=1 * m.data[i][j];
        bmats.C_3_29.data[i][j]+=17 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
