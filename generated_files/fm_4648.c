#include "fm_4648.h"

int fm_4648(double_cmat m, pack_mats_22x22 ABs) {
int N = ABs.A_1_1.shape[0];
double_cmat tmp0, tmp1;
create_double_matrix(pairint {N, N}, &tmp0);
create_double_matrix(pairint {N, N}, &tmp1);
for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
        tmp0.data[i][j] = +11*ABs.A_9_11.data[i][j]-ABs.A_9_1.data[i][j]-ABs.A_9_2.data[i][j]-ABs.A_9_3.data[i][j]-ABs.A_9_4.data[i][j]-ABs.A_9_5.data[i][j]-ABs.A_9_6.data[i][j]-ABs.A_9_7.data[i][j]-ABs.A_9_8.data[i][j]-ABs.A_9_9.data[i][j]-ABs.A_9_10.data[i][j]-ABs.A_10_11.data[i][j]-ABs.A_10_1.data[i][j]-ABs.A_10_2.data[i][j]-ABs.A_10_3.data[i][j]-ABs.A_10_4.data[i][j]-ABs.A_10_5.data[i][j]-ABs.A_10_6.data[i][j]-ABs.A_10_7.data[i][j]-ABs.A_10_8.data[i][j]+11*ABs.A_10_9.data[i][j]-ABs.A_10_10.data[i][j]-ABs.A_11_11.data[i][j]-ABs.A_11_1.data[i][j]-ABs.A_11_2.data[i][j]-ABs.A_11_3.data[i][j]-ABs.A_11_4.data[i][j]-ABs.A_11_5.data[i][j]-ABs.A_11_6.data[i][j]-ABs.A_11_7.data[i][j]-ABs.A_11_8.data[i][j]-ABs.A_11_9.data[i][j]+11*ABs.A_11_10.data[i][j];
        tmp0.data[i][j] /= 12.0;
        tmp1.data[i][j] = ABs.B_10_9.data[i][j]+ABs.B_11_10.data[i][j]+ABs.B_9_11.data[i][j];
    }
}
fmm_22x22(m, tmp0, tmp1);
free_double_matrix(tmp0);
free_double_matrix(tmp1);
    return 0;
}
