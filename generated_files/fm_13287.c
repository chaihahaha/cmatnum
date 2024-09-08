#include "fm_13287.h"

inline int fm_13287(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -16*bmats.A_21_17.data[i][j] + bmats.A_21_18.data[i][j] + bmats.Ax182.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_21_17.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_17_17.data[i][j]+=1 * m.data[i][j];
        bmats.C_18_17.data[i][j]+=1 * m.data[i][j];
        bmats.C_19_17.data[i][j]+=1 * m.data[i][j];
        bmats.C_20_17.data[i][j]+=1 * m.data[i][j];
        bmats.C_21_17.data[i][j]+=2 * m.data[i][j];
        bmats.C_22_17.data[i][j]+=1 * m.data[i][j];
        bmats.C_23_17.data[i][j]+=1 * m.data[i][j];
        bmats.C_24_17.data[i][j]+=1 * m.data[i][j];
        bmats.C_25_17.data[i][j]+=1 * m.data[i][j];
        bmats.C_26_17.data[i][j]+=1 * m.data[i][j];
        bmats.C_27_17.data[i][j]+=1 * m.data[i][j];
        bmats.C_28_17.data[i][j]+=1 * m.data[i][j];
        bmats.C_29_17.data[i][j]+=1 * m.data[i][j];
        bmats.C_30_17.data[i][j]+=1 * m.data[i][j];
        bmats.C_31_17.data[i][j]+=1 * m.data[i][j];
        bmats.C_32_17.data[i][j]+=1 * m.data[i][j];
        bmats.C_21_18.data[i][j]+=1 * m.data[i][j];
        bmats.C_21_19.data[i][j]+=1 * m.data[i][j];
        bmats.C_21_20.data[i][j]+=1 * m.data[i][j];
        bmats.C_17_21.data[i][j]+=17 * m.data[i][j];
        bmats.C_21_21.data[i][j]+=1 * m.data[i][j];
        bmats.C_21_22.data[i][j]+=1 * m.data[i][j];
        bmats.C_21_23.data[i][j]+=1 * m.data[i][j];
        bmats.C_21_24.data[i][j]+=1 * m.data[i][j];
        bmats.C_21_25.data[i][j]+=1 * m.data[i][j];
        bmats.C_21_26.data[i][j]+=1 * m.data[i][j];
        bmats.C_21_27.data[i][j]+=1 * m.data[i][j];
        bmats.C_21_28.data[i][j]+=1 * m.data[i][j];
        bmats.C_21_29.data[i][j]+=1 * m.data[i][j];
        bmats.C_21_30.data[i][j]+=1 * m.data[i][j];
        bmats.C_21_31.data[i][j]+=1 * m.data[i][j];
        bmats.C_21_32.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
