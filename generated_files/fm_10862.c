#include "fm_10862.h"

inline int fm_10862(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = bmats.A_2_25.data[i][j] - 16*bmats.A_2_26.data[i][j] + bmats.Ax2872.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_18_10.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_17_10.data[i][j]+=-1 * m.data[i][j];
        bmats.C_18_10.data[i][j]+=-1 * m.data[i][j];
        bmats.C_19_10.data[i][j]+=-1 * m.data[i][j];
        bmats.C_20_10.data[i][j]+=-1 * m.data[i][j];
        bmats.C_21_10.data[i][j]+=-1 * m.data[i][j];
        bmats.C_22_10.data[i][j]+=-1 * m.data[i][j];
        bmats.C_23_10.data[i][j]+=-1 * m.data[i][j];
        bmats.C_24_10.data[i][j]+=-1 * m.data[i][j];
        bmats.C_25_10.data[i][j]+=-1 * m.data[i][j];
        bmats.C_26_10.data[i][j]+=-1 * m.data[i][j];
        bmats.C_27_10.data[i][j]+=-1 * m.data[i][j];
        bmats.C_28_10.data[i][j]+=-1 * m.data[i][j];
        bmats.C_29_10.data[i][j]+=-1 * m.data[i][j];
        bmats.C_30_10.data[i][j]+=-1 * m.data[i][j];
        bmats.C_31_10.data[i][j]+=-1 * m.data[i][j];
        bmats.C_32_10.data[i][j]+=-1 * m.data[i][j];
        bmats.C_2_17.data[i][j]+=1 * m.data[i][j];
        bmats.C_2_18.data[i][j]+=1 * m.data[i][j];
        bmats.C_26_18.data[i][j]+=17 * m.data[i][j];
        bmats.C_2_19.data[i][j]+=1 * m.data[i][j];
        bmats.C_2_20.data[i][j]+=1 * m.data[i][j];
        bmats.C_2_21.data[i][j]+=1 * m.data[i][j];
        bmats.C_2_22.data[i][j]+=1 * m.data[i][j];
        bmats.C_2_23.data[i][j]+=1 * m.data[i][j];
        bmats.C_2_24.data[i][j]+=1 * m.data[i][j];
        bmats.C_2_25.data[i][j]+=1 * m.data[i][j];
        bmats.C_2_26.data[i][j]+=1 * m.data[i][j];
        bmats.C_2_27.data[i][j]+=1 * m.data[i][j];
        bmats.C_2_28.data[i][j]+=1 * m.data[i][j];
        bmats.C_2_29.data[i][j]+=1 * m.data[i][j];
        bmats.C_2_30.data[i][j]+=1 * m.data[i][j];
        bmats.C_2_31.data[i][j]+=1 * m.data[i][j];
        bmats.C_2_32.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
