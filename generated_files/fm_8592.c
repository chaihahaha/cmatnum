#include "fm_8592.h"

inline int fm_8592(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_16_27.data[i][j] + 16*bmats.A_16_28.data[i][j] + bmats.A_27_17.data[i][j] + bmats.A_27_18.data[i][j] + bmats.A_27_27.data[i][j] + bmats.A_27_31.data[i][j] - 16*bmats.A_27_32.data[i][j] + 16*bmats.A_28_11.data[i][j] - bmats.A_28_12.data[i][j] - bmats.Ax2251.data[i][j] - bmats.Ax2282.data[i][j] - bmats.Ax6836.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_11_32.data[i][j] + bmats.B_28_27.data[i][j] + bmats.B_32_12.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_27_12.data[i][j]+=-1 * m.data[i][j];
        bmats.C_16_27.data[i][j]+=1 * m.data[i][j];
        bmats.C_28_32.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
