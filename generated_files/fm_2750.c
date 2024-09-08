#include "fm_2750.h"

inline int fm_2750(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -11*bmats.A_15_12.data[i][j] + bmats.A_15_18.data[i][j] - bmats.A_1_19.data[i][j] + 11*bmats.A_1_20.data[i][j] + 11*bmats.A_20_4.data[i][j] - bmats.A_20_5.data[i][j] - bmats.Ax1327.data[i][j] - bmats.Ax1851.data[i][j] - bmats.Ax929.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = bmats.B_12_9.data[i][j] + bmats.B_20_15.data[i][j] + bmats.B_4_12.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_9_15.data[i][j]+=-1 * m.data[i][j];
        bmats.C_12_20.data[i][j]+=1 * m.data[i][j];
        bmats.C_15_1.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
