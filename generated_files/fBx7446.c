#include "fBx7446.h"

inline int fBx7446(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx7446.data[i][j] = bmats.B_29_17.data[i][j] + bmats.B_29_18.data[i][j] + bmats.B_29_19.data[i][j] + bmats.B_29_20.data[i][j] + bmats.B_29_21.data[i][j] + bmats.B_29_22.data[i][j] + bmats.B_29_23.data[i][j] + bmats.B_29_27.data[i][j] + bmats.B_29_28.data[i][j] + bmats.B_29_29.data[i][j] + bmats.B_29_30.data[i][j] + bmats.B_29_31.data[i][j] + bmats.B_29_32.data[i][j];
        }
    }
    return 0;
}
