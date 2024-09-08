#include "fBx4198.h"

inline int fBx4198(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx4198.data[i][j] = -bmats.B_10_13.data[i][j] - bmats.B_11_13.data[i][j] + bmats.B_12_13.data[i][j] + bmats.B_13_13.data[i][j] + bmats.B_14_13.data[i][j] + bmats.B_15_13.data[i][j] + bmats.B_16_13.data[i][j] + bmats.B_17_13.data[i][j] + bmats.B_18_13.data[i][j] + bmats.B_19_13.data[i][j] - bmats.B_1_13.data[i][j] + bmats.B_20_13.data[i][j] + bmats.B_21_13.data[i][j] + bmats.B_22_13.data[i][j] - bmats.B_2_13.data[i][j] - bmats.B_3_13.data[i][j] - bmats.B_4_13.data[i][j] - bmats.B_5_13.data[i][j] - bmats.B_6_13.data[i][j] - bmats.B_7_13.data[i][j] - bmats.B_8_13.data[i][j] - bmats.B_9_13.data[i][j];
        }
    }
    return 0;
}
