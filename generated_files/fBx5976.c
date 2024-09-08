#include "fBx5976.h"

inline int fBx5976(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx5976.data[i][j] = bmats.B_10_27.data[i][j] + bmats.B_11_27.data[i][j] + bmats.B_12_27.data[i][j] + bmats.B_13_27.data[i][j] + bmats.B_14_27.data[i][j] + bmats.B_15_27.data[i][j] + bmats.B_16_27.data[i][j] + bmats.B_1_27.data[i][j] + bmats.B_2_27.data[i][j] + bmats.B_3_27.data[i][j] + bmats.B_4_27.data[i][j] + bmats.B_5_27.data[i][j] + bmats.B_6_27.data[i][j] + bmats.B_7_27.data[i][j] + bmats.B_8_27.data[i][j] + bmats.B_9_27.data[i][j];
        }
    }
    return 0;
}
