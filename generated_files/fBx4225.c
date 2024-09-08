#include "fBx4225.h"

inline int fBx4225(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx4225.data[i][j] = bmats.B_10_5.data[i][j] + bmats.B_11_5.data[i][j] - bmats.B_12_5.data[i][j] - bmats.B_13_5.data[i][j] - bmats.B_14_5.data[i][j] - bmats.B_15_5.data[i][j] - bmats.B_16_5.data[i][j] - bmats.B_17_5.data[i][j] - bmats.B_18_5.data[i][j] - bmats.B_19_5.data[i][j] + bmats.B_1_5.data[i][j] - bmats.B_20_5.data[i][j] - bmats.B_21_5.data[i][j] - bmats.B_22_5.data[i][j] + bmats.B_2_5.data[i][j] + bmats.B_3_5.data[i][j] + bmats.B_4_5.data[i][j] + bmats.B_5_5.data[i][j] + bmats.B_6_5.data[i][j] + bmats.B_7_5.data[i][j] + bmats.B_8_5.data[i][j] + bmats.B_9_5.data[i][j];
        }
    }
    return 0;
}
