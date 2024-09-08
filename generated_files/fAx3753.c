#include "fAx3753.h"

inline int fAx3753(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax3753.data[i][j] = -10*bmats.A_12_12.data[i][j] + 2*bmats.A_12_13.data[i][j] + 2*bmats.A_12_14.data[i][j] + 2*bmats.A_12_15.data[i][j] + 2*bmats.A_12_16.data[i][j] + 2*bmats.A_12_17.data[i][j] + 2*bmats.A_12_18.data[i][j] + 2*bmats.A_12_19.data[i][j] + 2*bmats.A_12_20.data[i][j];
        }
    }
    return 0;
}
