#include "fBx4243.h"

inline int fBx4243(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx4243.data[i][j] = -bmats.B_10_17.data[i][j] - bmats.B_11_17.data[i][j] + bmats.B_12_17.data[i][j] + bmats.B_13_17.data[i][j] + bmats.B_14_17.data[i][j] + bmats.B_15_17.data[i][j] + bmats.B_16_17.data[i][j] + bmats.B_17_17.data[i][j] + bmats.B_18_17.data[i][j] + bmats.B_19_17.data[i][j] - bmats.B_1_17.data[i][j] + bmats.B_20_17.data[i][j] + bmats.B_21_17.data[i][j] + bmats.B_22_17.data[i][j] - bmats.B_2_17.data[i][j] - bmats.B_3_17.data[i][j] - bmats.B_4_17.data[i][j] - bmats.B_5_17.data[i][j] - bmats.B_6_17.data[i][j] - bmats.B_7_17.data[i][j] - bmats.B_8_17.data[i][j] - bmats.B_9_17.data[i][j];
        }
    }
    return 0;
}
