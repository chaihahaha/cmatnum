#include "fm_5491.h"

int fm_5491(double_cmat m, pack_mats_22x22 ABs) {
int N = ABs.A_1_1.shape[0];
double_cmat tmp0, tmp1;
create_double_matrix(pairint {N, N}, &tmp0);
create_double_matrix(pairint {N, N}, &tmp1);
for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
        tmp0.data[i][j] = -ABs.A_1_11.data[i][j]-ABs.A_1_1.data[i][j]-ABs.A_1_2.data[i][j]-ABs.A_1_3.data[i][j]+11*ABs.A_1_4.data[i][j]-ABs.A_1_5.data[i][j]-ABs.A_1_6.data[i][j]-ABs.A_1_7.data[i][j]-ABs.A_1_8.data[i][j]-ABs.A_1_9.data[i][j]-ABs.A_1_10.data[i][j]-ABs.A_4_11.data[i][j]-ABs.A_4_1.data[i][j]-ABs.A_4_2.data[i][j]-ABs.A_4_3.data[i][j]-ABs.A_4_4.data[i][j]-ABs.A_4_5.data[i][j]-ABs.A_4_6.data[i][j]-ABs.A_4_7.data[i][j]+11*ABs.A_4_8.data[i][j]-ABs.A_4_9.data[i][j]-ABs.A_4_10.data[i][j]-ABs.A_8_11.data[i][j]+11*ABs.A_8_1.data[i][j]-ABs.A_8_2.data[i][j]-ABs.A_8_3.data[i][j]-ABs.A_8_4.data[i][j]-ABs.A_8_5.data[i][j]-ABs.A_8_6.data[i][j]-ABs.A_8_7.data[i][j]-ABs.A_8_8.data[i][j]-ABs.A_8_9.data[i][j]-ABs.A_8_10.data[i][j];
        tmp0.data[i][j] /= 12.0;
        tmp1.data[i][j] = ABs.B_8_1.data[i][j]+ABs.B_1_4.data[i][j]+ABs.B_4_8.data[i][j];
    }
}
fmm_22x22(m, tmp0, tmp1);
free_double_matrix(tmp0);
free_double_matrix(tmp1);
    return 0;
}
