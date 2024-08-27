#include "fm_809.h"

inline int fm_809(double_cmat m, pack_mats_22x22 ABs) {

double dnum12 = 1/12.0;

int BL = ABs.A_1_1.shape[0];
double_cmat tmp0, tmp1;
create_double_matrix(pairint {BL, BL}, &tmp0);
create_double_matrix(pairint {BL, BL}, &tmp1);
for (int i=0; i<BL; i++) {
    for (int j=0; j<BL; j++) {
        tmp0.data[i][j] = -ABs.A_8_13.data[i][j]-ABs.A_8_14.data[i][j]-ABs.A_8_15.data[i][j]-ABs.A_8_16.data[i][j]-ABs.A_8_17.data[i][j]-ABs.A_8_18.data[i][j]-ABs.A_8_19.data[i][j]-ABs.A_8_20.data[i][j]-ABs.A_8_21.data[i][j]+11*ABs.A_8_22.data[i][j]-ABs.A_8_12.data[i][j]+ABs.A_11_11.data[i][j]+ABs.A_11_1.data[i][j]+ABs.A_11_2.data[i][j]+ABs.A_11_3.data[i][j]+ABs.A_11_4.data[i][j]+ABs.A_11_5.data[i][j]+ABs.A_11_6.data[i][j]+ABs.A_11_7.data[i][j]+ABs.A_11_8.data[i][j]-11*ABs.A_11_9.data[i][j]+ABs.A_11_10.data[i][j]-ABs.A_20_10.data[i][j]-ABs.A_20_11.data[i][j]-ABs.A_20_7.data[i][j]+11*ABs.A_20_8.data[i][j]-ABs.A_20_9.data[i][j]-ABs.A_20_1.data[i][j]-ABs.A_20_2.data[i][j]-ABs.A_20_3.data[i][j]-ABs.A_20_4.data[i][j]-ABs.A_20_5.data[i][j]-ABs.A_20_6.data[i][j];
        tmp0.data[i][j] *= dnum12;
        tmp1.data[i][j] = ABs.B_22_9.data[i][j]+ABs.B_8_11.data[i][j]+ABs.B_9_19.data[i][j];
    }
}
fmm_22x22(m, tmp0, tmp1);
free_double_matrix(tmp0);
free_double_matrix(tmp1);
    return 0;

}

