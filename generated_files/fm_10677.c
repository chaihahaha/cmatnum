#include "fm_10677.h"

inline int fm_10677(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 16*bmats.A_6_11.data[i][j] - bmats.A_6_12.data[i][j] - bmats.Ax2193.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_22_11.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_27_6.data[i][j]+=17 * m.data[i][j];
        bmats.C_1_11.data[i][j]+=1 * m.data[i][j];
        bmats.C_2_11.data[i][j]+=1 * m.data[i][j];
        bmats.C_3_11.data[i][j]+=1 * m.data[i][j];
        bmats.C_4_11.data[i][j]+=1 * m.data[i][j];
        bmats.C_5_11.data[i][j]+=1 * m.data[i][j];
        bmats.C_6_11.data[i][j]+=1 * m.data[i][j];
        bmats.C_7_11.data[i][j]+=1 * m.data[i][j];
        bmats.C_8_11.data[i][j]+=1 * m.data[i][j];
        bmats.C_9_11.data[i][j]+=1 * m.data[i][j];
        bmats.C_10_11.data[i][j]+=1 * m.data[i][j];
        bmats.C_11_11.data[i][j]+=1 * m.data[i][j];
        bmats.C_12_11.data[i][j]+=1 * m.data[i][j];
        bmats.C_13_11.data[i][j]+=1 * m.data[i][j];
        bmats.C_14_11.data[i][j]+=1 * m.data[i][j];
        bmats.C_15_11.data[i][j]+=1 * m.data[i][j];
        bmats.C_16_11.data[i][j]+=1 * m.data[i][j];
        bmats.C_6_17.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_18.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_19.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_20.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_21.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_22.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_23.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_24.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_25.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_26.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_27.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_28.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_29.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_30.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_31.data[i][j]+=-1 * m.data[i][j];
        bmats.C_6_32.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}