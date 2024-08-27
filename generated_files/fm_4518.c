#include "fm_4518.h"

inline int fm_4518(double_cmat m, pack_mats_22x22 ABs) {

double dnum12 = 1/12.0;

int BL = ABs.A_1_1.shape[0];
double_cmat tmp0, tmp1;
create_double_matrix(pairint {BL, BL}, &tmp0);
create_double_matrix(pairint {BL, BL}, &tmp1);
for (int i=0; i<BL; i++) {
    for (int j=0; j<BL; j++) {
        tmp0.data[i][j] = -ABs.A_8_13.data[i][j]-ABs.A_8_14.data[i][j]-ABs.A_8_15.data[i][j]-ABs.A_8_16.data[i][j]-ABs.A_8_17.data[i][j]+11*ABs.A_8_18.data[i][j]-ABs.A_8_19.data[i][j]-ABs.A_8_20.data[i][j]-ABs.A_8_21.data[i][j]-ABs.A_8_22.data[i][j]-ABs.A_8_12.data[i][j]+ABs.A_15_12.data[i][j]+ABs.A_15_13.data[i][j]+ABs.A_15_14.data[i][j]+ABs.A_15_15.data[i][j]+ABs.A_15_16.data[i][j]+ABs.A_15_17.data[i][j]+ABs.A_15_18.data[i][j]-11*ABs.A_15_19.data[i][j]+ABs.A_15_20.data[i][j]+ABs.A_15_21.data[i][j]+ABs.A_15_22.data[i][j]-ABs.A_18_10.data[i][j]-ABs.A_18_9.data[i][j]-ABs.A_18_5.data[i][j]-ABs.A_18_11.data[i][j]-ABs.A_18_1.data[i][j]-ABs.A_18_2.data[i][j]+11*ABs.A_18_4.data[i][j]-ABs.A_18_3.data[i][j]-ABs.A_18_6.data[i][j]-ABs.A_18_7.data[i][j]-ABs.A_18_8.data[i][j];
        tmp0.data[i][j] *= dnum12;
        tmp1.data[i][j] = ABs.B_19_7.data[i][j]+ABs.B_18_15.data[i][j]+ABs.B_4_19.data[i][j];
    }
}
fmm_22x22(m, tmp0, tmp1);
free_double_matrix(tmp0);
free_double_matrix(tmp1);
    return 0;

}

