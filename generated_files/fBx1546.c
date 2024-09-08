#include "fBx1546.h"

inline int fBx1546(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx1546.data[i][j] = bmats.B_16_10.data[i][j] + bmats.B_16_11.data[i][j] + bmats.B_16_5.data[i][j] + bmats.B_16_6.data[i][j] + bmats.B_16_8.data[i][j] + bmats.B_16_9.data[i][j];
        }
    }
    return 0;
}
