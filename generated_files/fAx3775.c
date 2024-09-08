#include "fAx3775.h"

inline int fAx3775(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax3775.data[i][j] = 2*bmats.A_14_12.data[i][j] + 2*bmats.A_14_13.data[i][j] - 10*bmats.A_14_14.data[i][j] + 2*bmats.A_14_17.data[i][j] + 2*bmats.A_14_18.data[i][j] + 2*bmats.A_14_19.data[i][j] + 2*bmats.A_14_20.data[i][j] + 2*bmats.A_14_21.data[i][j] + 2*bmats.A_14_22.data[i][j];
        }
    }
    return 0;
}
