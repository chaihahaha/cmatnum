#include "fBx12672.h"

inline int fBx12672(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx12672.data[i][j] = bmats.B_10_18.data[i][j] + bmats.B_11_18.data[i][j] + bmats.B_12_18.data[i][j] + bmats.B_13_18.data[i][j] + bmats.B_14_18.data[i][j] + bmats.B_15_18.data[i][j] + bmats.B_3_18.data[i][j] + bmats.B_4_18.data[i][j] + bmats.B_5_18.data[i][j] + bmats.B_6_18.data[i][j] + bmats.B_7_18.data[i][j] + bmats.B_8_18.data[i][j] + bmats.B_9_18.data[i][j];
        }
    }
    return 0;
}
