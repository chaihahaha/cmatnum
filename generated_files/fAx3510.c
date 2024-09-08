#include "fAx3510.h"

inline int fAx3510(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax3510.data[i][j] = -10*bmats.A_14_14.data[i][j] + 2*bmats.A_14_15.data[i][j] + 2*bmats.A_14_16.data[i][j] + 2*bmats.A_14_17.data[i][j] + 2*bmats.A_14_18.data[i][j] + 2*bmats.A_14_19.data[i][j] + 2*bmats.A_14_20.data[i][j] + 2*bmats.A_14_21.data[i][j] + 2*bmats.A_14_22.data[i][j];
        }
    }
    return 0;
}
