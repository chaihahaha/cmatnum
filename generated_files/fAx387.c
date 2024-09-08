#include "fAx387.h"

inline int fAx387(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax387.data[i][j] = 2*bmats.A_23_17.data[i][j] + 2*bmats.A_23_18.data[i][j] + 2*bmats.A_23_21.data[i][j] + 2*bmats.A_23_22.data[i][j] - 15*bmats.A_23_23.data[i][j] + 2*bmats.A_23_24.data[i][j] + 2*bmats.A_23_25.data[i][j] + 2*bmats.A_23_26.data[i][j] + 2*bmats.A_23_27.data[i][j] + 2*bmats.A_23_28.data[i][j] + 2*bmats.A_23_29.data[i][j] + 2*bmats.A_23_30.data[i][j] + 2*bmats.A_23_31.data[i][j] + 2*bmats.A_23_32.data[i][j];
        }
    }
    return 0;
}
