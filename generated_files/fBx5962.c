#include "fBx5962.h"

inline int fBx5962(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx5962.data[i][j] = bmats.B_17_27.data[i][j] + bmats.B_18_27.data[i][j] + bmats.B_19_27.data[i][j] + bmats.B_20_27.data[i][j] + bmats.B_21_27.data[i][j] + bmats.B_22_27.data[i][j] + bmats.B_23_27.data[i][j] + bmats.B_24_27.data[i][j] + bmats.B_25_27.data[i][j] + bmats.B_26_27.data[i][j] + bmats.B_31_27.data[i][j] + bmats.B_32_27.data[i][j];
        }
    }
    return 0;
}