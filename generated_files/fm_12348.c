#include "fm_12348.h"

inline int fm_12348(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_11_31.data[i][j] + 16*bmats.A_11_32.data[i][j] + bmats.A_30_18.data[i][j] + bmats.A_30_19.data[i][j] - 16*bmats.A_30_27.data[i][j] + bmats.A_30_29.data[i][j] + bmats.A_30_30.data[i][j] + bmats.A_30_31.data[i][j] + bmats.A_30_32.data[i][j] - bmats.A_32_13.data[i][j] + 16*bmats.A_32_14.data[i][j] - bmats.Ax485.data[i][j] - bmats.Ax754.data[i][j] - bmats.Ax8022.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_14_27.data[i][j] + bmats.B_27_16.data[i][j] + bmats.B_32_30.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_30_16.data[i][j]+=-1 * m.data[i][j];
        bmats.C_32_27.data[i][j]+=1 * m.data[i][j];
        bmats.C_11_30.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}