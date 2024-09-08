#include "fm_9981.h"

inline int fm_9981(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -16*bmats.A_8_31.data[i][j] + bmats.A_8_32.data[i][j] + bmats.Ax766.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_24_15.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_17_15.data[i][j]+=-1 * m.data[i][j];
        bmats.C_18_15.data[i][j]+=-1 * m.data[i][j];
        bmats.C_19_15.data[i][j]+=-1 * m.data[i][j];
        bmats.C_20_15.data[i][j]+=-1 * m.data[i][j];
        bmats.C_21_15.data[i][j]+=-1 * m.data[i][j];
        bmats.C_22_15.data[i][j]+=-1 * m.data[i][j];
        bmats.C_23_15.data[i][j]+=-1 * m.data[i][j];
        bmats.C_24_15.data[i][j]+=-1 * m.data[i][j];
        bmats.C_25_15.data[i][j]+=-1 * m.data[i][j];
        bmats.C_26_15.data[i][j]+=-1 * m.data[i][j];
        bmats.C_27_15.data[i][j]+=-1 * m.data[i][j];
        bmats.C_28_15.data[i][j]+=-1 * m.data[i][j];
        bmats.C_29_15.data[i][j]+=-1 * m.data[i][j];
        bmats.C_30_15.data[i][j]+=-1 * m.data[i][j];
        bmats.C_31_15.data[i][j]+=-1 * m.data[i][j];
        bmats.C_32_15.data[i][j]+=-1 * m.data[i][j];
        bmats.C_8_17.data[i][j]+=1 * m.data[i][j];
        bmats.C_8_18.data[i][j]+=1 * m.data[i][j];
        bmats.C_8_19.data[i][j]+=1 * m.data[i][j];
        bmats.C_8_20.data[i][j]+=1 * m.data[i][j];
        bmats.C_8_21.data[i][j]+=1 * m.data[i][j];
        bmats.C_8_22.data[i][j]+=1 * m.data[i][j];
        bmats.C_8_23.data[i][j]+=1 * m.data[i][j];
        bmats.C_8_24.data[i][j]+=1 * m.data[i][j];
        bmats.C_31_24.data[i][j]+=17 * m.data[i][j];
        bmats.C_8_25.data[i][j]+=1 * m.data[i][j];
        bmats.C_8_26.data[i][j]+=1 * m.data[i][j];
        bmats.C_8_27.data[i][j]+=1 * m.data[i][j];
        bmats.C_8_28.data[i][j]+=1 * m.data[i][j];
        bmats.C_8_29.data[i][j]+=1 * m.data[i][j];
        bmats.C_8_30.data[i][j]+=1 * m.data[i][j];
        bmats.C_8_31.data[i][j]+=1 * m.data[i][j];
        bmats.C_8_32.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
