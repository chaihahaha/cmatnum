#include "fm_226.h"

inline int fm_226(double_cmat m, pack_mats_22x22 ABs) {

double dnum12 = 1/12.0;

int BL = ABs.A_1_1.shape[0];
double_cmat tmp0, tmp1;
create_double_matrix(pairint {BL, BL}, &tmp0);
create_double_matrix(pairint {BL, BL}, &tmp1);
for (int i=0; i<BL; i++) {
    for (int j=0; j<BL; j++) {
        tmp0.data[i][j] = +ABs.A_8_13.data[i][j]+ABs.A_8_14.data[i][j]+ABs.A_1_12.data[i][j]-11*ABs.A_8_15.data[i][j]+ABs.A_8_16.data[i][j]+ABs.A_8_17.data[i][j]+ABs.A_8_18.data[i][j]+ABs.A_8_19.data[i][j]+ABs.A_8_20.data[i][j]+ABs.A_8_21.data[i][j]+ABs.A_8_22.data[i][j]+ABs.A_9_13.data[i][j]+ABs.A_9_14.data[i][j]+ABs.A_2_12.data[i][j]-11*ABs.A_9_15.data[i][j]+ABs.A_9_16.data[i][j]+ABs.A_9_17.data[i][j]+ABs.A_9_18.data[i][j]+ABs.A_9_19.data[i][j]+ABs.A_9_20.data[i][j]+ABs.A_9_21.data[i][j]+ABs.A_9_22.data[i][j]+ABs.A_10_13.data[i][j]+ABs.A_10_14.data[i][j]+ABs.A_3_12.data[i][j]-11*ABs.A_10_15.data[i][j]+ABs.A_10_16.data[i][j]+ABs.A_10_17.data[i][j]+ABs.A_10_18.data[i][j]+ABs.A_10_19.data[i][j]+ABs.A_10_20.data[i][j]+ABs.A_10_21.data[i][j]+ABs.A_10_22.data[i][j]+ABs.A_11_13.data[i][j]+ABs.A_4_11.data[i][j]+ABs.A_11_14.data[i][j]+ABs.A_4_12.data[i][j]-11*ABs.A_11_15.data[i][j]+ABs.A_4_1.data[i][j]+ABs.A_11_16.data[i][j]+ABs.A_4_2.data[i][j]+ABs.A_11_17.data[i][j]+ABs.A_4_3.data[i][j]+ABs.A_11_18.data[i][j]+ABs.A_4_4.data[i][j]+ABs.A_11_19.data[i][j]+ABs.A_4_5.data[i][j]+ABs.A_11_20.data[i][j]+ABs.A_4_6.data[i][j]+ABs.A_11_21.data[i][j]-11*ABs.A_4_7.data[i][j]+ABs.A_11_22.data[i][j]+ABs.A_4_8.data[i][j]+ABs.A_4_9.data[i][j]+ABs.A_4_10.data[i][j]+ABs.A_5_12.data[i][j]+ABs.A_6_12.data[i][j]+ABs.A_7_12.data[i][j]+ABs.A_1_13.data[i][j]+ABs.A_1_14.data[i][j]-11*ABs.A_1_15.data[i][j]+ABs.A_1_16.data[i][j]+ABs.A_1_17.data[i][j]+ABs.A_1_18.data[i][j]+ABs.A_1_19.data[i][j]+ABs.A_1_20.data[i][j]+ABs.A_1_21.data[i][j]+ABs.A_1_22.data[i][j]+ABs.A_2_13.data[i][j]+ABs.A_2_14.data[i][j]-11*ABs.A_2_15.data[i][j]+ABs.A_2_16.data[i][j]+ABs.A_2_17.data[i][j]+ABs.A_2_18.data[i][j]+ABs.A_2_19.data[i][j]+ABs.A_2_20.data[i][j]+ABs.A_2_21.data[i][j]+ABs.A_2_22.data[i][j]+ABs.A_3_13.data[i][j]+ABs.A_3_14.data[i][j]-11*ABs.A_3_15.data[i][j]+ABs.A_3_16.data[i][j]+ABs.A_3_17.data[i][j]+ABs.A_3_18.data[i][j]+ABs.A_3_19.data[i][j]+ABs.A_3_20.data[i][j]+ABs.A_3_21.data[i][j]+ABs.A_3_22.data[i][j]+ABs.A_4_13.data[i][j]+ABs.A_4_14.data[i][j]-11*ABs.A_4_15.data[i][j]+ABs.A_4_16.data[i][j]+ABs.A_4_17.data[i][j]+ABs.A_4_18.data[i][j]+ABs.A_4_19.data[i][j]+ABs.A_4_20.data[i][j]+ABs.A_4_21.data[i][j]+ABs.A_4_22.data[i][j]+ABs.A_5_13.data[i][j]+ABs.A_5_14.data[i][j]-11*ABs.A_5_15.data[i][j]+ABs.A_5_16.data[i][j]+ABs.A_5_17.data[i][j]+ABs.A_5_18.data[i][j]+ABs.A_5_19.data[i][j]+ABs.A_5_20.data[i][j]+ABs.A_5_21.data[i][j]+ABs.A_5_22.data[i][j]+ABs.A_6_13.data[i][j]+ABs.A_6_14.data[i][j]-11*ABs.A_6_15.data[i][j]+ABs.A_6_16.data[i][j]+ABs.A_6_17.data[i][j]+ABs.A_6_18.data[i][j]+ABs.A_6_19.data[i][j]+ABs.A_6_20.data[i][j]+ABs.A_6_21.data[i][j]+ABs.A_6_22.data[i][j]+ABs.A_7_13.data[i][j]+ABs.A_7_14.data[i][j]-11*ABs.A_7_15.data[i][j]+ABs.A_7_16.data[i][j]+ABs.A_7_17.data[i][j]+ABs.A_7_18.data[i][j]+ABs.A_7_19.data[i][j]+ABs.A_7_20.data[i][j]+ABs.A_7_21.data[i][j]+ABs.A_7_22.data[i][j]+ABs.A_8_12.data[i][j]+ABs.A_9_12.data[i][j]+ABs.A_10_12.data[i][j]+ABs.A_11_12.data[i][j]-ABs.A_18_10.data[i][j]-ABs.A_18_9.data[i][j]-ABs.A_18_5.data[i][j]-ABs.A_18_11.data[i][j]-ABs.A_18_1.data[i][j]-ABs.A_18_2.data[i][j]-ABs.A_18_4.data[i][j]-ABs.A_18_3.data[i][j]-ABs.A_18_6.data[i][j]-ABs.A_18_7.data[i][j]-ABs.A_18_8.data[i][j];
        tmp0.data[i][j] *= dnum12;
        tmp1.data[i][j] = -ABs.B_1_4.data[i][j]-ABs.B_2_4.data[i][j]-ABs.B_3_4.data[i][j]-ABs.B_4_4.data[i][j]-ABs.B_5_4.data[i][j]-ABs.B_6_4.data[i][j]-ABs.B_7_4.data[i][j]-ABs.B_8_4.data[i][j]-ABs.B_9_4.data[i][j]-ABs.B_10_4.data[i][j]-ABs.B_11_4.data[i][j]+ABs.B_15_7.data[i][j]-ABs.B_7_12.data[i][j]-ABs.B_7_13.data[i][j]-ABs.B_7_14.data[i][j]-ABs.B_7_15.data[i][j]-ABs.B_7_16.data[i][j]-ABs.B_7_17.data[i][j]-ABs.B_7_18.data[i][j]-ABs.B_7_19.data[i][j]-ABs.B_7_20.data[i][j]-ABs.B_7_21.data[i][j]-ABs.B_7_22.data[i][j];
    }
}
fmm_22x22(m, tmp0, tmp1);
free_double_matrix(tmp0);
free_double_matrix(tmp1);
    return 0;

}

