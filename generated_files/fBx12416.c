#include "fBx12416.h"

inline int fBx12416(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx12416.data[i][j] = bmats.B_10_3.data[i][j] + bmats.B_13_3.data[i][j] + bmats.B_15_3.data[i][j] + bmats.B_16_3.data[i][j] + bmats.B_2_3.data[i][j] + bmats.B_3_3.data[i][j] + bmats.B_4_3.data[i][j] + bmats.B_6_3.data[i][j] + bmats.B_8_3.data[i][j];
        }
    }
    return 0;
}
