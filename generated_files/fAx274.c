#include "fAx274.h"

inline int fAx274(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax274.data[i][j] = 2*bmats.A_26_19.data[i][j] + 2*bmats.A_26_20.data[i][j] + 2*bmats.A_26_21.data[i][j] + 2*bmats.A_26_22.data[i][j] + 2*bmats.A_26_23.data[i][j] + 2*bmats.A_26_24.data[i][j] + 2*bmats.A_26_25.data[i][j] - 15*bmats.A_26_26.data[i][j] + 2*bmats.A_26_27.data[i][j] + 2*bmats.A_26_28.data[i][j] + 2*bmats.A_26_29.data[i][j] + 2*bmats.A_26_30.data[i][j] + 2*bmats.A_26_31.data[i][j] + 2*bmats.A_26_32.data[i][j];
        }
    }
    return 0;
}
