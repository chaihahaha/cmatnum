#include "fBx4183.h"

inline int fBx4183(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx4183.data[i][j] = bmats.B_10_1.data[i][j] + bmats.B_11_1.data[i][j] - bmats.B_12_1.data[i][j] - bmats.B_13_1.data[i][j] - bmats.B_14_1.data[i][j] - bmats.B_15_1.data[i][j] - bmats.B_16_1.data[i][j] - bmats.B_17_1.data[i][j] - bmats.B_18_1.data[i][j] - bmats.B_19_1.data[i][j] + bmats.B_1_1.data[i][j] - bmats.B_20_1.data[i][j] - bmats.B_21_1.data[i][j] - bmats.B_22_1.data[i][j] + bmats.B_2_1.data[i][j] + bmats.B_3_1.data[i][j] + bmats.B_4_1.data[i][j] + bmats.B_5_1.data[i][j] + bmats.B_6_1.data[i][j] + bmats.B_7_1.data[i][j] + bmats.B_8_1.data[i][j] + bmats.B_9_1.data[i][j];
        }
    }
    return 0;
}
