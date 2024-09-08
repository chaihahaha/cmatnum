#include "fm_1191.h"

inline int fm_1191(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = 11*bmats.A_17_8.data[i][j] - bmats.A_17_9.data[i][j] - bmats.A_8_19.data[i][j] + 11*bmats.A_8_20.data[i][j] - 11*bmats.A_9_6.data[i][j] + bmats.A_9_7.data[i][j] + bmats.A_9_9.data[i][j] - bmats.Ax1988.data[i][j] - bmats.Ax2247.data[i][j] - bmats.Ax327.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = bmats.B_20_6.data[i][j] + bmats.B_6_19.data[i][j] + bmats.B_8_9.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_6_8.data[i][j]+=1 * m.data[i][j];
        bmats.C_9_17.data[i][j]+=1 * m.data[i][j];
        bmats.C_19_9.data[i][j]+=-1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
