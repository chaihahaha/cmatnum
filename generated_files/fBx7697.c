#include "fBx7697.h"

inline int fBx7697(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx7697.data[i][j] = bmats.B_26_23.data[i][j] + bmats.B_26_24.data[i][j] + bmats.B_26_25.data[i][j] + bmats.B_26_26.data[i][j] + bmats.B_26_27.data[i][j] + bmats.B_26_28.data[i][j] + bmats.B_26_29.data[i][j] + bmats.B_26_30.data[i][j] + bmats.B_26_31.data[i][j] + bmats.B_26_32.data[i][j];
        }
    }
    return 0;
}
