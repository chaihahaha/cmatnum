#include "fBx8256.h"

inline int fBx8256(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx8256.data[i][j] = bmats.B_20_25.data[i][j] + bmats.B_21_25.data[i][j] + bmats.B_22_25.data[i][j] + bmats.B_23_25.data[i][j] + bmats.B_24_25.data[i][j] + bmats.B_31_25.data[i][j] + bmats.B_32_25.data[i][j];
        }
    }
    return 0;
}
