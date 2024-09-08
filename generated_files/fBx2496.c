#include "fBx2496.h"

inline int fBx2496(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx2496.data[i][j] = bmats.B_14_18.data[i][j] + bmats.B_14_19.data[i][j] + bmats.B_14_20.data[i][j] + bmats.B_14_21.data[i][j] + bmats.B_14_22.data[i][j] + bmats.B_14_23.data[i][j] + bmats.B_14_24.data[i][j] + bmats.B_14_25.data[i][j] + bmats.B_14_26.data[i][j] + bmats.B_14_27.data[i][j] + bmats.B_14_28.data[i][j] + bmats.B_14_29.data[i][j] + bmats.B_14_30.data[i][j] + bmats.B_14_31.data[i][j] + bmats.B_14_32.data[i][j];
        }
    }
    return 0;
}
