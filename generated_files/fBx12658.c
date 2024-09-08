#include "fBx12658.h"

inline int fBx12658(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx12658.data[i][j] = bmats.B_11_2.data[i][j] + bmats.B_12_2.data[i][j] + bmats.B_13_2.data[i][j] + bmats.B_16_2.data[i][j] + bmats.B_1_2.data[i][j] + bmats.B_2_2.data[i][j] + bmats.B_3_2.data[i][j] + bmats.B_5_2.data[i][j] + bmats.B_6_2.data[i][j] + bmats.B_8_2.data[i][j] + bmats.B_9_2.data[i][j];
        }
    }
    return 0;
}
