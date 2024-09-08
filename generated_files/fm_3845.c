#include "fm_3845.h"

inline int fm_3845(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 16*bmats.A_14_31.data[i][j] - bmats.A_14_32.data[i][j] + bmats.A_15_10.data[i][j] - 16*bmats.A_15_9.data[i][j] - bmats.A_25_13.data[i][j] + 16*bmats.A_25_14.data[i][j] - bmats.Ax506.data[i][j] - bmats.Ax5291.data[i][j] - bmats.Ax745.data[i][j];
            tmp0.data[i][j] *= dnum17;
            tmp1.data[i][j] = bmats.B_14_15.data[i][j] + bmats.B_31_9.data[i][j] + bmats.B_9_30.data[i][j];
        }
    }
    fmm_32x32(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_14_9.data[i][j]+=1 * m.data[i][j];
        bmats.C_25_15.data[i][j]+=1 * m.data[i][j];
        bmats.C_15_30.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
