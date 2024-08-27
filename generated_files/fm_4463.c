#include "fm_4463.h"

inline int fm_4463(double_cmat m, pack_mats_22x22 ABs) {

double dnum12 = 1/12.0;

int BL = ABs.A_1_1.shape[0];
double_cmat tmp0, tmp1;
create_double_matrix(pairint {BL, BL}, &tmp0);
create_double_matrix(pairint {BL, BL}, &tmp1);
for (int i=0; i<BL; i++) {
    for (int j=0; j<BL; j++) {
        tmp0.data[i][j] = -ABs.A_1_12.data[i][j]+ABs.A_13_13.data[i][j]+ABs.A_13_14.data[i][j]+ABs.A_13_15.data[i][j]+ABs.A_13_16.data[i][j]+ABs.A_13_17.data[i][j]+ABs.A_13_18.data[i][j]+ABs.A_13_19.data[i][j]+ABs.A_13_20.data[i][j]+ABs.A_13_21.data[i][j]+ABs.A_13_22.data[i][j]-ABs.A_1_13.data[i][j]-ABs.A_1_14.data[i][j]+11*ABs.A_1_15.data[i][j]-ABs.A_1_16.data[i][j]-ABs.A_1_17.data[i][j]-ABs.A_1_18.data[i][j]-ABs.A_1_19.data[i][j]-ABs.A_1_20.data[i][j]-ABs.A_1_21.data[i][j]-ABs.A_1_22.data[i][j]-11*ABs.A_13_12.data[i][j]-ABs.A_15_10.data[i][j]-ABs.A_15_11.data[i][j]-ABs.A_15_4.data[i][j]-ABs.A_15_5.data[i][j]-ABs.A_15_6.data[i][j]-ABs.A_15_7.data[i][j]-ABs.A_15_8.data[i][j]-ABs.A_15_9.data[i][j]-ABs.A_15_1.data[i][j]+11*ABs.A_15_2.data[i][j]-ABs.A_15_3.data[i][j];
        tmp0.data[i][j] *= dnum12;
        tmp1.data[i][j] = ABs.B_12_4.data[i][j]+ABs.B_2_12.data[i][j]+ABs.B_15_13.data[i][j];
    }
}
fmm_22x22(m, tmp0, tmp1);
free_double_matrix(tmp0);
free_double_matrix(tmp1);
    return 0;

}

