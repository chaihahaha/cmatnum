#include "fBx4289.h"

inline int fBx4289(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx4289.data[i][j] = bmats.B_1_9.data[i][j] + bmats.B_2_9.data[i][j] + bmats.B_3_9.data[i][j] + bmats.B_4_9.data[i][j] + bmats.B_6_9.data[i][j] + bmats.B_9_9.data[i][j];
        }
    }
    return 0;
}
