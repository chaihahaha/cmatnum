#include "fBx4114.h"

inline int fBx4114(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx4114.data[i][j] = bmats.B_1_22.data[i][j] + bmats.B_2_22.data[i][j] + bmats.B_3_22.data[i][j] + bmats.B_4_22.data[i][j] + bmats.B_5_22.data[i][j] + bmats.B_6_22.data[i][j];
        }
    }
    return 0;
}
