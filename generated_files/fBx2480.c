#include "fBx2480.h"

inline int fBx2480(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx2480.data[i][j] = bmats.B_30_17.data[i][j] + bmats.B_30_25.data[i][j] + bmats.B_30_26.data[i][j] + bmats.B_30_27.data[i][j] + bmats.B_30_28.data[i][j] + bmats.B_30_29.data[i][j] + bmats.B_30_30.data[i][j] + bmats.B_30_32.data[i][j];
        }
    }
    return 0;
}
