#include "fBx4193.h"

inline int fBx4193(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx4193.data[i][j] = bmats.B_10_2.data[i][j] + bmats.B_11_2.data[i][j] - bmats.B_12_2.data[i][j] - bmats.B_13_2.data[i][j] - bmats.B_14_2.data[i][j] - bmats.B_15_2.data[i][j] - bmats.B_16_2.data[i][j] - bmats.B_17_2.data[i][j] - bmats.B_18_2.data[i][j] - bmats.B_19_2.data[i][j] + bmats.B_1_2.data[i][j] - bmats.B_20_2.data[i][j] - bmats.B_21_2.data[i][j] - bmats.B_22_2.data[i][j] + bmats.B_2_2.data[i][j] + bmats.B_3_2.data[i][j] + bmats.B_4_2.data[i][j] + bmats.B_5_2.data[i][j] + bmats.B_6_2.data[i][j] + bmats.B_7_2.data[i][j] + bmats.B_8_2.data[i][j] + bmats.B_9_2.data[i][j];
        }
    }
    return 0;
}
