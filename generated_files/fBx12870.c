#include "fBx12870.h"

inline int fBx12870(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx12870.data[i][j] = bmats.B_10_1.data[i][j] + bmats.B_11_1.data[i][j] + bmats.B_12_1.data[i][j] + bmats.B_13_1.data[i][j] + bmats.B_1_1.data[i][j] + bmats.B_2_1.data[i][j] + bmats.B_3_1.data[i][j] + bmats.B_8_1.data[i][j] + bmats.B_9_1.data[i][j];
        }
    }
    return 0;
}
