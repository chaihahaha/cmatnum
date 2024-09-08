#include "fBx7184.h"

inline int fBx7184(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx7184.data[i][j] = bmats.B_10_26.data[i][j] + bmats.B_11_26.data[i][j] + bmats.B_12_26.data[i][j] + bmats.B_13_26.data[i][j] + bmats.B_14_26.data[i][j] + bmats.B_15_26.data[i][j] + bmats.B_16_26.data[i][j] + bmats.B_1_26.data[i][j] + bmats.B_2_26.data[i][j] + bmats.B_3_26.data[i][j] + bmats.B_4_26.data[i][j] + bmats.B_5_26.data[i][j] + bmats.B_6_26.data[i][j] + bmats.B_7_26.data[i][j] + bmats.B_8_26.data[i][j] + bmats.B_9_26.data[i][j];
        }
    }
    return 0;
}
