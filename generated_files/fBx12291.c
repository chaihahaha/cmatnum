#include "fBx12291.h"

inline int fBx12291(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx12291.data[i][j] = bmats.B_10_3.data[i][j] + bmats.B_11_3.data[i][j] + bmats.B_12_3.data[i][j] + bmats.B_13_3.data[i][j] + bmats.B_3_3.data[i][j] + bmats.B_4_3.data[i][j] + bmats.B_5_3.data[i][j] + bmats.B_7_3.data[i][j] + bmats.B_8_3.data[i][j] + bmats.B_9_3.data[i][j];
        }
    }
    return 0;
}
