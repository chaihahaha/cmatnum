#include "fBx7425.h"

inline int fBx7425(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx7425.data[i][j] = bmats.B_27_19.data[i][j] + bmats.B_27_20.data[i][j] + bmats.B_27_21.data[i][j] + bmats.B_27_22.data[i][j] + bmats.B_27_24.data[i][j] + bmats.B_27_25.data[i][j] + bmats.B_27_26.data[i][j] + bmats.B_27_27.data[i][j] + bmats.B_27_28.data[i][j] + bmats.B_27_29.data[i][j] + bmats.B_27_30.data[i][j] + bmats.B_27_31.data[i][j] + bmats.B_27_32.data[i][j];
        }
    }
    return 0;
}
