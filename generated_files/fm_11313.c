#include "fm_11313.h"

inline int fm_11313(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = bmats.A_22_21.data[i][j] - 16*bmats.A_22_22.data[i][j] + bmats.Ax204.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_22_22.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_22_17.data[i][j]+=1 * m.data[i][j];
        bmats.C_22_18.data[i][j]+=1 * m.data[i][j];
        bmats.C_22_19.data[i][j]+=1 * m.data[i][j];
        bmats.C_22_20.data[i][j]+=1 * m.data[i][j];
        bmats.C_22_21.data[i][j]+=1 * m.data[i][j];
        bmats.C_17_22.data[i][j]+=1 * m.data[i][j];
        bmats.C_18_22.data[i][j]+=1 * m.data[i][j];
        bmats.C_19_22.data[i][j]+=1 * m.data[i][j];
        bmats.C_20_22.data[i][j]+=1 * m.data[i][j];
        bmats.C_21_22.data[i][j]+=1 * m.data[i][j];
        bmats.C_22_22.data[i][j]+=10 * m.data[i][j];
        bmats.C_23_22.data[i][j]+=1 * m.data[i][j];
        bmats.C_24_22.data[i][j]+=1 * m.data[i][j];
        bmats.C_25_22.data[i][j]+=1 * m.data[i][j];
        bmats.C_26_22.data[i][j]+=1 * m.data[i][j];
        bmats.C_27_22.data[i][j]+=1 * m.data[i][j];
        bmats.C_28_22.data[i][j]+=1 * m.data[i][j];
        bmats.C_29_22.data[i][j]+=1 * m.data[i][j];
        bmats.C_30_22.data[i][j]+=1 * m.data[i][j];
        bmats.C_31_22.data[i][j]+=1 * m.data[i][j];
        bmats.C_32_22.data[i][j]+=1 * m.data[i][j];
        bmats.C_22_23.data[i][j]+=1 * m.data[i][j];
        bmats.C_22_24.data[i][j]+=1 * m.data[i][j];
        bmats.C_22_25.data[i][j]+=1 * m.data[i][j];
        bmats.C_22_26.data[i][j]+=1 * m.data[i][j];
        bmats.C_22_27.data[i][j]+=1 * m.data[i][j];
        bmats.C_22_28.data[i][j]+=1 * m.data[i][j];
        bmats.C_22_29.data[i][j]+=1 * m.data[i][j];
        bmats.C_22_30.data[i][j]+=1 * m.data[i][j];
        bmats.C_22_31.data[i][j]+=1 * m.data[i][j];
        bmats.C_22_32.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
