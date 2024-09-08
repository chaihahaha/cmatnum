#include "fBx10449.h"

inline int fBx10449(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx10449.data[i][j] = bmats.B_8_17.data[i][j] + bmats.B_8_18.data[i][j] + bmats.B_8_19.data[i][j] + bmats.B_8_20.data[i][j] + bmats.B_8_21.data[i][j] + bmats.B_8_22.data[i][j] + bmats.B_8_23.data[i][j] + bmats.B_8_24.data[i][j] + bmats.B_8_25.data[i][j] + bmats.B_8_26.data[i][j] + bmats.B_8_27.data[i][j] + bmats.B_8_28.data[i][j] + bmats.B_8_29.data[i][j] + bmats.B_8_30.data[i][j] + bmats.B_8_31.data[i][j] + bmats.B_8_32.data[i][j];
        }
    }
    return 0;
}
