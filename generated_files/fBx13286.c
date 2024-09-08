#include "fBx13286.h"

inline int fBx13286(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx13286.data[i][j] = bmats.B_10_9.data[i][j] + bmats.B_11_9.data[i][j] + bmats.B_12_9.data[i][j] + bmats.B_13_9.data[i][j] + bmats.B_14_9.data[i][j] + bmats.B_15_9.data[i][j] + bmats.B_16_9.data[i][j] - bmats.B_17_9.data[i][j] - bmats.B_18_9.data[i][j] - bmats.B_19_9.data[i][j] + bmats.B_1_9.data[i][j] - bmats.B_20_9.data[i][j] - bmats.B_21_9.data[i][j] - bmats.B_22_9.data[i][j] - bmats.B_23_9.data[i][j] - bmats.B_24_9.data[i][j] - bmats.B_25_9.data[i][j] - bmats.B_26_9.data[i][j] - bmats.B_27_9.data[i][j] - bmats.B_28_9.data[i][j] - bmats.B_29_9.data[i][j] + bmats.B_2_9.data[i][j] - bmats.B_30_9.data[i][j] - bmats.B_31_9.data[i][j] - bmats.B_32_9.data[i][j] + bmats.B_3_9.data[i][j] + bmats.B_4_9.data[i][j] + bmats.B_5_9.data[i][j] + bmats.B_6_9.data[i][j] + bmats.B_7_9.data[i][j] + bmats.B_8_9.data[i][j] + bmats.B_9_9.data[i][j];
        }
    }
    return 0;
}
