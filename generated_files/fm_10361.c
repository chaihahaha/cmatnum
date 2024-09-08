#include "fm_10361.h"

inline int fm_10361(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = bmats.A_29_27.data[i][j] - 16*bmats.A_29_28.data[i][j] + bmats.Ax1966.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_29_28.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_29_17.data[i][j]+=1 * m.data[i][j];
        bmats.C_29_18.data[i][j]+=1 * m.data[i][j];
        bmats.C_29_19.data[i][j]+=1 * m.data[i][j];
        bmats.C_29_20.data[i][j]+=1 * m.data[i][j];
        bmats.C_29_21.data[i][j]+=1 * m.data[i][j];
        bmats.C_29_22.data[i][j]+=1 * m.data[i][j];
        bmats.C_29_23.data[i][j]+=1 * m.data[i][j];
        bmats.C_29_24.data[i][j]+=1 * m.data[i][j];
        bmats.C_29_25.data[i][j]+=1 * m.data[i][j];
        bmats.C_29_26.data[i][j]+=1 * m.data[i][j];
        bmats.C_29_27.data[i][j]+=1 * m.data[i][j];
        bmats.C_17_28.data[i][j]+=1 * m.data[i][j];
        bmats.C_18_28.data[i][j]+=1 * m.data[i][j];
        bmats.C_19_28.data[i][j]+=1 * m.data[i][j];
        bmats.C_20_28.data[i][j]+=1 * m.data[i][j];
        bmats.C_21_28.data[i][j]+=1 * m.data[i][j];
        bmats.C_22_28.data[i][j]+=1 * m.data[i][j];
        bmats.C_23_28.data[i][j]+=1 * m.data[i][j];
        bmats.C_24_28.data[i][j]+=1 * m.data[i][j];
        bmats.C_25_28.data[i][j]+=1 * m.data[i][j];
        bmats.C_26_28.data[i][j]+=1 * m.data[i][j];
        bmats.C_27_28.data[i][j]+=1 * m.data[i][j];
        bmats.C_28_28.data[i][j]+=1 * m.data[i][j];
        bmats.C_29_28.data[i][j]+=2 * m.data[i][j];
        bmats.C_30_28.data[i][j]+=1 * m.data[i][j];
        bmats.C_31_28.data[i][j]+=1 * m.data[i][j];
        bmats.C_32_28.data[i][j]+=1 * m.data[i][j];
        bmats.C_28_29.data[i][j]+=17 * m.data[i][j];
        bmats.C_29_29.data[i][j]+=1 * m.data[i][j];
        bmats.C_29_30.data[i][j]+=1 * m.data[i][j];
        bmats.C_29_31.data[i][j]+=1 * m.data[i][j];
        bmats.C_29_32.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
