#include "fBx13277.h"

inline int fBx13277(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx13277.data[i][j] = -bmats.B_12_23.data[i][j] - bmats.B_13_23.data[i][j] - bmats.B_15_23.data[i][j] - bmats.B_16_23.data[i][j] + bmats.B_17_23.data[i][j] + bmats.B_18_23.data[i][j] + bmats.B_19_23.data[i][j] - bmats.B_1_23.data[i][j] + bmats.B_20_23.data[i][j] + bmats.B_21_23.data[i][j] + bmats.B_22_23.data[i][j] + bmats.B_23_23.data[i][j] + bmats.B_24_23.data[i][j] + bmats.B_25_23.data[i][j] + bmats.B_26_23.data[i][j] + bmats.B_27_23.data[i][j] + bmats.B_28_23.data[i][j] + bmats.B_29_23.data[i][j] - bmats.B_2_23.data[i][j] + bmats.B_30_23.data[i][j] + bmats.B_31_23.data[i][j] + bmats.B_32_23.data[i][j] - bmats.B_3_23.data[i][j] - bmats.B_4_23.data[i][j] - bmats.B_5_23.data[i][j] - bmats.B_6_23.data[i][j] - bmats.Bx10243.data[i][j];
        }
    }
    return 0;
}
