#include "fAx3802.h"

inline int fAx3802(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax3802.data[i][j] = 2*bmats.A_19_12.data[i][j] + 2*bmats.A_19_13.data[i][j] + 2*bmats.A_19_14.data[i][j] + 2*bmats.A_19_15.data[i][j] + 2*bmats.A_19_16.data[i][j] - 10*bmats.A_19_19.data[i][j] + 2*bmats.A_19_20.data[i][j] + 2*bmats.A_19_21.data[i][j] + 2*bmats.A_19_22.data[i][j];
        }
    }
    return 0;
}
