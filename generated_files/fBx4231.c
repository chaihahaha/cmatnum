#include "fBx4231.h"

inline int fBx4231(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx4231.data[i][j] = -bmats.B_10_16.data[i][j] - bmats.B_11_16.data[i][j] + bmats.B_12_16.data[i][j] + bmats.B_13_16.data[i][j] + bmats.B_14_16.data[i][j] + bmats.B_15_16.data[i][j] + bmats.B_16_16.data[i][j] + bmats.B_17_16.data[i][j] + bmats.B_18_16.data[i][j] + bmats.B_19_16.data[i][j] - bmats.B_1_16.data[i][j] + bmats.B_20_16.data[i][j] + bmats.B_21_16.data[i][j] + bmats.B_22_16.data[i][j] - bmats.B_2_16.data[i][j] - bmats.B_3_16.data[i][j] - bmats.B_4_16.data[i][j] - bmats.B_5_16.data[i][j] - bmats.B_6_16.data[i][j] - bmats.B_7_16.data[i][j] - bmats.B_8_16.data[i][j] - bmats.B_9_16.data[i][j];
        }
    }
    return 0;
}
