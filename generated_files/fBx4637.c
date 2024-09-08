#include "fBx4637.h"

inline int fBx4637(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx4637.data[i][j] = bmats.B_10_28.data[i][j] + bmats.B_11_28.data[i][j] + bmats.B_12_28.data[i][j] + bmats.B_13_28.data[i][j] + bmats.B_14_28.data[i][j] + bmats.B_15_28.data[i][j] + bmats.B_16_28.data[i][j] + bmats.B_1_28.data[i][j] + bmats.B_2_28.data[i][j] + bmats.B_3_28.data[i][j] + bmats.B_4_28.data[i][j] + bmats.B_5_28.data[i][j] + bmats.B_6_28.data[i][j] + bmats.B_7_28.data[i][j] + bmats.B_8_28.data[i][j] + bmats.B_9_28.data[i][j];
        }
    }
    return 0;
}
