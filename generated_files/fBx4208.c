#include "fBx4208.h"

inline int fBx4208(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx4208.data[i][j] = -bmats.B_10_14.data[i][j] - bmats.B_11_14.data[i][j] + bmats.B_12_14.data[i][j] + bmats.B_13_14.data[i][j] + bmats.B_14_14.data[i][j] + bmats.B_15_14.data[i][j] + bmats.B_16_14.data[i][j] + bmats.B_17_14.data[i][j] + bmats.B_18_14.data[i][j] + bmats.B_19_14.data[i][j] - bmats.B_1_14.data[i][j] + bmats.B_20_14.data[i][j] + bmats.B_21_14.data[i][j] + bmats.B_22_14.data[i][j] - bmats.B_2_14.data[i][j] - bmats.B_3_14.data[i][j] - bmats.B_4_14.data[i][j] - bmats.B_5_14.data[i][j] - bmats.B_6_14.data[i][j] - bmats.B_7_14.data[i][j] - bmats.B_8_14.data[i][j] - bmats.B_9_14.data[i][j];
        }
    }
    return 0;
}
