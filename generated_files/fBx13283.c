#include "fBx13283.h"

inline int fBx13283(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx13283.data[i][j] = -bmats.B_10_24.data[i][j] - bmats.B_11_24.data[i][j] - bmats.B_12_24.data[i][j] - bmats.B_13_24.data[i][j] - bmats.B_14_24.data[i][j] - bmats.B_15_24.data[i][j] - bmats.B_16_24.data[i][j] + bmats.B_17_24.data[i][j] + bmats.B_18_24.data[i][j] + bmats.B_19_24.data[i][j] - bmats.B_1_24.data[i][j] + bmats.B_20_24.data[i][j] + bmats.B_21_24.data[i][j] + bmats.B_22_24.data[i][j] + bmats.B_23_24.data[i][j] + bmats.B_24_24.data[i][j] + bmats.B_25_24.data[i][j] + bmats.B_26_24.data[i][j] + bmats.B_27_24.data[i][j] + bmats.B_28_24.data[i][j] + bmats.B_29_24.data[i][j] - bmats.B_2_24.data[i][j] + bmats.B_30_24.data[i][j] + bmats.B_31_24.data[i][j] + bmats.B_32_24.data[i][j] - bmats.B_3_24.data[i][j] - bmats.B_4_24.data[i][j] - bmats.B_5_24.data[i][j] - bmats.B_6_24.data[i][j] - bmats.B_7_24.data[i][j] - bmats.B_8_24.data[i][j] - bmats.B_9_24.data[i][j];
        }
    }
    return 0;
}
