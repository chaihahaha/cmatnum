#include "fm_2374.h"

inline int fm_2374(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = bmats.A_18_12.data[i][j] + bmats.A_18_13.data[i][j] + bmats.A_18_14.data[i][j] + bmats.A_18_15.data[i][j] + bmats.A_18_16.data[i][j] - 11*bmats.A_18_17.data[i][j] + bmats.A_18_18.data[i][j] + bmats.A_18_19.data[i][j] + bmats.A_18_20.data[i][j] + bmats.A_18_21.data[i][j] + bmats.A_18_22.data[i][j] - bmats.A_22_6.data[i][j] + 11*bmats.A_22_7.data[i][j] - bmats.A_6_21.data[i][j] + 11*bmats.A_6_22.data[i][j] - bmats.Ax509.data[i][j] - bmats.Ax92.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = bmats.B_17_11.data[i][j] + bmats.B_22_18.data[i][j] + bmats.B_7_17.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_11_18.data[i][j]+=-1 * m.data[i][j];
        bmats.C_17_22.data[i][j]+=1 * m.data[i][j];
        bmats.C_18_6.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
