#include "fBx13256.h"

inline int fBx13256(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx13256.data[i][j] = bmats.B_13_4.data[i][j] + bmats.B_14_4.data[i][j] + bmats.B_15_4.data[i][j] + bmats.B_16_4.data[i][j] - bmats.B_17_4.data[i][j] - bmats.B_18_4.data[i][j] - bmats.B_19_4.data[i][j] + bmats.B_1_4.data[i][j] - bmats.B_20_4.data[i][j] - bmats.B_21_4.data[i][j] - bmats.B_22_4.data[i][j] - bmats.B_23_4.data[i][j] - bmats.B_24_4.data[i][j] - bmats.B_25_4.data[i][j] - bmats.B_26_4.data[i][j] - bmats.B_27_4.data[i][j] - bmats.B_28_4.data[i][j] - bmats.B_29_4.data[i][j] + bmats.B_2_4.data[i][j] - bmats.B_30_4.data[i][j] - bmats.B_31_4.data[i][j] - bmats.B_32_4.data[i][j] + bmats.B_3_4.data[i][j] + bmats.B_5_4.data[i][j] + bmats.B_6_4.data[i][j] + bmats.B_9_4.data[i][j] + bmats.Bx11903.data[i][j];
        }
    }
    return 0;
}
