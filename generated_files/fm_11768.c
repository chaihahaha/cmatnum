#include "fm_11768.h"

inline int fm_11768(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -16*bmats.A_30_19.data[i][j] + bmats.A_30_20.data[i][j] + bmats.Ax1569.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_30_19.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_30_17.data[i][j]+=1 * m.data[i][j];
        bmats.C_30_18.data[i][j]+=1 * m.data[i][j];
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
        bmats.C_30_19.data[i][j]+=2 * m.data[i][j];
        bmats.C_31_19.data[i][j]+=1 * m.data[i][j];
        bmats.C_32_19.data[i][j]+=1 * m.data[i][j];
        bmats.C_30_20.data[i][j]+=1 * m.data[i][j];
        bmats.C_30_21.data[i][j]+=1 * m.data[i][j];
        bmats.C_30_22.data[i][j]+=1 * m.data[i][j];
        bmats.C_30_23.data[i][j]+=1 * m.data[i][j];
        bmats.C_30_24.data[i][j]+=1 * m.data[i][j];
        bmats.C_30_25.data[i][j]+=1 * m.data[i][j];
        bmats.C_30_26.data[i][j]+=1 * m.data[i][j];
        bmats.C_30_27.data[i][j]+=1 * m.data[i][j];
        bmats.C_30_28.data[i][j]+=1 * m.data[i][j];
        bmats.C_30_29.data[i][j]+=1 * m.data[i][j];
        bmats.C_19_30.data[i][j]+=17 * m.data[i][j];
        bmats.C_30_30.data[i][j]+=1 * m.data[i][j];
        bmats.C_30_31.data[i][j]+=1 * m.data[i][j];
        bmats.C_30_32.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}