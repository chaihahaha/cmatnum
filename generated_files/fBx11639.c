#include "fBx11639.h"

inline int fBx11639(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx11639.data[i][j] = bmats.B_30_18.data[i][j] + bmats.B_30_19.data[i][j] + bmats.B_30_22.data[i][j] + bmats.B_30_23.data[i][j] + bmats.B_30_24.data[i][j] + bmats.B_30_31.data[i][j] + bmats.Bx2480.data[i][j];
        }
    }
    return 0;
}
