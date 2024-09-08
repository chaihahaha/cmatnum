#include "fBx13271.h"

inline int fBx13271(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx13271.data[i][j] = -bmats.B_11_22.data[i][j] - bmats.B_14_22.data[i][j] - bmats.B_15_22.data[i][j] - bmats.B_16_22.data[i][j] + bmats.B_17_22.data[i][j] + bmats.B_18_22.data[i][j] + bmats.B_19_22.data[i][j] - bmats.B_1_22.data[i][j] + bmats.B_20_22.data[i][j] + bmats.B_21_22.data[i][j] + bmats.B_22_22.data[i][j] + bmats.B_23_22.data[i][j] + bmats.B_24_22.data[i][j] + bmats.B_25_22.data[i][j] + bmats.B_26_22.data[i][j] + bmats.B_27_22.data[i][j] + bmats.B_28_22.data[i][j] + bmats.B_29_22.data[i][j] - bmats.B_2_22.data[i][j] + bmats.B_30_22.data[i][j] + bmats.B_31_22.data[i][j] + bmats.B_32_22.data[i][j] - bmats.B_3_22.data[i][j] - bmats.B_4_22.data[i][j] - bmats.B_5_22.data[i][j] - bmats.B_6_22.data[i][j] - bmats.Bx10907.data[i][j];
        }
    }
    return 0;
}
