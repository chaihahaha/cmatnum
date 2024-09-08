#include "fBx13274.h"

inline int fBx13274(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx13274.data[i][j] = bmats.B_11_7.data[i][j] + bmats.B_13_7.data[i][j] + bmats.B_14_7.data[i][j] + bmats.B_15_7.data[i][j] + bmats.B_16_7.data[i][j] - bmats.B_17_7.data[i][j] - bmats.B_18_7.data[i][j] - bmats.B_19_7.data[i][j] + bmats.B_1_7.data[i][j] - bmats.B_20_7.data[i][j] - bmats.B_21_7.data[i][j] - bmats.B_22_7.data[i][j] - bmats.B_23_7.data[i][j] - bmats.B_24_7.data[i][j] - bmats.B_25_7.data[i][j] - bmats.B_26_7.data[i][j] - bmats.B_27_7.data[i][j] - bmats.B_28_7.data[i][j] - bmats.B_29_7.data[i][j] - bmats.B_30_7.data[i][j] - bmats.B_31_7.data[i][j] - bmats.B_32_7.data[i][j] + bmats.B_3_7.data[i][j] + bmats.B_4_7.data[i][j] + bmats.B_5_7.data[i][j] + bmats.B_6_7.data[i][j] + bmats.Bx10249.data[i][j];
        }
    }
    return 0;
}
