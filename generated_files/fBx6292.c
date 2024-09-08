#include "fBx6292.h"

inline int fBx6292(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx6292.data[i][j] = bmats.B_28_17.data[i][j] + bmats.B_28_19.data[i][j] + bmats.B_28_20.data[i][j] + bmats.B_28_21.data[i][j] + bmats.B_28_22.data[i][j] + bmats.B_28_24.data[i][j] + bmats.B_28_27.data[i][j];
        }
    }
    return 0;
}
