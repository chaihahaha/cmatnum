#include "fBx13280.h"

inline int fBx13280(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx13280.data[i][j] = bmats.B_10_8.data[i][j] + bmats.B_11_8.data[i][j] + bmats.B_12_8.data[i][j] + bmats.B_13_8.data[i][j] + bmats.B_14_8.data[i][j] + bmats.B_15_8.data[i][j] + bmats.B_16_8.data[i][j] - bmats.B_17_8.data[i][j] - bmats.B_18_8.data[i][j] - bmats.B_19_8.data[i][j] + bmats.B_1_8.data[i][j] - bmats.B_20_8.data[i][j] - bmats.B_21_8.data[i][j] - bmats.B_22_8.data[i][j] - bmats.B_23_8.data[i][j] - bmats.B_24_8.data[i][j] - bmats.B_25_8.data[i][j] - bmats.B_26_8.data[i][j] - bmats.B_27_8.data[i][j] - bmats.B_28_8.data[i][j] - bmats.B_29_8.data[i][j] + bmats.B_2_8.data[i][j] - bmats.B_30_8.data[i][j] - bmats.B_31_8.data[i][j] - bmats.B_32_8.data[i][j] + bmats.B_3_8.data[i][j] + bmats.B_4_8.data[i][j] + bmats.B_5_8.data[i][j] + bmats.B_6_8.data[i][j] + bmats.B_7_8.data[i][j] + bmats.B_8_8.data[i][j] + bmats.B_9_8.data[i][j];
        }
    }
    return 0;
}
