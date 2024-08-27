#include "fm_820.h"

inline int fm_820(double_cmat m, pack_mats_22x22 ABs) {

double dnum12 = 1/12.0;

int BL = ABs.A_1_1.shape[0];
double_cmat tmp0, tmp1;
create_double_matrix(pairint {BL, BL}, &tmp0);
create_double_matrix(pairint {BL, BL}, &tmp1);
for (int i=0; i<BL; i++) {
    for (int j=0; j<BL; j++) {
        tmp0.data[i][j] = -ABs.A_4_12.data[i][j]-ABs.A_4_13.data[i][j]-ABs.A_4_14.data[i][j]-ABs.A_4_15.data[i][j]-ABs.A_4_16.data[i][j]-ABs.A_4_17.data[i][j]-ABs.A_4_18.data[i][j]-ABs.A_4_19.data[i][j]+11*ABs.A_4_20.data[i][j]-ABs.A_4_21.data[i][j]-ABs.A_4_22.data[i][j]+ABs.A_9_11.data[i][j]+ABs.A_9_1.data[i][j]+ABs.A_9_2.data[i][j]+ABs.A_9_3.data[i][j]+ABs.A_9_4.data[i][j]+ABs.A_9_5.data[i][j]+ABs.A_9_6.data[i][j]+ABs.A_9_7.data[i][j]+ABs.A_9_8.data[i][j]-11*ABs.A_9_9.data[i][j]+ABs.A_9_10.data[i][j]-ABs.A_20_10.data[i][j]-ABs.A_20_11.data[i][j]-ABs.A_20_7.data[i][j]-ABs.A_20_8.data[i][j]-ABs.A_20_9.data[i][j]-ABs.A_20_1.data[i][j]-ABs.A_20_2.data[i][j]-ABs.A_20_3.data[i][j]+11*ABs.A_20_4.data[i][j]-ABs.A_20_5.data[i][j]-ABs.A_20_6.data[i][j];
        tmp0.data[i][j] *= dnum12;
        tmp1.data[i][j] = ABs.B_4_9.data[i][j]+ABs.B_20_9.data[i][j]+ABs.B_9_15.data[i][j];
    }
}
fmm_22x22(m, tmp0, tmp1);
free_double_matrix(tmp0);
free_double_matrix(tmp1);
    return 0;

}

