#include "fm_10880.h"

inline int fm_10880(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 16*bmats.A_28_25.data[i][j] - bmats.A_28_26.data[i][j] - bmats.Ax4.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_12_25.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_28_1.data[i][j]+=-1 * m.data[i][j];
        bmats.C_28_2.data[i][j]+=-1 * m.data[i][j];
        bmats.C_28_3.data[i][j]+=-1 * m.data[i][j];
        bmats.C_28_4.data[i][j]+=-1 * m.data[i][j];
        bmats.C_28_5.data[i][j]+=-1 * m.data[i][j];
        bmats.C_28_6.data[i][j]+=-1 * m.data[i][j];
        bmats.C_28_7.data[i][j]+=-1 * m.data[i][j];
        bmats.C_28_8.data[i][j]+=-1 * m.data[i][j];
        bmats.C_28_9.data[i][j]+=-1 * m.data[i][j];
        bmats.C_28_10.data[i][j]+=-1 * m.data[i][j];
        bmats.C_28_11.data[i][j]+=-1 * m.data[i][j];
        bmats.C_28_12.data[i][j]+=-1 * m.data[i][j];
        bmats.C_28_13.data[i][j]+=-1 * m.data[i][j];
        bmats.C_28_14.data[i][j]+=-1 * m.data[i][j];
        bmats.C_28_15.data[i][j]+=-1 * m.data[i][j];
        bmats.C_28_16.data[i][j]+=-1 * m.data[i][j];
        bmats.C_17_25.data[i][j]+=1 * m.data[i][j];
        bmats.C_18_25.data[i][j]+=1 * m.data[i][j];
        bmats.C_19_25.data[i][j]+=1 * m.data[i][j];
        bmats.C_20_25.data[i][j]+=1 * m.data[i][j];
        bmats.C_21_25.data[i][j]+=1 * m.data[i][j];
        bmats.C_22_25.data[i][j]+=1 * m.data[i][j];
        bmats.C_23_25.data[i][j]+=1 * m.data[i][j];
        bmats.C_24_25.data[i][j]+=1 * m.data[i][j];
        bmats.C_25_25.data[i][j]+=1 * m.data[i][j];
        bmats.C_26_25.data[i][j]+=1 * m.data[i][j];
        bmats.C_27_25.data[i][j]+=1 * m.data[i][j];
        bmats.C_28_25.data[i][j]+=1 * m.data[i][j];
        bmats.C_29_25.data[i][j]+=1 * m.data[i][j];
        bmats.C_30_25.data[i][j]+=1 * m.data[i][j];
        bmats.C_31_25.data[i][j]+=1 * m.data[i][j];
        bmats.C_32_25.data[i][j]+=1 * m.data[i][j];
        bmats.C_9_28.data[i][j]+=17 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
