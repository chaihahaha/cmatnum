#include "fm_1406.h"

inline int fm_1406(double_cmat m, pack_mats_22x22 ABs) {

double dnum12 = 1/12.0;

int BL = ABs.A_1_1.shape[0];
double_cmat tmp0, tmp1;
create_double_matrix(pairint {BL, BL}, &tmp0);
create_double_matrix(pairint {BL, BL}, &tmp1);
for (int i=0; i<BL; i++) {
    for (int j=0; j<BL; j++) {
        tmp0.data[i][j] = -ABs.A_5_12.data[i][j]-ABs.A_5_13.data[i][j]-ABs.A_5_14.data[i][j]-ABs.A_5_15.data[i][j]-ABs.A_5_16.data[i][j]-ABs.A_5_17.data[i][j]-ABs.A_5_18.data[i][j]-ABs.A_5_19.data[i][j]-ABs.A_5_20.data[i][j]-ABs.A_5_21.data[i][j]+11*ABs.A_5_22.data[i][j]+ABs.A_11_11.data[i][j]+ABs.A_11_1.data[i][j]+ABs.A_11_2.data[i][j]+ABs.A_11_3.data[i][j]-11*ABs.A_11_4.data[i][j]+ABs.A_11_5.data[i][j]+ABs.A_11_6.data[i][j]+ABs.A_11_7.data[i][j]+ABs.A_11_8.data[i][j]+ABs.A_11_9.data[i][j]+ABs.A_11_10.data[i][j]-ABs.A_15_10.data[i][j]-ABs.A_15_11.data[i][j]-ABs.A_15_4.data[i][j]+11*ABs.A_15_5.data[i][j]-ABs.A_15_6.data[i][j]-ABs.A_15_7.data[i][j]-ABs.A_15_8.data[i][j]-ABs.A_15_9.data[i][j]-ABs.A_15_1.data[i][j]-ABs.A_15_2.data[i][j]-ABs.A_15_3.data[i][j];
        tmp0.data[i][j] *= dnum12;
        tmp1.data[i][j] = ABs.B_22_4.data[i][j]+ABs.B_5_11.data[i][j]+ABs.B_4_16.data[i][j];
    }
}
fmm_22x22(m, tmp0, tmp1);
free_double_matrix(tmp0);
free_double_matrix(tmp1);
    return 0;

}

