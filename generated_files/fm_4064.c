#include "fm_4064.h"

inline int fm_4064(double_cmat m, pack_mats_22x22 bmats) {
    double dnum12 = 1/12.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            tmp0.data[i][j] = -bmats.A_12_12.data[i][j] - bmats.A_12_13.data[i][j] - bmats.A_12_14.data[i][j] - bmats.A_12_15.data[i][j] - bmats.A_12_16.data[i][j] - bmats.A_12_17.data[i][j] - bmats.A_12_18.data[i][j] - bmats.A_12_19.data[i][j] + 11*bmats.A_12_20.data[i][j] - bmats.A_12_21.data[i][j] - bmats.A_12_22.data[i][j] - bmats.A_13_12.data[i][j] - bmats.A_13_13.data[i][j] - bmats.A_13_14.data[i][j] - bmats.A_13_15.data[i][j] - bmats.A_13_16.data[i][j] - bmats.A_13_17.data[i][j] - bmats.A_13_18.data[i][j] - bmats.A_13_19.data[i][j] + 11*bmats.A_13_20.data[i][j] - bmats.A_13_21.data[i][j] - bmats.A_13_22.data[i][j] - bmats.A_14_12.data[i][j] - bmats.A_14_13.data[i][j] - bmats.A_14_14.data[i][j] - bmats.A_14_15.data[i][j] - bmats.A_14_16.data[i][j] - bmats.A_14_17.data[i][j] - bmats.A_14_18.data[i][j] - bmats.A_14_19.data[i][j] + 11*bmats.A_14_20.data[i][j] - bmats.A_14_21.data[i][j] - bmats.A_14_22.data[i][j] - bmats.A_15_12.data[i][j] - bmats.A_15_13.data[i][j] - bmats.A_15_14.data[i][j] - bmats.A_15_15.data[i][j] - bmats.A_15_16.data[i][j] - bmats.A_15_17.data[i][j] - bmats.A_15_18.data[i][j] - bmats.A_15_19.data[i][j] + 11*bmats.A_15_20.data[i][j] - bmats.A_15_21.data[i][j] - bmats.A_15_22.data[i][j] - bmats.A_16_12.data[i][j] - bmats.A_16_13.data[i][j] - bmats.A_16_14.data[i][j] - bmats.A_16_15.data[i][j] - bmats.A_16_16.data[i][j] - bmats.A_16_17.data[i][j] - bmats.A_16_18.data[i][j] - bmats.A_16_19.data[i][j] + 11*bmats.A_16_20.data[i][j] - bmats.A_16_21.data[i][j] - bmats.A_16_22.data[i][j] - bmats.A_17_1.data[i][j] - bmats.A_17_10.data[i][j] - bmats.A_17_11.data[i][j] - bmats.A_17_12.data[i][j] - bmats.A_17_13.data[i][j] - bmats.A_17_14.data[i][j] - bmats.A_17_15.data[i][j] - bmats.A_17_16.data[i][j] - bmats.A_17_17.data[i][j] - bmats.A_17_18.data[i][j] - bmats.A_17_19.data[i][j] - bmats.A_17_2.data[i][j] + 11*bmats.A_17_20.data[i][j] - bmats.A_17_21.data[i][j] - bmats.A_17_22.data[i][j] - bmats.A_17_3.data[i][j] - bmats.A_17_4.data[i][j] - bmats.A_17_5.data[i][j] - bmats.A_17_6.data[i][j] - bmats.A_17_7.data[i][j] - bmats.A_17_8.data[i][j] - bmats.A_17_9.data[i][j] - bmats.A_18_12.data[i][j] - bmats.A_18_13.data[i][j] - bmats.A_18_14.data[i][j] - bmats.A_18_15.data[i][j] - bmats.A_18_16.data[i][j] - bmats.A_18_17.data[i][j] - bmats.A_18_18.data[i][j] - bmats.A_18_19.data[i][j] + 11*bmats.A_18_20.data[i][j] - bmats.A_18_21.data[i][j] - bmats.A_18_22.data[i][j] - bmats.A_19_12.data[i][j] - bmats.A_19_13.data[i][j] - bmats.A_19_14.data[i][j] - bmats.A_19_15.data[i][j] - bmats.A_19_16.data[i][j] - bmats.A_19_17.data[i][j] - bmats.A_19_18.data[i][j] - bmats.A_19_19.data[i][j] + 11*bmats.A_19_20.data[i][j] - bmats.A_19_21.data[i][j] - bmats.A_19_22.data[i][j] - bmats.A_20_12.data[i][j] - bmats.A_20_13.data[i][j] - bmats.A_20_14.data[i][j] - bmats.A_20_15.data[i][j] - bmats.A_20_16.data[i][j] - bmats.A_20_17.data[i][j] - bmats.A_20_18.data[i][j] - bmats.A_20_19.data[i][j] + 11*bmats.A_20_20.data[i][j] - bmats.A_20_21.data[i][j] - bmats.A_20_22.data[i][j] - bmats.A_21_12.data[i][j] - bmats.A_21_13.data[i][j] - bmats.A_21_14.data[i][j] - bmats.A_21_15.data[i][j] - bmats.A_21_16.data[i][j] - bmats.A_21_17.data[i][j] - bmats.A_21_18.data[i][j] - bmats.A_21_19.data[i][j] + 11*bmats.A_21_20.data[i][j] - bmats.A_21_21.data[i][j] - bmats.A_21_22.data[i][j] - bmats.A_22_12.data[i][j] - bmats.A_22_13.data[i][j] - bmats.A_22_14.data[i][j] - bmats.A_22_15.data[i][j] - bmats.A_22_16.data[i][j] - bmats.A_22_17.data[i][j] - bmats.A_22_18.data[i][j] - bmats.A_22_19.data[i][j] + 11*bmats.A_22_20.data[i][j] - bmats.A_22_21.data[i][j] - bmats.A_22_22.data[i][j] - bmats.A_9_12.data[i][j] - bmats.A_9_13.data[i][j] - bmats.A_9_14.data[i][j] - bmats.A_9_15.data[i][j] - bmats.A_9_16.data[i][j] + 11*bmats.A_9_17.data[i][j] - bmats.A_9_18.data[i][j] - bmats.A_9_19.data[i][j] - bmats.A_9_20.data[i][j] - bmats.A_9_21.data[i][j] - bmats.A_9_22.data[i][j];
            tmp0.data[i][j] *= dnum12;
            tmp1.data[i][j] = bmats.B_20_6.data[i][j]-bmats.B_17_12.data[i][j]-bmats.B_17_13.data[i][j]-bmats.B_17_14.data[i][j]-bmats.B_17_15.data[i][j]-bmats.B_17_16.data[i][j]-bmats.B_17_17.data[i][j]-bmats.B_17_18.data[i][j]-bmats.B_17_19.data[i][j]-bmats.B_1_20.data[i][j]-bmats.B_2_20.data[i][j]-bmats.B_3_20.data[i][j]-bmats.B_4_20.data[i][j]-bmats.B_5_20.data[i][j]-bmats.B_6_20.data[i][j]-bmats.B_7_20.data[i][j]-bmats.B_8_20.data[i][j]-bmats.B_9_20.data[i][j]-bmats.B_10_20.data[i][j]-bmats.B_11_20.data[i][j]-bmats.B_17_20.data[i][j]-bmats.B_17_21.data[i][j]-bmats.B_17_22.data[i][j];
        }
    }
    fmm_22x22(m, tmp0, tmp1);

    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
        bmats.C_20_17.data[i][j]+=1 * m.data[i][j];
        }
    }
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
