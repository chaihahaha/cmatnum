#include "fBx2401.h"

inline int fBx2401(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx2401.data[i][j] = bmats.B_16_1.data[i][j] + bmats.B_16_2.data[i][j] + bmats.B_16_3.data[i][j] + bmats.B_16_4.data[i][j] + bmats.B_16_7.data[i][j] + bmats.Bx1546.data[i][j];
        }
    }
    return 0;
}
