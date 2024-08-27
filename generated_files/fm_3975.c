#include "fm_3975.h"

inline int fm_3975(double_cmat m, pack_mats_22x22 ABs) {

double dnum12 = 1/12.0;

int BL = ABs.A_1_1.shape[0];
double_cmat tmp0, tmp1;
create_double_matrix(pairint {BL, BL}, &tmp0);
create_double_matrix(pairint {BL, BL}, &tmp1);
for (int i=0; i<BL; i++) {
    for (int j=0; j<BL; j++) {
        tmp0.data[i][j] = -11*ABs.A_21_10.data[i][j]+ABs.A_21_11.data[i][j]+ABs.A_21_12.data[i][j]-11*ABs.A_21_13.data[i][j]+ABs.A_21_14.data[i][j]+ABs.A_22_1.data[i][j]+ABs.A_22_2.data[i][j]+ABs.A_22_3.data[i][j]+ABs.A_22_4.data[i][j]+ABs.A_22_5.data[i][j]+ABs.A_22_6.data[i][j]+ABs.A_22_7.data[i][j]+ABs.A_22_8.data[i][j]+ABs.A_22_9.data[i][j]-11*ABs.A_22_10.data[i][j]+ABs.A_22_11.data[i][j]-ABs.A_2_12.data[i][j]-ABs.A_2_13.data[i][j]-ABs.A_2_14.data[i][j]-ABs.A_2_15.data[i][j]-ABs.A_2_16.data[i][j]-ABs.A_2_17.data[i][j]-ABs.A_2_18.data[i][j]-ABs.A_2_19.data[i][j]-ABs.A_2_20.data[i][j]-ABs.A_2_21.data[i][j]-ABs.A_2_22.data[i][j]+ABs.A_12_11.data[i][j]+ABs.A_12_1.data[i][j]+ABs.A_12_2.data[i][j]+ABs.A_12_3.data[i][j]+ABs.A_12_4.data[i][j]+ABs.A_12_5.data[i][j]+ABs.A_12_6.data[i][j]+ABs.A_12_7.data[i][j]+ABs.A_12_8.data[i][j]+ABs.A_12_9.data[i][j]-11*ABs.A_12_10.data[i][j]+ABs.A_13_11.data[i][j]+ABs.A_13_1.data[i][j]+ABs.A_13_2.data[i][j]+ABs.A_13_3.data[i][j]+ABs.A_13_4.data[i][j]+ABs.A_13_5.data[i][j]+ABs.A_13_6.data[i][j]+ABs.A_13_7.data[i][j]+ABs.A_13_8.data[i][j]+ABs.A_13_9.data[i][j]-11*ABs.A_13_10.data[i][j]+ABs.A_14_11.data[i][j]+ABs.A_14_1.data[i][j]+ABs.A_14_2.data[i][j]+ABs.A_14_3.data[i][j]+ABs.A_14_4.data[i][j]+ABs.A_14_5.data[i][j]+ABs.A_14_6.data[i][j]+ABs.A_14_7.data[i][j]+ABs.A_14_8.data[i][j]+ABs.A_14_9.data[i][j]-11*ABs.A_14_10.data[i][j]-11*ABs.A_15_10.data[i][j]+ABs.A_15_11.data[i][j]-11*ABs.A_16_10.data[i][j]+ABs.A_16_11.data[i][j]+ABs.A_15_4.data[i][j]+ABs.A_15_5.data[i][j]+ABs.A_15_6.data[i][j]+ABs.A_15_7.data[i][j]+ABs.A_15_8.data[i][j]+ABs.A_15_9.data[i][j]+ABs.A_15_1.data[i][j]+ABs.A_15_2.data[i][j]+ABs.A_15_3.data[i][j]+ABs.A_16_4.data[i][j]+ABs.A_16_5.data[i][j]+ABs.A_16_6.data[i][j]+ABs.A_16_7.data[i][j]+ABs.A_16_8.data[i][j]+ABs.A_16_9.data[i][j]+ABs.A_16_1.data[i][j]+ABs.A_16_2.data[i][j]+ABs.A_16_3.data[i][j]-11*ABs.A_18_10.data[i][j]+ABs.A_17_8.data[i][j]+ABs.A_18_9.data[i][j]+ABs.A_18_5.data[i][j]+ABs.A_18_11.data[i][j]+ABs.A_18_1.data[i][j]+ABs.A_18_2.data[i][j]+ABs.A_18_4.data[i][j]+ABs.A_18_3.data[i][j]+ABs.A_18_6.data[i][j]+ABs.A_18_7.data[i][j]+ABs.A_18_8.data[i][j]+ABs.A_17_7.data[i][j]+ABs.A_17_6.data[i][j]+ABs.A_17_5.data[i][j]+ABs.A_17_4.data[i][j]+ABs.A_17_3.data[i][j]+ABs.A_17_2.data[i][j]+ABs.A_17_1.data[i][j]+ABs.A_17_11.data[i][j]-11*ABs.A_17_10.data[i][j]+ABs.A_17_9.data[i][j]-11*ABs.A_19_10.data[i][j]+ABs.A_19_11.data[i][j]-11*ABs.A_20_10.data[i][j]+ABs.A_20_11.data[i][j]+ABs.A_19_7.data[i][j]+ABs.A_19_8.data[i][j]+ABs.A_19_9.data[i][j]+ABs.A_19_1.data[i][j]+ABs.A_19_2.data[i][j]+ABs.A_19_3.data[i][j]+ABs.A_19_4.data[i][j]+ABs.A_19_5.data[i][j]+ABs.A_19_6.data[i][j]+ABs.A_20_7.data[i][j]+ABs.A_20_8.data[i][j]+ABs.A_20_9.data[i][j]+ABs.A_20_1.data[i][j]+ABs.A_20_2.data[i][j]+ABs.A_20_3.data[i][j]+ABs.A_20_4.data[i][j]+ABs.A_20_5.data[i][j]+ABs.A_20_6.data[i][j]+ABs.A_21_15.data[i][j]+ABs.A_21_1.data[i][j]+ABs.A_21_16.data[i][j]+ABs.A_21_2.data[i][j]+ABs.A_21_17.data[i][j]+ABs.A_21_3.data[i][j]+ABs.A_21_18.data[i][j]+ABs.A_21_4.data[i][j]+ABs.A_21_19.data[i][j]+ABs.A_21_5.data[i][j]+ABs.A_21_20.data[i][j]+ABs.A_21_6.data[i][j]+ABs.A_21_21.data[i][j]+ABs.A_21_7.data[i][j]+ABs.A_21_22.data[i][j]+ABs.A_21_8.data[i][j]+ABs.A_21_9.data[i][j];
        tmp0.data[i][j] *= dnum12;
        tmp1.data[i][j] = -ABs.B_13_1.data[i][j]-ABs.B_13_2.data[i][j]-ABs.B_13_3.data[i][j]-ABs.B_13_4.data[i][j]-ABs.B_13_5.data[i][j]-ABs.B_13_6.data[i][j]-ABs.B_13_7.data[i][j]-ABs.B_13_8.data[i][j]-ABs.B_13_9.data[i][j]-ABs.B_13_10.data[i][j]-ABs.B_13_11.data[i][j]+ABs.B_10_13.data[i][j]-ABs.B_12_21.data[i][j]-ABs.B_13_21.data[i][j]-ABs.B_14_21.data[i][j]-ABs.B_15_21.data[i][j]-ABs.B_16_21.data[i][j]-ABs.B_17_21.data[i][j]-ABs.B_18_21.data[i][j]-ABs.B_19_21.data[i][j]-ABs.B_20_21.data[i][j]-ABs.B_21_21.data[i][j]-ABs.B_22_21.data[i][j];
    }
}
fmm_22x22(m, tmp0, tmp1);
free_double_matrix(tmp0);
free_double_matrix(tmp1);
    return 0;

}

