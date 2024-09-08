#include "fBx4219.h"

inline int fBx4219(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx4219.data[i][j] = -bmats.B_10_15.data[i][j] - bmats.B_11_15.data[i][j] + bmats.B_12_15.data[i][j] + bmats.B_13_15.data[i][j] + bmats.B_14_15.data[i][j] + bmats.B_15_15.data[i][j] + bmats.B_16_15.data[i][j] + bmats.B_17_15.data[i][j] + bmats.B_18_15.data[i][j] + bmats.B_19_15.data[i][j] - bmats.B_1_15.data[i][j] + bmats.B_20_15.data[i][j] + bmats.B_21_15.data[i][j] + bmats.B_22_15.data[i][j] - bmats.B_2_15.data[i][j] - bmats.B_3_15.data[i][j] - bmats.B_4_15.data[i][j] - bmats.B_5_15.data[i][j] - bmats.B_6_15.data[i][j] - bmats.B_7_15.data[i][j] - bmats.B_8_15.data[i][j] - bmats.B_9_15.data[i][j];
        }
    }
    return 0;
}
