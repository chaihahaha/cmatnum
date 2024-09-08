#include "fBx7712.h"

inline int fBx7712(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx7712.data[i][j] = bmats.B_10_17.data[i][j] + bmats.B_10_24.data[i][j] + bmats.B_10_25.data[i][j] + bmats.B_10_26.data[i][j] + bmats.B_10_27.data[i][j] + bmats.B_10_28.data[i][j] + bmats.B_10_29.data[i][j] + bmats.B_10_30.data[i][j] + bmats.B_10_31.data[i][j] + bmats.B_10_32.data[i][j];
        }
    }
    return 0;
}
