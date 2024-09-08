#include "fBx4203.h"

inline int fBx4203(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx4203.data[i][j] = bmats.B_10_3.data[i][j] + bmats.B_11_3.data[i][j] - bmats.B_12_3.data[i][j] - bmats.B_13_3.data[i][j] - bmats.B_14_3.data[i][j] - bmats.B_15_3.data[i][j] - bmats.B_16_3.data[i][j] - bmats.B_17_3.data[i][j] - bmats.B_18_3.data[i][j] - bmats.B_19_3.data[i][j] + bmats.B_1_3.data[i][j] - bmats.B_20_3.data[i][j] - bmats.B_21_3.data[i][j] - bmats.B_22_3.data[i][j] + bmats.B_2_3.data[i][j] + bmats.B_3_3.data[i][j] + bmats.B_4_3.data[i][j] + bmats.B_5_3.data[i][j] + bmats.B_6_3.data[i][j] + bmats.B_7_3.data[i][j] + bmats.B_8_3.data[i][j] + bmats.B_9_3.data[i][j];
        }
    }
    return 0;
}
