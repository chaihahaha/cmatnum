#include "fBx4086.h"

inline int fBx4086(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx4086.data[i][j] = bmats.B_10_10.data[i][j] + bmats.B_11_10.data[i][j] - bmats.B_12_10.data[i][j] - bmats.B_13_10.data[i][j] - bmats.B_14_10.data[i][j] - bmats.B_15_10.data[i][j] - bmats.B_16_10.data[i][j] - bmats.B_17_10.data[i][j] - bmats.B_18_10.data[i][j] - bmats.B_19_10.data[i][j] + bmats.B_1_10.data[i][j] - bmats.B_20_10.data[i][j] - bmats.B_21_10.data[i][j] - bmats.B_22_10.data[i][j] + bmats.B_2_10.data[i][j] + bmats.B_3_10.data[i][j] + bmats.B_4_10.data[i][j] + bmats.B_5_10.data[i][j] + bmats.B_6_10.data[i][j] + bmats.B_7_10.data[i][j] + bmats.B_8_10.data[i][j] + bmats.B_9_10.data[i][j];
        }
    }
    return 0;
}
