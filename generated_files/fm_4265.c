#include "fm_4265.h"

int fm_4265(double_cmat m, pack_mats_22x22 ABs) {
int N = ABs.A_1_1.shape[0];
double_cmat tmp0, tmp1;
create_double_matrix(pairint {N, N}, &tmp0);
create_double_matrix(pairint {N, N}, &tmp1);
for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
        tmp0.data[i][j] = -ABs.A_11_13.data[i][j]-ABs.A_11_14.data[i][j]-ABs.A_11_15.data[i][j]-ABs.A_11_16.data[i][j]-ABs.A_11_17.data[i][j]-ABs.A_11_18.data[i][j]-ABs.A_11_19.data[i][j]+11*ABs.A_11_20.data[i][j]-ABs.A_11_21.data[i][j]-ABs.A_11_22.data[i][j]+ABs.A_14_13.data[i][j]+ABs.A_14_14.data[i][j]+ABs.A_14_15.data[i][j]+ABs.A_14_16.data[i][j]+ABs.A_14_17.data[i][j]+ABs.A_14_18.data[i][j]+ABs.A_14_19.data[i][j]+ABs.A_14_20.data[i][j]+ABs.A_14_21.data[i][j]-11*ABs.A_14_22.data[i][j]-ABs.A_11_12.data[i][j]+ABs.A_14_12.data[i][j]-ABs.A_20_10.data[i][j]-ABs.A_20_11.data[i][j]-ABs.A_20_7.data[i][j]-ABs.A_20_8.data[i][j]-ABs.A_20_9.data[i][j]-ABs.A_20_1.data[i][j]-ABs.A_20_2.data[i][j]+11*ABs.A_20_3.data[i][j]-ABs.A_20_4.data[i][j]-ABs.A_20_5.data[i][j]-ABs.A_20_6.data[i][j];
        tmp0.data[i][j] /= 12.0;
        tmp1.data[i][j] = ABs.B_22_9.data[i][j]+ABs.B_20_14.data[i][j]+ABs.B_3_22.data[i][j];
    }
}
fmm_22x22(m, tmp0, tmp1);
free_double_matrix(tmp0);
free_double_matrix(tmp1);
    return 0;
}
