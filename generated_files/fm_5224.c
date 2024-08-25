#include "fm_5224.h"

int fm_5224(double_cmat m, pack_mats_22x22 ABs) {
int N = ABs.A_1_1.shape[0];
double_cmat tmp0, tmp1;
create_double_matrix(pairint {N, N}, &tmp0);
create_double_matrix(pairint {N, N}, &tmp1);
for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
        tmp0.data[i][j] = -ABs.A_12_13.data[i][j]+11*ABs.A_12_14.data[i][j]-ABs.A_12_15.data[i][j]-ABs.A_12_16.data[i][j]-ABs.A_12_17.data[i][j]-ABs.A_12_18.data[i][j]-ABs.A_12_19.data[i][j]-ABs.A_12_20.data[i][j]-ABs.A_12_21.data[i][j]-ABs.A_12_22.data[i][j]-ABs.A_14_13.data[i][j]-ABs.A_14_14.data[i][j]-ABs.A_14_15.data[i][j]+11*ABs.A_14_16.data[i][j]-ABs.A_14_17.data[i][j]-ABs.A_14_18.data[i][j]-ABs.A_14_19.data[i][j]-ABs.A_14_20.data[i][j]-ABs.A_14_21.data[i][j]-ABs.A_14_22.data[i][j]-ABs.A_12_12.data[i][j]-ABs.A_14_12.data[i][j]+11*ABs.A_16_12.data[i][j]-ABs.A_16_13.data[i][j]-ABs.A_16_14.data[i][j]-ABs.A_16_15.data[i][j]-ABs.A_16_16.data[i][j]-ABs.A_16_17.data[i][j]-ABs.A_16_18.data[i][j]-ABs.A_16_19.data[i][j]-ABs.A_16_20.data[i][j]-ABs.A_16_21.data[i][j]-ABs.A_16_22.data[i][j];
        tmp0.data[i][j] /= 12.0;
        tmp1.data[i][j] = ABs.B_16_12.data[i][j]+ABs.B_12_14.data[i][j]+ABs.B_14_16.data[i][j];
    }
}
fmm_22x22(m, tmp0, tmp1);
free_double_matrix(tmp0);
free_double_matrix(tmp1);
    return 0;
}
