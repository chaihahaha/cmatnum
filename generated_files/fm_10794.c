#include "fm_10794.h"

inline int fm_10794(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = bmats.A_11_25.data[i][j] - 16*bmats.A_11_26.data[i][j] + bmats.Ax2674.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_27_10.data[i][j];
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
        bmats.C_11_17.data[i][j]+=1 * m.data[i][j];
        bmats.C_11_18.data[i][j]+=1 * m.data[i][j];
        bmats.C_11_19.data[i][j]+=1 * m.data[i][j];
        bmats.C_11_20.data[i][j]+=1 * m.data[i][j];
        bmats.C_11_21.data[i][j]+=1 * m.data[i][j];
        bmats.C_11_22.data[i][j]+=1 * m.data[i][j];
        bmats.C_11_23.data[i][j]+=1 * m.data[i][j];
        bmats.C_11_24.data[i][j]+=1 * m.data[i][j];
        bmats.C_11_25.data[i][j]+=1 * m.data[i][j];
        bmats.C_11_26.data[i][j]+=1 * m.data[i][j];
        bmats.C_11_27.data[i][j]+=1 * m.data[i][j];
        bmats.C_26_27.data[i][j]+=17 * m.data[i][j];
        bmats.C_11_28.data[i][j]+=1 * m.data[i][j];
        bmats.C_11_29.data[i][j]+=1 * m.data[i][j];
        bmats.C_11_30.data[i][j]+=1 * m.data[i][j];
        bmats.C_11_31.data[i][j]+=1 * m.data[i][j];
        bmats.C_11_32.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}