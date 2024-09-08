#include "fBx4515.h"

inline int fBx4515(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx4515.data[i][j] = bmats.B_12_9.data[i][j] + bmats.B_13_9.data[i][j] + bmats.B_14_9.data[i][j] + bmats.B_15_9.data[i][j] + bmats.B_16_9.data[i][j] + bmats.B_17_9.data[i][j] + bmats.B_21_9.data[i][j] + bmats.B_22_9.data[i][j];
        }
    }
    return 0;
}
