#include "fm_12989.h"

inline int fm_12989(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 16*bmats.A_1_29.data[i][j] - bmats.A_1_30.data[i][j] - 16*bmats.A_28_17.data[i][j] + bmats.A_28_32.data[i][j] - bmats.A_29_11.data[i][j] + 16*bmats.A_29_12.data[i][j] - bmats.Ax1981.data[i][j] - bmats.Ax2371.data[i][j] - bmats.Ax441.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_12_17.data[i][j] + bmats.B_17_13.data[i][j] + bmats.B_29_28.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_28_13.data[i][j]+=-1 * m.data[i][j];
        bmats.C_29_17.data[i][j]+=1 * m.data[i][j];
        bmats.C_1_28.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
