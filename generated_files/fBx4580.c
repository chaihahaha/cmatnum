#include "fBx4580.h"

inline int fBx4580(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx4580.data[i][j] = bmats.B_12_8.data[i][j] + bmats.B_13_8.data[i][j] + bmats.B_14_8.data[i][j] + bmats.B_15_8.data[i][j] + bmats.B_16_8.data[i][j] + bmats.B_17_8.data[i][j] + bmats.B_20_8.data[i][j] + bmats.B_21_8.data[i][j] + bmats.B_22_8.data[i][j];
        }
    }
    return 0;
}
