#include "fAx3730.h"

inline int fAx3730(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax3730.data[i][j] = 2*bmats.A_22_12.data[i][j] + 2*bmats.A_22_13.data[i][j] + 2*bmats.A_22_14.data[i][j] + 2*bmats.A_22_15.data[i][j] + 2*bmats.A_22_16.data[i][j] + 2*bmats.A_22_17.data[i][j] + 2*bmats.A_22_18.data[i][j] + 2*bmats.A_22_19.data[i][j] - 10*bmats.A_22_22.data[i][j];
        }
    }
    return 0;
}
