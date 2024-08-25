#include "fm_1679.h"

int fm_1679(double_cmat m, pack_mats_22x22 ABs) {
int N = ABs.A_1_1.shape[0];
double_cmat tmp0, tmp1;
create_double_matrix(pairint {N, N}, &tmp0);
create_double_matrix(pairint {N, N}, &tmp1);
for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
        tmp0.data[i][j] = -ABs.A_6_12.data[i][j]-ABs.A_6_13.data[i][j]-ABs.A_6_14.data[i][j]-ABs.A_6_15.data[i][j]-ABs.A_6_16.data[i][j]-ABs.A_6_17.data[i][j]-ABs.A_6_18.data[i][j]+11*ABs.A_6_19.data[i][j]-ABs.A_6_20.data[i][j]-ABs.A_6_21.data[i][j]-ABs.A_6_22.data[i][j]+ABs.A_8_11.data[i][j]+ABs.A_8_1.data[i][j]-11*ABs.A_8_2.data[i][j]+ABs.A_8_3.data[i][j]+ABs.A_8_4.data[i][j]+ABs.A_8_5.data[i][j]+ABs.A_8_6.data[i][j]+ABs.A_8_7.data[i][j]+ABs.A_8_8.data[i][j]+ABs.A_8_9.data[i][j]+ABs.A_8_10.data[i][j]-ABs.A_13_11.data[i][j]-ABs.A_13_1.data[i][j]-ABs.A_13_2.data[i][j]-ABs.A_13_3.data[i][j]-ABs.A_13_4.data[i][j]-ABs.A_13_5.data[i][j]+11*ABs.A_13_6.data[i][j]-ABs.A_13_7.data[i][j]-ABs.A_13_8.data[i][j]-ABs.A_13_9.data[i][j]-ABs.A_13_10.data[i][j];
        tmp0.data[i][j] /= 12.0;
        tmp1.data[i][j] = ABs.B_19_2.data[i][j]+ABs.B_6_8.data[i][j]+ABs.B_2_17.data[i][j];
    }
}
fmm_22x22(m, tmp0, tmp1);
free_double_matrix(tmp0);
free_double_matrix(tmp1);
    return 0;
}
