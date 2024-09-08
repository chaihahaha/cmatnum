#include "fBx4214.h"

inline int fBx4214(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx4214.data[i][j] = bmats.B_10_4.data[i][j] + bmats.B_11_4.data[i][j] - bmats.B_12_4.data[i][j] - bmats.B_13_4.data[i][j] - bmats.B_14_4.data[i][j] - bmats.B_15_4.data[i][j] - bmats.B_16_4.data[i][j] - bmats.B_17_4.data[i][j] - bmats.B_18_4.data[i][j] - bmats.B_19_4.data[i][j] + bmats.B_1_4.data[i][j] - bmats.B_20_4.data[i][j] - bmats.B_21_4.data[i][j] - bmats.B_22_4.data[i][j] + bmats.B_2_4.data[i][j] + bmats.B_3_4.data[i][j] + bmats.B_4_4.data[i][j] + bmats.B_5_4.data[i][j] + bmats.B_6_4.data[i][j] + bmats.B_7_4.data[i][j] + bmats.B_8_4.data[i][j] + bmats.B_9_4.data[i][j];
        }
    }
    return 0;
}
