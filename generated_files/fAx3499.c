#include "fAx3499.h"

inline int fAx3499(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax3499.data[i][j] = -10*bmats.A_13_13.data[i][j] + 2*bmats.A_13_14.data[i][j] + 2*bmats.A_13_15.data[i][j] + 2*bmats.A_13_16.data[i][j] + 2*bmats.A_13_17.data[i][j] + 2*bmats.A_13_18.data[i][j] + 2*bmats.A_13_19.data[i][j] + 2*bmats.A_13_20.data[i][j] + 2*bmats.A_13_21.data[i][j];
        }
    }
    return 0;
}
