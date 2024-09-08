#include "fBx4622.h"

inline int fBx4622(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx4622.data[i][j] = bmats.B_29_17.data[i][j] + bmats.B_29_18.data[i][j] + bmats.B_29_19.data[i][j] + bmats.B_29_20.data[i][j] + bmats.B_29_21.data[i][j] + bmats.B_29_22.data[i][j] + bmats.B_29_23.data[i][j] + bmats.B_29_24.data[i][j] + bmats.B_29_25.data[i][j] + bmats.B_29_26.data[i][j];
        }
    }
    return 0;
}
