#include "fm_1533.h"

int fm_1533(double_cmat m, pack_mats_22x22 ABs) {
int N = ABs.A_1_1.shape[0];
double_cmat tmp0, tmp1;
create_double_matrix(pairint {N, N}, &tmp0);
create_double_matrix(pairint {N, N}, &tmp1);
for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
        tmp0.data[i][j] = -ABs.A_9_13.data[i][j]-ABs.A_9_14.data[i][j]-ABs.A_9_15.data[i][j]-ABs.A_9_16.data[i][j]-ABs.A_9_17.data[i][j]-ABs.A_9_18.data[i][j]-ABs.A_9_19.data[i][j]-ABs.A_9_20.data[i][j]+11*ABs.A_9_21.data[i][j]-ABs.A_9_22.data[i][j]-ABs.A_9_12.data[i][j]+ABs.A_10_11.data[i][j]+ABs.A_10_1.data[i][j]+ABs.A_10_2.data[i][j]-11*ABs.A_10_3.data[i][j]+ABs.A_10_4.data[i][j]+ABs.A_10_5.data[i][j]+ABs.A_10_6.data[i][j]+ABs.A_10_7.data[i][j]+ABs.A_10_8.data[i][j]+ABs.A_10_9.data[i][j]+ABs.A_10_10.data[i][j]-ABs.A_14_11.data[i][j]-ABs.A_14_1.data[i][j]-ABs.A_14_2.data[i][j]-ABs.A_14_3.data[i][j]-ABs.A_14_4.data[i][j]-ABs.A_14_5.data[i][j]-ABs.A_14_6.data[i][j]-ABs.A_14_7.data[i][j]-ABs.A_14_8.data[i][j]+11*ABs.A_14_9.data[i][j]-ABs.A_14_10.data[i][j];
        tmp0.data[i][j] /= 12.0;
        tmp1.data[i][j] = ABs.B_21_3.data[i][j]+ABs.B_9_10.data[i][j]+ABs.B_3_20.data[i][j];
    }
}
fmm_22x22(m, tmp0, tmp1);
free_double_matrix(tmp0);
free_double_matrix(tmp1);
    return 0;
}
