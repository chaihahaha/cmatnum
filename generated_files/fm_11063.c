#include "fm_11063.h"

inline int fm_11063(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = bmats.A_27_23.data[i][j] - 16*bmats.A_27_24.data[i][j] + bmats.Ax79.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_27_24.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_27_17.data[i][j]+=1 * m.data[i][j];
        bmats.C_27_18.data[i][j]+=1 * m.data[i][j];
        bmats.C_27_19.data[i][j]+=1 * m.data[i][j];
        bmats.C_27_20.data[i][j]+=1 * m.data[i][j];
        bmats.C_27_21.data[i][j]+=1 * m.data[i][j];
        bmats.C_27_22.data[i][j]+=1 * m.data[i][j];
        bmats.C_27_23.data[i][j]+=1 * m.data[i][j];
        bmats.C_17_24.data[i][j]+=1 * m.data[i][j];
        bmats.C_18_24.data[i][j]+=1 * m.data[i][j];
        bmats.C_19_24.data[i][j]+=1 * m.data[i][j];
        bmats.C_20_24.data[i][j]+=1 * m.data[i][j];
        bmats.C_21_24.data[i][j]+=1 * m.data[i][j];
        bmats.C_22_24.data[i][j]+=1 * m.data[i][j];
        bmats.C_23_24.data[i][j]+=1 * m.data[i][j];
        bmats.C_24_24.data[i][j]+=1 * m.data[i][j];
        bmats.C_25_24.data[i][j]+=1 * m.data[i][j];
        bmats.C_26_24.data[i][j]+=1 * m.data[i][j];
        bmats.C_27_24.data[i][j]+=2 * m.data[i][j];
        bmats.C_28_24.data[i][j]+=1 * m.data[i][j];
        bmats.C_29_24.data[i][j]+=1 * m.data[i][j];
        bmats.C_30_24.data[i][j]+=1 * m.data[i][j];
        bmats.C_31_24.data[i][j]+=1 * m.data[i][j];
        bmats.C_32_24.data[i][j]+=1 * m.data[i][j];
        bmats.C_27_25.data[i][j]+=1 * m.data[i][j];
        bmats.C_27_26.data[i][j]+=1 * m.data[i][j];
        bmats.C_24_27.data[i][j]+=17 * m.data[i][j];
        bmats.C_27_27.data[i][j]+=1 * m.data[i][j];
        bmats.C_27_28.data[i][j]+=1 * m.data[i][j];
        bmats.C_27_29.data[i][j]+=1 * m.data[i][j];
        bmats.C_27_30.data[i][j]+=1 * m.data[i][j];
        bmats.C_27_31.data[i][j]+=1 * m.data[i][j];
        bmats.C_27_32.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}