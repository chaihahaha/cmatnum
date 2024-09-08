#include "fAx3474.h"

inline int fAx3474(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax3474.data[i][j] = 2*bmats.A_16_12.data[i][j] + 2*bmats.A_16_13.data[i][j] - 10*bmats.A_16_16.data[i][j] + 2*bmats.A_16_17.data[i][j] + 2*bmats.A_16_18.data[i][j] + 2*bmats.A_16_19.data[i][j] + 2*bmats.A_16_20.data[i][j] + 2*bmats.A_16_21.data[i][j] + 2*bmats.A_16_22.data[i][j];
        }
    }
    return 0;
}
