#include "fBx13268.h"

inline int fBx13268(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx13268.data[i][j] = bmats.B_14_6.data[i][j] + bmats.B_15_6.data[i][j] + bmats.B_16_6.data[i][j] - bmats.B_17_6.data[i][j] - bmats.B_18_6.data[i][j] - bmats.B_19_6.data[i][j] + bmats.B_1_6.data[i][j] - bmats.B_20_6.data[i][j] - bmats.B_21_6.data[i][j] - bmats.B_22_6.data[i][j] - bmats.B_23_6.data[i][j] - bmats.B_24_6.data[i][j] - bmats.B_25_6.data[i][j] - bmats.B_26_6.data[i][j] - bmats.B_27_6.data[i][j] - bmats.B_28_6.data[i][j] - bmats.B_29_6.data[i][j] + bmats.B_2_6.data[i][j] - bmats.B_30_6.data[i][j] - bmats.B_31_6.data[i][j] - bmats.B_32_6.data[i][j] + bmats.B_3_6.data[i][j] + bmats.B_4_6.data[i][j] + bmats.B_5_6.data[i][j] + bmats.Bx10888.data[i][j];
        }
    }
    return 0;
}
