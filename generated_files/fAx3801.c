#include "fAx3801.h"

inline int fAx3801(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax3801.data[i][j] = 2*bmats.A_19_12.data[i][j] + 2*bmats.A_19_13.data[i][j] + 2*bmats.A_19_14.data[i][j] + 2*bmats.A_19_17.data[i][j] + 2*bmats.A_19_18.data[i][j] - 10*bmats.A_19_19.data[i][j] + 2*bmats.A_19_20.data[i][j] + 2*bmats.A_19_21.data[i][j] + 2*bmats.A_19_22.data[i][j];
        }
    }
    return 0;
}
