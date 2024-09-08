#include "fBx4188.h"

inline int fBx4188(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx4188.data[i][j] = -bmats.B_10_12.data[i][j] - bmats.B_11_12.data[i][j] + bmats.B_12_12.data[i][j] + bmats.B_13_12.data[i][j] + bmats.B_14_12.data[i][j] + bmats.B_15_12.data[i][j] + bmats.B_16_12.data[i][j] + bmats.B_17_12.data[i][j] + bmats.B_18_12.data[i][j] + bmats.B_19_12.data[i][j] - bmats.B_1_12.data[i][j] + bmats.B_20_12.data[i][j] + bmats.B_21_12.data[i][j] + bmats.B_22_12.data[i][j] - bmats.B_2_12.data[i][j] - bmats.B_3_12.data[i][j] - bmats.B_4_12.data[i][j] - bmats.B_5_12.data[i][j] - bmats.B_6_12.data[i][j] - bmats.B_7_12.data[i][j] - bmats.B_8_12.data[i][j] - bmats.B_9_12.data[i][j];
        }
    }
    return 0;
}
