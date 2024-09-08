#include "fBx13215.h"

inline int fBx13215(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx13215.data[i][j] = -bmats.B_10_30.data[i][j] - bmats.B_11_30.data[i][j] - bmats.B_12_30.data[i][j] - bmats.B_13_30.data[i][j] - bmats.B_14_30.data[i][j] - bmats.B_15_30.data[i][j] - bmats.B_16_30.data[i][j] + bmats.B_17_30.data[i][j] + bmats.B_18_30.data[i][j] + bmats.B_19_30.data[i][j] - bmats.B_1_30.data[i][j] + bmats.B_20_30.data[i][j] + bmats.B_21_30.data[i][j] + bmats.B_22_30.data[i][j] + bmats.B_23_30.data[i][j] + bmats.B_24_30.data[i][j] + bmats.B_25_30.data[i][j] + bmats.B_26_30.data[i][j] + bmats.B_27_30.data[i][j] + bmats.B_28_30.data[i][j] + bmats.B_29_30.data[i][j] - bmats.B_2_30.data[i][j] + bmats.B_30_30.data[i][j] + bmats.B_31_30.data[i][j] + bmats.B_32_30.data[i][j] - bmats.B_3_30.data[i][j] - bmats.B_4_30.data[i][j] - bmats.B_5_30.data[i][j] - bmats.B_6_30.data[i][j] - bmats.B_7_30.data[i][j] - bmats.B_8_30.data[i][j] - bmats.B_9_30.data[i][j];
        }
    }
    return 0;
}
