#include "fm_10704.h"

inline int fm_10704(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -16*bmats.A_1_27.data[i][j] + bmats.A_1_28.data[i][j] + bmats.Ax2309.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_17_11.data[i][j];
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
        bmats.C_1_17.data[i][j]+=1 * m.data[i][j];
        bmats.C_27_17.data[i][j]+=17 * m.data[i][j];
        bmats.C_1_18.data[i][j]+=1 * m.data[i][j];
        bmats.C_1_19.data[i][j]+=1 * m.data[i][j];
        bmats.C_1_20.data[i][j]+=1 * m.data[i][j];
        bmats.C_1_21.data[i][j]+=1 * m.data[i][j];
        bmats.C_1_22.data[i][j]+=1 * m.data[i][j];
        bmats.C_1_23.data[i][j]+=1 * m.data[i][j];
        bmats.C_1_24.data[i][j]+=1 * m.data[i][j];
        bmats.C_1_25.data[i][j]+=1 * m.data[i][j];
        bmats.C_1_26.data[i][j]+=1 * m.data[i][j];
        bmats.C_1_27.data[i][j]+=1 * m.data[i][j];
        bmats.C_1_28.data[i][j]+=1 * m.data[i][j];
        bmats.C_1_29.data[i][j]+=1 * m.data[i][j];
        bmats.C_1_30.data[i][j]+=1 * m.data[i][j];
        bmats.C_1_31.data[i][j]+=1 * m.data[i][j];
        bmats.C_1_32.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}