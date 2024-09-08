#include "fBx2481.h"

inline int fBx2481(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx2481.data[i][j] = bmats.B_30_18.data[i][j] + bmats.B_30_19.data[i][j] + bmats.B_30_20.data[i][j] + bmats.B_30_21.data[i][j] + bmats.B_30_23.data[i][j] + bmats.B_30_24.data[i][j] + bmats.B_30_31.data[i][j];
        }
    }
    return 0;
}
