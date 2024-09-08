#include "fBx2356.h"

inline int fBx2356(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx2356.data[i][j] = bmats.B_15_10.data[i][j] + bmats.B_15_11.data[i][j] + bmats.B_15_4.data[i][j] + bmats.B_15_5.data[i][j] + bmats.B_15_6.data[i][j] + bmats.B_15_7.data[i][j] + bmats.B_15_8.data[i][j] + bmats.B_15_9.data[i][j];
        }
    }
    return 0;
}
