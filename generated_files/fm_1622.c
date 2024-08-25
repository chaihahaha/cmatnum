#include "fm_1622.h"

int fm_1622(double_cmat m, pack_mats_22x22 ABs) {
int N = ABs.A_1_1.shape[0];
double_cmat tmp0, tmp1;
create_double_matrix(pairint {N, N}, &tmp0);
create_double_matrix(pairint {N, N}, &tmp1);
for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
        tmp0.data[i][j] = +ABs.A_2_11.data[i][j]+ABs.A_2_1.data[i][j]+ABs.A_2_2.data[i][j]-11*ABs.A_2_3.data[i][j]+ABs.A_2_4.data[i][j]+ABs.A_2_5.data[i][j]+ABs.A_2_6.data[i][j]+ABs.A_2_7.data[i][j]+ABs.A_2_8.data[i][j]+ABs.A_2_9.data[i][j]+ABs.A_2_10.data[i][j]-ABs.A_3_12.data[i][j]+11*ABs.A_3_13.data[i][j]-ABs.A_3_14.data[i][j]-ABs.A_3_15.data[i][j]-ABs.A_3_16.data[i][j]-ABs.A_3_17.data[i][j]-ABs.A_3_18.data[i][j]-ABs.A_3_19.data[i][j]-ABs.A_3_20.data[i][j]-ABs.A_3_21.data[i][j]-ABs.A_3_22.data[i][j]-ABs.A_14_11.data[i][j]-ABs.A_14_1.data[i][j]-ABs.A_14_2.data[i][j]+11*ABs.A_14_3.data[i][j]-ABs.A_14_4.data[i][j]-ABs.A_14_5.data[i][j]-ABs.A_14_6.data[i][j]-ABs.A_14_7.data[i][j]-ABs.A_14_8.data[i][j]-ABs.A_14_9.data[i][j]-ABs.A_14_10.data[i][j];
        tmp0.data[i][j] /= 12.0;
        tmp1.data[i][j] = ABs.B_3_2.data[i][j]+ABs.B_13_3.data[i][j]+ABs.B_3_14.data[i][j];
    }
}
fmm_22x22(m, tmp0, tmp1);
free_double_matrix(tmp0);
free_double_matrix(tmp1);
    return 0;
}
