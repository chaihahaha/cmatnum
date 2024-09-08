#include "fBx12682.h"

inline int fBx12682(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx12682.data[i][j] = bmats.B_15_10.data[i][j] + bmats.B_15_14.data[i][j] + bmats.B_15_15.data[i][j] + bmats.B_15_16.data[i][j] + bmats.B_15_3.data[i][j] + bmats.B_15_4.data[i][j] + bmats.B_15_5.data[i][j] + bmats.B_15_6.data[i][j] + bmats.B_15_7.data[i][j] + bmats.B_15_8.data[i][j] + bmats.B_15_9.data[i][j];
        }
    }
    return 0;
}
