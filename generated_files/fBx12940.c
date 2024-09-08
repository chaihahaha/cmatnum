#include "fBx12940.h"

inline int fBx12940(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx12940.data[i][j] = bmats.B_10_17.data[i][j] + bmats.B_11_17.data[i][j] + bmats.B_15_17.data[i][j] + bmats.B_16_17.data[i][j] + bmats.B_1_17.data[i][j] + bmats.B_2_17.data[i][j] + bmats.B_3_17.data[i][j] + bmats.B_4_17.data[i][j] + bmats.B_5_17.data[i][j] + bmats.B_6_17.data[i][j] + bmats.B_7_17.data[i][j] + bmats.B_8_17.data[i][j] + bmats.B_9_17.data[i][j];
        }
    }
    return 0;
}
