#include "fm_8846.h"

inline int fm_8846(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 16*bmats.A_11_5.data[i][j] - bmats.A_11_6.data[i][j] - bmats.A_5_5.data[i][j] + 16*bmats.A_5_6.data[i][j] + 16*bmats.A_6_11.data[i][j] - bmats.A_6_12.data[i][j] - bmats.Ax2193.data[i][j] - bmats.Ax2786.data[i][j] - bmats.Ax3914.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_11_5.data[i][j] + bmats.B_5_6.data[i][j] + bmats.B_6_11.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_6_5.data[i][j]+=1 * m.data[i][j];
        bmats.C_11_6.data[i][j]+=1 * m.data[i][j];
        bmats.C_5_11.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}