#include "fm_10598.h"

inline int fm_10598(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -16*bmats.A_13_27.data[i][j] + bmats.A_13_28.data[i][j] + bmats.Ax1963.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_29_11.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_17_11.data[i][j]+=-1 * m.data[i][j];
        bmats.C_18_11.data[i][j]+=-1 * m.data[i][j];
        bmats.C_19_11.data[i][j]+=-1 * m.data[i][j];
        bmats.C_20_11.data[i][j]+=-1 * m.data[i][j];
        bmats.C_21_11.data[i][j]+=-1 * m.data[i][j];
        bmats.C_22_11.data[i][j]+=-1 * m.data[i][j];
        bmats.C_23_11.data[i][j]+=-1 * m.data[i][j];
        bmats.C_24_11.data[i][j]+=-1 * m.data[i][j];
        bmats.C_25_11.data[i][j]+=-1 * m.data[i][j];
        bmats.C_26_11.data[i][j]+=-1 * m.data[i][j];
        bmats.C_27_11.data[i][j]+=-1 * m.data[i][j];
        bmats.C_28_11.data[i][j]+=-1 * m.data[i][j];
        bmats.C_29_11.data[i][j]+=-1 * m.data[i][j];
        bmats.C_30_11.data[i][j]+=-1 * m.data[i][j];
        bmats.C_31_11.data[i][j]+=-1 * m.data[i][j];
        bmats.C_32_11.data[i][j]+=-1 * m.data[i][j];
        bmats.C_13_17.data[i][j]+=1 * m.data[i][j];
        bmats.C_13_18.data[i][j]+=1 * m.data[i][j];
        bmats.C_13_19.data[i][j]+=1 * m.data[i][j];
        bmats.C_13_20.data[i][j]+=1 * m.data[i][j];
        bmats.C_13_21.data[i][j]+=1 * m.data[i][j];
        bmats.C_13_22.data[i][j]+=1 * m.data[i][j];
        bmats.C_13_23.data[i][j]+=1 * m.data[i][j];
        bmats.C_13_24.data[i][j]+=1 * m.data[i][j];
        bmats.C_13_25.data[i][j]+=1 * m.data[i][j];
        bmats.C_13_26.data[i][j]+=1 * m.data[i][j];
        bmats.C_13_27.data[i][j]+=1 * m.data[i][j];
        bmats.C_13_28.data[i][j]+=1 * m.data[i][j];
        bmats.C_13_29.data[i][j]+=1 * m.data[i][j];
        bmats.C_27_29.data[i][j]+=17 * m.data[i][j];
        bmats.C_13_30.data[i][j]+=1 * m.data[i][j];
        bmats.C_13_31.data[i][j]+=1 * m.data[i][j];
        bmats.C_13_32.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
