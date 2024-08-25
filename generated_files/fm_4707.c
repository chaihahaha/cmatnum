#include "fm_4707.h"

int fm_4707(double_cmat m, pack_mats_22x22 ABs) {
int N = ABs.A_1_1.shape[0];
double_cmat tmp0, tmp1;
create_double_matrix(pairint {N, N}, &tmp0);
create_double_matrix(pairint {N, N}, &tmp1);
for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
        tmp0.data[i][j] = -ABs.A_4_11.data[i][j]-ABs.A_4_1.data[i][j]-ABs.A_4_2.data[i][j]-ABs.A_4_3.data[i][j]-ABs.A_4_4.data[i][j]-ABs.A_4_5.data[i][j]-ABs.A_4_6.data[i][j]-ABs.A_4_7.data[i][j]-ABs.A_4_8.data[i][j]-ABs.A_4_9.data[i][j]+11*ABs.A_4_10.data[i][j]-ABs.A_5_11.data[i][j]-ABs.A_5_1.data[i][j]-ABs.A_5_2.data[i][j]-ABs.A_5_3.data[i][j]+11*ABs.A_5_4.data[i][j]-ABs.A_5_5.data[i][j]-ABs.A_5_6.data[i][j]-ABs.A_5_7.data[i][j]-ABs.A_5_8.data[i][j]-ABs.A_5_9.data[i][j]-ABs.A_5_10.data[i][j]-ABs.A_10_11.data[i][j]-ABs.A_10_1.data[i][j]-ABs.A_10_2.data[i][j]-ABs.A_10_3.data[i][j]-ABs.A_10_4.data[i][j]+11*ABs.A_10_5.data[i][j]-ABs.A_10_6.data[i][j]-ABs.A_10_7.data[i][j]-ABs.A_10_8.data[i][j]-ABs.A_10_9.data[i][j]-ABs.A_10_10.data[i][j];
        tmp0.data[i][j] /= 12.0;
        tmp1.data[i][j] = ABs.B_5_4.data[i][j]+ABs.B_10_5.data[i][j]+ABs.B_4_10.data[i][j];
    }
}
fmm_22x22(m, tmp0, tmp1);
free_double_matrix(tmp0);
free_double_matrix(tmp1);
    return 0;
}
