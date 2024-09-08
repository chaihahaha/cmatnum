#include "fBx13310.h"

inline int fBx13310(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx13310.data[i][j] = bmats.B_10_13.data[i][j] + bmats.B_11_13.data[i][j] + bmats.B_12_13.data[i][j] + bmats.B_13_13.data[i][j] + bmats.B_14_13.data[i][j] + bmats.B_15_13.data[i][j] + bmats.B_16_13.data[i][j] - bmats.B_17_13.data[i][j] - bmats.B_18_13.data[i][j] - bmats.B_19_13.data[i][j] + bmats.B_1_13.data[i][j] - bmats.B_20_13.data[i][j] - bmats.B_21_13.data[i][j] - bmats.B_22_13.data[i][j] - bmats.B_23_13.data[i][j] - bmats.B_24_13.data[i][j] - bmats.B_25_13.data[i][j] - bmats.B_26_13.data[i][j] - bmats.B_27_13.data[i][j] - bmats.B_28_13.data[i][j] - bmats.B_29_13.data[i][j] + bmats.B_2_13.data[i][j] - bmats.B_30_13.data[i][j] - bmats.B_31_13.data[i][j] - bmats.B_32_13.data[i][j] + bmats.B_3_13.data[i][j] + bmats.B_4_13.data[i][j] + bmats.B_5_13.data[i][j] + bmats.B_6_13.data[i][j] + bmats.B_7_13.data[i][j] + bmats.B_8_13.data[i][j] + bmats.B_9_13.data[i][j];
        }
    }
    return 0;
}
