#include "fBx4641.h"

inline int fBx4641(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Bx4641.data[i][j] = bmats.B_13_17.data[i][j] + bmats.B_13_18.data[i][j] + bmats.B_13_19.data[i][j] + bmats.B_13_20.data[i][j] + bmats.B_13_21.data[i][j] + bmats.B_13_22.data[i][j] + bmats.B_13_23.data[i][j] + bmats.B_13_24.data[i][j] + bmats.B_13_25.data[i][j] + bmats.B_13_26.data[i][j] + bmats.B_13_27.data[i][j] + bmats.B_13_28.data[i][j] + bmats.B_13_29.data[i][j] + bmats.B_13_30.data[i][j] + bmats.B_13_31.data[i][j] + bmats.B_13_32.data[i][j];
        }
    }
    return 0;
}
