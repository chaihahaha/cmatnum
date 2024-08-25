#include "fm_5481.h"

int fm_5481(double_cmat m, pack_mats_22x22 ABs) {
int N = ABs.A_1_1.shape[0];
double_cmat tmp0, tmp1;
create_double_matrix(pairint {N, N}, &tmp0);
create_double_matrix(pairint {N, N}, &tmp1);
for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
        tmp0.data[i][j] = -2*ABs.A_2_1.data[i][j]-ABs.A_9_1.data[i][j]+10*ABs.A_2_2.data[i][j]+11*ABs.A_9_2.data[i][j]-2*ABs.A_2_3.data[i][j]-ABs.A_9_3.data[i][j]-2*ABs.A_2_4.data[i][j]-ABs.A_9_4.data[i][j]-2*ABs.A_2_5.data[i][j]-ABs.A_9_5.data[i][j]-2*ABs.A_2_6.data[i][j]-ABs.A_9_6.data[i][j]-2*ABs.A_2_7.data[i][j]-ABs.A_9_7.data[i][j]-2*ABs.A_2_8.data[i][j]-ABs.A_9_8.data[i][j]+10*ABs.A_2_9.data[i][j]-ABs.A_9_9.data[i][j]-2*ABs.A_2_10.data[i][j]-ABs.A_9_10.data[i][j]-2*ABs.A_2_11.data[i][j]-ABs.A_9_11.data[i][j];
        tmp0.data[i][j] /= 12.0;
        tmp1.data[i][j] = ABs.B_2_2.data[i][j]+ABs.B_9_2.data[i][j]+ABs.B_2_9.data[i][j];
    }
}
fmm_22x22(m, tmp0, tmp1);
free_double_matrix(tmp0);
free_double_matrix(tmp1);
    return 0;
}
