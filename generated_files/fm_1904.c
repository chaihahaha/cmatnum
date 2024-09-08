#include "fm_1904.h"

inline int fm_1904(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_22_10.data[i][j] + 11*bmats.A_22_11.data[i][j] + bmats.A_22_12.data[i][j] - 11*bmats.A_22_13.data[i][j] + bmats.A_22_20.data[i][j] + bmats.A_22_22.data[i][j] - bmats.A_2_21.data[i][j] + 11*bmats.A_2_22.data[i][j] - bmats.Ax219.data[i][j] - bmats.Ax2545.data[i][j] - bmats.Ax567.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = bmats.B_11_13.data[i][j] + bmats.B_13_11.data[i][j] + bmats.B_22_22.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_11_22.data[i][j]+=-1 * m.data[i][j];
        bmats.C_13_22.data[i][j]+=1 * m.data[i][j];
        bmats.C_22_2.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
