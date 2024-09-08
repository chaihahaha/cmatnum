#include "fBx4071.h"

inline int fBx4071(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx4071.data[i][j] = bmats.B_11_20.data[i][j] + bmats.B_1_20.data[i][j] + bmats.B_2_20.data[i][j] + bmats.B_3_20.data[i][j] + bmats.B_4_20.data[i][j] + bmats.B_5_20.data[i][j] + bmats.B_6_20.data[i][j];
        }
    }
    return 0;
}
