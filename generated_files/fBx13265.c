#include "fBx13265.h"

inline int fBx13265(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx13265.data[i][j] = -bmats.B_15_21.data[i][j] - bmats.B_16_21.data[i][j] + bmats.B_17_21.data[i][j] + bmats.B_18_21.data[i][j] + bmats.B_19_21.data[i][j] - bmats.B_1_21.data[i][j] + bmats.B_20_21.data[i][j] + bmats.B_21_21.data[i][j] + bmats.B_22_21.data[i][j] + bmats.B_23_21.data[i][j] + bmats.B_24_21.data[i][j] + bmats.B_25_21.data[i][j] + bmats.B_26_21.data[i][j] + bmats.B_27_21.data[i][j] + bmats.B_28_21.data[i][j] + bmats.B_29_21.data[i][j] - bmats.B_2_21.data[i][j] + bmats.B_30_21.data[i][j] + bmats.B_31_21.data[i][j] + bmats.B_32_21.data[i][j] - bmats.B_3_21.data[i][j] - bmats.B_4_21.data[i][j] - bmats.B_5_21.data[i][j] - bmats.B_7_21.data[i][j] - bmats.B_9_21.data[i][j] - bmats.Bx11440.data[i][j];
        }
    }
    return 0;
}
