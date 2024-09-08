#include "fAx3808.h"

inline int fAx3808(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax3808.data[i][j] = 2*bmats.A_17_12.data[i][j] + 2*bmats.A_17_13.data[i][j] + 2*bmats.A_17_14.data[i][j] - 10*bmats.A_17_17.data[i][j] + 2*bmats.A_17_18.data[i][j] + 2*bmats.A_17_19.data[i][j] + 2*bmats.A_17_20.data[i][j] + 2*bmats.A_17_21.data[i][j] + 2*bmats.A_17_22.data[i][j];
        }
    }
    return 0;
}
