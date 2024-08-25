#include "fm_3416.h"

int fm_3416(double_cmat m, pack_mats_22x22 ABs) {
int N = ABs.A_1_1.shape[0];
double_cmat tmp0, tmp1;
create_double_matrix(pairint {N, N}, &tmp0);
create_double_matrix(pairint {N, N}, &tmp1);
for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
        tmp0.data[i][j] = +ABs.A_22_12.data[i][j]+ABs.A_22_13.data[i][j]+ABs.A_22_14.data[i][j]+ABs.A_22_15.data[i][j]-11*ABs.A_22_16.data[i][j]+ABs.A_22_17.data[i][j]+ABs.A_22_18.data[i][j]+ABs.A_22_19.data[i][j]+ABs.A_22_20.data[i][j]+ABs.A_22_21.data[i][j]+ABs.A_22_22.data[i][j];
        tmp0.data[i][j] /= 12.0;
        tmp1.data[i][j] = ABs.B_22_16.data[i][j];
    }
}
fmm_22x22(m, tmp0, tmp1);
free_double_matrix(tmp0);
free_double_matrix(tmp1);
    return 0;
}
