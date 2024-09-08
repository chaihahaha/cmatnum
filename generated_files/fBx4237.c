#include "fBx4237.h"

inline int fBx4237(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx4237.data[i][j] = bmats.B_10_6.data[i][j] + bmats.B_11_6.data[i][j] - bmats.B_12_6.data[i][j] - bmats.B_13_6.data[i][j] - bmats.B_14_6.data[i][j] - bmats.B_15_6.data[i][j] - bmats.B_16_6.data[i][j] - bmats.B_17_6.data[i][j] - bmats.B_18_6.data[i][j] - bmats.B_19_6.data[i][j] + bmats.B_1_6.data[i][j] - bmats.B_20_6.data[i][j] - bmats.B_21_6.data[i][j] - bmats.B_22_6.data[i][j] + bmats.B_2_6.data[i][j] + bmats.B_3_6.data[i][j] + bmats.B_4_6.data[i][j] + bmats.B_5_6.data[i][j] + bmats.B_6_6.data[i][j] + bmats.B_7_6.data[i][j] + bmats.B_8_6.data[i][j] + bmats.B_9_6.data[i][j];
        }
    }
    return 0;
}
