#include "fBx4620.h"

inline int fBx4620(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx4620.data[i][j] = bmats.B_10_12.data[i][j] + bmats.B_15_12.data[i][j] + bmats.B_16_12.data[i][j] + bmats.B_3_12.data[i][j] + bmats.B_4_12.data[i][j] + bmats.B_6_12.data[i][j] + bmats.B_7_12.data[i][j] + bmats.B_8_12.data[i][j] + bmats.B_9_12.data[i][j];
        }
    }
    return 0;
}
