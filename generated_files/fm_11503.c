#include "fm_11503.h"

inline int fm_11503(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 16*bmats.A_25_21.data[i][j] - bmats.A_25_22.data[i][j] - bmats.Ax128.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_9_21.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_25_1.data[i][j]+=-1 * m.data[i][j];
        bmats.C_25_2.data[i][j]+=-1 * m.data[i][j];
        bmats.C_25_3.data[i][j]+=-1 * m.data[i][j];
        bmats.C_25_4.data[i][j]+=-1 * m.data[i][j];
        bmats.C_25_5.data[i][j]+=-1 * m.data[i][j];
        bmats.C_25_6.data[i][j]+=-1 * m.data[i][j];
        bmats.C_25_7.data[i][j]+=-1 * m.data[i][j];
        bmats.C_25_8.data[i][j]+=-1 * m.data[i][j];
        bmats.C_25_9.data[i][j]+=-1 * m.data[i][j];
        bmats.C_25_10.data[i][j]+=-1 * m.data[i][j];
        bmats.C_25_11.data[i][j]+=-1 * m.data[i][j];
        bmats.C_25_12.data[i][j]+=-1 * m.data[i][j];
        bmats.C_25_13.data[i][j]+=-1 * m.data[i][j];
        bmats.C_25_14.data[i][j]+=-1 * m.data[i][j];
        bmats.C_25_15.data[i][j]+=-1 * m.data[i][j];
        bmats.C_25_16.data[i][j]+=-1 * m.data[i][j];
        bmats.C_17_21.data[i][j]+=1 * m.data[i][j];
        bmats.C_18_21.data[i][j]+=1 * m.data[i][j];
        bmats.C_19_21.data[i][j]+=1 * m.data[i][j];
        bmats.C_20_21.data[i][j]+=1 * m.data[i][j];
        bmats.C_21_21.data[i][j]+=1 * m.data[i][j];
        bmats.C_22_21.data[i][j]+=1 * m.data[i][j];
        bmats.C_23_21.data[i][j]+=1 * m.data[i][j];
        bmats.C_24_21.data[i][j]+=1 * m.data[i][j];
        bmats.C_25_21.data[i][j]+=1 * m.data[i][j];
        bmats.C_26_21.data[i][j]+=1 * m.data[i][j];
        bmats.C_27_21.data[i][j]+=1 * m.data[i][j];
        bmats.C_28_21.data[i][j]+=1 * m.data[i][j];
        bmats.C_29_21.data[i][j]+=1 * m.data[i][j];
        bmats.C_30_21.data[i][j]+=1 * m.data[i][j];
        bmats.C_31_21.data[i][j]+=1 * m.data[i][j];
        bmats.C_32_21.data[i][j]+=1 * m.data[i][j];
        bmats.C_5_25.data[i][j]+=17 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
