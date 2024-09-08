#include "fAx3805.h"

inline int fAx3805(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax3805.data[i][j] = 2*bmats.A_18_12.data[i][j] + 2*bmats.A_18_13.data[i][j] + 2*bmats.A_18_16.data[i][j] + 2*bmats.A_18_17.data[i][j] - 10*bmats.A_18_18.data[i][j] + 2*bmats.A_18_19.data[i][j] + 2*bmats.A_18_20.data[i][j] + 2*bmats.A_18_21.data[i][j] + 2*bmats.A_18_22.data[i][j];
        }
    }
    return 0;
}
