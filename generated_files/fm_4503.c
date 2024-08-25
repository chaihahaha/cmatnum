#include "fm_4503.h"

int fm_4503(double_cmat m, pack_mats_22x22 ABs) {
int N = ABs.A_1_1.shape[0];
double_cmat tmp0, tmp1;
create_double_matrix(pairint {N, N}, &tmp0);
create_double_matrix(pairint {N, N}, &tmp1);
for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
        tmp0.data[i][j] = -ABs.A_1_12.data[i][j]+ABs.A_12_13.data[i][j]+ABs.A_12_14.data[i][j]+ABs.A_12_15.data[i][j]+ABs.A_12_16.data[i][j]+ABs.A_12_17.data[i][j]+ABs.A_12_18.data[i][j]+ABs.A_12_19.data[i][j]+ABs.A_12_20.data[i][j]+ABs.A_12_21.data[i][j]+ABs.A_12_22.data[i][j]-ABs.A_1_13.data[i][j]-ABs.A_1_14.data[i][j]-ABs.A_1_15.data[i][j]-ABs.A_1_16.data[i][j]-ABs.A_1_17.data[i][j]-ABs.A_1_18.data[i][j]-ABs.A_1_19.data[i][j]+11*ABs.A_1_20.data[i][j]-ABs.A_1_21.data[i][j]-ABs.A_1_22.data[i][j]-11*ABs.A_12_12.data[i][j]-ABs.A_20_10.data[i][j]-ABs.A_20_11.data[i][j]-ABs.A_20_7.data[i][j]-ABs.A_20_8.data[i][j]-ABs.A_20_9.data[i][j]+11*ABs.A_20_1.data[i][j]-ABs.A_20_2.data[i][j]-ABs.A_20_3.data[i][j]-ABs.A_20_4.data[i][j]-ABs.A_20_5.data[i][j]-ABs.A_20_6.data[i][j];
        tmp0.data[i][j] /= 12.0;
        tmp1.data[i][j] = ABs.B_12_9.data[i][j]+ABs.B_1_12.data[i][j]+ABs.B_20_12.data[i][j];
    }
}
fmm_22x22(m, tmp0, tmp1);
free_double_matrix(tmp0);
free_double_matrix(tmp1);
    return 0;
}
