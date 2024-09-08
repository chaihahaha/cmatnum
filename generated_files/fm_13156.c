#include "fm_13156.h"

inline int fm_13156(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = bmats.A_17_17.data[i][j] - 16*bmats.A_17_18.data[i][j] + bmats.Ax4655.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_17_18.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_17_17.data[i][j]+=1 * m.data[i][j];
        bmats.C_18_17.data[i][j]+=17 * m.data[i][j];
        bmats.C_17_18.data[i][j]+=2 * m.data[i][j];
        bmats.C_18_18.data[i][j]+=1 * m.data[i][j];
        bmats.C_19_18.data[i][j]+=1 * m.data[i][j];
        bmats.C_20_18.data[i][j]+=1 * m.data[i][j];
        bmats.C_21_18.data[i][j]+=1 * m.data[i][j];
        bmats.C_22_18.data[i][j]+=1 * m.data[i][j];
        bmats.C_23_18.data[i][j]+=1 * m.data[i][j];
        bmats.C_24_18.data[i][j]+=1 * m.data[i][j];
        bmats.C_25_18.data[i][j]+=1 * m.data[i][j];
        bmats.C_26_18.data[i][j]+=1 * m.data[i][j];
        bmats.C_27_18.data[i][j]+=1 * m.data[i][j];
        bmats.C_28_18.data[i][j]+=1 * m.data[i][j];
        bmats.C_29_18.data[i][j]+=1 * m.data[i][j];
        bmats.C_30_18.data[i][j]+=1 * m.data[i][j];
        bmats.C_31_18.data[i][j]+=1 * m.data[i][j];
        bmats.C_32_18.data[i][j]+=1 * m.data[i][j];
        bmats.C_17_19.data[i][j]+=1 * m.data[i][j];
        bmats.C_17_20.data[i][j]+=1 * m.data[i][j];
        bmats.C_17_21.data[i][j]+=1 * m.data[i][j];
        bmats.C_17_22.data[i][j]+=1 * m.data[i][j];
        bmats.C_17_23.data[i][j]+=1 * m.data[i][j];
        bmats.C_17_24.data[i][j]+=1 * m.data[i][j];
        bmats.C_17_25.data[i][j]+=1 * m.data[i][j];
        bmats.C_17_26.data[i][j]+=1 * m.data[i][j];
        bmats.C_17_27.data[i][j]+=1 * m.data[i][j];
        bmats.C_17_28.data[i][j]+=1 * m.data[i][j];
        bmats.C_17_29.data[i][j]+=1 * m.data[i][j];
        bmats.C_17_30.data[i][j]+=1 * m.data[i][j];
        bmats.C_17_31.data[i][j]+=1 * m.data[i][j];
        bmats.C_17_32.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
