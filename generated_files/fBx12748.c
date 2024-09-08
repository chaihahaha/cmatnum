#include "fBx12748.h"

inline int fBx12748(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx12748.data[i][j] = bmats.B_10_18.data[i][j] + bmats.B_11_18.data[i][j] + bmats.B_12_18.data[i][j] + bmats.B_15_18.data[i][j] + bmats.B_3_18.data[i][j] + bmats.B_6_18.data[i][j] + bmats.B_7_18.data[i][j] + bmats.B_8_18.data[i][j] + bmats.B_9_18.data[i][j];
        }
    }
    return 0;
}
