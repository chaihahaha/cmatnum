#include "fm_1922.h"

int fm_1922(double_cmat m, pack_mats_22x22 ABs) {
int N = ABs.A_1_1.shape[0];
double_cmat tmp0, tmp1;
create_double_matrix(pairint {N, N}, &tmp0);
create_double_matrix(pairint {N, N}, &tmp1);
for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
        tmp0.data[i][j] = +ABs.A_22_15.data[i][j]-11*ABs.A_22_16.data[i][j]+ABs.A_22_17.data[i][j]+ABs.A_22_18.data[i][j]+ABs.A_22_19.data[i][j]+ABs.A_22_20.data[i][j]+ABs.A_22_21.data[i][j]+ABs.A_22_22.data[i][j]+ABs.A_22_12.data[i][j]+ABs.A_22_13.data[i][j]+ABs.A_22_14.data[i][j]-ABs.A_5_12.data[i][j]-ABs.A_5_13.data[i][j]-ABs.A_5_14.data[i][j]-ABs.A_5_15.data[i][j]-ABs.A_5_16.data[i][j]-ABs.A_5_17.data[i][j]-ABs.A_5_18.data[i][j]-ABs.A_5_19.data[i][j]+11*ABs.A_5_20.data[i][j]-ABs.A_5_21.data[i][j]-ABs.A_5_22.data[i][j]-ABs.A_20_10.data[i][j]+11*ABs.A_20_11.data[i][j]-ABs.A_20_7.data[i][j]-ABs.A_20_8.data[i][j]-ABs.A_20_9.data[i][j]-ABs.A_20_1.data[i][j]-ABs.A_20_2.data[i][j]-ABs.A_20_3.data[i][j]-ABs.A_20_4.data[i][j]-ABs.A_20_5.data[i][j]-ABs.A_20_6.data[i][j];
        tmp0.data[i][j] /= 12.0;
        tmp1.data[i][j] = ABs.B_16_9.data[i][j]+ABs.B_11_16.data[i][j]+ABs.B_20_22.data[i][j];
    }
}
fmm_22x22(m, tmp0, tmp1);
free_double_matrix(tmp0);
free_double_matrix(tmp1);
    return 0;
}
