#include "fm_1159.h"

int fm_1159(double_cmat m, pack_mats_22x22 ABs) {
int N = ABs.A_1_1.shape[0];
double_cmat tmp0, tmp1;
create_double_matrix(pairint {N, N}, &tmp0);
create_double_matrix(pairint {N, N}, &tmp1);
for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
        tmp0.data[i][j] = +ABs.A_2_11.data[i][j]+ABs.A_2_1.data[i][j]+ABs.A_2_2.data[i][j]+ABs.A_2_3.data[i][j]+ABs.A_2_4.data[i][j]+ABs.A_2_5.data[i][j]+ABs.A_2_6.data[i][j]-11*ABs.A_2_7.data[i][j]+ABs.A_2_8.data[i][j]+ABs.A_2_9.data[i][j]+ABs.A_2_10.data[i][j]-ABs.A_5_12.data[i][j]+11*ABs.A_5_13.data[i][j]-ABs.A_5_14.data[i][j]-ABs.A_5_15.data[i][j]-ABs.A_5_16.data[i][j]-ABs.A_5_17.data[i][j]-ABs.A_5_18.data[i][j]-ABs.A_5_19.data[i][j]-ABs.A_5_20.data[i][j]-ABs.A_5_21.data[i][j]-ABs.A_5_22.data[i][j]-ABs.A_18_10.data[i][j]-ABs.A_18_9.data[i][j]+11*ABs.A_18_5.data[i][j]-ABs.A_18_11.data[i][j]-ABs.A_18_1.data[i][j]-ABs.A_18_2.data[i][j]-ABs.A_18_4.data[i][j]-ABs.A_18_3.data[i][j]-ABs.A_18_6.data[i][j]-ABs.A_18_7.data[i][j]-ABs.A_18_8.data[i][j];
        tmp0.data[i][j] /= 12.0;
        tmp1.data[i][j] = ABs.B_5_2.data[i][j]+ABs.B_13_7.data[i][j]+ABs.B_7_16.data[i][j];
    }
}
fmm_22x22(m, tmp0, tmp1);
free_double_matrix(tmp0);
free_double_matrix(tmp1);
    return 0;
}
