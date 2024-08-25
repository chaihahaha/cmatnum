#include "fm_1544.h"

int fm_1544(double_cmat m, pack_mats_22x22 ABs) {
int N = ABs.A_1_1.shape[0];
double_cmat tmp0, tmp1;
create_double_matrix(pairint {N, N}, &tmp0);
create_double_matrix(pairint {N, N}, &tmp1);
for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
        tmp0.data[i][j] = -ABs.A_5_12.data[i][j]-ABs.A_5_13.data[i][j]-ABs.A_5_14.data[i][j]-ABs.A_5_15.data[i][j]-ABs.A_5_16.data[i][j]-ABs.A_5_17.data[i][j]-ABs.A_5_18.data[i][j]+11*ABs.A_5_19.data[i][j]-ABs.A_5_20.data[i][j]-ABs.A_5_21.data[i][j]-ABs.A_5_22.data[i][j]+ABs.A_8_11.data[i][j]+ABs.A_8_1.data[i][j]+ABs.A_8_2.data[i][j]-11*ABs.A_8_3.data[i][j]+ABs.A_8_4.data[i][j]+ABs.A_8_5.data[i][j]+ABs.A_8_6.data[i][j]+ABs.A_8_7.data[i][j]+ABs.A_8_8.data[i][j]+ABs.A_8_9.data[i][j]+ABs.A_8_10.data[i][j]-ABs.A_14_11.data[i][j]-ABs.A_14_1.data[i][j]-ABs.A_14_2.data[i][j]-ABs.A_14_3.data[i][j]-ABs.A_14_4.data[i][j]+11*ABs.A_14_5.data[i][j]-ABs.A_14_6.data[i][j]-ABs.A_14_7.data[i][j]-ABs.A_14_8.data[i][j]-ABs.A_14_9.data[i][j]-ABs.A_14_10.data[i][j];
        tmp0.data[i][j] /= 12.0;
        tmp1.data[i][j] = ABs.B_19_3.data[i][j]+ABs.B_5_8.data[i][j]+ABs.B_3_16.data[i][j];
    }
}
fmm_22x22(m, tmp0, tmp1);
free_double_matrix(tmp0);
free_double_matrix(tmp1);
    return 0;
}
