#include "fBx2488.h"

inline int fBx2488(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx2488.data[i][j] = bmats.B_10_29.data[i][j] + bmats.B_11_29.data[i][j] + bmats.B_12_29.data[i][j] + bmats.B_13_29.data[i][j] + bmats.B_14_29.data[i][j] + bmats.B_15_29.data[i][j] + bmats.B_16_29.data[i][j] + bmats.B_1_29.data[i][j] + bmats.B_2_29.data[i][j] + bmats.B_3_29.data[i][j] + bmats.B_4_29.data[i][j] + bmats.B_5_29.data[i][j] + bmats.B_6_29.data[i][j] + bmats.B_7_29.data[i][j] + bmats.B_8_29.data[i][j] + bmats.B_9_29.data[i][j];
        }
    }
    return 0;
}
