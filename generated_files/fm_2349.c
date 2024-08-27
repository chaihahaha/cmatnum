#include "fm_2349.h"

inline int fm_2349(double_cmat m, pack_mats_22x22 ABs) {

double dnum12 = 1/12.0;

int BL = ABs.A_1_1.shape[0];
double_cmat tmp0, tmp1;
create_double_matrix(pairint {BL, BL}, &tmp0);
create_double_matrix(pairint {BL, BL}, &tmp1);
for (int i=0; i<BL; i++) {
    for (int j=0; j<BL; j++) {
        tmp0.data[i][j] = +11*ABs.A_7_12.data[i][j]-ABs.A_7_13.data[i][j]-ABs.A_7_14.data[i][j]-ABs.A_7_15.data[i][j]-ABs.A_7_16.data[i][j]-ABs.A_7_17.data[i][j]-ABs.A_7_18.data[i][j]-ABs.A_7_19.data[i][j]-ABs.A_7_20.data[i][j]-ABs.A_7_21.data[i][j]-ABs.A_7_22.data[i][j]-ABs.A_12_11.data[i][j]-ABs.A_12_1.data[i][j]-ABs.A_12_2.data[i][j]-ABs.A_12_3.data[i][j]-ABs.A_12_4.data[i][j]-ABs.A_12_5.data[i][j]-ABs.A_12_6.data[i][j]-ABs.A_12_7.data[i][j]+11*ABs.A_12_8.data[i][j]-ABs.A_12_9.data[i][j]-ABs.A_12_10.data[i][j]+ABs.A_19_12.data[i][j]+ABs.A_19_13.data[i][j]+ABs.A_19_14.data[i][j]+ABs.A_19_15.data[i][j]+ABs.A_19_16.data[i][j]+ABs.A_19_17.data[i][j]-11*ABs.A_19_18.data[i][j]+ABs.A_19_19.data[i][j]+ABs.A_19_20.data[i][j]+ABs.A_19_21.data[i][j]+ABs.A_19_22.data[i][j];
        tmp0.data[i][j] *= dnum12;
        tmp1.data[i][j] = ABs.B_18_1.data[i][j]+ABs.B_8_18.data[i][j]+ABs.B_12_19.data[i][j];
    }
}
fmm_22x22(m, tmp0, tmp1);
free_double_matrix(tmp0);
free_double_matrix(tmp1);
    return 0;

}

